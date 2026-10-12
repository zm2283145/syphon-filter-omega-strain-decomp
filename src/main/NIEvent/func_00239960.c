#include "types.h"
typedef struct { char pad[0xC]; float c; float d; float a; float b; } S239960;
extern void Blast_Prepare(int, int, int, int, int, int, float, float, float);
void func_00239960(S239960* s, int x)
{
    Blast_Prepare(x, (int)s->a, 1, 0, 0, 0, s->b, s->c, s->d);
}