#include "types.h"
typedef struct { char pad[0xC]; unsigned char bc; char name[0x203]; int f210; } E33C;
typedef struct { char pad[0x20]; int f20; char pad2[0x18]; int f3c; } L33C;
typedef struct { char pad[0x10]; int f10; } W33C;
typedef struct { char pad[0x7C]; W33C* f7c; } O33C;
typedef struct { char pad[0x31]; unsigned char b31; } G33C;
extern L33C* cDME_GetLobby(void);
extern E33C* func_00450EF0(L33C*, int);
extern void func_00450EC0(L33C*, int);
extern unsigned char D_00532DC8;
extern char D_00532DD0[];
extern G33C* D_004FFC04;
extern char* strncpy(char*, const char*, int);
extern void func_003FD2D0(char*);
extern void cGameFrontEnd_LobbyDestroy(G33C*, int);
extern void func_002CA6F0(G33C*);
extern void GuiWidget_SendMessage(O33C*, W33C*, int, int, int);
void GuiScreen_PollLobby(O33C* o) {
    L33C* l = cDME_GetLobby();
    int i;
    E33C* e;
    int n;
    if (!l) return;
    n = l->f3c;
    for (i = 0; i < n; i++) {
        e = func_00450EF0(l, i);
        if (e->f210 == 9) {
            func_00450EC0(l, i);
            D_00532DC8 = 1;
            if (e->bc) {
                strncpy(D_00532DD0, (char*)&e->bc, 0x200);
                func_003FD2D0(D_00532DD0);
            } else {
                D_00532DD0[0] = 0;
            }
            D_004FFC04->b31 = 1;
            cGameFrontEnd_LobbyDestroy(D_004FFC04, 1);
            func_002CA6F0(D_004FFC04);
            return;
        }
    }
    if (!o->f7c) return;
    if (l->f20) {
        if (o->f7c->f10 != 1) {
            GuiWidget_SendMessage(o, o->f7c, 6, (int)"onActivate", 0);
            o->f7c->f10 = 1;
        }
    } else {
        if (o->f7c->f10) {
            GuiWidget_SendMessage(o, o->f7c, 6, (int)"onWake", 0);
            o->f7c->f10 = 0;
        }
    }
}
