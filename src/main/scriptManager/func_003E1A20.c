#include "types.h"
extern unsigned char D_004938D0;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void ScriptMgr_CallFunction(void*, char*, int);
static inline int ok3E1(void) { return D_005721C8 ? D_005721C0 : 1; }
void func_003E1A20(void* s) {
    if (D_004938D0) {
        ScriptMgr_CallFunction(s, "init::ClientStartLevel", 0);
        if (!D_005721C8 || ok3E1()) ScriptMgr_CallFunction(s, "init::StartLevel", 0);
    }
}
