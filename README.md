# 🏓 Pong Game - Retro Gaming en C

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![SDL2](https://img.shields.io/badge/SDL2-Graphics-blue?style=for-the-badge)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

> 🎮 Un jeu Pong classique développé en C utilisant la puissante bibliothèque SDL2

## ✨ Aperçu

Revivez l'expérience du célèbre jeu Pong ! Ce projet implémente le jeu d'arcade classique avec des graphiques simples et une physique de base utilisant SDL2.

## 🛠️ Prérequis

| Composant | Version | Statut |
|-----------|---------|--------|
| ![GCC](https://img.shields.io/badge/GCC-Compiler-red) | MinGW | ✅ Requis |
| ![SDL2](https://img.shields.io/badge/SDL2-Graphics-blue) | 2.0+ | ✅ Requis |

## 📦 Installation de SDL2

### 🪟 Windows (MinGW)

1. **Téléchargement** 📥
   ```
   🌐 Visitez : https://www.libsdl.org/
   📂 Téléchargez la version MinGW
   ```

2. **Installation** 🔧
   ```
   📁 Extraire dans votre répertoire de projet
   ✅ Vérifier la présence des dossiers include/ et lib/
   ```

## 🚀 Compilation & Exécution

### 🔨 Compiler le projet
```bash
gcc main.c -I include -L lib -lmingw32 -lSDL2main -lSDL2 -o main.exe
```

### ▶️ Lancer le jeu
```bash
./main.exe
```

## 🎯 Fonctionnalités actuelles

- ✅ Fenêtre de jeu 640x480
- ✅ Affichage d'un rectangle blanc
- ✅ Délai d'affichage de 10 secondes
- 🚧 **En développement** : Contrôles joueur, balle, collisions

## 👨‍💻 Auteur

**MEHDI NAOUI** - *Développeur* 👑
- 📅 Année : 2025
- 🎯 Objectif : Apprendre la programmation de jeux en C

## 📚 Ressources & Remerciements

🙏 **Inspiré par** : Tutoriel YouTube de **Daniel HIRSCH**  
📖 **Documentation** : [SDL2 Official Docs](https://www.libsdl.org/)

---

<div align="center">

### 🌟 N'hésitez pas à laisser une ⭐ si ce projet vous plaît !

*Fait avec ❤️ et beaucoup de ☕*

</div>