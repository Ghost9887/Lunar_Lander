#ifndef LANDINGSPOT_H
#define LANDINGSPOT_H

#include "common.h"
#include "spaceship.h"

typedef struct{
  Vector2 pos;
  float length;
  int scoreMultiplier;
  bool active;
}LandingSpot;

LandingSpot createLandingSpot(int index);
void initLandingSpots(LandingSpot *landingSpot);
void updateLandingSpots(LandingSpot *landingArr, SpaceShip *ship);

#endif
