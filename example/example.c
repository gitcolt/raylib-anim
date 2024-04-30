#include "state.h"

#include "raylib.h"

#include <malloc.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

enum AnimId {
    ANIM_ID_WALK,
};

void init(State *state) {
    int num_frames = 6;
    int frame_duration = 5;
    const char *spritesheet_filename = "./scarfy.png";
    Anim *anim_a = malloc(sizeof(Anim));
    anim_init(anim_a, num_frames, frame_duration, spritesheet_filename);

    animator_init(&state->animator);
    animator_add_anim(&state->animator, anim_a, ANIM_ID_WALK);
    animator_set_anim(&state->animator, ANIM_ID_WALK);
}

void update(State *state) {
    animator_update(&state->animator, state->tick);
    ++state->tick;
}

void draw(State *state) {
    Vector2 pos = {100, 100};
    animator_draw(&state->animator, pos);
}

int main() {
    State state = {
        .tick = 0,
        .animator = {
        },
    };
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, ":)");
    init(&state);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        update(&state);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw(&state);
        EndDrawing();
    }

    animator_destroy(&state.animator);
    CloseWindow();
}
