#include "types.h"
typedef struct { char a; char pad[7]; int n; char* p; } B3_336D40;
void func_00336D40(B3_336D40* s)
{
    int i;
    s->a = 0;
    for (i = 0; i < s->n; i++) {
        s->p[i] = 0;
    }
}