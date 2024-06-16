<template>
    <ion-page>
        <ion-content :fullscreen="true">
            <div class="background">
                <div class="shape"></div>
                <div class="shape"></div>
            </div>
        <form>
            <h3>Register Here</h3>

            <label for="Lastname">Nom</label>
            <ion-input type="text" placeholder="Nom" id="lastname"></ion-input>

            <label for="Lastname">Prénom</label>
            <ion-input type="text" placeholder="Prénom" id="name"></ion-input>

            <label for="username">Email</label>
            <ion-input type="text" placeholder="Email" id="username"></ion-input>

            <label for="password">Password</label>
            <ion-input type="password" placeholder="Password" id="password"></ion-input>

            <p>Déjà un compte ? <a @click="() => router.push('/login')">Login</a></p>
            <ion-button @click="() => router.push('/home')">Log In</ion-button>
        </form>
        </ion-content>
    </ion-page>
</template>

<script setup lang="ts">
import {
    IonPage,
    IonContent,
    IonButton,
    IonInput,
} from "@ionic/vue";
import { useRouter } from "vue-router";

const router = useRouter();
</script>

<style scoped>
.background{
    width: 100%;
    height: 100%px;
    position: absolute;
    transform: translate(-50%,-50%);
    left: 50%;
    top: 50%;
}
.background .shape{
    height: 200px;
    width: 200px;
    position: absolute;
  -webkit-clip-path: polygon(25% 5%, 75% 5%, 100% 50%, 75% 95%, 25% 95%, 0% 50%);
  clip-path: polygon(25% 5%, 75% 5%, 100% 50%, 75% 95%, 25% 95%, 0% 50%);
}
.shape:first-child{
    background: linear-gradient(
        #ff512f,
        #f09819
    );
    left: -80px;
    top: -80px;
}
.shape:last-child{
    background: linear-gradient(
        to right,
        #ff512f,
        #f09819
    );
    right: -30px;
    bottom: -40px;
}
form{
    height: 75%;
    width: 80%;
    --padding-start: 20px;
    background-color: rgba(255,255,255,0.13);
    position: absolute;
    transform: translate(-50%,-50%);
    top: 50%;
    left: 50%;
    border-radius: 10px;
    backdrop-filter: blur(10px);
    border: 2px solid rgba(255,255,255,0.1);
    box-shadow: 0 0 40px rgba(8,7,16,0.6);
    padding: 0px 35px 50px 35px;
}
form *{
    font-family: 'Poppins',sans-serif;
    color: #ffffff;
    letter-spacing: 0.5px;
    outline: none;
    border: none;
}
form h3{
    font-size: 32px;
    font-weight: 500;
    line-height: 42px;
    text-align: center;
}

form a{
    color: #ff512f;
}

label{
    display: block;
    margin-top: 30px;
    font-size: 16px;
    font-weight: 500;
}
ion-input{
    display: block;
    height: 50px;
    width: 100%;
    background-color: rgba(255,255,255,0.07);
    border-radius: 3px;
    margin-top: 8px;
    font-size: 14px;
    font-weight: 300;
}
::placeholder{
    color: #e5e5e5;
}
ion-button{
    width: 100%;
    --background:linear-gradient(
        to right,
        #ff512f,
        #f09819
    );
    color: white;
    padding: 15px 0;
    font-size: 18px;
    font-weight: 600;
    border-radius: 5px;
    cursor: pointer;
    --background-activated: #6d080811;
}
.social{
  margin-top: 30px;
  display: flex;
}
.social div{
  background: red;
  width: 150px;
  border-radius: 3px;
  padding: 5px 10px 10px 5px;
  background-color: rgba(255,255,255,0.27);
  color: #eaf0fb;
  text-align: center;
}
.social div:hover{
  background-color: rgba(255,255,255,0.47);
}
.social .fb{
  margin-left: 25px;
}
.social i{
  margin-right: 4px;
}

</style>