#include "types.h"
typedef struct { char pad[0x24]; void* a; void* c; char pad2[0xC]; void* b; } Obj271B;
extern void func_003E8DE0(void* p, int v);
void LoadingScreen_DrawHostText(Obj271B* s, int v) {
    if (s->a) func_003E8DE0(s->a, v);
    if (s->b) func_003E8DE0(s->b, v);
    if (s->c) func_003E8DE0(s->c, 0);
}