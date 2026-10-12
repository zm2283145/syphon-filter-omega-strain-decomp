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
extern char D_004FFB50[];
extern int D_004FFC04;
extern int D_004FFBBC;
extern Net_4415A0 D_0055A830;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0498[]; extern char D_004C04A8[];
int Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int func_002CAE30(int, int, char*, char*, void*, int);
void func_002CAC80(int, int);
int func_0040D740(Net_4415A0*);
int func_004422D0(int, char*, char*);
int func_00441780();
void func_00441370(Obj_4415A0*);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return func_002CAE30(mgr, type, Loc_LookupText(t), Loc_LookupText(m), cb, x); }

extern "C" void func_004415A0(Obj_4415A0* self)
{
    Net_4415A0* net = &D_0055A830;
    if (!D_0055A830.impl->f59F) {
        if (!func_00441780()) return;
        if (!self->shown) {
            self->shown = 1;
            self->dlg = ShowDlg(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
        }
        if (!func_0040D740(net)) {
            int old = self->dlg;
            self->dlg = ShowDlg(D_004FFC04, 2, D_004C0468, D_004C04A8, self, 2);
            func_002CAC80(D_004FFC04, old);
            return;
        }
    }
    {
        char* agent = (char*)Agent_GetSelected(D_004FFB50, -1);
        bool other = D_0055A830.impl->f5A8 != D_004FFBBC;
        if (self->mode != 4) {
            char* name = 0;
            if (self->mode != 0 && !other) name = (self->mode == 3) ? self->name : agent + 0x8AC;
            if (func_004422D0(self->f50, name, 0)) {
                self->dlg = ShowDlg(D_004FFC04, 5, D_004C0448, D_004C0498, self, 1);
                return;
            }
        }
        func_00441370(self);
    }
}

