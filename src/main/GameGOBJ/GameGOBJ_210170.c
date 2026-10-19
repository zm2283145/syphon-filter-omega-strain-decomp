/*
 * main/GameGOBJ: 4 files, 00210170-00210390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00210170 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DAE50;
extern void* D_004DCF10;
extern char D_004F5410[];
extern ByteEvent* Event_Construct(ByteEvent*, char*);

/* Base vtable D_004DCF10 is set first, then the derived one. */
ByteEvent* cAtmosphericEffectMsg_ctor(ByteEvent* self, int value) {
    Event_Construct(self, D_004F5410);
    self->vtable = &D_004DCF10;
    self->vtable = &D_004DAE50;
    self->value = value;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00210170 */

/* merge_units: begin func_002101D0 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline short R16_002101D0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_002101D0(void) { unsigned short lo = R16_002101D0(); return lo + ((unsigned short)R16_002101D0() << 16); }
static inline float RF_002101D0(void) { int i = R32_002101D0(); return *(float*)&i; }
static inline char R8_002101D0(void) { return *D_005061D0++; }
typedef struct { void* vtable; char pad[0x1C]; unsigned char one; char p21[3]; int f; } M_002101D0;
extern char D_004F53F8[];
extern char D_004DAE70[];
#if 0 /* merge_units */
extern char D_004DCF10[];
#endif /* merge_units */
#define D_004DCF10 ((char*)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(M_002101D0* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) ((void)Event_Construct((ByteEvent *)(a0), (char *)(a1))) /* merge_units */

extern void Event_Send(M_002101D0* m, void* target, int flags);
extern void cMessage_dtor(M_002101D0* m, int flags);
void cMaxActiveNpcCountMsg_NetReceive(void* target) {
    M_002101D0 m;
    Event_Construct(&m, D_004F53F8);
    m.vtable = D_004DAE70;
    m.f = R32_002101D0();
    m.one = 1;
    if (target) Event_Send(&m, target, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef D_004DCF10 /* merge_units */
#undef Event_Construct /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002101D0 */

/* merge_units: begin func_002102E0 */
#pragma push /* merge_units */
#include "net_write_one_word.h"

/* Serialize the 32-bit message field. */
DEFINE_NET_WRITE_ONE_WORD(cMaxActiveNpcCountMsg_v04)
#pragma pop /* merge_units */
/* merge_units: end func_002102E0 */

/* merge_units: begin func_00210390 */
#pragma push /* merge_units */
extern int D_004F5400;

int cMaxActiveNpcCountMsg_v05(void) {
    return D_004F5400;
}
#pragma pop /* merge_units */
/* merge_units: end func_00210390 */
