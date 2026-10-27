/*
 * SFOGame/Source/SpecFxDefs: 2 files, 00232C00-00232E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00232C00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* g_LocalPlayer;
extern char D_004A6E38[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cPlayer_AtmosphericParticleEffect(void* w, void* o);
void* cSnowEffect_ctor(void* p, signed char type, float a, void* src, float b, float c);
void* cCameraAtmosphericEffect_ctor(void* p, signed char type, float a, float b, float c, float d);
}
static inline void* GAlloc(int sz, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, sz, D_004A6E38, line);
}
extern "C" void SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc(signed char type, void* src, float a, float b, float c, float d)
{
    void* w = g_LocalPlayer;
    cPlayer_AtmosphericParticleEffect(w, 0);
    if (type == 0x16 || type == 0x17 || type == 0x18) {
        void* p = GAlloc(0xD0, 0x4CD);
        if (p) p = cSnowEffect_ctor(p, type, b, src, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    } else {
        void* p = GAlloc(0xC0, 0x4D2);
        if (p) p = cCameraAtmosphericEffect_ctor(p, type, a, b, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    }
}
static inline void merge_flush_func_00232C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232C00 */

/* merge_units: begin func_00232E00 */
#pragma push /* merge_units */
#include "vu0_ops.h"

typedef struct ListNode232E00 {
    struct ListNode232E00* prev;
    struct ListNode232E00* next;
    struct LightRef232E00* value;
} ListNode232E00;

typedef struct LightRef232E00 {
    void* obj;
    char pad4[5];
    unsigned char enabled;
} LightRef232E00;

typedef struct {
    ListNode232E00* node;
} ListIt232E00;

typedef struct {
    char pad0[0x38];
    int key;
    char pad3C[0x74 - 0x3C];
    char list[8];
} Fx232E00;

typedef struct {
    Vec4 r[4];
} Mtx232E00;

extern void std_list_cElementPtr_begin_void(ListIt232E00* out, void* list);
extern void std_list_cElementPtr_end_void(ListIt232E00* out, void* list);
extern ListIt232E00* cLListIterator_cElementPtr_ctor_listR(ListIt232E00* dst, ListIt232E00* src);
extern void cParticle_Render(void* obj, int key, Mtx232E00* m);

#pragma push
#pragma opt_rotateloops off
void cSnowEffect_Render(Fx232E00* self) {
    ListIt232E00 it;
    ListIt232E00 first;
    ListIt232E00 last;
    ListIt232E00 tmpBegin;
    ListIt232E00 tmpEnd;
    Mtx232E00 m;

    VU0_UnitMatrix(&m);
    std_list_cElementPtr_begin_void(&tmpBegin, self->list);
    cLListIterator_cElementPtr_ctor_listR(&first, &tmpBegin);
    it = first;
    while (std_list_cElementPtr_end_void(&tmpEnd, self->list), cLListIterator_cElementPtr_ctor_listR(&last, &tmpEnd), it.node != last.node) {
        if (it.node->value->obj != 0 && it.node->value->enabled) {
            cParticle_Render(it.node->value->obj, self->key, &m);
        }
        it.node = it.node->next;
    }
}
#pragma pop
static inline void merge_flush_func_00232E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232E00 */
