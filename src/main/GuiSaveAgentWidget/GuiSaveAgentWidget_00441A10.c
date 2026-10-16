#pragma cplusplus on
#include "types.h"

struct NetImpl_441A10 { char pad[0x59D]; unsigned char f59D; char pad59E[0xA]; int f5A8; };
struct Net_441A10 { NetImpl_441A10* impl; int f4; void* cb; };

struct Obj_441A10 {
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
extern char D_004FFB50[];
extern int D_004FFC04;
extern int D_004FFBBC;
extern unsigned char D_004FFBB8;
extern Net_441A10 D_0055A830;
extern char D_004C0448[]; extern char D_004C04F0[]; extern char D_004C0500[];
extern char D_004C0510[]; extern char D_004C0520[];
int* Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int FrontEnd_OpenPopup(int, int, char*, char*, void*, int);
void MemCard_Refresh(Net_441A10*);
void GuiSaveAgentWidget_WriteCard(Obj_441A10*);
void func_00441C10(void);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, Loc_LookupText(t), Loc_LookupText(m), cb, x); }

extern "C" void GuiSaveAgentWidget_HandleEvent(Obj_441A10* self)
{
    Net_441A10* net = &D_0055A830;
    if (self->mode != 0 && self->mode != 4) self->f50 = Agent_GetSelected(D_004FFB50, -1)[1];
    self->shown = 0;
    net->cb = (void*)func_00441C10;
    MemCard_Refresh(net);
    if (!net->impl->f59D) {
        if (self->mode == 2 && !D_004FFBB8) {
            net->cb = 0;
            self->Close(0);
            return;
        }
        if (self->mode == 4) {
            self->dlg = ShowDlg(D_004FFC04, 2, D_004C0448, D_004C04F0, self, 10);
            return;
        }
        {
            char* m = self->mode ? D_004C0500 : D_004C0510;
            self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, m, self, 3);
        }
        return;
    }
    D_004FFBB8 = 1;
    if (self->mode != 0 && D_004FFBBC != net->impl->f5A8) {
        self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, D_004C0520, self, 5);
        return;
    }
    GuiSaveAgentWidget_WriteCard(self);
}
