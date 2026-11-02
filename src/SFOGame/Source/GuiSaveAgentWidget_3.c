/*
 * SFOGame/Source/GuiSaveAgentWidget: 2 files, 00441780-00441960
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
#if 0 /* merge_units */
void GuiSaveAgentWidget_HandleEvent(Obj_441780*);
#endif /* merge_units */
void GuiSaveAgentWidget_HandleEvent(void*); /* merge_units */
#define GuiSaveAgentWidget_HandleEvent(a0) (GuiSaveAgentWidget_HandleEvent((void *)(a0))) /* merge_units */

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
#undef GuiSaveAgentWidget_HandleEvent /* merge_units */
static inline void merge_flush_GuiSaveAgentWidget_441780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_441780 */

/* merge_units: begin GuiSaveAgentWidget_441960 */
#pragma push /* merge_units */
typedef struct { char pad[0x59D]; unsigned char b59d; unsigned char b59e; } G441;
typedef struct { char pad[0x48]; int f48; } O441;
#if 0 /* merge_units */
extern G441* g_MemCard;
#endif /* merge_units */
#define g_MemCard (*(G441 **)&g_MemCard) /* merge_units */

extern char D_004C0448[];
extern char* nGlobalization_GetString_charP(char*);
#if 0 /* merge_units */
extern void GuiSaveAgentWidget_HandleEvent(O441*);
#endif /* merge_units */
#define GuiSaveAgentWidget_HandleEvent(a0) (GuiSaveAgentWidget_HandleEvent((void *)(a0))) /* merge_units */

extern void SaveAgentWidget_Prepare(O441*);
#if 0 /* merge_units */
extern int cGameFrontEnd_PushMessageBox(int, int, char*, char*, O441*, int);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (void *)(a4), (a5))) /* merge_units */

void GuiSaveAgentWidget_StartChecks(O441* o) {
    G441* g = g_MemCard;
    if (!g->b59d) {
        GuiSaveAgentWidget_HandleEvent(o);
    } else if (!g->b59e) {
        int m = D_004FFC04;
        char* t = nGlobalization_GetString_charP(D_004C0448);
        o->f48 = cGameFrontEnd_PushMessageBox(m, 5, t, nGlobalization_GetString_charP("MC_ASKFORMAT"), o, 0);
    } else {
        SaveAgentWidget_Prepare(o);
    }
}
#undef g_MemCard /* merge_units */
#undef GuiSaveAgentWidget_HandleEvent /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
static inline void merge_flush_GuiSaveAgentWidget_441960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_441960 */
