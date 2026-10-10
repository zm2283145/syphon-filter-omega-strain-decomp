#include "types.h"
typedef struct { char pad[0x3C]; } G3E_00346180;
extern void func_001BECC0(G3E_00346180* p, int x);
void func_00346180(G3E_00346180* p, int n, int x) {
    for (; n != 0; n--) {
        func_001BECC0(p, x);
        p++;
    }
}