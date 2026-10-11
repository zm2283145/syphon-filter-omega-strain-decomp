#pragma cplusplus on

#include "types.h"

/* Resolve the attached animation data pointer, directly or via lookup. */
typedef struct { int valid; unsigned char* data; } Ref_3947A0;
typedef struct { int pad0; int count; int key; int pad1; int key2; } Tab_3947A0;
typedef struct { Tab_3947A0* tab; } Inner_3947A0;
typedef struct { int pad0; Inner_3947A0* inner; } Res_3947A0;
class Obj_3947A0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual Res_3947A0* resolve();
    unsigned char pad[0x64];
    Ref_3947A0* ref;
};

extern "C" {
int func_00182260(Tab_3947A0* t, int* key);
int func_00181E80(Tab_3947A0* t, int* key);
}

static inline unsigned char Valid_3947A0(Ref_3947A0* r) { return r->valid != 0; }

extern "C" int cVUM_GOBJ_v20(Obj_3947A0* o)
{
    int r = 0;
    Ref_3947A0* ref = o->ref;
    if (ref != 0 && Valid_3947A0(ref)) {
        r = (int)(ref->data + 0x30);
    } else {
        Res_3947A0* res = o->resolve();
        if (res != 0) {
            Tab_3947A0* t = res->inner->tab;
            int v;
            if (t->count > 0) {
                int k = t->key;
                v = func_00182260(t, &k);
            } else {
                int k = t->key2;
                v = func_00181E80(t, &k);
            }
            r = v;
        }
    }
    return r;
}