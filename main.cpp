#include <raylib.h>
#include <iostream>
#include <string>


    const int MAP_WIDTH = 25;
    const int MAP_HEIGHT = 25;
    const int TILE_SIZE = 32;

    int worldMap[25][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int main() {

    int screen_width = 800;
    int screen_height = 800;

    int death = 0;

    Color firstcolor = {253, 253, 253, 255};
    Color secondcolor = {42, 246, 255, 255};
    Color green = {20, 160, 133, 255};

    bool collision = false;


    
    int ballX = 400;
    int ballY = 400;
    float ballRadius = 20;

    Vector2 ballpos = { (float)ballX, (float)ballY };

    Rectangle paddle = { 300.0f, 600.0f, 200.0f, 20.0f }; 



    int colliderY = 200;
    int colliderX = 200;


    const int speed = 5;

    

    InitWindow(screen_width, screen_height, "Window");
    Font customFont = LoadFontEx("resources/font/Minecraft.ttf", 32, NULL, 0);

    Image bgImage = LoadImage("resources/assets/world_tileset.png");

    ImageResize(&bgImage, 550, 550); 

    Rectangle grassSource = { 0.0f, 0.0f, 64.0f, 64.0f };
    Rectangle wallSource = { 64.0f, 0.0f, 64.0f, 64.0f };



    Texture2D bgTexture = LoadTextureFromImage(bgImage);



    SetTargetFPS(60);

    // Game loop
    while(WindowShouldClose() == false) {
        
        // Event handling
        
        // Updating positions
        std::cout << "Test" << std::endl;
        std::cout << ballY << " " << ballX << std::endl;

        // new movement - X axis
        if(IsKeyDown(KEY_A)) { ballX -= speed; }
        if(IsKeyDown(KEY_D)) { ballX += speed; }

        // new movement - Y axis
        if(IsKeyDown(KEY_W)) { ballY -= speed; }
        if(IsKeyDown(KEY_S)) { ballY += speed; }

        // new sprint method

        // border
        if(ballX <= death) { ballX = screen_width; }
        else if(ballX >= screen_width) { ballX = death; }
        else if(ballY <= death) { ballY = screen_height; }
        else if(ballY >= screen_height) { ballY = death; }

        ballpos = { (float)ballX, (float)ballY };



        ballpos = { float(ballX), float(ballY) };



        if (CheckCollisionCircleRec(ballpos, ballRadius, paddle)) {
            std::cout << "Collision" << std::endl;
            DrawText("Collision", 400, 400, 20, RED);
            
            if (collision == false) {
                std::cout << "True" << std::endl;
                collision = true;
            }

            if(IsKeyDown(KEY_S)) { 
                ballY = paddle.y - ballRadius; 
            }
    

            else if(IsKeyDown(KEY_W)) { 
                ballY = paddle.y + paddle.height + ballRadius; 
            }

            else if(IsKeyDown(KEY_A)) { 
                ballX = paddle.x + paddle.width + ballRadius; 
            }

            else if(IsKeyDown(KEY_D)) { 
                ballX = paddle.x - ballRadius; 


            }
        }

        ballpos = { float(ballX), float(ballY) };

        while (speed == 1){
            std::cout << "test";
        }

    

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                Vector2 screenPos = { (float)(x * TILE_SIZE), float(y * TILE_SIZE) };

                if (worldMap[y][x] == 1) {
                    DrawTextureRec(bgTexture, wallSource, screenPos, WHITE);
                }
                else if (worldMap[y][x] == 0) {
                    DrawTextureRec(bgTexture, grassSource, screenPos, WHITE);
                }
            }
        }

        EndTextureMode();
        DrawCircleV(ballpos, ballRadius, RED);
        DrawRectangleRec(paddle, BLACK);
        
        DrawTextEx(customFont, TextFormat("X: %d Y: %d", ballY, ballX), Vector2{10, 7}, 32, 2, RED);
        DrawText(TextFormat("%d", GetFPS(), "FPS"), 400, 300, 50, RED);

        EndDrawing();
    }

    UnloadFont(customFont);
    UnloadTexture(bgTexture);
    CloseWindow();
    return 0;
}