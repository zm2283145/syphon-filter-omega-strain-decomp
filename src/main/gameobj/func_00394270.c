#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

class Owner394270 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};

struct OwnerData394270 {
    void* vt;
    char p4[0xC];
    char pos[0x40];
    unsigned char dirty;
};

struct Tracer394270 {
    char p[0x50];
    float width;
};

struct Self394270 {
    char p0[0x50];
    OwnerData394270* owner;
    char p54[0xC];
    int id;
    Tracer394270* tracer;
    char p68[4];
    float width;
};

extern "C" {
extern char D_004BC430[];
void* Mem_Alloc(int pool, int size, char* file, int line);
Tracer394270* Tracer_Create(void* p, int id, void* pos, float scale);
void Object_Activate(Self394270* self, int arg);
}

extern "C" void func_00394270(Self394270* self, int arg)
{
    if (self->id != -1 && self->tracer == 0) {
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0x70, D_004BC430, 0x273);
        }
        if (p) {
            OwnerData394270* o = self->owner;
            if (o->dirty) ((Owner394270*)o)->Update();
            p = Tracer_Create(p, self->id, o->pos, 1.0f);
        }
        self->tracer = (Tracer394270*)p;
        if (self->tracer) self->tracer->width = self->width;
    }
    Object_Activate(self, arg);
}
