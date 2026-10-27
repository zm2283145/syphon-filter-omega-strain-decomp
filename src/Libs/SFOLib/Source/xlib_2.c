/*
 * Libs/SFOLib/Source/xlib: 10 files, 003796C0-00379B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003796C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Sets the flag byte at +0xD0. */
void XLib_FrameEnvChanged(unsigned char* self) {
    self[208] = 1;
}
static inline void merge_flush_func_003796C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003796C0 */

/* merge_units: begin func_003796D0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x50]; unsigned long long bits; } Rec50;
typedef struct { char pad[8]; Rec50** items; } RecTable;

/* Returns the low 14 bits of the 64-bit field of item i (as a 64-bit value). */
long long cTexMan_GetTxtrAddr(RecTable* t, int i)
{
    long long bits = t->items[i]->bits;
    return (int)(bits & 0x3FFF);
}
static inline void merge_flush_func_003796D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003796D0 */

/* merge_units: begin func_00379700 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture registry accessors (code lies between the vu1model.cc and xlib.cc
 * address ranges). Original translation unit not identified yet.
 */


extern int cTexture_GetTEX1_1(TexEntry*);

/* Address of the entry's embedded sub-object. */
void* cTexture_GetTEX0_1(TexEntry* self) {
    return self->body;
}

int cTexture_GetPSM(TexEntry* self) {
    return self->info->unk0A;
}

int cTexture_GetHeight(TexEntry* self) {
    return self->info->unk06;
}

int cTexture_GetWidth(TexEntry* self) {
    return self->info->unk04;
}

TexEntry* cTexMan_GetTexture(TexRegistry* reg, int index) {
    return reg->entries[index];
}

Words4* tIRGBA_ctor(Words4* self, int a, int b, int c, int d) {
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    return self;
}

void cDmaMan_EndChain_int(void) {
}

int cTexMan_GetTEX1_1(TexRegistry* reg, int index) {
    return cTexture_GetTEX1_1(reg->entries[index]);
}

void* cTexMan_GetTEX0_1(TexRegistry* reg, int index) {
    return reg->entries[index]->body;
}

int XLib_GetTexMan(Manager37F9D0* self) {
    return self->unk1058;
}
static inline void merge_flush_func_00379700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379700 */

/* merge_units: begin func_003797E0 */
#pragma push /* merge_units */
/* Unpacked fields of a 64-bit hardware register (stored one per word). */
typedef struct RegFields {
    char pad[0xD8];
    unsigned int f0;  /* bit 0 */
    unsigned int f1;  /* bits 1.. */
    unsigned int f4;  /* bits 4.. */
    unsigned int f12; /* bits 12.. */
    unsigned int f14; /* bit 14 */
    unsigned int f15; /* bit 15 */
    unsigned int f16; /* bit 16 */
    unsigned int f17; /* bits 17.. */
} RegFields;

/* Packs the unpacked register fields into a 64-bit register value. */
unsigned long XLib_GetPixelEnv(RegFields* s) {
    return (unsigned long)s->f0
         | ((unsigned long)s->f1 << 1)
         | ((unsigned long)s->f4 << 4)
         | ((unsigned long)s->f12 << 12)
         | ((unsigned long)s->f14 << 14)
         | ((unsigned long)s->f15 << 15)
         | ((unsigned long)s->f16 << 16)
         | ((unsigned long)s->f17 << 17);
}
static inline void merge_flush_func_003797E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003797E0 */

/* merge_units: begin func_00379840 */
#pragma push /* merge_units */
typedef struct Flags8 {
    char pad[0x100];
    unsigned int f[8];
} Flags8;

/* Packs eight flag words into a bitmask (bits 3..10). */
unsigned long XLib_GetPrimEnv(Flags8* o) {
    unsigned long m = ((unsigned long)o->f[0] << 3) | ((unsigned long)o->f[1] << 4);
    m = ((unsigned long)o->f[2] << 5) | m;
    m = ((unsigned long)o->f[3] << 6) | m;
    m = ((unsigned long)o->f[4] << 7) | m;
    m = ((unsigned long)o->f[5] << 8) | m;
    m = ((unsigned long)o->f[6] << 9) | m;
    return ((unsigned long)o->f[7] << 10) | m;
}
static inline void merge_flush_func_00379840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379840 */

/* merge_units: begin func_003798A0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003798A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003798A0 */

/* merge_units: begin func_00379AB0 */
#pragma push /* merge_units */
unsigned char cXViewport_IsOrtho(unsigned char* self) {
    return self[260];
}
static inline void merge_flush_func_00379AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379AB0 */

/* merge_units: begin func_00379AC0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; char blockA[0x40]; char blockB[0xB4]; unsigned char useA; } Obj104;
#if 0 /* merge_units */
extern void cXViewport_Validate(Obj104* o);
#endif /* merge_units */
#define cXViewport_Validate(a0) (cXViewport_Validate((Ent *)(a0))) /* merge_units */


/* Updates the object, then returns block +0x10 when the flag at +0x104 is set, else block +0x50. */
void* cXViewport_GetProjMat(Obj104* o)
{
    cXViewport_Validate(o);
    if (o->useA)
        return o->blockA;
    return o->blockB;
}
#undef cXViewport_Validate /* merge_units */
static inline void merge_flush_func_00379AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379AC0 */

/* merge_units: begin func_00379B00 */
#pragma push /* merge_units */
/* Address of the currently selected 272-byte item. */
char* XLib_GetViewport(Manager37F9D0* self) {
    return self->items[self->current];
}
static inline void merge_flush_func_00379B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379B00 */

/* merge_units: begin func_00379B20 */
#pragma push /* merge_units */
typedef struct { char pad[0xF00]; char sub[1]; } Obj00379B20;
extern void XLib_UpdateCompMat(Obj00379B20* obj, int a, int b);
extern void XLib_TestBBox_cMatrixR_cVectorR_cVectorR(Obj00379B20* obj, void* sub, int a, int b);
/* Initialise base, then the sub-object at 0xF00. */
void XLib_TestBBox_cVectorR_cVectorR(Obj00379B20* obj, int a, int b)
{
    XLib_UpdateCompMat(obj, a, b);
    XLib_TestBBox_cMatrixR_cVectorR_cVectorR(obj, obj->sub, a, b);
}
static inline void merge_flush_func_00379B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379B20 */
