#include "assets.h"

#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    back_texture = LoadTexture("data/images/back.png");
    imagine_texture = LoadTexture("data/images/8753.png");
    wall_texture = LoadTexture("data/images/wall.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/block1.png");
    paddle_texture = LoadTexture("data/images/paddle2.png");
    ball_sprite = load_sprite("data/images/fire/fire", ".png", 8, true, 10);
}

void unload_textures()
{
    UnloadTexture(wall_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(paddle_texture);
    unload_sprite(ball_sprite);
    UnloadTexture(imagine_texture);
    UnloadTexture(back_texture);



}

void load_sounds()
{
    InitAudioDevice();
    win_sound = LoadSound("data/sounds/win.wav");
    lose_sound = LoadSound("data/sounds/lose.wav");
    game_sound = LoadSound("data/sounds/GameSound.mp3");

}

void unload_sounds()
{
    UnloadSound(win_sound);
    UnloadSound(lose_sound);
    UnloadSound(game_sound);

    CloseAudioDevice();
}
