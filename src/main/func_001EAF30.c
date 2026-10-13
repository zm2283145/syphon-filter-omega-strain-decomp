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
    p->masks[0].bits = *mask0;
    p->masks[1].bits = *mask1;
    p->masks[2].bits = *mask2;
    p->masks[3].bits = *mask3;
    p->cfg.range0Min = cfg->range0Min;
    p->cfg.range0Max = cfg->range0Max;
    p->cfg.range1Min = cfg->range1Min;
    p->cfg.range1Max = cfg->range1Max;
    p->cfg.range2Min = cfg->range2Min;
    p->cfg.range2Max = cfg->range2Max;
    p->cfg.enabled = cfg->enabled;
    p->descFlag = enabled;
    p->active = 0;
    p->unk32 = 0;
    p->unk70 = 0;
    p->unk90 = -1;
    p->unk94 = -1;
    p->unk98 = 0;
    p->unkA0 = 0;
    p->bestHeight = -3.4028234663852886e38f; /* -FLT_MAX */
    p->unkE4 = 0;
    return p;
}
