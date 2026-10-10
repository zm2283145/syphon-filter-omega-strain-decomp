#include "types.h"

extern void func_003B5300(void* tmp);
extern void func_0013BCB0(void* self, void* tmp);
extern void func_00138B70(void* tmp, int flag);

/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int func_003B52B0(void* self) {
    char tmp[16];
    func_003B5300(tmp);
    func_0013BCB0(self, tmp);
    func_00138B70(tmp, -1);
    return 0;
}
