/*
 * SFOGame/Source/game: 6 files, 001368D0-00136CD0
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
extern "C" { extern char D_0049A890[]; void func_00139EE0(void* p, short f); void cMemMan_Deallocate(int pool, void* p, const char* file, int line); }
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
static inline void merge_flush_func_00136BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136BD0 */

/* merge_units: begin func_00136CD0 */
#pragma push /* merge_units */
typedef struct { int unk0; } Guard;
typedef struct { char pad[0x90]; void* resource; } Holder90;
extern void cTimerDisable_ctor(Guard* g);
extern void cArray_cNodePtr_dtor(void* resource, int flags);
#if 0 /* merge_units */
extern void cMemMan_Deallocate(void* a0, void* p, const char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((int)(a0), (a1), (a2), (a3))) /* merge_units */

extern void cTimerDisable_dtor(Guard* g, int flags);

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
#undef cMemMan_Deallocate /* merge_units */
static inline void merge_flush_func_00136CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136CD0 */
