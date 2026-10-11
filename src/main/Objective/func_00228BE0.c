#include "types.h"
typedef struct { char pad[0x28]; char total; char count; } Obj00228BE0;
extern void* ObjMan_GetService(void);
extern void Objective_Succeed(void* man, Obj00228BE0* obj, int flag);
void func_00228BE0(Obj00228BE0* self, char n)
{
    self->count = n;
    if (!(self->count < self->total))
        Objective_Succeed(ObjMan_GetService(), self, 0);
}