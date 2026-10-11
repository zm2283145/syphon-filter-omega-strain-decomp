#include "types.h"
typedef struct { char pad[0x30]; void* owner; } S2D3040;
typedef struct { char pad[0xC]; int arg; } A2D3040;
extern int NetEvent_Send(void* owner, int id, int kind, int arg, int a4, int a5, int a6);
void func_002D3040(S2D3040* s, A2D3040* a, unsigned char c, float f)
{
    NetEvent_Send(s->owner, 0x1E, 8, a->arg, (int)f, c, 0);
}