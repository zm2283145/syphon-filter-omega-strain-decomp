#include "types.h"
typedef struct { char pad[0x98]; int a[30]; } S22D380;
int func_0022D380(S22D380* s, int v) {
    int i;
    for (i = 0; i < 30; i++) {
        if (s->a[i] == v) return i;
    }
    return -1;
}