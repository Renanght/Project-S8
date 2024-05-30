# 🍯 Hive Project 🐝

**`UniLaSalle Amiens - IOT Project using FIWARE`**
<p align="center"> 
Bienvenue dans le monde fascinant de l'apiculture urbaine connectée !
Hive Project vous invite à découvrir une nouvelle façon d'appréhender l'apiculture, alliant tradition et innovation technologique.
</p>

<p align="center"> 
Que vous soyez un apiculteur expérimenté ou un novice curieux, notre mission est de vous accompagner dans la création d'une expérience apicole urbaine enrichissante et responsable.
</p>
Au cœur de notre concept :

  - Des ruches connectées intelligentes dotées de capteurs pour une surveillance en temps réel de la santé et de l'activité de vos colonies.
  - Une application mobile intuitive pour suivre l'évolution de vos ruches, recevoir des alertes personnalisées et obtenir des conseils d'experts.
  - Une muselière anti-frelon asiatique brevetée pour protéger vos abeilles de ce redoutable prédateur.
  - Un accompagnement expert à chaque étape de votre aventure apicole.

Avec Hive Project, l'apiculture urbaine devient accessible à tous !  

## Sommaire

<details>
  <summary>Mobile Application</summary>

L'application est basée sur le framework [Ionic](https://ionicframework.com/) utilisé comme support aux Frameworks Javascripts pour convertir une application web en application Mobile Cross Plateform. Dans notre cas, nous avons décidé d'utilisé [VueJS](https://vuejs.org/).

### 1. NodeJS

Nous utiliserons plus tard l'outil `npm`, nous allons l'installer ou vérifier sa présence via [NodeJS](https://nodejs.org/en).  
  
```bash
node -v
```

  ou  

```bash
node --version
```

Si une version apparait vous pouvez passez à la partie suivante.  
Dans le cas contraire, installez NodeJS en téléchargeant l'instaleur depuis le site de [NodeJS](https://nodejs.org/en).  
  
### 2. Ionic

Nous allons tout d'abord vérifier la présence de [Ionic](https://ionicframework.com/) sur le système.  

  ```bash
node -v
```

  ou  

```bash
node --version
```

Si [Ionic](https://ionicframework.com/) n'est pas présent sur votre machine, vous pouvez executer l'installer avec la commande suivante:

```bash
npm i -g @ionic/cli
```

### 3. VueJS

[VueJS](https://vuejs.org/) est présent directement dans [NodeJS](https://nodejs.org/en) à partir de la version 18.3.  

### 4.  Git clone

Pour récupérer le code de l'application, vous devez ouvrir un terminal à l'endroit où vous souhaitez avoir le code et exécuté la commande suivante:  

```bash
git clone <URL>
```

Par la suite, vous pouvez allez dans votre projet via `cd`, vous pouvez maintenant accéder au code de l'application.  
Vous pouvez installer les différentes dépendances suplémentaire avec:

```bash
npm install
```

Pour executer l'application web en Localhost, utilisez:  

```bash
ionic serve
```

⚠️ Ne pas oubliez d'inspecter l'élément pour obtenir un visuel similaire à un téléphone.

</details>

<details>
  <summary>FIWARE</summary>
  This is the content that will be hidden initially.
</details>

<details>
  <summary>Capteurs</summary>
  This is the content that will be hidden initially.
</details>

<details>
  <summary>Réalisation Matérielle</summary>
  Notre maquette de ruche est une réalisation combinant la découpe laser et l'impression 3D pour créer une structure fonctionnelle et esthétique. Cette ruche est composée de trois parties distinctes, chacune     
  conçue pour optimiser la gestion et la protection de la colonie d'abeilles.

  ###1. La Partie Vitale de la Ruche

  La première section est la partie essentielle de la ruche, où se déroule la majorité de l'activité vitale. Cette zone est spécialement conçue pour permettre aux abeilles d'entrer et de sortir librement. À     
  l'intérieur, la reine dispose de cellules créées par les abeilles ouvrières pour pondre ses œufs. Cette partie est cruciale pour la croissance et le développement de la colonie, car elle constitue le cœur de 
  la ruche où se déroulent les cycles de vie des abeilles.

  ###2. Le Cadre de Récolte

  La deuxième section est un cadre additionnel que l'on peut ajouter à la structure principale. Ce cadre est destiné à accueillir des cadres supplémentaires que les abeilles rempliront de miel. Grâce à une 
  grille spéciale, la reine ne peut pas accéder à cette section pour y pondre, ce qui permet de maintenir cette zone exclusivement dédiée à la production de miel. Cela facilite grandement la récolte du miel sans 
  perturber la colonie ou compromettre les œufs de la reine.


  ⚠️ Chaque colonie d'abeilles étant unique, il est possible d'ajouter plusieurs cadres de récolte si la colonie se développe. Cette modularité permet d'adapter la ruche à la taille et aux besoins de chaque 
  colonie, assurant ainsi une gestion optimale et flexible de l'espace de production de miel.

  ###3. Le Couvercle de Protection

  Pour compléter la structure, nous avons conçu un couvercle robuste permettant de fermer la ruche efficacement et de la protéger des prédateurs. Ce couvercle est une composante essentielle pour assurer la 
  sécurité de la colonie, en offrant une barrière contre les intempéries et les attaques potentielles.

  ###Sécurité Contre les Frelons Asiatiques

  Pour répondre à la menace des frelons asiatiques, nous avons également développé une sorte de muselière à placer à l'entrée de la ruche. Cet accessoire innovant est spécialement conçu pour empêcher les frelons 
  d'accéder à l'intérieur de la ruche tout en permettant aux abeilles de continuer à entrer et sortir librement. Cette protection supplémentaire est cruciale pour la préservation des colonies face à ce prédateur 
  agressif.

  
</details>
