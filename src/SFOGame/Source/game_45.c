/*
 * SFOGame/Source/game: 3 files, 00136D40-00136DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00136D40 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_cNodePtr_dtor, std_vector_imp_cNodePtr_1_dtor)
static inline void merge_flush_func_00136D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136D40 */

/* merge_units: begin func_00136DA0 */
#pragma push /* merge_units */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void* cTimerDisable_ctor(void* self)
{
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136DA0 */

/* merge_units: begin func_00136DF0 */
#pragma push /* merge_units */
/* cGameSystem_dtor: world destructor - frees the owned subsystems, then destroys the members and the base. */
#pragma cplusplus on
#include "alloc_guard.h"
struct VObj_36DF0 { virtual void Destroy(int f); };
typedef struct PtrVec_36DF0 { int unk0; int count; } PtrVec_36DF0;
typedef struct Guard_36DF0 { char d[0x10]; } Guard_36DF0;

typedef struct World_36DF0 {
    void* vt;
    char pad4[0x2C - 0x4];
    char m2C[0x3C - 0x2C];
    char m3C[0x54 - 0x3C];
    char m54[0x70 - 0x54];
    char m70[0x80 - 0x70];
    VObj_36DF0* p80;
    void* p84;
    void* p88;
    void* p8C;
    PtrVec_36DF0* objs;
    char pad94[0x9C - 0x94];
    char m9C[0xC4 - 0x9C];
    char mC4[0xDC - 0xC4];
    void* pDC;
    void* pE0;
    void* pE4;
    void* pE8;
    void* pEC;
    char padF0[0x1C8 - 0xF0];
    void* p1C8[4];
    char pad1D8[0x1E0 - 0x1D8];
    void* p1E0;
} World_36DF0;

extern "C" {
void EnableIntc(int id);
extern char D_0049A890[];
extern char D_004D9060[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
VObj_36DF0** std_vector_cNodePtr_opIndex(PtrVec_36DF0* v, int i);
void cHud_dtor(void* p, int f);
void cVisionFxMan_dtor(void* p, int f);
void cWaterFx_dtor(void* p, int f);
void cDecalMan_dtor(void* p, int f);
void cLoader_DeallocateAllAnimationBuffers(void* p);
#if 0 /* merge_units */
void cTimerDisable_ctor(Guard_36DF0* g);
#endif /* merge_units */
#define cTimerDisable_ctor(a0) ((void)cTimerDisable_ctor((void *)(a0))) /* merge_units */

void cEnvMan_dtor(void* p, int f);
void cTimerDisable_dtor(Guard_36DF0* g, int f);
void cTremorManager_dtor(void* p, int f);
void cWeaponDB_dtor(void* p, int f);
void cAgentData_dtor(void* p, int f);
void cGameSystem_ClearNodeList(World_36DF0* w);
void cGameSystem_ClearNodeGroups(World_36DF0* w);
void cGameSystem_DestroyAnimationSets(World_36DF0* w);
void cGameSystem_DestroySkeletons(World_36DF0* w);
void cGameSystem_DestroyPlayerCameraAndScene(World_36DF0* w);
void std_list_cCAMERA_GOBJPtr_dtor(void* p, int f);
void std_list_cGOBJPtr_dtor(void* p, int f);
void std_map_cString_cSkaAnimationSetPtr_dtor(void* p, int f);
void String_Dtor(void* p, int f);
void cLList_cHogFile_dtor(void* p, int f);
void std_vector_tVUMNamePairPtr_dtor(void* p, int f);
void cSystemContainer_dtor(World_36DF0* w, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}

/* allocator lock taken without a guard object (no stack slot) */
#define LOCKC_36DF0() { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; }
#define UNLOCKC_36DF0() { if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
#define DELETE_36DF0(p, dtor, line) \
    { void* q = (p); if (q) { LOCKC_36DF0() dtor(q, -1); cMemMan_Deallocate(0, q, D_0049A890, line); UNLOCKC_36DF0() } }

extern "C" World_36DF0* cGameSystem_dtor(World_36DF0* self, short del)
{
    if (self) {
        self->vt = D_004D9060;
        DELETE_36DF0(self->pDC, cHud_dtor, 0xCA)
        DELETE_36DF0(self->pE0, cVisionFxMan_dtor, 0xCD)
        DELETE_36DF0(self->pE4, cWaterFx_dtor, 0xCF)
        {
            void* q = self->pE8;
            if (q) { AllocGuard g; cMemMan_Deallocate(0, q, D_0049A890, 0xD1); }
        }
        DELETE_36DF0(self->pEC, cDecalMan_dtor, 0xD3)
        if (self->objs) {
            int i;
            for (i = self->objs->count - 1; i >= 0; i--) {
                VObj_36DF0* q = *std_vector_cNodePtr_opIndex(self->objs, i);
                AllocGuard g;
                q->Destroy(-1);
                cMemMan_Deallocate(0, q, D_0049A890, 0xD7);
            }
        }
        {
            VObj_36DF0* q = self->p80;
            AllocGuard g;
            q->Destroy(-1);
            cMemMan_Deallocate(0, q, D_0049A890, 0xD9);
        }
        {
            void* q = self->p88;
            AllocGuard g;
            if (q) cLoader_DeallocateAllAnimationBuffers(q);
            cMemMan_Deallocate(0, q, D_0049A890, 0xDA);
        }
        {
            /* this block's allocator guard was not inlined: explicit calls to its out-of-line ctor/dtor */
            Guard_36DF0 g;
            void* q = self->p84;
            cTimerDisable_ctor(&g);
            cEnvMan_dtor(q, -1);
            cMemMan_Deallocate(0, q, D_0049A890, 0xDB);
            cTimerDisable_dtor(&g, -1);
        }
        DELETE_36DF0(self->p8C, cTremorManager_dtor, 0xDE)
        {
            void* q = self->p1E0;
            AllocGuard g;
            cWeaponDB_dtor(q, -1);
            cMemMan_Deallocate(0, q, D_0049A890, 0xE0);
        }
        int i;
        void** pp;
        for (i = 0, pp = (void**)self; i < 4; i++, pp++) {
            void* q = pp[0x1C8 / 4]; /* self->p1C8[i] */
            if (q) {
                AllocGuard g;
                cAgentData_dtor(q, -1);
                cMemMan_Deallocate(0, q, D_0049A890, 0xE4);
            }
        }
        cGameSystem_ClearNodeList(self);
        cGameSystem_ClearNodeGroups(self);
        cGameSystem_DestroyAnimationSets(self);
        cGameSystem_DestroySkeletons(self);
        cGameSystem_DestroyPlayerCameraAndScene(self);
        /* member destructors (the null tests are the compiler's this-checks) */
        if (self->mC4) std_list_cCAMERA_GOBJPtr_dtor(self->mC4, 0);
        if (self->m9C) std_list_cGOBJPtr_dtor(self->m9C, 0);
        if (self->m70) std_map_cString_cSkaAnimationSetPtr_dtor(self->m70, -1);
        if (self->m54) String_Dtor(self->m54, 0);
        if (self->m3C) cLList_cHogFile_dtor(self->m3C, -1);
        if (self->m2C) std_vector_tVUMNamePairPtr_dtor(self->m2C, -1);
        cSystemContainer_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef cTimerDisable_ctor /* merge_units */
#undef operator_delete /* merge_units */
static inline void merge_flush_func_00136DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136DF0 */
