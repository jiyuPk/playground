#include "Game_state.h"

Game_state::Game_state(std::shared_ptr<sf::RenderWindow> window) :
	render_window(window)
{
}

void Game_state::finish()
{
	render_window->close();
}
