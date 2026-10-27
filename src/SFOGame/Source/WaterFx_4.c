/*
 * SFOGame/Source/WaterFx: 3 files, 002B2A40-002B2B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B2A40 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x44]; struct { char pad[0x22]; unsigned short count; } *info; } E2Model;
typedef struct { char pad[8]; E2Model** models; } E2ModelTable;
typedef struct { int a; int b; } E2List;
typedef struct {
    float rate;
    E2List list;
    char pad0c[4];
    int f10;
    float f14;
    int f18;
    int model;
    int count;
} E2WaterSub;
typedef struct {
    int f0;
    int f4;
    char pad08[0x38];
    int f40;
    char pad44[0x24];
    int f68;
    char pad6c[4];
    E2WaterSub sub;
} E2WaterFx;
extern int* nSfxLoader_GetHandle(int);
extern void std_list_deleter_tNode_ctor(E2List*);
extern E2ModelTable* g_TextureMgr;
#pragma opt_propagation off
E2WaterFx* cWaterFx_tBody_ctor(E2WaterFx* s) {
    E2WaterSub* sub;
    float z;
    s->f4 = -2;
    s->f0 = 0;
    s->f40 = 0;
    s->f68 = *nSfxLoader_GetHandle(0x28);
    sub = &s->sub;
    sub->rate = 0.0375f;
    std_list_deleter_tNode_ctor(&sub->list);
    sub->model = *nSfxLoader_GetHandle(0x27);
    z = 0.0f;
    sub->count = g_TextureMgr->models[sub->model]->info->count;
    sub->f10 = 0;
    sub->f14 = z - z;
    sub->f18 = 0;
    return s;
}
static inline void merge_flush_func_002B2A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2A40 */

/* merge_units: begin func_002B2AF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter std_list_deleter_tNode_erase_listdeleter_listdeleter
#include "obj_list_dtor.h"

DEFINE_OBJ_LIST_DTOR(std_list_tNode_dtor)
static inline void merge_flush_func_002B2AF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2AF0 */

/* merge_units: begin func_002B2B70 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cWaterFx_AddBody_cVectorR_float_float: claim a free splash record slot, construct it, and initialise it at pos. */
typedef int u128_t __attribute__((mode(TI)));
struct Vec4_2B2B70 {
    float x, y, z, w;
    Vec4_2B2B70() {}
    Vec4_2B2B70(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(const Vec4_2B2B70& o) { u128_t q; __asm__ volatile("lq %0, 0x0(%1)\n sq %0, 0x0(%2)" : "=&r"(q) : "r"(&o), "r"(this) : "memory"); }
    Vec4_2B2B70& operator=(const Vec4_2B2B70& o) { u128_t q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Owner_2B2B70 { int pad[3]; int id; };
struct WaterFxRecord {
    Owner_2B2B70 *f0;
    int f4;
    float f8;
    int pad;
    Vec4_2B2B70 pos;
    Vec4_2B2B70 vel;
    float f30;
    int pad2[3];
    char f40[0x40];
    float f80;
    float f84;
    float f88;
};
struct WaterFx {
    char pad[0x400];
    WaterFxRecord *recs[20];
    int count;
};

extern "C" {
extern char D_004ABFF0[];
void *opNew_uint_int_charP_int(int size, int pool, char *file, int line);
#if 0 /* merge_units */
WaterFxRecord *cWaterFx_tBody_ctor(void *p);
#endif /* merge_units */
#define cWaterFx_tBody_ctor(a0) ((WaterFxRecord *)cWaterFx_tBody_ctor((E2WaterFx *)(a0))) /* merge_units */

void WaterFx_InitSplash(void *a, Vec4_2B2B70 *pos, float f, float g);
void cWaterFx_AddBody_cVectorR_float_float(WaterFx *fx, Vec4_2B2B70 *pos, float a, float b);
}

static inline void SetOwner_2B2B70(WaterFxRecord *r, Owner_2B2B70 *o) { r->f0 = o; int t; const int& v = o ? o->id : (t = -1); r->f4 = v; }

void cWaterFx_AddBody_cVectorR_float_float(WaterFx *fx, Vec4_2B2B70 *pos, float a, float b)
{
    WaterFxRecord *rec;
    int slot;
    int i;
    float aa;
    float bb;

    slot = -1;
    bb = 0.2f + b;
    aa = a;
    for (i = 0; i < 20; i++) {
        if (fx->recs[i] == 0) {
            void *p;
            slot = i;
            p = opNew_uint_int_charP_int(0xA0, 0, D_004ABFF0, 0x1AA);
            if (p) p = cWaterFx_tBody_ctor(p);
            fx->recs[slot] = (WaterFxRecord *)p;
            fx->count++;
            break;
        }
    }
    if (slot < 0) return;
    rec = fx->recs[slot];
    SetOwner_2B2B70(rec, 0);
    rec->f8 = aa;
    { Vec4_2B2B70 *d = &rec->pos; d->Set(*pos); }
    rec->vel = Vec4_2B2B70(0.0f, 0.0f, 0.0f, 0.0f);
    rec->f30 = bb;
    WaterFx_InitSplash(rec->f40, &rec->pos, rec->f8, rec->f30);
    {
        float t = rec->f8;
        float s = rec->f30;
        float lo;
        float hi = 3.8f * t - (lo = 0.6f * t);
        rec->f80 = lo;
        rec->f84 = hi;
        rec->f88 = s;
    }
}
#undef cWaterFx_tBody_ctor /* merge_units */
static inline void merge_flush_func_002B2B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2B70 */
