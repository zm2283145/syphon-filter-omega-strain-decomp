#include "types.h"

extern void* func_003EEB30(void* obj);
extern int func_003EF010(void* p);

/* Resolves obj via func_003EEB30 and forwards to func_003EF010 (0 if none). */
int func_002535E0(void* obj) {
    void* p = func_003EEB30(obj);
    if (p) {
        return func_003EF010(p);
    }
    return 0;
}
