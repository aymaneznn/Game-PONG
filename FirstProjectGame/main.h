#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.h"

using namespace std;
using namespace sf;

// const taille de la fenêtre
const int WIN_WHITH = 1300;
const int WIN_HEIGH = 920;

// chargement de la police d'ecriture
void loadFont();

// parametrer un texte
void setText(Text& txt, string texte, int taille, float x, float y);