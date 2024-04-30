#ifndef ANIM_H
#define ANIM_H

#include "raylib.h"

typedef struct {
    int frame_idx;
    int num_frames;
    int frame_duration;
    Texture2D tex;
} Anim;

void anim_init(Anim *anim, int num_frames, int frame_duration, const char *spritesheet_filename);
void anim_destroy(Anim *anim);
void anim_load_texture(Anim *anim, const char *spritesheet_filename);
void anim_update(Anim *anim, long long t);
void anim_draw(Anim *anim, Vector2 pos);

#endif
