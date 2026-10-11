
#include "types.h"
extern unsigned char D_004938D0;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004BD8E0[];
extern char D_004BD900[];
extern void ScriptMgr_CallFunction(void*, char*, int);

static inline int Pt2_Ok(void) { return D_005721C8 ? D_005721C0 : 1; }
void func_003E1A20(void* mgr) {
    if (D_004938D0) {
        ScriptMgr_CallFunction(mgr, D_004BD8E0, 0);
        if (!D_005721C8 || Pt2_Ok()) ScriptMgr_CallFunction(mgr, D_004BD900, 0);
    }
}
