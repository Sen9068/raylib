#include "game.h"
#include <raylib.h>
#include <iostream>
#include <string>

Game::Game() {
    InitWindow(screen_width, screen_height, "Window");
    SetTargetFPS(60);

    customFont = LoadFontEx("resources/font/Minecraft.ttf", 32, NULL, 0);
    Image bgImage = LoadImage("resources/assets/world_tileset.png");
    bgTexture = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage);

    ballpos = { (float)ballX, (float)ballY };

    int templateMap[13][13] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for(int y = 0; y < 13; y++) {
        for(int x = 0; x < 13; x++) {
            worldMap[y][x] = templateMap[y][x];
        }
    }
} 
Game::~Game() {
    UnloadFont(customFont);
    UnloadTexture(bgTexture);
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    int currentspeed = speed;
    if (IsKeyDown(KEY_LEFT_SHIFT)) { currentspeed = speed + 2; }

    if (IsKeyDown(KEY_A)) { ballX -= currentspeed; }
    if (IsKeyDown(KEY_D)) { ballX += currentspeed; }
    if (IsKeyDown(KEY_W)) { ballY -= currentspeed; }
    if (IsKeyDown(KEY_S)) { ballY += currentspeed; }

    if (ballX <= death) ballX = screen_width;
    else if (ballX >= screen_width) ballX = death;
    if (ballY <= death) ballY = screen_height;
    else if (ballY >= screen_height) ballY = death;

    ballpos = { (float)ballX, (float)ballY }; 

    if (CheckCollisionCircleRec(ballpos, ballRadius, paddle)) {
        if (collision == false) { collision = true; }

        if (IsKeyDown(KEY_S)) { ballY = paddle.y - ballRadius; }
        else if (IsKeyDown(KEY_W)) { ballY = paddle.y + paddle.height + ballRadius; }
        else if (IsKeyDown(KEY_A)) { ballX = paddle.x + paddle.width + ballRadius; }
        else if (IsKeyDown(KEY_D)) { ballX = paddle.x - ballRadius; }

        ballpos = { (float)ballX, (float)ballY };
    } else {
        collision = false;
    }
} 

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++) { 
            Vector2 screenPos = { (float)(x * TILE_SIZE), (float)(y * TILE_SIZE) };
            if (worldMap[y][x] == 1) {
                DrawTextureRec(bgTexture, wallSource, screenPos, WHITE);
            } else if (worldMap[y][x] == 0) {
                DrawTextureRec(bgTexture, grassSource, screenPos, WHITE);
            }
        }
    }

    DrawRectangleRec(paddle, BLACK);
    DrawCircleV(ballpos, ballRadius, RED);

    DrawText(TextFormat("%d FPS", GetFPS()), 400, 300, 50, RED);
    DrawTextEx(customFont, TextFormat("X: %d Y: %d", ballX, ballY), Vector2{10, 7}, 32, 2, RED);

    EndDrawing();
}