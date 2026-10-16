#include "types.h"

typedef struct E_416D10 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_416D10;
typedef struct O_416D10 { char pad[0x24]; void* inst; char pad28[0x58]; E_416D10* cur; } O_416D10;

extern E_416D10* GuiInterfaceDecorator_FindEvent(O_416D10* o, char* name);
extern void IeElement_EvaluateAt(void* i, float t);
extern void IeElement_Fade(void* i, float t);
extern void IeElement_PlayRange(void* i, float a, float b, int f);

int GuiInterfaceDecorator_FireEvent(O_416D10* o, char* name)
{
    E_416D10* e;
    if (o->inst == 0) return 0;
    e = GuiInterfaceDecorator_FindEvent(o, name);
    if (e != 0) {
    switch (e->kind) {
    case 1:
        IeElement_EvaluateAt(o->inst, e->x);
        IeElement_Fade(o->inst, e->y);
        break;
    case 2:
        IeElement_EvaluateAt(o->inst, e->x);
        IeElement_PlayRange(o->inst, e->x, e->y, 1);
        break;
    case 3:
        IeElement_EvaluateAt(o->inst, e->x);
        IeElement_PlayRange(o->inst, e->x, e->y, 0);
        break;
    }
    o->cur = e;
    return 1;
    }
    return 0;
}

