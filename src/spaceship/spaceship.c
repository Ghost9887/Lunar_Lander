#include "spaceship.h"

SpaceShip createSpaceShip(){
  SpaceShip ship;
  ship.pos = (Vector2){ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 };
  ship.size = (Vector2){ 32, 32 };
  ship.velocity = (Vector2){ 100.0f, 0 };
  ship.terminalVelocity = 200.0f;
  ship.thrustPower = 100.0f;
  ship.rotation = 0.0f;
  ship.sprite1 = LoadTexture("assets/ship1.png");
  ship.sprite2 = LoadTexture("assets/ship2.png");
  return ship;
}

void drawSpaceShip(SpaceShip *spaceShip){
  if(IsKeyDown(KEY_SPACE)){
    DrawTexturePro(spaceShip->sprite2, (Rectangle){ 0, 0, 32, 32 }, (Rectangle){ spaceShip->pos.x, spaceShip->pos.y, 32, 32 }, (Vector2){ spaceShip->size.x / 2, spaceShip->size.y / 2 },
        spaceShip->rotation, WHITE);
  }else{
    DrawTexturePro(spaceShip->sprite1, (Rectangle){ 0, 0, 32, 32 }, (Rectangle){ spaceShip->pos.x, spaceShip->pos.y, 32, 32 }, (Vector2){ spaceShip->size.x / 2, spaceShip->size.y / 2 },
        spaceShip->rotation, WHITE);
  }
}

void moveSpaceShip(SpaceShip *spaceShip){
  float deltaTime = GetFrameTime();
  //apply gravity
  if(spaceShip->velocity.y <= spaceShip->terminalVelocity) spaceShip->velocity.y += GRAVITY * deltaTime * 20; //make it faster
  //apply drag
  if(spaceShip->velocity.x > 0.0f) spaceShip->velocity.x -= DRAG * deltaTime;
  else if(spaceShip->velocity.x < 0.0f) spaceShip->velocity.x += DRAG * deltaTime;

  //apply thrust
  if(IsKeyDown(KEY_SPACE)){
    float radians = (spaceShip->rotation - 90.0f) * DEG2RAD;
    Vector2 thrustDirection = { cosf(radians), sinf(radians) };
    spaceShip->velocity.x += thrustDirection.x * spaceShip->thrustPower * deltaTime;
    spaceShip->velocity.y += thrustDirection.y * spaceShip->thrustPower * deltaTime;
  }

  //apply angle
  spaceShip->rotation = fmod(spaceShip->rotation, 360);
  if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
    spaceShip->rotation += 100.0f * deltaTime;
  }
  if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
    spaceShip->rotation -= 100.0f * deltaTime;
  }

  //move the spaceship
  //spaceShip->pos.x += spaceShip->velocity.x * deltaTime;
  spaceShip->pos.y += spaceShip->velocity.y * deltaTime;
}

void updateSpaceShip(SpaceShip *spaceShip){
  drawSpaceShip(spaceShip);
  moveSpaceShip(spaceShip);
}
