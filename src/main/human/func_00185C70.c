#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C_185C70 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct O_185C70 { char pad[0xC]; unsigned int id; char pad10[0x48]; C_185C70* ctl; };
extern "C" { extern unsigned char D_005721C8; extern char D_004FFB50[]; void* Agent_GetSelected(void* list, int idx); }
static inline unsigned char Has_185C70(O_185C70* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void* func_00185C70(O_185C70* o)
{
    int idx;
    if (D_005721C8) {
        if (Has_185C70(o)) idx = ((o->id & 0x7F000000) >> 24) - 1;
        else idx = -1;
    } else {
        idx = 0;
    }
    if (Has_185C70(o)) return Agent_GetSelected(D_004FFB50, idx);
    return 0;
}