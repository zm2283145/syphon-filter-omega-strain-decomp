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
extern int Gui_Manager(void);
extern void* GuiManager_OpenGui(int, char*, char*);
extern int Gui_Canvas(void);
extern void GuiCanvas_Transition(int, O29D*, void*);
extern int cDME_GetLobby(void);
extern void SFOLobby_ConfigScreenExit(int);
extern int D_004FFC04;
extern void cGameFrontEnd_LobbyDestroy(int, int);
extern char* GuiLobbyScreen_GetLobbyString(O29D*, int, int, int, int, int);
extern void std_basic_string_char_char_traits_char_ctor_charP(S29D*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(S29D*);
extern void cGameFrontEnd_PushMessageBox(int, int, char*, char*, int, int);
extern void String_Dtor(S29D*, int);
void GuiOnlineConnect_Back(O29D* o, int show) {
    void* w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineOfflineSelect", "ONOFFSEL");
    GuiCanvas_Transition(Gui_Canvas(), o, w);
    if (o->b94) {
        if (cDME_GetLobby()) SFOLobby_ConfigScreenExit(cDME_GetLobby());
        o->b94 = 0;
    }
    cGameFrontEnd_LobbyDestroy(D_004FFC04, 1);
    if (show) {
        S29D a;
        S29D b;
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(o, 0xB, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(o, 0x84, 0, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), tb, 0, 0);
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
void* Gui_Manager(void);
#endif /* merge_units */
#define Gui_Manager() ((void *)Gui_Manager()) /* merge_units */

#if 0 /* merge_units */
void* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((void *)Gui_Canvas()) /* merge_units */

#if 0 /* merge_units */
void* GuiManager_OpenGui(void* a, char* b, char* c);
#endif /* merge_units */
#define GuiManager_OpenGui(a0, a1, a2) (GuiManager_OpenGui((int)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void GuiCanvas_Transition(void* ui, S_0029DFC0* self, void* pg);
#endif /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) (GuiCanvas_Transition((int)(a0), (O29D *)(a1), (a2))) /* merge_units */

int FrontEnd_IsRegisterEnabled(void* ui);
void GuiAccountLogin_SetMode(void* pg, int a);
char* cGameSystem_GetAgentData(void* a, int b);
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
        pg = GuiManager_OpenGui(Gui_Manager(), D_004AAC70, D_004AAC80);
        if (pg) {
            unsigned char ok = 1;
            if (!D_004FFC04->f265 && !IsEmpty_DFC0(cGameSystem_GetAgentData(g_Game, -1) + 0x8CC))
                ok = 0;
            if (ok && FrontEnd_IsRegisterEnabled(D_004FFC04))
                GuiAccountLogin_SetMode(pg, 1);
            else
                GuiAccountLogin_SetMode(pg, 0);
            GuiCanvas_Transition(Gui_Canvas(), self, pg);
        }
    }
}
#undef D_004FFC04 /* merge_units */
#undef Gui_Manager /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiManager_OpenGui /* merge_units */
#undef GuiCanvas_Transition /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029DFC0 */
