#include "types.h"

typedef struct Settings2E {
    char pad00[0x2E];
    unsigned char altMode; /* 0x2E */
} Settings2E;

extern Settings2E* D_004FFC04;
extern char D_004A9CA0[];
extern char D_004A9CB8[];
extern char D_004A9CD0[];
extern char D_004A9CE8[];
extern void* func_00414790(void);
extern void* func_00418A80(void* lib, const char* a, const char* b);
extern void* func_004147A0(void);
extern void func_00414AC0(void* mgr, int arg, void* res);

/* Looks up the mode-dependent resource and hands it to the manager. */
void func_002928E0(int arg) {
    void* res;
    if (D_004FFC04->altMode) {
        res = func_00418A80(func_00414790(), D_004A9CA0, D_004A9CB8);
    } else {
        res = func_00418A80(func_00414790(), D_004A9CD0, D_004A9CE8);
    }
    func_00414AC0(func_004147A0(), arg, res);
}
