#pragma opt_strength_reduction off
#include "types.h"

typedef struct { int* p; } It_173D60;
typedef struct { int pad; int size; int* data; } Vec_173D60;
typedef struct { char pad[0x204]; Vec_173D60 zones; } Zm_173D60;
typedef struct { char pad[0x4C]; int type; } Obj_173D60;

extern int D_004EE780;
extern void func_001740D0(It_173D60* out, Vec_173D60* v);
extern void func_001740B0(It_173D60* out, Vec_173D60* v);
extern int func_00174030(It_173D60* a, It_173D60* b);
extern int* func_001740A0(It_173D60* it);
extern int func_00174080(int* a, int* b);
extern void func_00174070(It_173D60* out, It_173D60* src);
extern void func_00174050(It_173D60* it);
extern int* func_00174010(Vec_173D60* v);
extern void func_00174000(It_173D60* out, Vec_173D60* v, int** p);
extern void KeyVector_Reserve(Vec_173D60* v, int n);
extern void KeyVector_PushBack(Vec_173D60* v, int* pos, int n, int* key);
extern Obj_173D60* Object_LookupById(int* id);

void ZoneMgr_Associate(Zm_173D60* self, char* zone, int recurse, char* other)
{
    int* key = (int*)(zone + 0xC);
    It_173D60 r1;
    It_173D60 r2;
    It_173D60 e;
    unsigned char ok;
    {
        It_173D60 it;
        It_173D60 end;
        func_001740D0(&it, &self->zones);
        func_001740B0(&end, &self->zones);
        while (func_00174030(&it, &end)) {
            if (func_00174080(func_001740A0(&it), key)) {
                func_00174070(&r1, &it);
                goto found1;
            }
            func_00174050(&it);
        }
        func_00174070(&r1, &end);
    found1:;
    }
    ok = 1;
    if (other && self != (Zm_173D60*)other) {
        It_173D60 it;
        It_173D60 end;
        int* key2 = (int*)(other + 0xC);
        func_001740D0(&it, &self->zones);
        func_001740B0(&end, &self->zones);
        while (func_00174030(&it, &end)) {
            if (func_00174080(func_001740A0(&it), key2)) {
                func_00174070(&r2, &it);
                goto found2;
            }
            func_00174050(&it);
        }
        func_00174070(&r2, &end);
    found2:
        ok = !(r2.p == self->zones.data + self->zones.size);
    }
    if (ok) {
        int* p = func_00174010(&self->zones);
        func_00174000(&e, &self->zones, &p);
        if (r1.p == e.p) {
            KeyVector_Reserve(&self->zones, self->zones.size + 1);
            KeyVector_PushBack(&self->zones, self->zones.data + self->zones.size, 1, key);
        }
    }
    if (recurse) {
        int i;
        for (i = 0; i < self->zones.size; i++) {
            Obj_173D60* o = Object_LookupById(&self->zones.data[i]);
            if (o && o != (Obj_173D60*)self && o->type == D_004EE780)
                ZoneMgr_Associate((Zm_173D60*)o, zone, 0, other);
        }
    }
}
#pragma opt_strength_reduction reset

