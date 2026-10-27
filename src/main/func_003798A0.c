#include "types.h"
#pragma opt_propagation off

typedef unsigned long long u64_t;
typedef struct { char pad[0x108]; u64_t v108; } Ent;
typedef struct {
    char pad0[0x90];
    u64_t frame1, frame2, zbuf, xyoff, scissor, alpha2, alpha1;
    char padC8[0xEC - 0xC8];
    unsigned int fba;
    char padF0[0x1F0 - 0xF0];
    Ent ents[1];
} Ctx;
typedef struct { char pad[0xA70]; int cur; } CtxCur;
extern char D_00537F80[];
extern u64_t* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
extern void cXViewport_Validate(Ent* e);

typedef struct { u64_t lo, hi; } GsQ_98A0;
/* Builds the GS environment packet (FRAME/ZBUF/XYOFFSET/SCISSOR/ALPHA/FBA/TEXA via A+D)
   for the current buffer entry; the A+D pairs straddle quadwords. */
void XLib_UpdateRenderFrameEnv(Ctx* c)
{
    GsQ_98A0* q = (GsQ_98A0*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 0x10, 0, 1);
    Ent* e;
    q->lo = 0x11000000;
    q->hi = 0x0300002EULL | ((u64_t)0x020001E9 << 32);
    q++;
    q->lo = 0x01000404ULL | ((u64_t)0x5000000F << 32);
    q->hi = 0x800EULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    e = &c->ents[((CtxCur*)c)->cur];
    cXViewport_Validate(e);
    c->scissor = e->v108;
    q->hi = c->frame1; q++; q->lo = 0x4C;
    q->hi = c->frame2; q++; q->lo = 0x4D;
    q->hi = c->zbuf; q++; q->lo = 0x4E;
    q->hi = c->zbuf; q++; q->lo = 0x4F;
    q->hi = c->xyoff; q++; q->lo = 0x18;
    q->hi = c->xyoff; q++; q->lo = 0x19;
    q->hi = c->scissor; q++; q->lo = 0x40;
    q->hi = c->scissor; q++; q->lo = 0x41;
    q->hi = c->alpha1; q++; q->lo = 0x44;
    q->hi = c->alpha2; q++; q->lo = 0x45;
    q->hi = 0; q++; q->lo = 0x49;
    q->hi = c->fba; q++; q->lo = 0x4A;
    q->hi = 0; q++; q->lo = 0x4B;
    q->hi = 0x8080ULL | ((u64_t)0x80 << 32); q++; q->lo = 0x3B;
}