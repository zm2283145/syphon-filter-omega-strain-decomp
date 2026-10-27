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
