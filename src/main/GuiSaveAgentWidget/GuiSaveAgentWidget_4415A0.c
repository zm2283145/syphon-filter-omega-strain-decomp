#pragma cplusplus on
#include "types.h"

struct NetImpl_4415A0 { char pad[0x59F]; unsigned char f59F; char pad5A0[8]; int f5A8; };
struct Net_4415A0 { NetImpl_4415A0* impl; };

struct Obj_4415A0 {
    void* vtable;
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
extern Net_4415A0 g_MemCard;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0498[]; extern char D_004C04A8[];
int Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int FrontEnd_OpenPopup(int, int, char*, char*, void*, int);
void FrontEnd_ClosePopup(int, int);
int MemCardWrap_MakeDirectory(Net_4415A0*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
int SaveAgentWidget_SpaceCheck();
void SaveAgentWidget_Save(Obj_4415A0*);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, Loc_LookupText(t), Loc_LookupText(m), cb, x); }

extern "C" void SaveAgentWidget_Prepare(Obj_4415A0* self)
{
    Net_4415A0* net = &g_MemCard;
    if (!g_MemCard.impl->f59F) {
        if (!SaveAgentWidget_SpaceCheck()) return;
        if (!self->shown) {
            self->shown = 1;
            self->dlg = ShowDlg(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
        }
        if (!MemCardWrap_MakeDirectory(net)) {
            int old = self->dlg;
            self->dlg = ShowDlg(D_004FFC04, 2, D_004C0468, D_004C04A8, self, 2);
            FrontEnd_ClosePopup(D_004FFC04, old);
            return;
        }
    }
    {
        char* agent = (char*)Agent_GetSelected(g_Game, -1);
        bool other = g_MemCard.impl->f5A8 != g_CardSlotId;
        if (self->mode != 4) {
            char* name = 0;
            if (self->mode != 0 && !other) name = (self->mode == 3) ? self->name : agent + 0x8AC;
            if (SaveAgentWidget_FindSlotFile(self->f50, name, 0)) {
                self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, D_004C0498, self, 1);
                return;
            }
        }
        SaveAgentWidget_Save(self);
    }
}

