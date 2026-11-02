/*
 * SFOGame/Source/game: 6 files, 00137920-00137A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00137920 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop

#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cEnvSettingsPtr_dtor)
static inline void merge_flush_func_00137920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137920 */

/* merge_units: begin func_001379A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x24]; char m[4]; };
extern "C" {
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cHotboxMan_HandleMessage();
extern "C" void cSystem_getSOBJClassId();
extern "C" void cSystem_ScriptHandleMessage();
extern void * const D_004D9960[];
#if 0 /* merge_units */
void std_list_cHotboxPtr_dtor(void* m, short f);
#endif /* merge_units */
void* std_list_cHotboxPtr_dtor(void* self, short deleteFlag); /* merge_units */
#define std_list_cHotboxPtr_dtor(a0, a1) ((void)std_list_cHotboxPtr_dtor((void *)(a0), (a1))) /* merge_units */

void cSystem_dtor(void* p, short f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */


}
extern "C" O_001379A0* cHotboxMan_dtor(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D9960);
        if (self->m) std_list_cHotboxPtr_dtor(self->m, 0);
        cSystem_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004D9960[16] = { (void*)0x0, (void*)0x0, (void*)cHotboxMan_dtor, (void*)cHotboxMan_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001379A0(void) {}
#undef std_list_cHotboxPtr_dtor /* merge_units */
#undef operator_delete /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001379A0 */

/* merge_units: begin func_00137A20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cHotboxPtr_dtor)
static inline void merge_flush_func_00137A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137A20 */

/* merge_units: begin func_00137AA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cNodePtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_00137AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137AA0 */

/* merge_units: begin func_00137AB0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {

extern char D_004D9060[];
extern char D_0049A890[];
extern char D_0049AB60[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cSystemContainer_ctor_void(void* p);
void std_vector_tVUMNamePairPtr_ctor(void* p);
void std_list_deleter_cHogFile_ctor(void* p);
void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR(void* p, void* a, void* b);
void std_list_deleter_voidPtr_ctor_void(void* p);
void Libc_Strcpy(void* s, char* src);
void* cVisionFxMan_ctor(void* p);
void* cWaterFx_ctor(void* p);
void* cPathSystem_ctor(void* p);
void* cGameSound_ctor(void* p);
void* cAISoundSystem_ctor(void* p);
void* cObjectiveMan_ctor(void* p);
void* cHotboxMan_ctor(void* p, int a);
void* cGameOptions_ctor(void* p);
void* cGameFrontEnd_ctor(void* p);
void* cWeaponDB_ctor(void* p);
void cSystemContainer_AddSystem(void* w, void* p);
void std_vector_pod_int_reserve(void* p, int n);
}

struct Sub2C_WC { char pad[0xC]; unsigned char bC; };
struct Blk10_WC { int f0; int f4; int f8; unsigned char bC; };
struct Blk14_WC { char pad[0x10]; int f10; };
struct Blk70_WC { char pad[0xC]; int fC; unsigned char b10; };
struct World_WC {
    void* vtbl;
    char pad4[0x10 - 0x4];
    int f10;
    char pad14[0x2C - 0x14];
    Sub2C_WC m2C;
    char pad39[0x3C - 0x39];
    char m3C[0x48 - 0x3C];
    int f48;
    int f4C;
    unsigned char b50;
    unsigned char b51;
    char pad52[2];
    int f54;
    int f58;
    int f5C;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    unsigned char b63;
    unsigned char b64;
    unsigned char b65;
    unsigned char b66;
    unsigned char b67;
    unsigned char b68;
    char pad69[3];
    int f6C;
    char m70[0x80 - 0x70];
    void* f80;
    Blk70_WC* f84;
    Blk14_WC* f88;
    void* f8C;
    void* f90;
    char pad94[4];
    void* f98;
    char m9C[0xAC - 0x9C];
    int fAC;
    int fB0;
    void* fB4;
    int fB8;
    char padBC[0xC4 - 0xBC];
    char mC4[0xD8 - 0xC4];
    unsigned char bD8;
    unsigned char bD9;
    char padDA[2];
    int fDC;
    void* fE0;
    void* fE4;
    Blk10_WC* fE8;
    int fEC;
    char padF0[0x140 - 0xF0];
    char s140[0x1C0 - 0x140];
    int f1C0;
    char pad1C4[4];
    int f1C8;
    int f1CC;
    int f1D0;
    int f1D4;
    int f1D8;
    void* f1DC;
    void* f1E0;
    char pad1E4[4];
    long f1E8;
};

#include "alloc_guard.h"
/* allocation under the scoped allocator lock (each guard keeps a 16-byte frame slot) */
static inline void* WcAlloc(int sz, int line) { AllocGuard g; return cMemMan_Allocate(0, sz, D_0049A890, line); }
#define WC_ALLOC(p, T, sz, line) p = (T)WcAlloc(sz, line);

/* map member ctor with comparator/allocator temporaries; two inline levels put them below the guards */
static inline void MapInitB(void* m) { int cmp; int alc; std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR(m, &cmp, &alc); }
static inline void MapInitA(void* m) { MapInitB(m); }

extern "C" World_WC* World_Construct(World_WC* w)
{
    cSystemContainer_ctor_void(w);
    w->vtbl = D_004D9060;
    {
        Sub2C_WC* m = &w->m2C;
        std_vector_tVUMNamePairPtr_ctor(m);
        m->bC = 1;
    }
    std_list_deleter_cHogFile_ctor(w->m3C);
    w->b50 = 0;
    w->b51 = 0;
    w->f54 = 0;
    w->f58 = 0;
    w->f5C = 0;
    w->b60 = 0;
    w->b61 = 0;
    w->b62 = 0;
    w->b63 = 0;
    w->b64 = 0;
    w->b65 = 1;
    MapInitA(w->m70);
    std_list_deleter_voidPtr_ctor_void(w->m9C);
    w->fAC = 0;
    w->fB0 = 0;
    w->fB8 = 0;
    std_list_deleter_voidPtr_ctor_void(w->mC4);
    w->bD9 = 0;
    w->fDC = 0;
    w->fE0 = 0;
    w->fE4 = 0;
    w->fE8 = 0;
    w->fEC = 0;
    w->f1E8 = 0;
    Libc_Strcpy(w->s140, D_0049AB60);
    {
        void* p;
        WC_ALLOC(p, void*, 0x200, 0x93);
        if (p) p = cVisionFxMan_ctor(p);
        w->fE0 = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x460, 0x94);
        if (p) p = cWaterFx_ctor(p);
        w->fE4 = p;
    }
    {
        Blk10_WC* p;
        WC_ALLOC(p, Blk10_WC*, 0x10, 0x95);
        if (p) {
            p->f0 = 0;
            p->f4 = 0;
            p->f8 = 0;
            p->bC = 0;
        }
        w->fE8 = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x7C, 0x97);
        if (p) p = cPathSystem_ctor(p);
        cSystemContainer_AddSystem(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x54C0, 0x98);
        if (p) p = cGameSound_ctor(p);
        cSystemContainer_AddSystem(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x20, 0x99);
        if (p) p = cAISoundSystem_ctor(p);
        cSystemContainer_AddSystem(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x11B4, 0x9A);
        if (p) p = cObjectiveMan_ctor(p);
        cSystemContainer_AddSystem(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x34, 0x9C);
        if (p) p = cHotboxMan_ctor(p, 0);
        w->f80 = p;
    }
    {
        Blk14_WC* p;
        WC_ALLOC(p, Blk14_WC*, 0x14, 0x9D);
        if (p) p->f10 = 0;
        w->f88 = p;
    }
    {
        Blk70_WC* p;
        WC_ALLOC(p, Blk70_WC*, 0x70, 0x9E);
        if (p) {
            std_list_deleter_voidPtr_ctor_void(p);
            p->b10 = 0;
            p->fC = 0;
        }
        w->f84 = p;
    }
    w->f8C = 0;
    {
        void* p;
        WC_ALLOC(p, void*, 0x24, 0xA0);
        if (p) p = cGameOptions_ctor(p);
        w->f1DC = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x318, 0xA3);
        if (p) p = cGameFrontEnd_ctor(p);
        w->fB4 = p;
    }
    cSystemContainer_AddSystem(w, w->fB4);
    std_vector_pod_int_reserve(&w->m2C, 0x100);
    w->f98 = 0;
    w->f90 = 0;
    w->f10 = 0;
    w->f48 = 0;
    w->f4C = 0;
    {
        void* p;
        WC_ALLOC(p, void*, 0xD8, 0xB2);
        if (p) p = cWeaponDB_ctor(p);
        w->f1E0 = p;
    }
    w->f1C8 = 0;
    w->f1CC = 0;
    w->f1D0 = 0;
    w->f1D4 = 0;
    w->f1C0 = 0;
    w->f1D8 = 0;
    w->b66 = 0;
    w->b67 = 0;
    w->b68 = 0;
    w->f6C = -1;
    return w;
}
static inline void merge_flush_func_00137AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137AB0 */

/* merge_units: begin func_00138350 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(String_Dtor_138350, String_Dtor)
static inline void merge_flush_func_00138350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00138350 */
