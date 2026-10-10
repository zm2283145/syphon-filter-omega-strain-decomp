#include "types.h"

extern char D_005721F0;   /* already-initialized flag / instance */
extern char D_005721E0[];
extern void* Loc_LookupText(void* storage);

/* Lazy singleton: returns the instance if set up, else initializes it. */
void* func_001692F0(void) {
    if (D_005721F0) {
        return &D_005721F0;
    }
    return Loc_LookupText(D_005721E0);
}
