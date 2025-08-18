#pragma once
#include "entity.hpp"

class Player : public Entity {
 private:
  constexpr static float _radius = 25.f;
  float _speed;

 public:
  void Update(double dt) override;
  Player();
  void Render(sf::RenderWindow &window) const override;
};