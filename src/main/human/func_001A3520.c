#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
#include "net_local_id.h"
int Event_Construct(char **, char *);
int Event_Send(char **, char * , int);
int Inventory_HasAnyItem(int);
int cMessage_dtor(char **, int);
int WeaponInv_MoveItemsToBackpack(int, int);
int func_00255A50(int, int, int);
int Backpack_Construct(char * , int, int);
int ItemInv_Any(int);
extern char D_004DCEF0;
extern char D_004DCF10;
extern char D_005061B0;
}
#pragma opt_common_subs off
extern "C" void Npc_DeadStateDrop(char * arg0) {
    char * sp40[12];
    int x; int inv;
    if (F_(arg0, 0x3464, int) == 0) {
        inv = F_(arg0, 0x3524, int);
        x = F_(arg0, 0x33A0, int);
        bool ok; if (!Inventory_HasAnyItem(inv) && !x) { ok = F_(arg0, 0x2D, unsigned char) && F_(arg0, 0x2C, unsigned char) && !F_(arg0, 0x2E, unsigned char) && F_(arg0, 0x3468, unsigned char); if (!ok && !ItemInv_Any(F_(arg0, 0x3528, int))) return; } {
        if (F_(arg0, 0x14, unsigned char) != 0) {
            F_(arg0, 0x3464, int) = Backpack_Construct(arg0, 1, 0);
            WeaponInv_MoveItemsToBackpack(inv, F_(arg0, 0x3464, int));
            if (x != 0) {
                func_00255A50(F_(arg0, 0x3464, int), x, F_(arg0, 0x339C, int));
            }
            unsigned char on = *(volatile unsigned char*)&D_005721C8; if (on != 0) { int h; int id; int a = D_005721A8; if (on) { if (D_00494178 == -1) func_002EBAF8(&D_00494178, a); id = D_00494178; } else id = 0;
                h = F_(arg0, 0x3464, int);
                Event_Construct(sp40, &D_005061B0);
                sp40[0] = &D_004DCEF0;
                F_(sp40, 0x28, int) = h;
                F_(sp40, 0x20, signed char) = 4;
                F_(sp40, 0x2C, int) = id;
                F_(sp40, 0x24, signed char) = 0;
                Event_Send(sp40, arg0, 0);
                sp40[0] = &D_004DCF10;
                cMessage_dtor(sp40, 0);
            }
        }
        }
    }
}