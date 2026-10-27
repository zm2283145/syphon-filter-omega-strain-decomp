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
extern void std_vector_cNIEventBasePtr_ctor(Part* p);
extern void std_vector_VectorKey_ctor(Part* p);
extern void std_vector_VisKey_ctor(Part* p);

/* Constructor: base GOBJ init, then three enabled parts and unit scale. */
Obj* cNIEventBase_ctor(Obj* self, int a2, int a3)
{
    Part* pa;
    Part* pb;
    Part* pc;
    int id = -1;
    cGOBJ_ctor(self, &id, a2, a3);
    self->vtable = D_004DC190;
    pa = &self->a;
    std_vector_cNIEventBasePtr_ctor(pa);
    pa->enabled = 1;
    pb = &self->b;
    std_vector_VectorKey_ctor(pb);
    pb->enabled = 1;
    pc = &self->c;
    std_vector_VisKey_ctor(pc);
    pc->enabled = 1;
    self->scale = 1.0f;
    return self;
}
