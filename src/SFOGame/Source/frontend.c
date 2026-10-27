/*
 * SFOGame/Source/frontend: 1 file, 00229B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00229B40 */
#pragma push /* merge_units */
#include "types.h"
#include "frontend.h"

extern char g_skelManager[];
char FrontEndScene_skelHogFmt[] = "%s\\COMMON\\SKEL.HOG";
extern char g_dataRoot[];
extern void cSkeletonDataBank_Clear(void* skelManager);
extern void sprintf(char* buf, const char* fmt, const char* arg);
extern void cHogList_Close(void* archives, const char* name);

/* Frees every loaded skeleton and closes COMMON\SKEL.HOG again (undoes cFrontendSystem_LoadSkeletons). */
void cFrontendSystem_DestroySkeletons(FrontEndScene* self, void* archives) {
    char path[128];
    cSkeletonDataBank_Clear(g_skelManager);
    sprintf(path, FrontEndScene_skelHogFmt, g_dataRoot);
    cHogList_Close(archives, path);
}
static inline void merge_flush_func_00229B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00229B40 */
