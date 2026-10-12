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
extern char D_004FFB50[];
extern int D_004FFC04;
extern int D_004FFD2C;
extern int D_004FFBBC;
extern Net_441370 D_0055A830;
extern char D_004C0448[]; extern char D_004C0458[]; extern char D_004C0468[];
extern char D_004C0478[]; extern char D_004C0488[];
int Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int func_002CAE30(int, int, char*, char*, void*, int);
void func_002CAC80(int, int);
unsigned char func_00333F60(int, int, int);
unsigned char func_00334110(int);
unsigned char func_0045A2A0(int);
void func_0040DC80(Net_441370*, char*);
int func_004422D0(int, char*, char*);
int func_00441780(Obj_441370*);
}

static inline int ShowDlg(int mgr, int type, char* t, char* m, void* cb, int x) { return func_002CAE30(mgr, type, Loc_LookupText(t), Loc_LookupText(m), cb, x); }

extern "C" void func_00441370(Obj_441370* self)
{
    Net_441370* net = &D_0055A830;
    int agent = Agent_GetSelected(D_004FFB50, -1);
    if (func_00441780(self)) {
        unsigned char ok;
        int old;
        if (!self->shown) {
            self->shown = 1;
            self->dlg = ShowDlg(D_004FFC04, 0, D_004C0448, D_004C0458, self, 0);
        }
        if (self->mode == 4) {
            ok = func_0045A2A0(D_004FFD2C);
        } else {
            char addr[0x20];
            if (func_004422D0(self->f50, (char*)Agent_GetSelected(D_004FFB50, -1) + 0x8AC, addr))
                func_0040DC80(net, addr);
            if (self->mode == 0) ok = func_00333F60(agent, self->f50, 0);
            else ok = func_00334110(agent);
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
            D_004FFBBC = net->impl->f5A8;
        }
        func_002CAC80(D_004FFC04, old);
    }
}

