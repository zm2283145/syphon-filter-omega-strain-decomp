#pragma cplusplus on
#include "types.h"

struct Net_441370 { struct NetImpl_441370* impl; int f4; int f8; };
struct NetImpl_441370 { char pad[0x5A8]; int f5A8; };

struct Obj_441370 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E();
    virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14();
    virtual void Close(int a); /* +0x5C */
    char pad04[0x44];
    int dlg;
    unsigned char mode;
    int f50;
    unsigned char shown;
};

extern "C" {
extern char g_Game[];
extern int D_004FFC04;
extern int g_OptionsRecord;
extern int g_CardSlotId;
extern Net_441370 g_MemCard;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0478[]; extern char D_004C0488[];
int Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int FrontEnd_OpenPopup(int, int, char*, char*, void*, int);
void FrontEnd_ClosePopup(int, int);
unsigned char AgentData_Create(int, int, int);
unsigned char AgentData_Save(int);
unsigned char GameOptions_WriteConfigFile(int);
void MemCardWrap_Remove(Net_441370*, char*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
int SaveAgentWidget_SpaceCheck(Obj_441370*);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, Loc_LookupText(t), Loc_LookupText(m), cb, x); }

extern "C" void SaveAgentWidget_Save(Obj_441370* self)
{
    Net_441370* net = &g_MemCard;
    int agent = Agent_GetSelected(g_Game, -1);
    if (SaveAgentWidget_SpaceCheck(self)) {
        unsigned char ok;
        int old;
        if (!self->shown) {
            self->shown = 1;
            self->dlg = ShowDlg(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
        }
        if (self->mode == 4) {
            ok = GameOptions_WriteConfigFile(g_OptionsRecord);
        } else {
            char addr[0x20];
            if (SaveAgentWidget_FindSlotFile(self->f50, (char*)Agent_GetSelected(g_Game, -1) + 0x8AC, addr))
                MemCardWrap_Remove(net, addr);
            if (self->mode == 0) ok = AgentData_Create(agent, self->f50, 0);
            else ok = AgentData_Save(agent);
        }
        old = self->dlg;
        if (!ok) {
            if (self->mode == 2)
                self->dlg = ShowDlg(D_004FFC04, 4, D_004C0468, D_004C0478, self, 2);
            else
                self->dlg = ShowDlg(D_004FFC04, 2, D_004C0468, D_004C0488, self, 2);
        } else {
            net->f8 = 0;
            self->Close(1);
            g_CardSlotId = net->impl->f5A8;
        }
        FrontEnd_ClosePopup(D_004FFC04, old);
    }
}

