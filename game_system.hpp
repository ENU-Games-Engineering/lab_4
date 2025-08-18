#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "player.hpp"

struct GameSystem{
    static std::unique_ptr<Player> player;
    static sf::Text win_text;
    static sf::Font font;

    static void Load();
    static void Clean();
    static void Update(sf::RenderWindow &window);
    static void Render(sf::RenderWindow &window);
};