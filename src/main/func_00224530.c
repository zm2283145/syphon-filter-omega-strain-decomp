#include "types.h"

extern signed char D_004F7530;
extern char D_004F7548[];
extern char D_004F7538[];
extern void ScalarCollection_Init(void* obj);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void func_00224590(void);

/* Returns the lazily constructed static collection. */
void* func_00224530(void) {
    if (!D_004F7530) {
        ScalarCollection_Init(D_004F7548);
        __register_global_object(D_004F7548, func_00224590, D_004F7538);
        D_004F7530 = 1;
    }
    return D_004F7548;
}
