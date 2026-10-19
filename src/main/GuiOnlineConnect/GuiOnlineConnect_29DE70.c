/*
 * main/GuiOnlineConnect: 2 files, 0029DE70-0029DFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029DE70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a[4]; } S29D;
typedef struct { char pad[0x94]; unsigned char b94; } O29D;
extern int Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(int, char*, char*);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, O29D*, void*);
extern int DME_GetLobby(void);
extern void SFOLobby_LeaveNetworkState(int);
extern int D_004FFC04;
extern void FrontEnd_LeaveOnline(int, int);
extern char* GuiScreen_GetLobbyString(O29D*, int, int, int, int, int);
extern void String_CtorCStr_13B480(S29D*, char*);
extern char* String_CStr(S29D*);
extern void FrontEnd_OpenPopup(int, int, char*, char*, int, int);
extern void String_Dtor(S29D*, int);
void GuiOnlineConnect_Back(O29D* o, int show) {
    void* w = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
    if (o->b94) {
        if (DME_GetLobby()) SFOLobby_LeaveNetworkState(DME_GetLobby());
        o->b94 = 0;
    }
    FrontEnd_LeaveOnline(D_004FFC04, 1);
    if (show) {
        S29D a;
        S29D b;
        String_CtorCStr_13B480(&a, GuiScreen_GetLobbyString(o, 0xB, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, GuiScreen_GetLobbyString(o, 0x84, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0029DE70 */

/* merge_units: begin func_0029DFC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub_0029DFC0 { char pad[0x70]; int f70; };
struct Ui_0029DFC0 { char pad[0x265]; unsigned char f265; };
struct S_0029DFC0 {
    char pad0[0x88]; int f88; char pad8C[0xF4 - 0x8C]; Sub_0029DFC0* pF4; char padF8[0x100 - 0xF8];
    Sub_0029DFC0* p100; char pad104[0x118 - 0x104]; int f118;
};
extern "C" {
#if 0 /* merge_units */
extern Ui_0029DFC0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Ui_0029DFC0 **)&D_004FFC04) /* merge_units */

extern char g_Game[];
extern char D_004AAC70[];
extern char D_004AAC80[];
void GuiOnlineConnect_ShowGroup(S_0029DFC0* self, unsigned char sel);
#if 0 /* merge_units */
void* Gui_GetScreenList(void);
#endif /* merge_units */
#define Gui_GetScreenList() ((void *)Gui_GetScreenList()) /* merge_units */

#if 0 /* merge_units */
void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

#if 0 /* merge_units */
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_FindOrLoad(a0, a1, a2) (GuiManager_FindOrLoad((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void GuiStack_SwapScreens(void* ui, S_0029DFC0* self, void* pg);
#endif /* merge_units */
#define GuiStack_SwapScreens(a0, a1, a2) (GuiStack_SwapScreens((int)(a0), (O29D *)(a1), (a2))) /* merge_units */

int func_002CA070(void* ui);
void func_00288DE0(void* pg, int a);
char* Agent_GetSelected(void* a, int b);
int strlen(const char* s);
}
static inline bool HasText_DFC0(const char* s) { return strlen(s) != 0; }
static inline int IsEmpty_DFC0(const char* s) { return HasText_DFC0(s) ^ 1; }
extern "C" void GuiOnlineConnect_Advance(S_0029DFC0* self)
{
    unsigned char go = 0;
    int st = self->f118;
    if (st == 4 || st == 0) {
        self->f88 = 8;
        GuiOnlineConnect_ShowGroup(self, 1);
        if (!self->pF4->f70)
            GuiOnlineConnect_Advance(self);
    } else if (st == 1 && self->f88 == 8) {
        self->f88 = 9;
        GuiOnlineConnect_ShowGroup(self, 1);
        if (!self->pF4->f70)
            GuiOnlineConnect_Advance(self);
    } else if (st == 1 || st == 2) {
        GuiOnlineConnect_ShowGroup(self, 2);
        if (!self->p100->f70)
            go = 1;
        else
            self->f88 = 0xA;
    }
    if (go) {
        void* pg;
        GuiOnlineConnect_ShowGroup(self, 4);
        pg = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AAC70, D_004AAC80);
        if (pg) {
            unsigned char ok = 1;
            if (!D_004FFC04->f265 && !IsEmpty_DFC0(Agent_GetSelected(g_Game, -1) + 0x8CC))
                ok = 0;
            if (ok && func_002CA070(D_004FFC04))
                func_00288DE0(pg, 1);
            else
                func_00288DE0(pg, 0);
            GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
        }
    }
}
#undef D_004FFC04 /* merge_units */
#undef Gui_GetScreenList /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef GuiManager_FindOrLoad /* merge_units */
#undef GuiStack_SwapScreens /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029DFC0 */
