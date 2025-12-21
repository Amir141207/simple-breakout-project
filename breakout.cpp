#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"

#include "raylib.h"

void update()
{
    switch(game_state) {
        case menu_state:
            if (IsKeyPressed(KEY_ENTER)) {
                current_level_index = 0;
                SetExitKey(0);
                game_state = in_game_state;
                load_level(0);
                PlaySound(game_sound);


            }
            break;
        case in_game_state:
            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
                move_paddle2(-paddle_speed);
            }
            if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
                move_paddle2(paddle_speed);
            }
            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
                move_paddle(-paddle_speed);
            }
            if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
                move_paddle(paddle_speed);
            }
            move_ball();
            if (!is_ball_inside_level()) {
                live--;
                load_level();
                if (live == 0){
                    load_level();
                    PlaySound(lose_sound);
                    game_state = end_state;
                }
            } else if (current_level_blocks == 0) {
                load_level(1);
                PlaySound(win_sound);
            }
            if (IsKeyDown(KEY_ESCAPE)) {
                game_state = paused_state;

            }
            break;
        case paused_state:
            if (IsKeyPressed(KEY_ENTER)){
                game_state = in_game_state;
            }
            break;
        case end_state:
            if (IsKeyPressed(KEY_ENTER)){
                live = 3;
                game_state = menu_state;

            }


    }
}


void draw()
{
     if (game_state == menu_state){
        draw_menu();

    } else if (game_state == in_game_state)
    {
        draw_level();
        draw_paddle();
        draw_ball();
        draw_ui();
    } else if(game_state == victory_state){
        draw_victory_menu();
    }else if(game_state == paused_state) {
        draw_pause_menu();
    }else if(game_state = end_state){
       draw_end();
    }


}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "Breakout");
    SetTargetFPS(60);
    load_fonts();
    load_textures();
    load_level();
    load_sounds();

    while (!WindowShouldClose()) {
        BeginDrawing();
        update();

        draw();

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}
