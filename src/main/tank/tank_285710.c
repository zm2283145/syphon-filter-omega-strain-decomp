/*
 * main/tank: range (4 files, 00285710-00285C00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00285710 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Gun285710 { VPAD32(a) VPAD16(b) VPAD16(c) VPAD2(d) VPAD1(e) virtual void Fire(); virtual void Arm(int on); };
struct Sub285710 { Gun285710* gun; };
struct Tank285710 { char p[0x60]; Gun285710* turret; char p64[8]; Sub285710* sub; };
struct Msg285710 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; float f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void func_0023E3D0(Gun285710*);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth285710(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_00285710(Tank285710* self, float v) {
    Gun285710* t = self->turret;
    func_0023E3D0(t);
    t->Fire();
    if (self->sub) self->sub->gun->Arm(1);
    if (D_005721C8 && IsAuth285710()) {
        Msg285710 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = 0;
m.b24 = 1;
m.f2C = v;
m.b20 = 4;
m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285710 */

/* merge_units: begin func_00285810 */
#pragma push /* merge_units */
#pragma cplusplus on
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285810 */

/* merge_units: begin func_00285AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(...);                      
extern char D_004A93D0;
extern unsigned char D_00533880;
}
typedef struct { char p0[104]; int f68; } PS0_00285AA0;
extern "C" void func_00285AA0(PS0_00285AA0 *arg0, int arg1, char * arg2) {
    char * temp_s0;
    char * temp_s0_2;

    temp_s0 = (char *)(arg0->f68);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s0, &D_004A93D0, 0x1F9);
        }
    }
    {
        AllocGuard g;
    temp_s0_2 = Mem_Alloc(0, 0x2C, &D_004A93D0, 0x1FB);
    }
    if (temp_s0_2 != NULL) {
        F_(temp_s0_2, 0x4, int) = (int)(arg2);
        F_(temp_s0_2, 0x0, int) = arg1;
        F_(temp_s0_2, 0x24, float) = F_(F_(temp_s0_2, 0x4, char *), 0x144, float);
        F_(temp_s0_2, 0x28, signed char) = 0;
    }
    arg0->f68 = (int)(temp_s0_2);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285AA0 */

/* merge_units: begin func_00285C00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
}
typedef struct { char p0[100]; int f64; } PS0_00285C00;
extern "C" void func_00285C00(PS0_00285C00 *arg0, int arg1, char * arg2) {
    char * temp_s0;
    char * temp_s0_2;

    temp_s0 = (char *)(arg0->f64);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s0, &D_004A93D0, 0x1F1);
        }
    }
    {
        AllocGuard g;
    temp_s0_2 = Mem_Alloc(0, 0x2C, &D_004A93D0, 0x1F3);
    }
    if (temp_s0_2 != NULL) {
        F_(temp_s0_2, 0x4, int) = (int)(arg2);
        F_(temp_s0_2, 0x0, int) = arg1;
        F_(temp_s0_2, 0x24, float) = F_(F_(temp_s0_2, 0x4, char *), 0x144, float);
        F_(temp_s0_2, 0x28, signed char) = 0;
    }
    arg0->f64 = (int)(temp_s0_2);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00285C00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00285C00 */
