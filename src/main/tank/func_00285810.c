#pragma cplusplus on
#include "types.h"
extern "C" {

typedef struct { char pad[0x14]; float x; float y; } Tgt_285810;
typedef struct { Tgt_285810* obj; float x; float y; } Elem_285810;
typedef struct { char pad[0x144]; float t; } Clock_285810;
typedef struct {
    int pad0;
    Clock_285810* clock;
    Elem_285810 e[2];
    int count;
    float last;
} Part_285810;
typedef struct { char pad[0xC]; int id; } Target_285810;
typedef struct { char pad[0xA4]; float f; } Aux_285810;
typedef struct {
    char pad0[0x10];
    float cooldown;
    char pad14[0x40];
    unsigned char busy;
    char pad55[7];
    Target_285810* target;
    int targetId;
    char pad64[4];
    Aux_285810* aux;
} Turret_285810;
typedef struct {
    char pad0[0x64];
    Part_285810* a;
    Part_285810* b;
    Turret_285810* turret;
    unsigned char armed;
    char pad71[3];
    float timer;
} Tank_285810;

extern float D_0048B3D0;
extern float D_0048B3D8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char func_00286990(Turret_285810* t, float dt);
extern void func_00286690(Turret_285810* t, Target_285810* tgt, unsigned char valid, unsigned char r);
extern int func_00287710(Turret_285810* t);
extern void func_00285590(Tank_285810* self, int v);
extern int func_00287AB0(Part_285810* p);

}
static inline bool Null_285810(void* p) { return !p; }
static inline bool NotNull_285810(void* p) { return p != 0; }
static inline int Flag_285810(void) { return D_005721C8 ? D_005721C0 : 1; }

static inline int Valid_285810(Target_285810* tgt, Turret_285810* t) { if (tgt == 0) return 1; if (tgt->id == t->targetId) return 1; return 0; }
static inline void Part_Update_285810(Part_285810* p)
{
    if (p && func_00287AB0(p)) {
        int i;
        float d;
        float v;
        v = p->clock->t;
        d = v - p->last;
        p->last = v;
        d *= D_0048B3D0;
        for (i = 0; i < p->count; i++) {
            Tgt_285810* o = p->e[i].obj;
            float x = d * p->e[i].x;
            float y = d * p->e[i].y;
            o->x = x;
            o->y = y;
        }
    }
}

extern "C" void cTank_v10(Tank_285810* self, float dt)
{
    Turret_285810* t = self->turret;
    if (t) {
        Target_285810* tgt;
        unsigned char r;
        unsigned char valid;
        if (!(t->cooldown <= 0.0f)) t->cooldown -= dt;
        r = func_00286990(t, dt);
        tgt = t->target;
        valid = 1;
        if (!Null_285810(tgt) && tgt->id != t->targetId) valid = 0;
        tgt = valid ? tgt : 0;
        if (tgt && !t->busy && r && t->cooldown <= 0.0f) {
            if (!D_005721C8 || Flag_285810() || !(t->aux->f <= 1.0f))
                func_00286690(t, tgt, valid, r);
        }
        if (!(self->timer <= 0.0f)) {
            self->timer -= dt;
        } else if (self->armed) {
            self->timer = D_0048B3D8;
            func_00285590(self, func_00287710(self->turret));
            self->armed = 1;
        }
    }
    Part_Update_285810(self->a);
    Part_Update_285810(self->b);
}







