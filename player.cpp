#include "player.hpp"
#include "game_parameters.hpp"
#include "level_system.hpp"

using ls = LevelSystem;

void Player::Update(double dt) {
  //Move in four directions based on keys
  sf::Vector2f new_pos(getPosition().x,getPosition().y);
  //Move up
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
      getPosition().y > _radius) {
      new_pos.y -= _speed*dt;
  }
  //Move down
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
      getPosition().y < game_height-_radius) {
      new_pos.y += _speed*dt;
  }
  //Move left
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 
      getPosition().x > _radius) {
      new_pos.x -= _speed*dt;
  }
  //Move Right
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
      getPosition().x < game_width - _radius) {
      new_pos.x += _speed*dt;
  }

  if(ls::getTileAt(new_pos) != ls::WALL){
    setPosition(new_pos);
  }

  Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(std::make_unique<sf::CircleShape>(25.f)) {   
  _shape->setFillColor(sf::Color::Magenta);
  _shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::Render(sf::RenderWindow &window) const {
  window.draw(*_shape);
}