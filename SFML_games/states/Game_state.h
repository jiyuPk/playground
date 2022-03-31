#pragma once
#include <memory>
#include <SFML/Graphics.hpp>


class Game_state {
public:
	Game_state(std::shared_ptr<sf::RenderWindow>);

	virtual void init() = 0;
	virtual void update(sf::Event) = 0;
	virtual void render() = 0;

	void finish();

protected:
	// variables

	// resources
	std::shared_ptr<sf::RenderWindow> render_window;
};	