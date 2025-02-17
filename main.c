#include "raylib.h"

#define win_width 500
#define win_height 500

const char *win_title = "gpt-loading...";

float loader_radius = 30.0f;
float max_loader_radius = 60.0f;
float loader_growth_rate = 3.5f;

bool max_radius = 0;

typedef struct Loader
{
    float x;
    float y;
    float radius;
    Color color;
} Loader;

int main () 
{
    InitWindow(win_width, win_height, win_title);
    
    Loader loader;
    loader.x = win_width / 2.0;
    loader.y = win_height / 2.0;
    loader.radius = loader_radius;
    loader.color = WHITE;

    while (!WindowShouldClose())
    {
        float frame_time = GetFrameTime() * 10;
        float total_growth_rate = loader_growth_rate * frame_time;
        
        if (loader.radius >= max_loader_radius) 
        {
            loader.radius = loader_radius;
        }
        
        loader.radius += total_growth_rate;

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawText(win_title, 0.3*win_width, 10, 30, WHITE);
        DrawCircle(loader.x, loader.y, loader.radius, loader.color);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
