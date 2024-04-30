#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "anim.h"

#include <stddef.h>

#define MAX_ANIMATOR_ANIMATIONS 10

typedef struct {
    Anim *anim;
    int id;
} AnimIdPair;

typedef struct {
    AnimIdPair animations[MAX_ANIMATOR_ANIMATIONS];
    size_t animations_len;
    AnimIdPair curr_anim;
} Animator;

void animator_init(Animator *animator);
void animator_destroy(Animator *animator);
void animator_add_anim(Animator *animator, Anim *anim, int anim_id);
void animator_set_anim(Animator *animator, int anim_id);
void animator_update(Animator *animator, long long tick);
void animator_draw(Animator *animator, Vector2 pos);
Anim *animator_get_curr_anim(Animator *animator);

#endif
