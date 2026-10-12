#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class VObj { public: virtual ~VObj(); };
class Act {
public:
    VPAD32(a) VPAD32(b)
    virtual unsigned char Kind();
    char pad4[0xC - 0x4];
    char a0C[0x40 - 0xC];
    float f40;
    char pad44[0x60 - 0x44];
    char a60[0x3310 - 0x60];
    VObj* w3310;
    VObj* w3314;
    char pad3318[0x3584 - 0x3318];
    void* p3584;
};
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049D8D0;
extern char g_TargetVisMgr;
extern unsigned char D_005721C8;
void Alloc_Lock(int);
void Alloc_Unlock(int);
void Mem_Free(int, void*, char*, int);
void func_0038CBF0(void*);
void TargetVis_Unregister(void*, void*);
void Actor_ShockReaction(Act*, unsigned char, int, float);
void func_003928D0(Act*, int);
void func_00436C00(int*);
void func_00433CE0(int*, void*);
void func_00436BA0(int*, int);
void func_002D2110(void*);
void ActorPhys_ReleaseWaterEffect(VObj*);
}

extern "C" void func_001B5190(Act* a, int arg)
{
    int loc;
    VObj* o;
    int i;
    func_0038CBF0(a->a60);
    TargetVis_Unregister(&g_TargetVisMgr, a);
    for (i = 0; i < 3; i++) Actor_ShockReaction(a, i, 0, 1.0f);
    func_003928D0(a, arg);
    if (D_005721C8) {
        func_00436C00(&loc);
        func_00433CE0(&loc, a->a0C);
        if (a->p3584) {
            if (a->Kind() != 3 || (int)a->f40 > 0) func_002D2110(a->p3584);
        }
        func_00436BA0(&loc, -1);
    }
    if (a->w3310) ActorPhys_ReleaseWaterEffect(a->w3310);
    o = a->w3310;
    if (o) {
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        o->~VObj();
        Mem_Free(0, o, &D_0049D8D0, 0x456);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        a->w3310 = 0;
    }
    o = a->w3314;
    if (o) {
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        o->~VObj();
        Mem_Free(0, o, &D_0049D8D0, 0x45B);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        a->w3314 = 0;
    }
}
