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
extern char g_Game[];
extern int D_004FFC04;
extern int g_CardSlotId;
extern unsigned char D_004FFBB8;
extern Net_441CA0 g_MemCard;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0498[]; extern char D_004C04A8[]; extern char D_004C0530[];
extern char D_004C0540[]; extern char D_004C0550[]; extern char D_004C0560[];
char* cGameSystem_GetAgentData(void*, int);
char* nGlobalization_GetString_charP(char*);
int cGameFrontEnd_PushMessageBox(int, int, char*, char*, void*, int);
void cGameFrontEnd_PopMessageBox(int, int);
unsigned char cAgentData_Create(char*, int, int);
void cMemCard_FullCheck(Net_441CA0*);
int cMemCard_Format(Net_441CA0*);
int cMemCard_MakeGameDir(Net_441CA0*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
void GuiSaveAgentWidget_Write(Obj_441CA0*);
void GuiSaveAgentWidget_StartChecks(Obj_441CA0*);
void GuiSaveAgentWidget_HandleEvent(Obj_441CA0*);
int GuiWidget_onMessage(void*, void*, int, int, void*);
}

static inline int Open1(int mgr, int type, char* t, char* key, void* cb, int x) { return cGameFrontEnd_PushMessageBox(mgr, type, t, nGlobalization_GetString_charP(key), cb, x); }
static inline int Open2(int mgr, int type, char* t, char* key, void* cb, int x) { return cGameFrontEnd_PushMessageBox(mgr, type, nGlobalization_GetString_charP(t), nGlobalization_GetString_charP(key), cb, x); }

extern "C" int GuiSaveAgentWidget_OnEvent(Obj_441CA0* self, void* w, int msg, int sub, void* arg)
{
    Net_441CA0* net = &g_MemCard;
    char* err = nGlobalization_GetString_charP(D_004C0468);
    char* title = nGlobalization_GetString_charP(D_004C0448);
    unsigned short m = msg;

    if (m == 27) {
        if (sub == 3 || sub == 9) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            GuiSaveAgentWidget_HandleEvent(self);
            return 1;
        }
        if (sub == 2) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            net->cb = 0;
            self->Close(0);
            return 1;
        }
        if (sub == 0 || sub == 1 || sub == 5) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            if (self->mode == 2)
                self->dlg = Open1(D_004FFC04, 5, title, D_004C0530, self, 9);
            return 1;
        }
    } else if (m == 26) {
        if (sub == 3) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            if (!self->mode)
                cAgentData_Create(cGameSystem_GetAgentData(g_Game, -1), self->f50, 1);
            if (self->mode == 3 || !self->mode)
                g_CardSlotId = -1;
            net->cb = 0;
            D_004FFBB8 = 0;
            self->Close(0);
            return 1;
        }
        if (sub == 0) {
            NetImpl_441CA0* impl;
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            impl = net->impl;
            if (!impl->f59D) {
                GuiSaveAgentWidget_HandleEvent(self);
            } else if (impl->f59E) {
                self->dlg = Open1(D_004FFC04, 2, err, D_004C0540, self, 8);
            } else {
                int ok;
                self->dlg = Open1(D_004FFC04, 0, title, D_004C0550, self, 0);
                ok = cMemCard_Format(net);
                cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
                if (!ok) {
                    self->dlg = Open1(D_004FFC04, 2, err, D_004C0560, self, 2);
                } else {
                    if (!self->shown) {
                        self->shown = 1;
                        self->dlg = Open2(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
                    }
                    if (!cMemCard_MakeGameDir(net)) {
                        cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
                        self->dlg = Open1(D_004FFC04, 2, err, D_004C04A8, self, 2);
                    } else {
                        char* agent = cGameSystem_GetAgentData(g_Game, -1);
                        int changed = g_MemCard.impl->f5A8 != g_CardSlotId;
                        if (self->mode != 4) {
                            char* name = 0;
                            if (self->mode && !changed)
                                name = (self->mode == 3) ? self->name : agent + 0x8AC;
                            if (SaveAgentWidget_FindSlotFile(self->f50, name, 0)) {
                                self->dlg = Open2(D_004FFC04, 5, D_004C0448, D_004C0498, self, 1);
                                goto done;
                            }
                        }
                        GuiSaveAgentWidget_Write(self);
                    }
                }
            }
        done:
            return 1;
        }
        if (sub == 1) {
            NetImpl_441CA0* impl;
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            cMemCard_FullCheck(net);
            impl = net->impl;
            if (!impl->f59D || !impl->f59E || !impl->f59F)
                GuiSaveAgentWidget_HandleEvent(self);
            else
                GuiSaveAgentWidget_Write(self);
            return 1;
        }
        if (sub == 2) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            GuiSaveAgentWidget_HandleEvent(self);
            return 1;
        }
        if (sub == 10) {
            self->Close(0);
            return 1;
        }
        if (sub == 7) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            if (self->mode == 2)
                self->dlg = Open1(D_004FFC04, 5, title, D_004C0530, self, 9);
            return 1;
        }
        if (sub == 5) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            cMemCard_FullCheck(net);
            GuiSaveAgentWidget_StartChecks(self);
            return 1;
        }
        if (sub == 9) {
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
            net->cb = 0;
            self->Close(0);
            return 1;
        }
        return 1;
    }
    return GuiWidget_onMessage(self, w, msg, sub, arg);
}