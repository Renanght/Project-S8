import { createRouter, createWebHistory } from '@ionic/vue-router';
import { RouteRecordRaw } from 'vue-router';

const routes: Array<RouteRecordRaw> = [
  
  {
    path: "/",
    component: () => import("@/views/LoginPage.vue"),
  },
  {
    path: "/home",
    component: () => import("@/views/HomePage.vue"),
  },
  {
    path: "/login",
    component: () => import("@/views/LoginPage.vue"),
  },
  {
    path: "/register",
    component: () => import("@/views/RegisterPage.vue"),
  },
]

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes
})

export default router
