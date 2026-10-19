/*
 * Matched functions (byte-identical with the retail executable).
 * Initializes a few fields of an AI state record.
 */

#include "types.h"

extern char g_LevelFarDistance[]; /* float */
extern char g_VideoFrameCounter[]; /* pointer */

typedef struct AIStateInit {
    char pad00[0x10];
    float unk10;  /* 0x10 */
    int unk14;    /* 0x14: written as the bit pattern of pi/4 */
    char pad18[0x38];
    int unk50;    /* 0x50 */
} AIStateInit;

void NpcPerception_ResetView(AIStateInit* self) {
    self->unk14 = 0x3F490FDB; /* 0.7853982f */
    self->unk10 = *(float*)g_LevelFarDistance;
    self->unk50 = *(int*)g_VideoFrameCounter + 20;
}
