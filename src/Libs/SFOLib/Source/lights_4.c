/*
 * Libs/SFOLib/Source/lights: 2 files, 00372AC0-00372B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00372AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Field accessors of Obj372AC0.
 */

#include "loose03_types.h"

float cSceneLight_GetFalloffAngleCos(Obj372AC0* self) {
    return self->unk50;
}

void* cSceneLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

float func_00372AE0(Obj372AC0* self) {
    return self->unk54;
}

float func_00372AF0(Obj372AC0* self) {
    return self->unk14;
}

float func_00372B00(Obj372AC0* self) {
    return self->unk10;
}

void* cLightSrc_GetPosition(Obj372AC0* self) {
    return self->unk30;
}

void* cParallelLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

signed char func_00372B30(Obj372AC0* self) {
    return self->unk1E;
}
static inline void merge_flush_func_00372AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372AC0 */

/* merge_units: begin func_00372B40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned char m; unsigned char t; unsigned char f; unsigned char p3; int v; char pad[0x18]; } Light;
typedef struct { int v; int z; } Cor;
typedef struct { Light l[256]; Cor c[1]; } Big;
typedef struct { char pad[0x4C]; int n; int nc; char* buf; char pad58[8]; char d[1]; } LightMgr;
static inline void FASTDMA_ToSPR(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void FASTDMA_Wait_ToSPR(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
void cLightMan_AquireSourcesByProperty(LightMgr* m, int a, int b, int c)
{
    int i;
    Light* l;
    FASTDMA_ToSPR((int)m->buf, (int)m->d, m->n * 2);
    FASTDMA_Wait_ToSPR();
    m->nc = 0;
    for (i = 0; i < m->n; i++) {
        l = (Light*)(m->buf + i * 32);
        if (!(l->m & a)) continue;
        if (b != 0xFF && !(l->t & b)) continue;
        if (!(l->f & c)) continue;
        ((Cor*)(m->buf + 0x2000))[m->nc].z = 0;
        ((Cor*)(m->buf + 0x2000))[m->nc].v = l->v;
        m->nc++;
    }
}
static inline void merge_flush_func_00372B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00372B40 */
