#include "types.h"
int Net_ResetSession(void);
int func_002EA4F0(void*, void*);
extern int D_00572270[4][20];
extern signed char D_00572418[4];
extern char func_002CAA70;
extern char sfo_malloc_2CA9B0;
unsigned char func_0042B000(void) {
    int i;
    int j;
    int r;
    unsigned char ok;
    for (i = 0; i < 4; i++) {
        D_00572418[i] = 0;
        { int* p = D_00572270[i]; for (j = 0; j < 20; j++) p[j] = 0; }
    }
    ok = 0;
    r = func_002EA4F0(&func_002CAA70, &sfo_malloc_2CA9B0);
    Net_ResetSession();
    if (r == 0) ok = 1;
    return ok;
}