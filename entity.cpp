#include "entity.hpp"

const sf::Vector2f Entity::getPosition() { return _position;}

void Entity::setPosition(const sf::Vector2f &pos) { 
  _position = pos;
  _shape->setPosition(sf::Vector2f(_position));
}

void Entity::move(const sf::Vector2f &pos) { _position += pos;}

void Entity::Update(const double dt) {}

Entity::Entity(std::unique_ptr<sf::Shape> s) : _shape(std::move(s)) {}