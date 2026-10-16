#pragma cplusplus on
#include "types.h"
extern "C" {
int func_002E9A10(...);
int func_002E9A98(...);
int func_002E9F08(...);
int func_003C9C30(...);
extern int D_0055D488;
extern char D_0055D490;
void func_003FF140();
}
extern "C" bool func_003FF210(void) {
    struct { int a[2]; char b; char c; } sl;
    bool ok = 0;
    if (func_002E9A10() == 0) {
        bool r = 0;
        if (func_003C9C30(sl.a) != 0 && func_002E9A98(sl.a, &sl.b, 1, 1) == 0 && func_002E9A98(sl.a, &sl.c, 1, 1) == 0) {
            r = 1;
            D_0055D488 = 0;
        }
        if (r && func_002E9F08(&D_0055D490, func_003FF140) == 0) ok = 1;
    }
    return ok;
}
