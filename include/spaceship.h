#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "common.h"

typedef struct{
  Vector2 pos;
  Vector2 size;
  Vector2 velocity;
  float terminalVelocity;
  float thrustPower;
  float rotation;
  Texture2D sprite1;
  Texture2D sprite2;
}SpaceShip;

SpaceShip createSpaceShip();
void updateSpaceShip(SpaceShip *spaceShip);

#endif
