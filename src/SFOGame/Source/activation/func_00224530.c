#include "types.h"

extern signed char D_004F7530;
extern char D_004F7548[];
extern char D_004F7538[];
extern void std_list_deleter_voidPtr_ctor_void(void* obj);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void cGOBJActivationMan_dtor(void);

/* Returns the lazily constructed static collection. */
void* GetGOBJActivationMan(void) {
    if (!D_004F7530) {
        std_list_deleter_voidPtr_ctor_void(D_004F7548);
        __register_global_object(D_004F7548, cGOBJActivationMan_dtor, D_004F7538);
        D_004F7530 = 1;
    }
    return D_004F7548;
}
