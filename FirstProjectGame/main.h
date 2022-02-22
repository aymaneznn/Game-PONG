#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.h"

using namespace std;
using namespace sf;

// const taille de la fenêtre
const int WIN_WHITH = 1300;
const int WIN_HEIGH = 920;

int speed = 30;
int speedBot = 30;

// player
float raquettePosX = 50;
float raquettePosY = 50;

// balle
float ballePosX = WIN_WHITH / 2;
float ballePosY = WIN_HEIGH / 2;

// BOT
float botPosX = WIN_WHITH - 80;
float botPosY = 0;

Vector2f ballDir = Vector2f(1.5f, 2);

int score1_ = 0;
int score2_ = 0;

bool repaireBot = true;

// chargement de la police d'ecriture
void loadFont();

// parametrer un texte
void setText(Text& txt, string texte, int taille, float x, float y);

void updateBalle();