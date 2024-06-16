<template>
  <ion-page>
    <div class="home-container">
      <div class="home-header">
        <h1>Bienvenue Arthur !</h1>
      </div>
      <div class="home-list">
        <ion-list>
          <ion-item v-for="hive in hives" :key="hive.id">
            <ion-thumbnail slot="start">
              <img alt="Silhouette of hive" src="../images/hivelogo.svg" />
            </ion-thumbnail>
            <div class="label-container">
              <ion-label>{{ hive.id }}</ion-label>
              <ion-label>Poids: {{ hive.Poid.value }} kg</ion-label>
              <ion-label>Température: {{ hive.Temperature.value }} °C</ion-label>
              <ion-label >Récolte: {{ hive.recolte.value }} </ion-label>
            </div>
          </ion-item>
        </ion-list>
      </div>
    </div>
  </ion-page>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue';
import { IonList, IonItem, IonThumbnail, IonLabel, IonPage } from '@ionic/vue';
import axios from 'axios';

interface Hive {
  id: string;
  Poid: {
    value: number;
  };
  Temperature: {
    value: number;
  };
  recolte: {
    value: number;
  };
}
const hives = ref<Hive[]>([]);

onMounted(async () => {
  try {
    const response = await axios.get('http://10.19.3.15:1026/v2/entities');
    hives.value = response.data;
    console.log(response.data);
  } catch (error) {
    console.error('Erreur lors de la récupération des données', error);
  }
});
</script>

<style scoped>
ion-page {
  height: 100%;
  width: 100%;
  padding: 0;
}

.home-container {
  background: #feeda1;
  height: 100%;
  width: 100%;
  margin: 0;
  padding: 0;
}

.home-header {
  margin-top: 0;
  padding-top: 0;
  height: 20%;
  width: 100%;
  background: #f2d80c;
  border-bottom-left-radius: 38px;
  border-bottom-right-radius: 38px;
  display: flex;
  align-items: center; /* Centrage vertical */
}

.home-header h1 {
  margin-left: 20px;
}

.home-list {
  margin-top: 15px;
}

ion-list {
  background: transparent;
}

ion-item {
  --background: transparent;
  margin: 5px;
}

item-native::after {
  --background: transparent;
}

.label-container {
  display: flex;
  flex-direction: column;
}
</style>
