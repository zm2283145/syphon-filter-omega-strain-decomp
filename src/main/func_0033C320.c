#include "types.h"
#pragma cplusplus on
struct S33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual void v24(); };
struct V33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; } W33;
typedef struct { char pad[0x248]; int f248; } G33;
typedef struct { char pad[0x84]; int f84; } O33;
extern "C" {
extern G33* D_004FFC04;
extern char D_004B99D8[];
extern char* func_0033CE30(O33*, int, char*, char*, int, int);
extern int func_002CAE30(G33*, int, char*, char*, int, int);
extern void func_002C82F0(G33*);
extern void func_002C81D0(G33*);
extern void func_002CAC80(G33*, int);
extern int func_00414790(void);
extern W33* func_00418A80(int, char*, char*);
extern void func_00418840(int, W33*);
extern int func_004294C0(void);
extern int func_00442510(int, int);
extern int func_0044A230(int);
extern V33* func_004147A0(void);
extern void func_0041E0F0(W33*, V33*, int, int, int);
}
extern "C" int func_0033C320(O33* self, int type) {
    int c = -1;
    int h;
    W33* w;
    switch (type) {
    case 1: c = 0x78; break;
    case 3: c = 0x7A; break;
    case 4: c = 0x7B; break;
    case 9: c = 0x7C; break;
    case 2: c = 0x79; break;
    case 6: c = 0x79; break;
    }
    if (type == 1 && self->f84 == 9) c = -1;
    h = -1;
    if (c != -1) {
        G33* g = D_004FFC04;
        h = func_002CAE30(g, 0, D_004B99D8, func_0033CE30(self, (unsigned char)c, 0, 0, 0, 0), 0, 0);
        func_002C82F0(D_004FFC04);
    }
    w = 0;
    switch (type) {
    case 0: w = func_00418A80(func_00414790(), "GuiOnlineConnect", "ONLINECN"); break;
    case 1: w = func_00418A80(func_00414790(), "GuiCommandCenter", "CMDCENTR"); break;
    case 2: w = func_00418A80(func_00414790(), "GuiNetJoinMission", "JOINMIS"); break;
    case 6: w = func_00418A80(func_00414790(), "GuiMissionSetup", "MSNSETUP"); break;
    case 3: w = func_00418A80(func_00414790(), "GuiNetAgencyCell", "AGENTCEL"); break;
    case 4: w = func_00418A80(func_00414790(), "GuiNetContacts", "CONTACTS"); break;
    case 5: w = func_00418A80(func_00414790(), "GuiOnlineOptions", "ONLIPREF"); break;
    case 9: w = func_00418A80(func_00414790(), "GuiNetMessages", "NETMESS"); break;
    case 7: w = func_00418A80(func_00414790(), "GuiAccountLogin", "ACNTLOGN"); break;
    }
    if (c != -1) func_002C81D0(D_004FFC04);
    if (w) {
        if (type == 6 || type == 2) {
            int x = D_004FFC04->f248;
            int p = func_004294C0();
            if (!p || !func_00442510(p, x)) {
                if (h != -1) func_002CAC80(D_004FFC04, h);
                func_00418840(func_00414790(), w);
                return 0;
            }
        }
        if (type == 3) {
            int p = func_004294C0();
            if (!p || !func_0044A230(p)) {
                if (h != -1) func_002CAC80(D_004FFC04, h);
                func_00418840(func_00414790(), w);
                return 0;
            }
        }
        if (type == 0 || type == 7) w->f10 = 1;
    }
    ((S33*)self)->v24();
    if (w) {
        V33* m;
        w->flags &= ~2;
        m = func_004147A0();
        m->v23(w, 0);
    }
    func_004147A0()->v24(self);
    if (h != -1) func_002CAC80(D_004FFC04, h);
    if (w) {
        w->flags |= 2;
        func_0041E0F0(w, func_004147A0(), 0x10, 2, 0);
    }
    return 1;
}
