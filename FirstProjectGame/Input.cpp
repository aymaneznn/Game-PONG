#include "Input.h"


Input::Input()
{
	button.left = button.right = button.down = button.attack = button.escape = false;
}

Input::~Input()
{
	
}

Input::Button Input::GetButton(void) const {
	return button;
}

// fonction qui quitte la fenêtre 
void Input::InputHandler(Event event, RenderWindow& window) {

	if (event.type == Event::Closed) {
		window.close();
	}
	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Escape)
			window.close();
	}

	if (event.type == Event::KeyPressed) {
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			cout << " escape " << endl;
			break;
		case Keyboard::Left:
			button.left = true;
			cout << " Left " << endl;
			break;
		case Keyboard::Right:
			button.right = true;
			cout << " Right " << endl;
			break;
		case Keyboard::Down:
			button.down = true;
			cout << " Down " << endl;
			break;
		case Keyboard::Up:
			button.up = true;
			cout << " Up " << endl;
			break;
		}
	}

	if (event.type == Event::KeyReleased) {
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Down:
			button.down = false;
			break;
		case Keyboard::Up:
			button.up = false;
			break;
		}
	}

	if (event.type == Event::MouseButtonPressed) {
		if (event.mouseButton.button == Mouse::Left) {
			button.attack = true;
		}

	}

	if (event.type == Event::MouseButtonReleased) {
		if (event.mouseButton.button == Mouse::Left) {
			button.attack = false;
		}

	}

}