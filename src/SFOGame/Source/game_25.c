/*
 * SFOGame/Source/game: 11 files, 001368D0-00137580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001368D0 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

char D_0049AAF0[] = "%s\\COMMON\\PAR.HOG"; /* format */
extern char D_0048B2F8[];
extern char D_0053B540[];
extern void* cHogList_Open(void* self, const char* text, int a2, int a3);
extern void cParticleSystem_LoadRequestedEffects(void* list, void* item);
extern void cHogList_Close(void* self, const char* text);
extern int* nSfxLoader_GetHandle(int index);
extern void cMan_SetBloodEffect(int slot, int value);

/* Sets up the title text and copies the four configured values into slots (1, 0, 2, 3). */
void LoadRequestedParticles(void* self)
{
    char buf[0x80];
    sprintf(buf, D_0049AAF0, D_0048B2F8);
    cParticleSystem_LoadRequestedEffects(D_0053B540, cHogList_Open(self, buf, 1, 0));
    cHogList_Close(self, buf);
    cMan_SetBloodEffect(1, *nSfxLoader_GetHandle(0));
    cMan_SetBloodEffect(0, *nSfxLoader_GetHandle(1));
    cMan_SetBloodEffect(2, *nSfxLoader_GetHandle(2));
    cMan_SetBloodEffect(3, *nSfxLoader_GetHandle(3));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001368D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001368D0 */

/* merge_units: begin func_00136990 */
#pragma push /* merge_units */
char D_0049AB10[] = "%s\\%s\\SCRIPTS.HOG";
char D_0049AB30[] = "%s\\COMMON\\IARCADEN.HOG";
char D_0049AB48[] = "iarcade";
char D_0049AB50[] = "iarcade::init";
extern char g_LevelDirName[];
extern char D_00555070[]; /* script interpreter */
#if 0 /* merge_units */
extern void* cHogList_Open(void* self, char* path, int a, int b);
#endif /* merge_units */
#define cHogList_Open(a0, a1, a2, a3) (cHogList_Open((a0), (const char *)(a1), (a2), (a3))) /* merge_units */




extern void cScriptInterpreter_SetHog(void* interp, void* script);
extern void cScriptInterpreter_LoadScript(void* interp, const char* name, int a);
extern int cScriptInterpreter_CheckAllReferences(void* interp);
extern void cScriptInterpreter_ExecuteInitCode(void* interp);
extern void cScriptInterpreter_CallFunction(void* interp, const char* name, int a);

/* Loads and starts the arcade script, then loads the second resource. */
void OpenScriptHog(void* self)
{
    char path[0x80];
    sprintf(path, D_0049AB30, D_0048B2F8);
    cScriptInterpreter_SetHog(D_00555070, cHogList_Open(self, path, 0, 0));
    cScriptInterpreter_LoadScript(D_00555070, D_0049AB48, 0);
    cScriptInterpreter_CheckAllReferences(D_00555070);
    cScriptInterpreter_ExecuteInitCode(D_00555070);
    cScriptInterpreter_CallFunction(D_00555070, D_0049AB50, 0);
    sprintf(path, D_0049AB10, D_0048B2F8, g_LevelDirName);
    cHogList_Open(self, path, 0, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136990(void) {}
#undef cHogList_Open /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136990 */

/* merge_units: begin func_00136A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int cWeaponDB_LoadLevelSpecific(int, int, int);

/* Forwards (a1, a2) to cWeaponDB_LoadLevelSpecific on the object at +0x1E0; always returns 1. */
int cGameSystem_LoadWeaponDB(char* self, int a1, int a2) {
    cWeaponDB_LoadLevelSpecific(*(int*)(self + 0x1E0), a1, a2);
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136A70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136A70 */

/* merge_units: begin func_00136A90 */
#pragma push /* merge_units */
typedef struct G1Ev G1Ev;
typedef struct {
    char pad[0x50]; char state; char prevState; char pad2[0xE8 - 0x52]; void* anim;
    char pad3[0x1C4 - 0xEC]; unsigned char f1C4; unsigned char f1C5; unsigned char f1C6;
} G1Ob;
extern int* cMessage_Name(G1Ev*);
extern int cSystemContainer_HandleMessage(G1Ob*, G1Ev*);
extern int cGameSystem_NextFrame(G1Ob*);
extern void cGameSystem_SendAgentData(G1Ob*, int, int);
extern void cScreenFader_StartFade(void*, int, float);
extern int D_005436B0;
extern int D_004F5398;
extern unsigned char g_IsMultiplayer;
int cGameSystem_HandleMessage(G1Ob* o, G1Ev* e)
{
    int t;
    int handled = (unsigned char)cSystemContainer_HandleMessage(o, e);
    t = *cMessage_Name(e);
    if (t == D_005436B0) {
        return cGameSystem_NextFrame(o) != 0 || handled != 0;
    }
    t = *cMessage_Name(e);
    if (t == D_004F5398) {
        if ((unsigned char)o->state != 0x13 && (unsigned char)o->state != 0x14) {
            if (g_IsMultiplayer) cGameSystem_SendAgentData(o, 0, 1);
            if (o->f1C4 && o->f1C5 && o->f1C6) {
                o->prevState = o->state;
                o->state = 0x14;
            } else {
                o->prevState = o->state;
                o->state = 0x13;
                cScreenFader_StartFade(o->anim, 2, 1.0f);
            }
            return 1;
        }
    }
    return handled;
}
static inline void merge_flush_func_00136A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136A90 */

/* merge_units: begin func_00136BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma opt_strength_reduction off
struct E_00136BD0 { int f0; int f4; int f8; int fC; };
struct L_00136BD0 { int f0; int n; E_00136BD0* arr; };
struct O_00136BD0 { char pad[0x98]; L_00136BD0* l; };
extern "C" { extern char D_0049A890[]; void func_00139EE0(void* p, short f); 
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, const char* file, int line);
#endif /* merge_units */
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line); /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */
}
extern "C" void cGameSystem_ClearNodeGroups(O_00136BD0* o)
{
    if (o->l) {
        int i;
        L_00136BD0* l;
        for (i = 0; i < o->l->n; i++) o->l->arr[i].f4 = 0;
        l = o->l;
        {
            AllocGuard g;
            if (l) { if (l) { if (l) func_00139EE0(l, 0); } }
            cMemMan_Deallocate(0, l, D_0049A890, 0x107);
        }
        o->l = 0;
    }
}
#pragma opt_strength_reduction reset
#undef cMemMan_Deallocate /* merge_units */
static inline void merge_flush_func_00136BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136BD0 */

/* merge_units: begin func_00136CD0 */
#pragma push /* merge_units */
typedef struct { int unk0; } Guard;
typedef struct { char pad[0x90]; void* resource; } Holder90;
#if 0 /* merge_units */
extern void cTimerDisable_ctor(Guard* g);
#endif /* merge_units */
void * cTimerDisable_ctor(); /* merge_units */


#if 0 /* merge_units */
extern void cArray_cNodePtr_dtor(void* resource, int flags);
#endif /* merge_units */
void* cArray_cNodePtr_dtor(void* self, short deleteFlag); /* merge_units */
#define cArray_cNodePtr_dtor(a0, a1) ((void)cArray_cNodePtr_dtor((a0), (short)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cMemMan_Deallocate(void* a0, void* p, const char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((int)(a0), (a1), (char *)(a2), (a3))) /* merge_units */



#if 0 /* merge_units */
extern void cTimerDisable_dtor(Guard* g, int flags);
#endif /* merge_units */
void cTimerDisable_dtor(void*, int); /* merge_units */
#define cTimerDisable_dtor(a0, a1) (cTimerDisable_dtor((void *)(a0), (a1))) /* merge_units */



/* Releases the held resource (destroy + free) under a guard and clears the pointer. */
void cGameSystem_ClearNodeList(Holder90* self)
{
    void* res = self->resource;
    if (res) {
        Guard g;
        cTimerDisable_ctor(&g);
        cArray_cNodePtr_dtor(res, -1);
        cMemMan_Deallocate(0, res, D_0049A890, 0xFA);
        cTimerDisable_dtor(&g, -1);
        self->resource = 0;
    }
}
#undef cArray_cNodePtr_dtor /* merge_units */
#undef cMemMan_Deallocate /* merge_units */
#undef cTimerDisable_dtor /* merge_units */
static inline void merge_flush_func_00136CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136CD0 */

/* merge_units: begin func_00136D40 */
#pragma push /* merge_units */
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
extern char D_004D9060[];
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */


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
#if 0 /* merge_units */
void cTimerDisable_dtor(Guard_36DF0* g, int f);
#endif /* merge_units */
#define cTimerDisable_dtor(a0, a1) (cTimerDisable_dtor((void *)(a0), (a1))) /* merge_units */


void cTremorManager_dtor(void* p, int f);
void cWeaponDB_dtor(void* p, int f);
void cAgentData_dtor(void* p, int f);
#if 0 /* merge_units */
void cGameSystem_ClearNodeList(World_36DF0* w);
#endif /* merge_units */
#define cGameSystem_ClearNodeList(a0) (cGameSystem_ClearNodeList((Holder90 *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cGameSystem_ClearNodeGroups(World_36DF0* w);
#endif /* merge_units */
#define cGameSystem_ClearNodeGroups(a0) (cGameSystem_ClearNodeGroups((O_00136BD0 *)(a0))) /* merge_units */


void cGameSystem_DestroyAnimationSets(World_36DF0* w);
void cGameSystem_DestroySkeletons(World_36DF0* w);
void cGameSystem_DestroyPlayerCameraAndScene(World_36DF0* w);
void std_list_cCAMERA_GOBJPtr_dtor(void* p, int f);
void std_list_cGOBJPtr_dtor(void* p, int f);
void std_map_cString_cSkaAnimationSetPtr_dtor(void* p, int f);
void String_Dtor(void* p, int f);
#if 0 /* merge_units */
void cLList_cHogFile_dtor(void* p, int f);
#endif /* merge_units */
void* cLList_cHogFile_dtor(void* self, short deleteFlag); /* merge_units */
#define cLList_cHogFile_dtor(a0, a1) ((void)cLList_cHogFile_dtor((a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_vector_tVUMNamePairPtr_dtor(void* p, int f);
#endif /* merge_units */
void* std_vector_tVUMNamePairPtr_dtor(void* self, short deleteFlag); /* merge_units */
#define std_vector_tVUMNamePairPtr_dtor(a0, a1) ((void)std_vector_tVUMNamePairPtr_dtor((a0), (short)(a1))) /* merge_units */

void cSystemContainer_dtor(World_36DF0* w, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */



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
#undef cMemMan_Deallocate /* merge_units */
#undef cTimerDisable_ctor /* merge_units */
#undef cTimerDisable_dtor /* merge_units */
#undef cGameSystem_ClearNodeList /* merge_units */
#undef cGameSystem_ClearNodeGroups /* merge_units */
#undef cLList_cHogFile_dtor /* merge_units */
#undef std_vector_tVUMNamePairPtr_dtor /* merge_units */
#undef operator_delete /* merge_units */
static inline void merge_flush_func_00136DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136DF0 */

/* merge_units: begin func_00137580 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop

#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_tVUMNamePairPtr_dtor)
static inline void merge_flush_func_00137580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137580 */

/* merge_units: begin func_00137670 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor around an out-of-line base destructor. */
DEFINE_NESTED_NULL_DTOR2(cLList_cHogFile_dtor, std_list_imp_cHogFile_dtor)
static inline void merge_flush_func_00137670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00137670 */
