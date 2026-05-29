#include <raylib.h>
#include <iostream>
#include <string>

int main() {

    int screen_width = 800;
    int screen_height = 800;

    int death = 0;



    Color firstcolor = {253, 253, 253, 255};
    Color secondcolor = {42, 246, 255, 255};
    Color green = {20, 160, 133, 255};


    
    int ballX = 400;
    int ballY = 400;
    float ballRadius = 20;

    Vector2 ballpos = { (float)ballX, (float)ballY };

    Rectangle paddle = { 300.0f, 600.0f, 200.0f, 20.0f }; 



    int colliderY = 200;
    int colliderX = 200;

    int speed = 5;

    

    InitWindow(screen_width, screen_height, "Window");
    Font customFont = LoadFontEx("resources/font/Minecraft.ttf", 32, NULL, 0);

    Image bgImage = LoadImage("resources/assets/world_tileset.png");


    Texture2D bgTexture = LoadTextureFromImage(bgImage);



    SetTargetFPS(60);
    // Game loop
    while(WindowShouldClose() == false) {
        
        // Event handling
        
        // Updating positions
        std::cout << "Test" << std::endl;
        std::cout << ballY << " " << ballX << std::endl;


        if(IsKeyDown(KEY_A))
        {
            std::cout << "Pressed A" << std::endl;
            ballX -= speed;

        }
        if(IsKeyDown(KEY_W))
        {
            std::cout << "Pressed W" << std::endl;
            ballY -= speed;
        }
        if(IsKeyDown(KEY_D))
        {
            std::cout << "Pressed D" << std::endl;
            ballX += speed;
        }
        if(IsKeyDown(KEY_S))
        {
            std::cout << "Pressed S" << std::endl;
            ballY += speed;
        }

        
        if(IsKeyDown(KEY_W) && IsKeyDown(KEY_LEFT_SHIFT))
        {
            ballY -= speed +5;
        }


        if(ballX <= death){
            ballX = screen_width;
        }

        else if(ballX >= screen_width){
            ballX = death;
        }

        else if(ballY <= death){
            ballY = screen_height;
        }

        else if(ballY >= screen_height){
            ballY = death;
        }

        ballpos = { (float)ballX, (float)ballY };

        ClearBackground(RAYWHITE);
        DrawRectangleRec(paddle, BLACK);
        

        if (CheckCollisionCircleRec(ballpos, ballRadius, paddle)) {
            std::cout << "Prostim fungjsddjsndsd" << std::endl;
            DrawText("Collision", 400, 400, 20, RED);
        }
    

        // Drawing
        BeginDrawing();

        DrawTexture(bgTexture, 10, 50, WHITE);

        DrawCircleV(ballpos, ballRadius, RED);
        
        DrawTextEx(customFont, TextFormat("X: %d Y: %d", ballY, ballX), Vector2{10, 7}, 32, 2, RED);

        EndDrawing();
    }

    UnloadFont(customFont);
    UnloadTexture(bgTexture);
    CloseWindow();
    return 0;
}