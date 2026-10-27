/*
 * SFOGame/Source/netTaserMsg: 1 file, 0027BB00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027BB00 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { void* vtable; char data[0x20]; unsigned char mode; char pad[3]; int unk28; char pad2[0x24]; } Visitor;

extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
extern void cNetTaserMsg_UnpackAndProcess(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor (mode 2) on the stack, applies it to self and destroys it. */
void cNetTaserMsg_NetReceive(void* self)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_00504050);
    v.vtable = D_004DCDA0;
    v.mode = 2;
    v.unk28 = 0;
    cNetTaserMsg_UnpackAndProcess(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
static inline void merge_flush_func_0027BB00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BB00 */
