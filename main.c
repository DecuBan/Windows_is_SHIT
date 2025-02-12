#include <raylib.h>

#include "res/eat_up.png.h"
#include "res/oleg.ogg.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "WinShit 💩💩💩"

int main(void)
{
#if defined(RELEASE)
    SetTraceLog(LOG_FATAL);
#endif

    /**
     *  Init
     */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    if (!IsWindowReady())
        TraceLog(LOG_FATAL, "Window cannot be initialized");

    InitAudioDevice();

    /**
     *  Settings
     */
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowState(FLAG_WINDOW_UNFOCUSED);

    SetTargetFPS(30);

    /**
     *  Image resource
     */
    Image image =
        LoadImageFromMemory(".png", EAT_UP_PNG_DATA, EAT_UP_PNG_DATA_SIZE);

    ImageResize(&image, GetRenderWidth(), GetRenderHeight());

    Texture2D textureFromImage = LoadTextureFromImage(image);

    /**
     *  Music resource
     */
    Music music =
        LoadMusicStreamFromMemory(".ogg", OLEG_OGG_DATA, OLEG_OGG_DATA_SIZE);

    SetMusicVolume(music, 0.17f);

    PlayMusicStream(music);

    float timePlayed = 0.0f;
    bool isPaused = false;

    /**
     *  Update
     */
    while (!WindowShouldClose())
    {
        /**
         *  Update music stream buffer
         */
        UpdateMusicStream(music);

        timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

        if (timePlayed > 1.0f)
            timePlayed = 1.0f;

        /**
         *  Drawing
         */
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(textureFromImage, 0, 0, WHITE);

        EndDrawing();
    }

    /**
     *  Unload resources
     */
    UnloadImage(image);
    UnloadTexture(textureFromImage);

    UnloadMusicStream(music);

    /**
     *  Close devices
     */
    CloseAudioDevice();

    CloseWindow();

    return 0;
}
