#include "types.h"
typedef struct { char pad[0x2E4]; int pending; int a; int b; } Q255;
int func_00255860(Q255* s, int* a, int* b) {
    if (s->pending) {
        s->pending--;
        *a = s->a;
        *b = s->b;
        return 1;
    }
    *a = 0;
    *b = 0;
    return 0;
}