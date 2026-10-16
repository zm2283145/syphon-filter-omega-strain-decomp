#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"
class R_F1A0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ren_F1A0 { unsigned int f0; char pad4[0x20]; unsigned int f24; };
struct Obj_F1A0 { char pad[0x49]; unsigned char kind; char pad4a[0xE]; R_F1A0* recv; char pad5c[0xC]; Ren_F1A0* ren; };
struct List_F1A0 { int n; Obj_F1A0* items[1]; };
extern "C" {
extern char D_00543790[];
extern unsigned char D_005721C8;
void Shadow_AddReceiver(void* mgr, Obj_F1A0* o, int flag);
void Shadow_AddCaster(void* mgr, Obj_F1A0* o, int mode);
}
extern "C" void Shadow_RegisterReceiver(List_F1A0* list)
{
    Obj_F1A0** p;
    for (p = list->items; p != list->items + list->n; p++) {
        Obj_F1A0* o = *p;
        if (o->kind == 1) {
            Ren_F1A0* r = o->ren;
            if (r->f24 & 0x60) { unsigned char v = r->f0 != 0; if (v)
                Shadow_AddReceiver(D_00543790, o, 0); }
        } else if (o->kind == 2) {
            Obj_F1A0* c = o;
            unsigned char local = 0;
            R_F1A0* rc = c->recv;
            if (rc && rc->IsLocal())
                local = 1;
            if (D_005721C8) {
                if (local)
                    Shadow_AddCaster(D_00543790, c, 2);
            } else if (local) {
                Shadow_AddCaster(D_00543790, c, 2);
            } else {
                Shadow_AddCaster(D_00543790, c, 1);
            }
        }
    }
}



