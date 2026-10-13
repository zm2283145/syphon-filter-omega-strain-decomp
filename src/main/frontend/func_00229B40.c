#include "types.h"
#include "frontend.h"

extern char g_skelManager[];
char FrontEndScene_skelHogFmt[] = "%s\\COMMON\\SKEL.HOG";
extern char g_dataRoot[];
extern void Skel_FreeAll(void* skelManager);
extern void sprintf(char* buf, const char* fmt, const char* arg);
extern void ArchiveList_CloseNamed(void* archives, const char* name);

/* Frees every loaded skeleton and closes COMMON\SKEL.HOG again (undoes FrontEndScene_LoadSkeletons). */
void FrontEndScene_UnloadSkeletons(FrontEndScene* self, void* archives) {
    char path[128];
    Skel_FreeAll(g_skelManager);
    sprintf(path, FrontEndScene_skelHogFmt, g_dataRoot);
    ArchiveList_CloseNamed(archives, path);
}
