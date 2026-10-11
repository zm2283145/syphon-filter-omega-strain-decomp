#include "types.h"
typedef struct { char pad[0xC]; int id; char pad10[0x80]; int mode; } T_0460;
typedef struct { char pad[0xC]; int id; } O_0460;
typedef struct { char pad[0x30]; O_0460* obj; } S_0460;
extern void* D_004FFBD0;
extern char D_004EE6E0[];
extern unsigned char D_005721C8;
T_0460* func_00170E20(void* mgr, O_0460* obj, int a, int b);
void func_00170500(void* list, T_0460** pt);
void NetEvent_Send(O_0460* obj, int type, int size, int a, int b, int c, int d);
T_0460* Global_MakeNPCInteractable(S_0460* self)
{
    T_0460* t = func_00170E20(D_004FFBD0, self->obj, 1, 0);
    t->mode = 3;
    func_00170500(D_004EE6E0, &t);
    if (D_005721C8)
        NetEvent_Send(self->obj, 0x2A, 4, self->obj->id, t->id, 0, 0);
    return t;
}