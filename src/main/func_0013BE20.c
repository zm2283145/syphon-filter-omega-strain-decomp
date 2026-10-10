#include "types.h"

extern signed char D_004EA0D0;
extern char D_004EA0F0[];
extern char D_004EA0D8[];
extern void func_0013C250(void* obj, void* a, void* b);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void func_0013BF00(void);

/* Returns the lazily constructed static container. */
void* func_0013BE20(void) {
    int tagB;
    int tagA;
    if (!D_004EA0D0) {
        func_0013C250(D_004EA0F0, &tagA, &tagB);
        __register_global_object(D_004EA0F0, func_0013BF00, D_004EA0D8);
        D_004EA0D0 = 1;
    }
    return D_004EA0F0;
}
