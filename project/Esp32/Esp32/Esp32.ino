#include <WiFi.h>
#include <HTTPClient.h>
#include "HX711.h"
#include <math.h>
#include <ArduinoJson.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_PIN  17 // ESP32 pin GPIO17 connected to DS18B20 sensor's DATA pin

// Paramètres WiFi
const char* ssid = "RIOC-TP-IoT";       // Remplacez par le nom de votre réseau WiFi
const char* password = "GRIT-RIOC_2024";    // Remplacez par votre mot de passe WiFi

// URL de l'API
const char* serverName = "http://10.19.3.15:1026/v2/entities";
const char* deleteURL = "http://10.19.3.15:1026/v2/entities/Ruche1"; // URL pour l'appel DELETE

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

// Initialisation du capteur HX711
HX711 scale;

unsigned long lastTime = 0;
unsigned long timerDelay = 5000; // Délai de 1 minute en millisecondes (60*1000)



OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

float tempC; // temperature in Celsius
float tempF; // temperature in Fahrenheit

void setup() {
  // Connexion au WiFi
  Serial.begin(9600);
  connectToWiFi();
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  DS18B20.begin();    // initialize the DS18B20 sensor
  Tare();
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.get_units(10);
    double val = analogRead(13);
    double fenya = (val / 1023) * 5;
    double r = (5 - fenya) / fenya * 4700;

    if ((millis() - lastTime) > timerDelay) {
      makeHTTPRequest(reading, 1 / (log(r / 10000) / 3950 + 1 / (25 + 273.15)) - 273.15);
      lastTime = millis();
      Serial.println("ENVOIE REQUETE");
    }
  } else {
    Serial.println("HX711 not found.");
  }

  // Appel de la fonction deleteEntity pour tester
  if (/* condition pour supprimer l'entité */ false) {
    deleteEntity();
  }

  delay(1000); // Petite pause pour éviter de surcharger la boucle
}

void Tare() {
  scale.set_scale(445);    
  Serial.println("Tare... remove any weights from the scale.");
  delay(5000);
  scale.tare();
  Serial.println("Tare done...");
}

void connectToWiFi() {
  Serial.println("Connexion au WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { // Attente de la connexion
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connecté avec succès");
  Serial.print("Adresse IP attribuée : ");
  Serial.println(WiFi.localIP());
}

void makeHTTPRequest(float poids, float temps) {
  if (WiFi.status() == WL_CONNECTED) {
    deleteEntity(); // Vérifier si connecté au WiFi
    HTTPClient http; // Création de l'objet HTTPClient

    
    DS18B20.requestTemperatures();       // send the command to get temperatures
    tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C


    http.begin(serverName); // Spécifie la destination de la requête
    http.addHeader("Content-Type", "application/json"); // Spécifie le type de contenu


    // Création du payload JSON
    StaticJsonDocument<200> doc;
    doc["id"] = "Ruche1";
    doc["type"] = "Hive";
    JsonObject temperature = doc.createNestedObject("Temperature");
    temperature["type"] = "float";
    temperature["value"] = tempC;
    JsonObject poid = doc.createNestedObject("Poid");
    poid["type"] = "float";
    poid["value"] = poids;
    JsonObject recolte = doc.createNestedObject("recolte");
    recolte["type"] = "number";


    Serial.println(poids - 400);

    if(poids - 400 >= 400){
      recolte["value"] = "1";
    }else{
      recolte["value"] = "0";
    }
    
    // Convertir JSON en String

    String requestBody;
    serializeJson(doc, requestBody);

    // Envoyer la requête POST
    int httpResponseCode = http.POST(requestBody);

    handleHTTPResponse(httpResponseCode, http);

    http.end(); // Fermeture de la connexion
  } else {
    Serial.println("Erreur de connexion WiFi");
  }
}

void deleteEntity() {
  if (WiFi.status() == WL_CONNECTED) { // Vérifier si connecté au WiFi
    HTTPClient http; // Création de l'objet HTTPClient

    http.begin(deleteURL); // Spécifie la destination de la requête DELETE

    // Envoyer la requête DELETE
    int httpResponseCode = http.sendRequest("DELETE");

    http.end(); // Fermeture de la connexion
  } else {
    Serial.println("Erreur de connexion WiFi");
  }
}

void handleHTTPResponse(int httpResponseCode, HTTPClient &http) {
  if (httpResponseCode > 0) { // Vérifie si la requête a réussi
    Serial.print("Code de réponse HTTP : ");
    Serial.println(httpResponseCode);

    if (httpResponseCode != 204) { // Vérifie si ce n'est pas un code 204
      String response = http.getString(); // Obtention de la réponse
      Serial.println(response);
    }
  } else {
    Serial.print("Erreur lors de la requête : ");
    Serial.println(httpResponseCode);
  }
}
