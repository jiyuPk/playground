#include "Tetris_state.h"

tetris_state::tetris_state(std::shared_ptr<sf::RenderWindow> window) :
	Game_state(window)
{
}

void tetris_state::init()
{
	sf::Texture t;
	if (!t.loadFromFile("images/tiles.png"))
		throw;

	block = new sf::Sprite(t);
}

void tetris_state::update(sf::Event e)
{

}

void tetris_state::render()
{
}

tetris_state::~tetris_state() {
	delete block;
}

