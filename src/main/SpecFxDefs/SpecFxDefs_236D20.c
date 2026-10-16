/*
 * main/SpecFxDefs: range (5 files, 00236D20-00236F80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00236D20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char pad[0xC]; void* buf; } E4Own;
extern "C" {
extern char D_004A6E38[];
void func_003A2BA0(void* p, int n);
}
extern "C" void ParticleEffectComp_Stop(E4Own* o)
{
    void* p = o->buf;
    if (p) {
        {
            AllocGuard g;
            func_003A2BA0(p, -1);
            Mem_Free(0, p, D_004A6E38, 0x12C);
        }
        o->buf = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236D20 */

/* merge_units: begin func_00236DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                        
int Tracer_Create(int, int, char*, float);             
#if 0 /* merge_units */
extern char D_004A6E38;
#endif /* merge_units */
#define D_004A6E38 (*(char*)&D_004A6E38) /* merge_units */

extern unsigned char D_00533880;
}
extern "C" void ParticleEffectComp_Start(char * arg0) {
    int var_s1;

    {
        AllocGuard g;
    var_s1 = Mem_Alloc(0, 0x70, &D_004A6E38, 0x125);
    }
    if (var_s1 != 0) {
        var_s1 = Tracer_Create(var_s1, F_(arg0, 0x8, int), arg0 + 0x10, 1.0f);
    }
    F_(arg0, 0xC, int) = var_s1;
}
#undef D_004A6E38 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236DE0 */

/* merge_units: begin func_00236EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj00236EA0 {
public:
    int id;
    virtual void s0();
    virtual void s1();
    virtual void release();
};
struct Raw00236EA0 { int id; void* vt; };
extern "C" char D_004DBE90[];
extern "C" char D_004D9280[];
extern "C" void func_003EC950(void* p);
extern "C" Obj00236EA0* ParticleEffectComp_Destroy(Obj00236EA0* self, short deleteFlag)
{
    if (self) {
        Raw00236EA0* r = (Raw00236EA0*)self;
        r->vt = D_004DBE90;
        self->release();
        if (self)
            r->vt = D_004D9280;
        if (deleteFlag > 0)
            func_003EC950(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236EA0 */

/* merge_units: begin func_00236F20 */
#pragma push /* merge_units */
typedef struct { unsigned char flag; char pad[7]; } D2_FxFlag;
typedef struct { int a; int b; } D2_FxEntry;
extern D2_FxFlag D_004F7A54[];
extern D2_FxEntry D_004F7A50[];
static inline D2_FxEntry* d2_get(int id) {
    if ((unsigned int)id < 41) return &D_004F7A50[id];
    return 0;
}
D2_FxEntry* SpecFx_GetEffectDef(signed char id) {
    if (!D_004F7A54[id].flag) return 0;
    return d2_get(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236F20 */

/* merge_units: begin func_00236F80 */
#pragma push /* merge_units */
typedef struct { int obj; unsigned char flag; char pad[3]; } E236F;
typedef struct { char pad[0xD0]; E236F e[15]; } G236F;
#if 0 /* merge_units */
extern G236F D_004F7A50;
#endif /* merge_units */
#define D_004F7A50 (*(G236F*)&D_004F7A50) /* merge_units */

extern int D_00539248;
extern void func_003813A0(int a, int b, int c);
void func_00236F80(void)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (D_004F7A50.e[i].flag) {
            func_003813A0(D_00539248, D_004F7A50.e[i].obj, 1);
            D_004F7A50.e[i].flag = 0;
        }
    }
}
#undef D_004F7A50 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236F80 */
