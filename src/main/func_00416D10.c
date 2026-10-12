#include "types.h"

typedef struct E_416D10 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_416D10;
typedef struct O_416D10 { char pad[0x24]; void* inst; char pad28[0x58]; E_416D10* cur; } O_416D10;

extern E_416D10* func_00416E40(O_416D10* o, char* name);
extern void func_003F45A0(void* i, float t);
extern void func_003F44E0(void* i, float t);
extern void func_003F4510(void* i, float a, float b, int f);

int func_00416D10(O_416D10* o, char* name)
{
    E_416D10* e;
    if (o->inst == 0) return 0;
    e = func_00416E40(o, name);
    if (e != 0) {
    switch (e->kind) {
    case 1:
        func_003F45A0(o->inst, e->x);
        func_003F44E0(o->inst, e->y);
        break;
    case 2:
        func_003F45A0(o->inst, e->x);
        func_003F4510(o->inst, e->x, e->y, 1);
        break;
    case 3:
        func_003F45A0(o->inst, e->x);
        func_003F4510(o->inst, e->x, e->y, 0);
        break;
    }
    o->cur = e;
    return 1;
    }
    return 0;
}

