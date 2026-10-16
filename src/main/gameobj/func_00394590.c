#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

class OwnerV394590 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};

class SelfV394590 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Kill(int arg);
    virtual int IsDone();
};

struct Owner394590 {
    void* vt;
    char p4[0xC];
    char pos[0x40];
    unsigned char dirty;
};

struct Tracer394590 {
    char p0[0x1C];
    int active;
};

struct Self394590 {
    void* vt;
    char p4[8];
    unsigned int type;
    char p10[0x40];
    Owner394590* owner;
    char p54[0x10];
    Tracer394590* tracer;
    char p68[4];
    float age;
};

extern "C" {
extern char D_004BC430[];
void Mem_Free(int pool, void* p, char* file, int line);
void ParticleInst_Kill(Tracer394590* t, int flag);
void ParticleInst_Update(Tracer394590* t, void* pos, int z, float dt);
void Object_Unregister(Self394590* self);
void Object_DeleteLater(Self394590* self, float t);
}

extern "C" void cPARTICLE_GOBJ_v10(Self394590* self, float dt)
{
    if (self->tracer) {
        if (self->tracer->active) {
            Owner394590* o = self->owner;
            if (o->dirty) ((OwnerV394590*)o)->Update();
            ParticleInst_Update(self->tracer, o->pos, 0, dt);
        } else if (((SelfV394590*)self)->IsDone()) {
            ((SelfV394590*)self)->Kill(-1);
            if (((self->type & 0xFF0000) >> 16) == 0xE7) {
                Object_Unregister(self);
                Object_DeleteLater(self, 0.1f);
                Tracer394590* t = self->tracer;
                if (t) {
                    {
                        AllocGuard g;
                        ParticleInst_Kill(t, -1);
                        Mem_Free(0, t, D_004BC430, 0x23A);
                    }
                    self->tracer = 0;
                }
            }
        }
        self->age += dt;
    }
}
