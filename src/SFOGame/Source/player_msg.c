/*
 * SFOGame/Source/player_msg: 8 files, 0020FEB0-00210170
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
static inline void merge_flush_func_0020FEB0(void) {} /* merge_units */
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
static inline void merge_flush_func_0020FEC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020FEC0 */

/* merge_units: begin func_0020FFD0 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline short R16_20FFD0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_20FFD0(void) { unsigned short lo = R16_20FFD0(); return lo + ((unsigned short)R16_20FFD0() << 16); }
typedef struct { void* vtable; char pad[0x20]; signed char b; } M_20FFD0;
extern char D_004F5410[];
#if 0 /* merge_units */
extern char D_004DAE50[];
#endif /* merge_units */
#define D_004DAE50 ((char*)&D_004DAE50) /* merge_units */

#if 0 /* merge_units */
extern char D_004DCF10[];
#endif /* merge_units */
#define D_004DCF10 ((char*)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(M_20FFD0* m, void* type);
#endif /* merge_units */
void* cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void SfxAtmosphericParticleEffect_eAtmosphericEffect(int b);
#if 0 /* merge_units */
extern void cMessage_dtor(M_20FFD0* m, int flags);
#endif /* merge_units */
void cMessage_dtor(void*, int); /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void cAtmosphericEffectMsg_NetReceive(void) {
    M_20FFD0 m;
    cMessage_ctor_cMessageNameR(&m, D_004F5410);
    m.vtable = D_004DAE50;
    m.b = R32_20FFD0();
    SfxAtmosphericParticleEffect_eAtmosphericEffect(m.b);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef D_004DAE50 /* merge_units */
#undef D_004DCF10 /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0020FFD0(void) {} /* merge_units */
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
static inline void merge_flush_func_002100C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002100C0 */

/* merge_units: begin func_00210170 */
#pragma push /* merge_units */
#include "loose01_types.h"

#if 0 /* merge_units */
extern void* D_004DAE50;
#endif /* merge_units */
#define D_004DAE50 (*(void **)&D_004DAE50) /* merge_units */

#if 0 /* merge_units */
extern void* D_004DCF10;
#endif /* merge_units */
#define D_004DCF10 (*(void **)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern ByteEvent* cMessage_ctor_cMessageNameR(ByteEvent*, char*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((ByteEvent *)cMessage_ctor_cMessageNameR((void *)(a0), (void *)(a1))) /* merge_units */


/* Base vtable D_004DCF10 is set first, then the derived one. */
ByteEvent* cAtmosphericEffectMsg_ctor(ByteEvent* self, int value) {
    cMessage_ctor_cMessageNameR(self, D_004F5410);
    self->vtable = &D_004DCF10;
    self->vtable = &D_004DAE50;
    self->value = value;
    return self;
}
#undef D_004DAE50 /* merge_units */
#undef D_004DCF10 /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
static inline void merge_flush_func_00210170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00210170 */

/* merge_units: begin func_002101D0 */
#pragma push /* merge_units */
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
extern void cMessage_ctor_cMessageNameR(M_002101D0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


extern void QueueMessage_cMessageR_cSystemP_int(M_002101D0* m, void* target, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(M_002101D0* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void cMaxActiveNpcCountMsg_NetReceive(void* target) {
    M_002101D0 m;
    cMessage_ctor_cMessageNameR(&m, D_004F53F8);
    m.vtable = D_004DAE70;
    m.f = R32_002101D0();
    m.one = 1;
    if (target) QueueMessage_cMessageR_cSystemP_int(&m, target, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef D_004DCF10 /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002101D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002101D0 */

/* merge_units: begin func_002102E0 */
#pragma push /* merge_units */
/* Serialize the 32-bit message field. */
DEFINE_NET_WRITE_ONE_WORD(cMaxActiveNpcCountMsg_Pack)
static inline void merge_flush_func_002102E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002102E0 */

/* merge_units: begin func_00210390 */
#pragma push /* merge_units */
extern int D_004F5400;

int cMaxActiveNpcCountMsg_GetMsgId(void) {
    return D_004F5400;
}
static inline void merge_flush_func_00210390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00210390 */
