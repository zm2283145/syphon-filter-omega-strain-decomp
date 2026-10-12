#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ctl9170 {
public:
    VPAD16(p) VPAD2(q) VPAD1(r)
    virtual int isTeamed();      /* slot 19 */
};
struct Obj9170 { char pad[0xC]; unsigned int flags; char pad2[0x48]; Ctl9170* ctl; };
extern "C" {
extern unsigned char D_005721C8;
Obj9170* PlayerSlots_Get(int i);
void func_002C9270(int a, Obj9170* o, int key, int c);
}
extern "C" void func_002C9170(int a, int key, int c)
{
    int i;
    for (i = 0; i < 4; i++) {
        Obj9170* o = PlayerSlots_Get(i);
        int k;
        if (!o)
            continue;
        if (D_005721C8) {
            unsigned char has = 0;
            if (o->ctl && o->ctl->isTeamed())
                has = 1;
            if (has)
                k = ((o->flags & 0x7F000000) >> 24) - 1;
            else
                k = -1;
        } else {
            k = 0;
        }
        if (key == k) {
            func_002C9270(a, o, key, c);
            return;
        }
    }
}