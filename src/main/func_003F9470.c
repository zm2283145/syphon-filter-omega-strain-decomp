#include "types.h"
typedef struct { char pad[0x14C]; unsigned char active; } O9470;
typedef struct N9470 { int m0; struct N9470* next; O9470 obj; char pad[0x170 - 0x8 - sizeof(O9470)]; unsigned char keep; } N9470;
typedef struct { int m0; int list; } T9470;
extern N9470* func_003F9520(void* list);
extern void Hog_Unload(O9470* o);
extern void func_003F9A30(N9470** out, T9470* self, N9470** pos);
void func_003F9470(T9470* self)
{
    N9470* end;
    N9470* n = func_003F9520(&self->list)->next;
    end = func_003F9520(&self->list);
    while (n != end) {
        O9470* o = &n->obj;
        if (!n->keep || !o->active) {
            N9470* r;
            N9470* pos;
            if (o->active)
                Hog_Unload(o);
            pos = n;
            func_003F9A30(&r, self, &pos);
            n = r;
        } else {
            n = n->next;
        }
    }
}