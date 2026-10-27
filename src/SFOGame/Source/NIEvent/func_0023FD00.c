#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
struct VObj_23FD00 { virtual void Destroy(int f); };
struct Obj_23FD00 {
    void* vt;
    char pad04[0x98];
    char m9C[0x10];
    char mAC[0x18];
    char mC4[0x7C];
    VObj_23FD00* obj;
    char m144[0x20];
    char m164[0x20];
    char m184[0x20];
    char m1A4[0x10];
};
extern "C" {
extern char cNIEventOBJ_vtable[];
extern char D_004DC190[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cNIEventFXTrack_dtor(void* p, int f);
void std_vector_deleter_FloatKey_dtor(void* p, int f);
void cArray_VisKey_dtor(void* p, int f);
void cArray_VectorKey_dtor(void* p, int f);
void cArray_cNIEventBasePtr_dtor(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void L4_23FD00(void* p) { if (p) std_vector_deleter_FloatKey_dtor(p, 0); }
static inline void L3_23FD00(void* p) { if (p) L4_23FD00(p); }
static inline void L2_23FD00(void* p) { if (p) L3_23FD00(p); }
static inline void L1_23FD00(char* p) { if (p) L2_23FD00(p + 4); }
static inline void Base_23FD00(Obj_23FD00* l)
{
    if (l) {
        l->vt = D_004DC190;
        cArray_VisKey_dtor(l->mC4, -1);
        cArray_VectorKey_dtor(l->mAC, -1);
        cArray_cNIEventBasePtr_dtor(l->m9C, -1);
        cGOBJ_dtor(l, 0);
    }
}
extern "C" Obj_23FD00* cNIEventOBJ_dtor(Obj_23FD00* l, short flag)
{
    if (l) {
        VObj_23FD00* o;
        l->vt = cNIEventOBJ_vtable;
        o = l->obj;
        if (o) {
            AllocGuard g;
            o->Destroy(-1);
            cMemMan_Deallocate(0, o, "NIEvent.hh", 0x166);
        }
        cNIEventFXTrack_dtor(l->m1A4, -1);
        L1_23FD00(l->m184);
        L1_23FD00(l->m164);
        L1_23FD00(l->m144);
        Base_23FD00(l);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}