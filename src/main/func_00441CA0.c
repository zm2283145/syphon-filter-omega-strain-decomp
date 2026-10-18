#pragma cplusplus on
#include "types.h"

struct NetImpl_441CA0 { char pad[0x59D]; unsigned char f59D; unsigned char f59E; unsigned char f59F; char pad5A0[8]; int f5A8; };
struct Net_441CA0 { NetImpl_441CA0* impl; int f4; int cb; };

struct Obj_441CA0 {
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
    char name[1];
};

extern "C" {
extern char D_004FFB50[];
extern int D_004FFC04;
extern int D_004FFBBC;
extern unsigned char D_004FFBB8;
extern Net_441CA0 D_0055A830;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0498[]; extern char D_004C04A8[]; extern char D_004C0530[];
extern char D_004C0540[]; extern char D_004C0550[]; extern char D_004C0560[];
char* Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int FrontEnd_OpenPopup(int, int, char*, char*, void*, int);
void FrontEnd_ClosePopup(int, int);
unsigned char AgentData_Create(char*, int, int);
void MemCard_Refresh(Net_441CA0*);
int MemCardWrap_Format(Net_441CA0*);
int MemCardWrap_MakeDirectory(Net_441CA0*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
void SaveAgentWidget_Save(Obj_441CA0*);
void GuiSaveAgentWidget_WriteCard(Obj_441CA0*);
void GuiSaveAgentWidget_HandleEvent(Obj_441CA0*);
int GuiWidget_OnEvent(void*, void*, int, int, void*);
}

static inline int Open1(int mgr, int type, char* t, char* key, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, t, Loc_LookupText(key), cb, x); }
static inline int Open2(int mgr, int type, char* t, char* key, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, Loc_LookupText(t), Loc_LookupText(key), cb, x); }

extern "C" int GuiSaveAgentWidget_OnEvent(Obj_441CA0* self, void* w, int msg, int sub, void* arg)
{
    Net_441CA0* net = &D_0055A830;
    char* err = Loc_LookupText(D_004C0468);
    char* title = Loc_LookupText(D_004C0448);
    unsigned short m = msg;

    if (m == 27) {
        if (sub == 3 || sub == 9) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            GuiSaveAgentWidget_HandleEvent(self);
            return 1;
        }
        if (sub == 2) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            net->cb = 0;
            self->Close(0);
            return 1;
        }
        if (sub == 0 || sub == 1 || sub == 5) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            if (self->mode == 2)
                self->dlg = Open1(D_004FFC04, 5, title, D_004C0530, self, 9);
            return 1;
        }
    } else if (m == 26) {
        if (sub == 3) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            if (!self->mode)
                AgentData_Create(Agent_GetSelected(D_004FFB50, -1), self->f50, 1);
            if (self->mode == 3 || !self->mode)
                D_004FFBBC = -1;
            net->cb = 0;
            D_004FFBB8 = 0;
            self->Close(0);
            return 1;
        }
        if (sub == 0) {
            NetImpl_441CA0* impl;
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            impl = net->impl;
            if (!impl->f59D) {
                GuiSaveAgentWidget_HandleEvent(self);
            } else if (impl->f59E) {
                self->dlg = Open1(D_004FFC04, 2, err, D_004C0540, self, 8);
            } else {
                int ok;
                self->dlg = Open1(D_004FFC04, 0, title, D_004C0550, self, 0);
                ok = MemCardWrap_Format(net);
                FrontEnd_ClosePopup(D_004FFC04, self->dlg);
                if (!ok) {
                    self->dlg = Open1(D_004FFC04, 2, err, D_004C0560, self, 2);
                } else {
                    if (!self->shown) {
                        self->shown = 1;
                        self->dlg = Open2(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
                    }
                    if (!MemCardWrap_MakeDirectory(net)) {
                        FrontEnd_ClosePopup(D_004FFC04, self->dlg);
                        self->dlg = Open1(D_004FFC04, 2, err, D_004C04A8, self, 2);
                    } else {
                        char* agent = Agent_GetSelected(D_004FFB50, -1);
                        int changed = D_0055A830.impl->f5A8 != D_004FFBBC;
                        if (self->mode != 4) {
                            char* name = 0;
                            if (self->mode && !changed)
                                name = (self->mode == 3) ? self->name : agent + 0x8AC;
                            if (SaveAgentWidget_FindSlotFile(self->f50, name, 0)) {
                                self->dlg = Open2(D_004FFC04, 5, D_004C0448, D_004C0498, self, 1);
                                goto done;
                            }
                        }
                        SaveAgentWidget_Save(self);
                    }
                }
            }
        done:
            return 1;
        }
        if (sub == 1) {
            NetImpl_441CA0* impl;
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            MemCard_Refresh(net);
            impl = net->impl;
            if (!impl->f59D || !impl->f59E || !impl->f59F)
                GuiSaveAgentWidget_HandleEvent(self);
            else
                SaveAgentWidget_Save(self);
            return 1;
        }
        if (sub == 2) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            GuiSaveAgentWidget_HandleEvent(self);
            return 1;
        }
        if (sub == 10) {
            self->Close(0);
            return 1;
        }
        if (sub == 7) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            if (self->mode == 2)
                self->dlg = Open1(D_004FFC04, 5, title, D_004C0530, self, 9);
            return 1;
        }
        if (sub == 5) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            MemCard_Refresh(net);
            GuiSaveAgentWidget_WriteCard(self);
            return 1;
        }
        if (sub == 9) {
            FrontEnd_ClosePopup(D_004FFC04, self->dlg);
            net->cb = 0;
            self->Close(0);
            return 1;
        }
        return 1;
    }
    return GuiWidget_OnEvent(self, w, msg, sub, arg);
}