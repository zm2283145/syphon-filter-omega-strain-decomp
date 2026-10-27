/*
 * Libs/SFOLib/Source/dmaman: 2 files, 00375B40-00375BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00375B40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char p0[8]; unsigned int end; char pC[4]; unsigned int cur; int f14; int f18; char f1C; } B375;
typedef struct { char p0[0xC]; int base; } C375;
typedef struct { B375 *buf[0x33]; C375 *cfg[3]; int cursel; } A375;
int cDmaMan_BeginChain_eDmaChannel_int(A375 *self, unsigned char i, int n) {
    B375 *b = self->buf[i];
    if (b->cur + n * 0x10 >= b->end) {
        self->cursel = i;
        b->cur = self->cfg[i]->base;
    }
    b->f14 = b->cur;
    b->f18 = 0;
    b->f1C = 0;
    return b->cur;
}
static inline void merge_flush_func_00375B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375B40 */

/* merge_units: begin func_00375BA0 */
#pragma push /* merge_units */
/* Packet buffer: wraps if full, writes two zero dwords at the cursor and returns it (minus 8 when flag is set). */
typedef struct { char p0[8]; unsigned int end; char pC[4]; unsigned int cur; int f14; int f18; char f1C; } B375BA0;
typedef struct { char p0[0xC]; int base; } C375BA0;
typedef struct { B375BA0 *buf[0x33]; C375BA0 *cfg[3]; int cursel; } A375BA0;
static inline void Put375BA0(B375BA0* b, unsigned long long v) { unsigned long long* p = (unsigned long long*)b->cur; b->cur += 8; *p = v; }
int cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(A375BA0 *self, unsigned char i, char id, int addr, int flag) {
    B375BA0 *b = self->buf[i];
    if (b->cur >= b->end) {
        self->cursel = i;
        b->cur = self->cfg[i]->base;
    }
    b->f18 = addr;
    b->f1C = id;
    b->f14 = b->cur;
    Put375BA0(b, 0);
    Put375BA0(b, 0);
    return flag ? b->cur - 8 : b->cur;
}
static inline void merge_flush_func_00375BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00375BA0 */
