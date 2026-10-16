#pragma cplusplus on
#include "types.h"

struct NetImpl_441780 { char pad[0x59D]; unsigned char f59D; unsigned char f59E; char pad59F[5]; int f5A4; };
struct Net_441780 { NetImpl_441780* impl; };

struct Obj_441780 {
    void* vtable;
    char pad04[0x44];
    int dlg;
    unsigned char mode;
    int f50;
};

extern "C" {
extern char D_004FFB50[];
extern int D_004FFC04;
extern Net_441780 D_0055A830;
extern char D_004C04B8[]; extern char D_004C04C0[]; extern char D_004C04C8[];
extern char D_004C04D8[]; extern char D_004C0468[];
int Agent_GetSelected(void*, int);
char* Loc_LookupText(char*);
int FrontEnd_OpenPopup(int, int, char*, char*, void*, int);
void FrontEnd_ClosePopup(int, int);
int AgentData_GetSaveSize(int);
int func_0040D580(Net_441780*, int);
int func_0040D690(Net_441780*, char*);
int func_004422D0(int, char*, char*);
void GuiSaveAgentWidget_HandleEvent(Obj_441780*);
int sprintf(char*, const char*, ...);
char* strncpy(char*, const char*, int);
char* strstr(const char*, const char*);
char* func_00128F58(char*, const char*);
void String_Copy(char*, const char*);
}

static inline int ShowMsg(int mgr, int type, char* t, char* msg, void* cb, int x) { return FrontEnd_OpenPopup(mgr, type, Loc_LookupText(t), msg, cb, x); }

extern "C" int func_00441780(Obj_441780* self)
{
    Net_441780* net = &D_0055A830;
    int need = 0;
    int have;
    int lim;
    if (self->mode == 4) {
        if (!func_0040D690(net, D_004C04B8)) need = 1000;
    } else if (!func_004422D0(self->f50, 0, 0)) {
        need = AgentData_GetSaveSize(Agent_GetSelected(D_004FFB50, -1));
    }
    have = func_0040D580(net, need);
    lim = net->impl->f5A4;
    if (!net->impl->f59D || !net->impl->f59E) {
        FrontEnd_ClosePopup(D_004FFC04, self->dlg);
        GuiSaveAgentWidget_HandleEvent(self);
        return 0;
    }
    if (lim < have) {
        char num[8];
        char msg[0x108];
        char* fmt;
        char* p;
        int n;
        sprintf(num, D_004C04C0, have);
        fmt = Loc_LookupText(D_004C04C8);
        p = strstr(fmt, D_004C04D8);
        n = p - fmt;
        if (p) {
            strncpy(msg, fmt, n);
            msg[n] = 0;
            func_00128F58(msg, num);
            func_00128F58(msg, p + 4);
        } else {
            String_Copy(msg, fmt);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->dlg);
        self->dlg = ShowMsg(D_004FFC04, 2, D_004C0468, msg, self, 7);
        return 0;
    }
    return 1;
}

