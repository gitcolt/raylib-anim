#include "anim.h"

#include <stdio.h>
#include <malloc.h>

void anim_load_texture(Anim *anim, const char *spritesheet_filename) {
    anim->tex = LoadTexture(spritesheet_filename);
}

void anim_init(Anim *anim,
               int num_frames,
               int frame_duration,
               const char *spritesheet_filename) {
    Texture2D tex = LoadTexture(spritesheet_filename);
    anim->num_frames = num_frames;
    anim->tex = tex;
    anim->frame_idx = 0;
    anim->frame_duration = frame_duration;
}

void anim_destroy(Anim *anim) {
    free(anim);
}

void anim_update(Anim *anim, long long t) {
    if (anim->frame_duration == 0 || anim->num_frames == 0) {
        return;
    }
    anim->frame_idx = (t / anim->frame_duration) % anim->num_frames;
}

void anim_draw(Anim *anim, Vector2 pos) {
    int frame_width = anim->tex.width / anim->num_frames;
    Rectangle src_rec = {
        .x = anim->frame_idx * frame_width,
        .y = 0,
        .width = frame_width,
        .height = anim->tex.height,
    };
    DrawTextureRec(anim->tex, src_rec, pos, RAYWHITE);
}
