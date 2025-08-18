#include <iostream>
#include "game_system.hpp"
#include "game_parameters.hpp"
#include "level_system.hpp"

using ls = LevelSystem;

std::unique_ptr<Player> GameSystem::player;
sf::Text GameSystem::win_text;
sf::Font GameSystem::font;

void GameSystem::Load() {

  player = std::make_unique<Player>();

  ls::loadLevelFile("resources/levels/maze.txt");

  int tile_size_x = game_width/ls::getWidth();
  int tile_size_y = game_height/ls::getHeight();

  for (size_t y = 0; y < ls::getHeight(); ++y) {
    for (size_t x = 0; x < ls::getWidth(); ++x) {
      std::cout << ls::getTile({x, y});
      if(ls::getTile({x,y}) == ls::START)
        player->setPosition({x*tile_size_x,y*tile_size_y});
    }
    std::cout << std::endl;
  }

  win_text.setString("Well Done !!!");
  font.loadFromFile("resources/fonts/RobotoMono-Regular.ttf");
  win_text.setFont(font);
  win_text.setPosition(-100,-100);
  win_text.setCharacterSize(60);
  win_text.setColor(sf::Color(0,255,0));
}

void GameSystem::Clean(){
  player.reset();
}

void GameSystem::Update(sf::RenderWindow &window){
  static sf::Clock clock;
  float dt = clock.restart().asSeconds();
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
        window.close();
        return;
    }
  }
  if(ls::getTileAt(player->getPosition()) == ls::END){
    win_text.setPosition(game_width/2.f-100,game_height/2.f);
    return;
  }
    

  player->Update(dt);


}

void GameSystem::Render(sf::RenderWindow &window){
  ls::Render(window);
  player->Render(window);
  window.draw(win_text);
}
