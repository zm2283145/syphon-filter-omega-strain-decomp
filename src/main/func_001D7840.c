/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Copy a Rec24 (0x24-byte record, see func_001D86D0 for its constructor). */
Rec24* func_001D7840(Rec24* d, Rec24* s) {
    d->unk00 = s->unk00;
    d->unk04 = s->unk04;
    d->unk08 = s->unk08;
    d->unk0C = s->unk0C;
    d->unk10 = s->unk10;
    d->unk14 = s->unk14;
    d->unk18 = s->unk18;
    d->unk1C = s->unk1C;
    d->unk20 = s->unk20;
    return d;
}
