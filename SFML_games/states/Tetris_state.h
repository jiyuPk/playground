#pragma once
#include "Game_state.h"

class tetris_state : public Game_state {
public:
	tetris_state(std::shared_ptr<sf::RenderWindow>);
	void init();
	void update(sf::Event);
	void render();
	~tetris_state();

private:
	sf::Sprite* block;
};
