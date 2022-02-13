#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Input
{

	struct Button{bool left, right, up, down, attack, escape;};

private:
	Button button;

public:
	Input();
	~Input();
	void InputHandler(Event event, RenderWindow& window);
	Button GetButton(void)const;
};

