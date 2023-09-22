# Belib' Graph

![Capture d’écran du 2023-09-22 10-50-44](https://github.com/NathanBnvn/Belib_graph/assets/45998296/4efb1203-a95e-4101-9a16-84f29153a00c)
*credit to Precious Madubuike from Unsplash*

## Introduction
La mobilité citoyenne dans les grandes villes est une question récurrente.  
Début septembre 2023, Marseille retirait 1500 trottinettes sur les 4000. 
La ville de Paris via sa plateforme Paris Data permet d’avoir accès à de nombreuses informations de son réseau de mobilité. 
Pour ce projet, je me suis particulièrement intéressé à l’API, « Belib' - Points de recharge pour véhicules électriques - Disponibilité temps réel ». 
Celle-ci permet de suivre en temps réel, les états des bornes de véhicules électriques.

## Objectifs
Le programme développer en C++ fonctionne depuis un ordinateur mais également depus Buildroot. Il peut donc être utilisé dans un système embarqué.

## Les fonctionnalités
L’un des enjeux a été de représenter graphiquement l’évolution de l’utilisation de borne de véhicules électriques à Paris et de voir comment donner du sens aux diverses données recueillies. 
Concernant la structure du projet, il est composé d’un fichier JSON regroupant les diverses données de l’API et d’une librairie graphique pour la génération de diagramme. 
J'ai pensé qu'il pouvait être intéressant de filtrer la multitude de données par arrondissements afin de voir la répartition par arrondissement.
De plus, on pourra voir à quel moment de la journée la location est la plus importante.

## Utilisation
Pour télécharger le projet : 

```sh
  git clone https://github.com/NathanBnvn/Belib_graph.git
```

Etant un projet en c++, vous pourrez le compilé via g++.