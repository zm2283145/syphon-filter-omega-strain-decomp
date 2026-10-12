#include "types.h"
int func_002824D0();
int cGOBJ_GetScriptTypeKeyPtr();
int func_003D8740();
int Script_ActivateBodyToss_2();
int Script_ActivateBodyToss();
int func_004768E0();
extern char D_00493878;
extern char D_00493880;
extern void* D_00588038;
extern char D_00588040;
extern int D_00588048;
extern int D_00588050;
extern int D_00588058;
void func_004D8C60(void) {
    D_00588038 = "cActivateBodyTossMsg";
    D_00588048 = func_002824D0(func_004768E0, &D_00588040, "cActivateBodyTossMsg");
    D_00588050 = func_003D8740(Script_ActivateBodyToss, &D_00493880, "ActivateBodyToss", 1, cGOBJ_GetScriptTypeKeyPtr());
    D_00588058 = func_003D8740(Script_ActivateBodyToss_2, &D_00493880, "ActivateBodyToss", 2, cGOBJ_GetScriptTypeKeyPtr(), &D_00493878);
}
