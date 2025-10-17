#include "landingspot.h"

int getMultiplier(float length){
  if(length < 15.0f){
    return 4;
  }
  if(length < 30.0f && length > 15.1f){
    return 3;
  }
  if(length < 40.0f && length > 30.1f){
    return 2;
  }
  return 1;
}

LandingSpot createLandingSpot(int index){
  LandingSpot spot;
  spot.pos = (Vector2){ 
      // X
    (float)(GetRandomValue(index * 
    (SCREEN_WIDTH / MAX_LANDING_SPOTS),  
    (index + 1) * 
    (SCREEN_WIDTH / MAX_LANDING_SPOTS))), 
      // Y
    (float)(GetRandomValue(600, SCREEN_HEIGHT - 100)) 

  };
  spot.length = (float)(GetRandomValue(10, 50));
  spot.scoreMultiplier = getMultiplier(spot.length);
  spot.active = true;
  return spot;
}

void initLandingSpots(LandingSpot *landingArr){
  for(int i = 0; i < MAX_LANDING_SPOTS; i++){
    landingArr[i] = createLandingSpot(i);
  }
}

void moveTerrain(LandingSpot *landingArr, SpaceShip *ship){
  float deltaTime = GetFrameTime();
  landingArr->pos.x -= ship->velocity.x * deltaTime;
}

void drawLandingSpots(LandingSpot *landingSpot){
  DrawLine(landingSpot->pos.x, landingSpot->pos.y, landingSpot->pos.x + landingSpot->length, landingSpot->pos.y, WHITE);
  DrawText(TextFormat("%dX", landingSpot->scoreMultiplier), landingSpot->pos.x, landingSpot->pos.y + 10, 20, WHITE);
}

void generateNewSpots(LandingSpot *landingSpot, LandingSpot *landingArr, int index){
  if(landingSpot->pos.x <= -(SCREEN_WIDTH / MAX_LANDING_SPOTS)){
    //create another one at the end
    landingArr[index] = createLandingSpot(MAX_LANDING_SPOTS);
  }
  else if(landingSpot->pos.x >= SCREEN_WIDTH + (SCREEN_WIDTH / MAX_LANDING_SPOTS)){
    landingArr[index] = createLandingSpot(-1);
  }
}

void updateLandingSpots(LandingSpot *landingArr, SpaceShip *ship){
  for(int i = 0; i < MAX_LANDING_SPOTS; i++){
    if(landingArr[i].active){
      drawLandingSpots(&landingArr[i]);
      moveTerrain(&landingArr[i], ship);
      generateNewSpots(&landingArr[i], landingArr, i);
    }
  }
}
