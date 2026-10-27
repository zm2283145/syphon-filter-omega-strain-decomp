/*
 * SFOGame/Source/GuiSaveAgentWidget: 1 file, 00441780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_441780 */
#pragma push /* merge_units */
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
extern char g_Game[];
extern int D_004FFC04;
extern Net_441780 g_MemCard;
extern char D_004C04B8[]; extern char D_004C04C0[]; extern char D_004C04C8[];
extern char D_004C04D8[]; extern char D_004C0468[];
int cGameSystem_GetAgentData(void*, int);
char* nGlobalization_GetString_charP(char*);
int cGameFrontEnd_PushMessageBox(int, int, char*, char*, void*, int);
void cGameFrontEnd_PopMessageBox(int, int);
int cAgentData_GetNumSavedBytes(int);
int cMemCard_GetClustersNeeded(Net_441780*, int);
int cMemCard_FileExists(Net_441780*, char*);
int SaveAgentWidget_FindSlotFile(int, char*, char*);
void GuiSaveAgentWidget_HandleEvent(Obj_441780*);
int sprintf(char*, const char*, ...);
char* strncpy(char*, const char*, int);
char* strstr(const char*, const char*);
char* Libc_Strcat(char*, const char*);
void Libc_Strcpy(char*, const char*);
}

static inline int ShowMsg(int mgr, int type, char* t, char* msg, void* cb, int x) { return cGameFrontEnd_PushMessageBox(mgr, type, nGlobalization_GetString_charP(t), msg, cb, x); }

extern "C" int SaveAgentWidget_SpaceCheck(Obj_441780* self)
{
    Net_441780* net = &g_MemCard;
    int need = 0;
    int have;
    int lim;
    if (self->mode == 4) {
        if (!cMemCard_FileExists(net, D_004C04B8)) need = 1000;
    } else if (!SaveAgentWidget_FindSlotFile(self->f50, 0, 0)) {
        need = cAgentData_GetNumSavedBytes(cGameSystem_GetAgentData(g_Game, -1));
    }
    have = cMemCard_GetClustersNeeded(net, need);
    lim = net->impl->f5A4;
    if (!net->impl->f59D || !net->impl->f59E) {
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
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
        fmt = nGlobalization_GetString_charP(D_004C04C8);
        p = strstr(fmt, D_004C04D8);
        n = p - fmt;
        if (p) {
            strncpy(msg, fmt, n);
            msg[n] = 0;
            Libc_Strcat(msg, num);
            Libc_Strcat(msg, p + 4);
        } else {
            Libc_Strcpy(msg, fmt);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->dlg);
        self->dlg = ShowMsg(D_004FFC04, 2, D_004C0468, msg, self, 7);
        return 0;
    }
    return 1;
}
static inline void merge_flush_GuiSaveAgentWidget_441780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_441780 */
