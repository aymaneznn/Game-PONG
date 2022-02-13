#include "main.h"


// variables global
RenderWindow window;
Font font;
Input input;
float posx = 0;
float posy = 800;
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
	Texture texture;
	int size = 25;
	

	// cretaion d'un cercle
	CircleShape circle(size);
	circle.setFillColor(Color::White);
	circle.setOutlineColor(Color::Yellow);
	circle.setOutlineThickness(5);
	circle.setPosition(posx, posy);

	CircleShape triangle(80.f,8);
	triangle.setFillColor(Color::Red);
	triangle.setOutlineColor(Color::Yellow);
	triangle.setOutlineThickness(5);
	triangle.setPosition(50, 50);

	// creation d'un rectangle

	RectangleShape rectangle(Vector2f(120.f,50.f));
	rectangle.setFillColor(Color::Blue);
	rectangle.setPosition(0, 0);
	
	
	while (window.isOpen()){
		Event event;
		while (window.pollEvent(event))
		{
			
			input.InputHandler(event, window);

			if(input.GetButton().right == true) {
				sprintf_s(tempx, "%f", posx);
				sprintf_s(tempy, "%f", posy);
				
				if (posx > WIN_WHITH)
					posx = WIN_WHITH;
				posx += 10;
				setText(txt, tempx, 10, posx+70, posy);
				setText(txt2, tempy, 10, posx+70, posy+30);
				circle.setPosition(posx, posy);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(circle);
			}
			if (input.GetButton().left == true) {
				sprintf_s(tempx, "%f", posx);
				sprintf_s(tempy, "%f", posy);

				if (posx < 0)
					posx = 0;
				posx -= 10;
				setText(txt, tempx, 10, posx+70, posy);
				setText(txt2, tempy, 10, posx + 70, posy + 30);
				circle.setPosition(posx, posy);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(circle);
			}

			if (input.GetButton().up == true) {
				sprintf_s(tempx, "%f", posx);
				sprintf_s(tempy, "%f", posy);

				if (posy < 0)
					posy = 0;
				posy -= 10;
				setText(txt, tempx, 10, posx+70, posy);
				setText(txt2, tempy, 10, posx + 70, posy + 30);
				circle.setPosition(posx, posy);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(circle);
			}
			if (input.GetButton().down == true) {
				sprintf_s(tempx, "%f", posx);
				sprintf_s(tempy, "%f", posy);

				if (posy > WIN_HEIGH)
					posy = WIN_HEIGH;
				posy += 10;
				setText(txt, tempx, 10, posx + 70, posy);
				setText(txt2, tempy, 10, posx + 70, posy + 30);
				circle.setPosition(posx, posy);
				window.clear(Color::Black);
				window.draw(txt);
				window.draw(circle);
			}

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Add)
					size += 2;
					circle.setRadius(size);
					circle.setPosition(posx, posy);
					window.draw(circle);
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::M)
					size -= 2;
				circle.setRadius(size);
				circle.setPosition(posx, posy);
				window.draw(circle);
			}
			
		}
		window.clear(Color::Black);
		window.draw(circle);
		window.draw(rectangle);
		window.draw(triangle);
		window.draw(txt);
		window.draw(txt2);
		window.display();
	}
   
    return 0;
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