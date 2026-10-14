/*
 * main/game: range (3 files, 001368D0-00136A70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001368D0 */
#pragma push /* merge_units */
char D_0049AAF0[] = "%s\\COMMON\\PAR.HOG"; /* format */
extern char D_0048B2F8[];
extern char D_0053B540[];
extern void* Archive_Open(void* self, const char* text, int a2, int a3);
extern void func_00397B20(void* list, void* item);
extern void ArchiveList_CloseNamed(void* self, const char* text);
extern int* SpecFx_GetEffectDef(int index);
extern void func_0038B8B0(int slot, int value);

/* Sets up the title text and copies the four configured values into slots (1, 0, 2, 3). */
void Game_LoadParResources(void* self)
{
    char buf[0x80];
    sprintf(buf, D_0049AAF0, D_0048B2F8);
    func_00397B20(D_0053B540, Archive_Open(self, buf, 1, 0));
    ArchiveList_CloseNamed(self, buf);
    func_0038B8B0(1, *SpecFx_GetEffectDef(0));
    func_0038B8B0(0, *SpecFx_GetEffectDef(1));
    func_0038B8B0(2, *SpecFx_GetEffectDef(2));
    func_0038B8B0(3, *SpecFx_GetEffectDef(3));
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
extern char D_004FFC90[];
extern char D_00555070[]; /* script interpreter */
#if 0 /* merge_units */
extern void* Archive_Open(void* self, char* path, int a, int b);
#endif /* merge_units */
#define Archive_Open(a0, a1, a2, a3) (Archive_Open((a0), (void *)(a1), (a2), (a3))) /* merge_units */

extern void func_003E2140(void* interp, void* script);
extern void ScriptMgr_LoadScript(void* interp, const char* name, int a);
extern int cScriptInterpreter_CheckAllReferences(void* interp);
extern void cScriptInterpreter_ExecuteInitCode(void* interp);
extern void ScriptMgr_CallFunction(void* interp, const char* name, int a);

/* Loads and starts the arcade script, then loads the second resource. */
void IArcade_Init(void* self)
{
    char path[0x80];
    sprintf(path, D_0049AB30, D_0048B2F8);
    func_003E2140(D_00555070, Archive_Open(self, path, 0, 0));
    ScriptMgr_LoadScript(D_00555070, D_0049AB48, 0);
    cScriptInterpreter_CheckAllReferences(D_00555070);
    cScriptInterpreter_ExecuteInitCode(D_00555070);
    ScriptMgr_CallFunction(D_00555070, D_0049AB50, 0);
    sprintf(path, D_0049AB10, D_0048B2F8, D_004FFC90);
    Archive_Open(self, path, 0, 1);
}
#undef Archive_Open /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136990 */

/* merge_units: begin func_00136A70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int func_001457C0(int, int, int);

/* Forwards (a1, a2) to func_001457C0 on the object at +0x1E0; always returns 1. */
int func_00136A70(char* self, int a1, int a2) {
    func_001457C0(*(int*)(self + 0x1E0), a1, a2);
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136A70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136A70 */
