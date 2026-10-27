/*
 * main/GameGOBJ: 4 files, 0020FEB0-002100C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020FEB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F5418;

int cAtmosphericEffectMsg_GetMsgId(void) {
    return D_004F5418;
}
#pragma pop /* merge_units */
/* merge_units: end func_0020FEB0 */

/* merge_units: begin func_0020FEC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DAE50[];

struct Msg_0020FEC0 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DAE50; p->b24 = s->b24;

extern "C" { char D_004A41A8[] = "player_msg.hh"; }
DEFINE_MESSAGE_CLONE(cAtmosphericEffectMsg_Clone, Msg_0020FEC0, 40, D_004A41A8, 86, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0020FEC0 */

/* merge_units: begin func_0020FFD0 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline short R16_20FFD0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_20FFD0(void) { unsigned short lo = R16_20FFD0(); return lo + ((unsigned short)R16_20FFD0() << 16); }
typedef struct { void* vtable; char pad[0x20]; signed char b; } M_20FFD0;
extern char D_004F5410[];
extern char D_004DAE50[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(M_20FFD0* m, void* type);
extern void SfxAtmosphericParticleEffect_eAtmosphericEffect(int b);
extern void cMessage_dtor(M_20FFD0* m, int flags);
void cAtmosphericEffectMsg_NetReceive(void) {
    M_20FFD0 m;
    cMessage_ctor_cMessageNameR(&m, D_004F5410);
    m.vtable = D_004DAE50;
    m.b = R32_20FFD0();
    SfxAtmosphericParticleEffect_eAtmosphericEffect(m.b);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0020FFD0 */

/* merge_units: begin func_002100C0 */
#pragma push /* merge_units */
#include "net_write_one_word.h"

typedef struct { char pad[0x24]; unsigned char value; } Atm002100C0;

void cAtmosphericEffectMsg_Pack(Atm002100C0* self)
{
    NetW1_write32(self->value);
}
#pragma pop /* merge_units */
/* merge_units: end func_002100C0 */
