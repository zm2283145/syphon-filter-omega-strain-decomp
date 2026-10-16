#include "types.h"
typedef struct { char pad[0x24]; void* a; void* c; char pad2[0xC]; void* b; } Obj271B;
extern void IeElement_SetShown(void* p, int v);
void LoadingScreen_DrawHostText(Obj271B* s, int v) {
    if (s->a) IeElement_SetShown(s->a, v);
    if (s->b) IeElement_SetShown(s->b, v);
    if (s->c) IeElement_SetShown(s->c, 0);
}