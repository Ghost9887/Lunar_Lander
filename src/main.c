#include "common.h"
#include "spaceship.h"
#include "landingspot.h"

int main(){
  
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lunar Lander");
  SetTargetFPS(FPS);

  //create the space ship
  SpaceShip spaceShip = createSpaceShip();

  //spawn landing spots
  LandingSpot landingArr[MAX_LANDING_SPOTS];
  initLandingSpots(landingArr);

  while(!WindowShouldClose()){
    
    BeginDrawing();
      
      ClearBackground(BLACK);

      updateSpaceShip(&spaceShip);

      updateLandingSpots(landingArr, &spaceShip);

    EndDrawing();

  }

  //unload the sprites
  UnloadTexture(spaceShip.sprite1);
  UnloadTexture(spaceShip.sprite2);

  CloseWindow();

  return 0;
}
