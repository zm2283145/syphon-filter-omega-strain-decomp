#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C_2B1280 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct O_2B1280 { char pad[0xC]; unsigned int id; char pad10[0x48]; C_2B1280* ctl; };
struct G_2B1280 { char pad[0x30]; O_2B1280* obj; };
extern "C" { extern unsigned char D_005721C8; extern char D_004FFB50[]; extern G_2B1280* D_004FFC0C; int func_0012F5B0(void* list, int idx); }
static inline unsigned char Has_2B1280(O_2B1280* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
/* Looks up the local player's entry for the current object (-1 when there is none). */
extern "C" int func_002B1280(void)
{
    if (D_004FFC0C && D_004FFC0C->obj) {
        O_2B1280* o = D_004FFC0C->obj;
        int idx;
        if (D_005721C8) {
            if (Has_2B1280(o)) idx = ((o->id & 0x7F000000) >> 24) - 1;
            else idx = -1;
        } else {
            idx = 0;
        }
        return func_0012F5B0(D_004FFB50, idx);
    }
    return -1;
}
