#include "types.h"

extern signed char D_005721F0;
extern int D_005721E0;
extern int Loc_LookupText(void*);

/* Returns Loc_LookupText(&D_005721E0) when the D_005721F0 flag is set, else 0. */
int func_00169330(void) {
    int r = D_005721F0;
    if (r != 0) r = Loc_LookupText(&D_005721E0);
    else r = 0;
    return r;
}
