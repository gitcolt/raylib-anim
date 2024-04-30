#include <stdio.h>

#include "animator.h"

void animator_init(Animator *animator) {
    animator->animations_len = 0;
}

void animator_destroy(Animator *animator) {
    for (int i = 0; i < animator->animations_len; ++i) {
        Anim *anim = animator->animations[i].anim;
        anim_destroy(anim);
    }
}

void animator_add_anim(Animator *animator, Anim *anim, int anim_id) {
    animator->animations[animator->animations_len++] = (AnimIdPair){ anim, anim_id };
}

void animator_set_anim(Animator *animator, int anim_id) {
    for (int i = 0; i < animator->animations_len; ++i) {
        if (animator->animations[i].id == anim_id) {
            animator->curr_anim = animator->animations[i];
            return;
        }
    }
    fprintf(stderr, "Could not find anim with given id (%d)\n", anim_id);
}

void animator_update(Animator *animator, long long tick) {
    Anim *curr_anim = animator->curr_anim.anim;
    if (!curr_anim)
        return;
    anim_update(curr_anim, tick);
}

void animator_draw(Animator *animator, Vector2 pos) {
    anim_draw(animator->curr_anim.anim, pos);
}

Anim *animator_get_curr_anim(Animator *animator) {
    return animator->curr_anim.anim;
}
