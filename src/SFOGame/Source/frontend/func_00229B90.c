#include "types.h"
#include "frontend.h"
#pragma opt_common_subs off
extern char D_004A62C8[]; /* "FEMALE.SKEL" */
extern char D_004A62D8[]; /* "MALE.SKEL" */
extern char D_004A62E8[]; /* "" (end of list) */
extern char g_dataRoot[];
extern char FrontEndScene_skelHogFmt[];
extern char g_skelManager[];
extern int sprintf(char* buf, const char* fmt, ...);
extern int cHogList_OpenProtected(void* archives, char* path, int b);
extern int cSkeletonDataBank_AddSkeletonData_charP_cHogFileR(int* out, void* skelManager, char* name, int hog);

/* Opens COMMON\SKEL.HOG into `archives` and loads the female and male skeletons
 * from it (the front end's copy of cLoader_LoadSkeletons). */
void cFrontendSystem_LoadSkeletons(FrontEndScene* self, void* archives) {
    char path[128];
    char* names[3] = { D_004A62C8, D_004A62D8, D_004A62E8 };
    int skel;
    int hog;
    char** name;
    sprintf(path, FrontEndScene_skelHogFmt, g_dataRoot);
    hog = cHogList_OpenProtected(archives, path, 0);
    for (name = names; **name != 0; name++) {
        cSkeletonDataBank_AddSkeletonData_charP_cHogFileR(&skel, g_skelManager, *name, hog);
    }
}
