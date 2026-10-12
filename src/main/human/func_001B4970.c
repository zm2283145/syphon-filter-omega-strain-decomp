#pragma cplusplus on
#include "types.h"
class VObj { public: virtual ~VObj(); };
extern "C" {
typedef struct {
    char pad0[0xC]; char a0C[0x60 - 0xC]; char a60[0x3310 - 0x60];
    VObj* w3310; VObj* w3314;
} Act;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049D8D0;
extern char g_TargetVisMgr;
void Alloc_Lock(int);
void Alloc_Unlock(int);
void Mem_Free(int, void*, char*, int);
void func_0038CBF0(void*);
void TargetVis_Unregister(void*, void*);
void func_003928A0(void*);
void func_00436C00(int*);
void func_00433CE0(int*, void*);
void func_00436BA0(int*, int);
void ActorPhys_ReleaseWaterEffect(VObj*);
}

extern "C" void func_001B4970(Act* a)
{
    int loc;
    VObj* o;
    func_0038CBF0(a->a60);
    TargetVis_Unregister(&g_TargetVisMgr, a);
    func_003928A0(a);
    func_00436C00(&loc);
    func_00433CE0(&loc, a->a0C);
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
    func_00436BA0(&loc, -1);
}

