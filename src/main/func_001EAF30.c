/*
 * Matched functions (byte-identical with the retail executable).
 * Just below the humanCollision.cc range; these are humanCollision preset helpers
 * (see research HUMAN_COLLISION.md).
 */

#include "types.h"
#include "loose00_types.h"

/* 16-byte copy. */
Quad* func_001EAF30(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Configure a collision preset: selector, four candidate masks, the
 * height/distance/cosine ranges and flags; resets per-frame state. */
HumanColPreset* HumanColPreset_SetConfig(HumanColPreset* p, int selector, int* mask0, int* mask1,
                                         int* mask2, int* mask3, HumanColPresetCfg* cfg, int enabled) {
    p->selector = selector;
    p->mask0 = *mask0;
    p->mask1 = *mask1;
    p->mask2 = *mask2;
    p->mask3 = *mask3;
    p->heightMin = cfg->range0Min;
    p->heightMax = cfg->range0Max;
    p->distSqMin = cfg->range1Min;
    p->distSqMax = cfg->range1Max;
    p->cosMin = cfg->range2Min;
    p->cosMax = cfg->range2Max;
    p->negateFlag = cfg->enabled;
    p->enabled = enabled;
    p->active = 0;
    p->accepted = 0;
    p->unk70 = 0;
    p->unk90 = -1;
    p->unk94 = -1;
    p->unk98 = 0;
    p->unkA0 = 0;
    p->savedHeight = -3.4028234663852886e38f; /* -FLT_MAX */
    p->unkE4 = 0;
    return p;
}
