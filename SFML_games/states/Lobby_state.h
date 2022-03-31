#pragma once
#include "Game_state.h"
class Lobby_state : public Game_state {
public:
	Lobby_state(std::shared_ptr<sf::RenderWindow>);
	void init();
	void update(sf::Event);
	void render();

private:
};

