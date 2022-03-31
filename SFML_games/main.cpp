#include "states/Lobby_state.h"

int main() {
	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(320, 480), "SFML GAMES");
	Game_state* state = new Lobby_state(window);
	state->init();

	while (window->isOpen()) {
		sf::Event e;

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				state->finish();
			state->update(e);
		}
		window->clear(sf::Color::White);
		state->render();
		window->display();
	}

	return 0;
}