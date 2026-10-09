/*
 * Matched functions (byte-identical with the retail executable).
 * cAI helpers: setter for field +0x54 (mirrored onto the game object in
 * multiplayer) and two service-wrapped calls.
 */

#include "types.h"
#include "ai_types.h"

extern char D_004ED9B0[];
extern char D_004FFB50[];  /* global service registry */
extern char D_005721C8[];  /* multiplayer flag byte */
extern int Service_Lookup(int, int);
extern int func_001589D0(void);
extern int func_00158A80(void);
extern int func_00164330(int);
extern int func_001644B0(int);

void func_0016F490(cAI* self, int value) {
    AIGObj* gobj;
    AIGObjSub* sub;

    self->unk54 = value;
    if (*(unsigned char*)D_005721C8 != 0) {
        gobj = self->gobj;
        if (gobj != 0) {
            sub = gobj->unk3584;
            if (sub != 0) {
                sub->unk30 = value;
            }
        }
    }
}

int func_0016F4D0(void) {
    func_001589D0();
    return func_00164330(Service_Lookup((int)D_004FFB50, (int)D_004ED9B0));
}

int func_0016F510(void) {
    func_001644B0(Service_Lookup((int)D_004FFB50, (int)D_004ED9B0));
    return func_00158A80();
}
