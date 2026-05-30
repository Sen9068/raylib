#ifndef GAME_H
#define GAME_H

#include <raylib.h>

class Game {
    private:
    // Game Dimensions
        const int screen_width = 800;
        const int screen_height = 800;
        const int death = 0;

    // Ball
        int ballX = 400;
        int ballY = 400;
        float ballRadius = 20;
        Vector2 ballpos;
        int speed = 5;
        bool collision = false;

    //paddle var
        Rectangle paddle = { 300.0f, 600.0f, 200.0f, 20.0f };
    
    // assets
        Font customFont;
        Texture2D bgTexture;
        Rectangle grassSource = { 0.0f, 0.0f, 64.0f, 64.0f };
        Rectangle wallSource = { 64.0f, 0.0f, 64.0f, 64.0f };

    // Map grid
        static const int MAP_WIDTH = 13;
        static const int MAP_HEIGHT = 13;
        const int TILE_SIZE = 64;
        int worldMap[13][13];

        public:
            Game();
            ~Game();

            void Run();
            void Update();
            void Draw();

};

#endif
