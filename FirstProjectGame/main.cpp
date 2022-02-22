#include "main.h"


// variables global
RenderWindow window;
Font font;
Input input;

char cscore1[256];
char cscore2[256];


char tempx[256];
char tempy[256];

int main(){

	ContextSettings options;
	options.antialiasingLevel = 8;

    window.create(VideoMode(WIN_WHITH, WIN_HEIGH, 32), "2D Game", Style::Default, options);
	window.setVerticalSyncEnabled(true);
	
	// chargement de la police d'ecriture 
	loadFont();

	// creation d'un texte
	Text txt;
	Text txt2;
	Text score1;
	Text score2;
	

	Texture texture;
	int size = 15;
	

	// cretaion d'un cercle
	CircleShape circle((float)size);
	circle.setFillColor(Color::White);
	circle.setOutlineColor(Color::White);
	circle.setOutlineThickness(5);
	circle.setPosition(ballePosX, ballePosY);

	// creation d'un rectangle

	RectangleShape rectangle(Vector2f(40.f,150.f));
	rectangle.setFillColor(Color::Red);
	rectangle.setOutlineColor(Color::White);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(raquettePosX, raquettePosY);

	RectangleShape rectangleBot(Vector2f(40.f, 150.f));
	rectangleBot.setFillColor(Color::Blue);
	rectangleBot.setOutlineColor(Color::White);
	rectangleBot.setOutlineThickness(5);
	rectangleBot.setPosition(botPosX, botPosY);
	

	while (window.isOpen()){
		Event event;
		updateBalle();
		sprintf_s(cscore1, "%d", score1_);
		sprintf_s(cscore2, "%d", score2_);
		setText(score1, cscore1, 50, WIN_WHITH / 2 - 50, 10);

		setText(score2, cscore2, 50, WIN_WHITH / 2 + 60, 10);
		circle.setPosition(ballePosX, ballePosY);
		window.clear(Color::Black);
		window.draw(circle);
		// BOT
		/*if (repaireBot) {

			if (botPosY < 50)
				repaireBot = false;
			botPosY -= speedBot;
			rectangleBot.setPosition(botPosX, botPosY);
			window.clear(Color::Black);
			window.draw(rectangleBot);
		}
		else {

			if (botPosY > WIN_HEIGH -180)
				repaireBot = true;
			botPosY += speedBot;

			rectangleBot.setPosition(botPosX, botPosY);
			window.clear(Color::Black);
			window.draw(rectangleBot);
		}*/

		rectangleBot.setPosition(botPosX, botPosY);
		window.clear(Color::Black);
		window.draw(rectangleBot);

		
		while (window.pollEvent(event))
		{
			
			input.InputHandler(event, window);


			
			// palayer 
			if (input.GetButton().up == true) {
				sprintf_s(tempx, "%f", raquettePosX);
				sprintf_s(tempy, "%f", raquettePosY);

				if (raquettePosY < 50)
					raquettePosY = 50;
				raquettePosY -= speed;
				//posYbot -= speed;
				setText(txt, tempx, 20, raquettePosX+70, raquettePosY);
				setText(txt2, tempy, 20, raquettePosX + 70, raquettePosY + 30); 
				rectangle.setPosition(raquettePosX, raquettePosY);
				//rectangleBot.setPosition(posXbot, posYbot);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(rectangle);
				//window.draw(rectangleBot);
			}
			if (input.GetButton().down == true) {
				sprintf_s(tempx, "%f", raquettePosX);
				sprintf_s(tempy, "%f", raquettePosY);

				if (raquettePosY > WIN_HEIGH - 200)
					raquettePosY = WIN_HEIGH - 200;
				raquettePosY += speed;
				//posYbot += speed;
				setText(txt, tempx, 20, raquettePosX + 70, raquettePosY);
				setText(txt2, tempy, 20, raquettePosX + 70, raquettePosY + 30);
				rectangle.setPosition(raquettePosX, raquettePosY);
				//rectangleBot.setPosition(posXbot, posYbot);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(rectangle);
				//window.draw(rectangleBot);
			}

			// palayer 2
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Z) {

					if (botPosY < 50)
						botPosY = 50;
					botPosY -= speedBot;
					rectangleBot.setPosition(botPosX, botPosY);
					window.clear(Color::Black);
					window.draw(rectangleBot);
				}
				if (event.key.code == Keyboard::S) {
					if (botPosY > WIN_HEIGH - 180)
						botPosY = WIN_HEIGH - 180;
					botPosY += speedBot;

					rectangleBot.setPosition(botPosX, botPosY);
					window.clear(Color::Black);
					window.draw(rectangleBot);
				}
			}

		}
		window.clear(Color::Black);
		window.draw(circle);
		window.draw(rectangle);
		window.draw(rectangleBot);
		window.draw(txt);
		window.draw(txt2);
		window.draw(score1);
		window.draw(score2);
		window.display();
	}
   
    return 0;
}
void updateBalle() {
	ballePosX += ballDir.x * 3;
	ballePosY += ballDir.y * 3;

	if ((ballePosX < raquettePosX + 40 && ballePosX > raquettePosX
		&& ballePosY < raquettePosY + 150 && ballePosY > raquettePosY)
		||
		(ballePosX > botPosX - 40 && ballePosX < botPosX
			&& ballePosY < botPosY + 150 && ballePosY > botPosY)) {
		ballDir.x *= -1;
	}

	if (ballePosX < 0) {
		ballePosX = WIN_WHITH / 2;
		ballePosY = WIN_HEIGH / 2;
		ballDir.x = fabs(ballDir.x);
		ballDir.y *= -1;
		score2_ ++;
	}

	if (ballePosX > 1300) {
		ballePosX = WIN_WHITH / 2;
		ballePosY = WIN_HEIGH / 2;
		ballDir.x = -fabs(ballDir.x);
		ballDir.y *= 1;
		score1_++;
	}

	if (ballePosY > WIN_HEIGH || ballePosY < 0) {
		ballDir.y *= -1;
	}

	/*if (ballePosY > 920) {
		ballDir.x *= 1;
	}*/
	
}

// chargement de la police d'ecriture
void loadFont() {
	if (!font.loadFromFile("res/poppins.ttf")) {
		cout << "Erreur chargement de la font " << endl;
	}
}

void setText(Text& txt, string texte, int taille, float x, float y) {
	// on donne à notre texte une font 
	txt.setFont(font);
	// on indique la chaine de caractère à afficher
	txt.setString(texte);
	// on indique la taille du texte 
	txt.setCharacterSize(taille);
	// on donne la couleur
	txt.setFillColor(Color::Cyan);
	txt.setPosition(x,y);
	// modifier le style du texte 
	//txt.setStyle(Text::Bold | Text::Underlined);
}