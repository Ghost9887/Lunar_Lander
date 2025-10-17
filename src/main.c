#include "common.h"
#include "spaceship.h"

int main(){
  
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lunar Lander");
  SetTargetFPS(FPS);

  //create the space ship
  SpaceShip spaceShip = createSpaceShip();

  while(!WindowShouldClose()){
    
    BeginDrawing();
      
      ClearBackground(BLACK);

      updateSpaceShip(&spaceShip);

    EndDrawing();

  }

  //unload the sprites
  UnloadTexture(spaceShip.sprite1);
  UnloadTexture(spaceShip.sprite2);

  CloseWindow();

  return 0;
}
