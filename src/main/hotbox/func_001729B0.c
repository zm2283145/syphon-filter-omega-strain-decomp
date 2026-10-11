#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class O_29B0 {
public:
    VPAD16(a) VPAD8(b) VPAD1(c)
    virtual int Handle();
    char pad[0x8C];
    int state;
};
struct Ev_29B0 { char pad[0x24]; unsigned char kind; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
}
struct T_29B0 { int id; bool operator==(const T_29B0& o) const { return id == o.id; } };
extern "C" { extern T_29B0 D_004F5440; T_29B0* Event_GetType(Ev_29B0* e); }
extern "C" int func_001729B0(O_29B0* self, Ev_29B0* e)
{
    int ok = D_005721C8 ? D_005721C0 : 1;
    if (ok && self->state == 8 && *Event_GetType(e) == D_004F5440 && e->kind == 4)
        return self->Handle();
    return 1;
}