#pragma opt_strength_reduction off
#include "types.h"

typedef struct { int* p; } It_173D60;
typedef struct { int pad; int size; int* data; } Vec_173D60;
typedef struct { char pad[0x204]; Vec_173D60 zones; } Zm_173D60;
typedef struct { char pad[0x4C]; int type; } Obj_173D60;

extern int D_004EE780;
extern void cArray_cObjectId_Begin(It_173D60* out, Vec_173D60* v);
extern void cArray_cObjectId_End_void(It_173D60* out, Vec_173D60* v);
extern int cArray_cObjectId_Iterator_opNe(It_173D60* a, It_173D60* b);
extern int* cArray_cObjectId_Iterator_opMul(It_173D60* it);
extern int ObjectKey_Equals(int* a, int* b);
extern void cArray_cObjectId_Iterator_ctor(It_173D60* out, It_173D60* src);
extern void cArray_cObjectId_Iterator_opInc(It_173D60* it);
extern int* std_vector_imp_cObjectId_end(Vec_173D60* v);
extern void std_vector_cObjectId_pointer2iterator(It_173D60* out, Vec_173D60* v, int** p);
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
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (ObjectKey_Equals(cArray_cObjectId_Iterator_opMul(&it), key)) {
                cArray_cObjectId_Iterator_ctor(&r1, &it);
                goto found1;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r1, &end);
    found1:;
    }
    ok = 1;
    if (other && self != (Zm_173D60*)other) {
        It_173D60 it;
        It_173D60 end;
        int* key2 = (int*)(other + 0xC);
        cArray_cObjectId_Begin(&it, &self->zones);
        cArray_cObjectId_End_void(&end, &self->zones);
        while (cArray_cObjectId_Iterator_opNe(&it, &end)) {
            if (ObjectKey_Equals(cArray_cObjectId_Iterator_opMul(&it), key2)) {
                cArray_cObjectId_Iterator_ctor(&r2, &it);
                goto found2;
            }
            cArray_cObjectId_Iterator_opInc(&it);
        }
        cArray_cObjectId_Iterator_ctor(&r2, &end);
    found2:
        ok = !(r2.p == self->zones.data + self->zones.size);
    }
    if (ok) {
        int* p = std_vector_imp_cObjectId_end(&self->zones);
        std_vector_cObjectId_pointer2iterator(&e, &self->zones, &p);
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

