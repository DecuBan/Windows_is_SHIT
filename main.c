#include <raylib.h>

#include "res/eat_up.png.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "WinShit 💩💩💩"

int main(void)
{
#if defined(RELEASE)
    SetTraceLog(LOG_FATAL);
#endif

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowState(FLAG_WINDOW_UNFOCUSED);

    SetTargetFPS(30);

    Image image =
        LoadImageFromMemory(".png", EAT_UP_PNG_DATA, EAT_UP_PNG_DATA_SIZE);
    ImageResize(&image, GetRenderWidth(), GetRenderHeight());
    //
    Texture2D textureFromImage = LoadTextureFromImage(image);

    if (IsWindowReady())
        while (!WindowShouldClose())
        {
            BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(textureFromImage, 0, 0, WHITE);

            EndDrawing();
        }
    else
        TraceLog(LOG_FATAL, "Window cannot be initialized");

    UnloadImage(image);
    UnloadTexture(textureFromImage);

    CloseWindow();

    return 0;
}
