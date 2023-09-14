# Belib' Graph

## Introduction
La mobilité citoyenne dans les grandes villes est une question récurrente.  
Début septembre 2023, Marseille retirait 1500 trottinettes sur les 4000. 
La ville de Paris via sa plateforme Paris Data permet d’avoir accès à de nombreuses informations de son réseau de mobilité. 
Pour ce projet, je me suis particulièrement intéressé à l’API, « Belib' - Points de recharge pour véhicules électriques - Disponibilité temps réel ». 
Celle-ci permet de suivre en temps réel, les états des bornes de véhicules électriques.


## Les fonctionnalités
L’un des enjeux sera de représenter graphiquement l’évolution de l’utilisation de borne de véhicules électriques à Paris et de voir comment donner du sens aux diverses données recueillies. 
Concernant la structure du projet, il est composé d’un fichier JSON regroupant les diverses données de l’API et d’une librairie graphique pour la génération de diagramme. 
Il pourra être intéressant de filtrer la multitude de données par arrondissements. 
De plus, on pourra voir à quel moment de la journée la location est la plus importante et à quel emplacement.