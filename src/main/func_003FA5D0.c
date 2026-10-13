#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct C_A5D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int F54(); };
struct O_A5D0 { VPAD4(a) VPAD1(b) virtual void F1C(int i); char pad[0x10]; unsigned char b14; char pad2[0x43]; C_A5D0* c58; };
struct It_A5D0 { O_A5D0** p; };
struct Vec_A5D0;
extern "C" {
void* World_GetActorArray(void);
Vec_A5D0* func_001339A0(void* arr);
void PtrVec_Begin(It_A5D0* out, Vec_A5D0* v);
void PtrVec_End(It_A5D0* out, Vec_A5D0* v);
void func_00133980(It_A5D0* out, It_A5D0* in);
void printf(char* fmt, int i);
extern char D_004BE240[];
extern unsigned char D_0055C780[];
extern unsigned char D_005724B0;
}
static inline bool Ok_A5D0(O_A5D0* o) { bool r = false; C_A5D0* c = o->c58; if (c) { if (c->F54()) r = true; } return r; }
static inline int Ne_A5D0(It_A5D0* a, It_A5D0* b) { return (a->p == b->p) ^ 1; }
extern "C" void NetObj_LoadNetworkData(void)
{
    int i;
    void* arr;
    unsigned char* s;
    if (D_005724B0 != 7) {
        for (i = 0, s = D_0055C780; i < 4; i++, s++) {
            if (*s == 1) {
                It_A5D0 it;
                It_A5D0 end;
                It_A5D0 tb;
                It_A5D0 te;
                arr = World_GetActorArray();
                PtrVec_Begin(&tb, func_001339A0(arr));
                func_00133980(&it, &tb);
                for (PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te); Ne_A5D0(&it, &end); PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te)) {
                    if (Ok_A5D0(*it.p)) {
                        O_A5D0* o = *it.p;
                        if (o->b14) {
                            o->F1C(i);
                            break;
                        }
                    }
                    it.p++;
                }
            } else {
                printf(D_004BE240, i);
            }
        }
    }
}





