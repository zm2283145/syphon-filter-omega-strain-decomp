#include "types.h"

typedef struct { char pad[0xC]; unsigned char enabled; } Part;
typedef struct {
    void* vtable;
    char pad[0x98];
    Part a;
    char padA[0xAC - 0x9C - sizeof(Part)];
    Part b;
    char padB[0xC4 - 0xAC - sizeof(Part)];
    Part c;
    char padC[0x134 - 0xC4 - sizeof(Part)];
    float scale;
} Obj;
extern char D_004DC190[];
extern void cGOBJ_ctor(Obj* self, int* id, int a2, int a3);
extern void func_0023F660(Part* p);
extern void func_0023F640(Part* p);
extern void func_0023F620(Part* p);

/* Constructor: base GOBJ init, then three enabled parts and unit scale. */
Obj* func_0023F350(Obj* self, int a2, int a3)
{
    Part* pa;
    Part* pb;
    Part* pc;
    int id = -1;
    cGOBJ_ctor(self, &id, a2, a3);
    self->vtable = D_004DC190;
    pa = &self->a;
    func_0023F660(pa);
    pa->enabled = 1;
    pb = &self->b;
    func_0023F640(pb);
    pb->enabled = 1;
    pc = &self->c;
    func_0023F620(pc);
    pc->enabled = 1;
    self->scale = 1.0f;
    return self;
}
