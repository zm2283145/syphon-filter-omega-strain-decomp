/*
 * SFOGame/Source/GuiLobbyScreen: 6 files, 0033C280-0033C9E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033C280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_imp_Record_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0033C280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C280 */

/* merge_units: begin func_0033C2A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(cArray_Record_dtor, std_vector_imp_Record_dtor)
static inline void merge_flush_func_0033C2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C2A0 */

/* merge_units: begin func_0033C300 */
#pragma push /* merge_units */
Rel* std_vector_Record_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0033C300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C300 */

/* merge_units: begin func_0033C320 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual void v24(); };
struct V33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; } W33;
typedef struct { char pad[0x248]; int f248; } G33;
typedef struct { char pad[0x84]; int f84; } O33;
extern "C" {
extern G33* D_004FFC04;
extern char D_004B99D8[];
extern char* GuiLobbyScreen_GetLobbyString(O33*, int, char*, char*, int, int);
extern int cGameFrontEnd_PushMessageBox(G33*, int, char*, char*, int, int);
extern void FrontEnd_StartSplashThread(G33*);
extern void FrontEnd_StopSplashThread(G33*);
extern void cGameFrontEnd_PopMessageBox(G33*, int);
extern int Gui_Manager(void);
extern W33* GuiManager_OpenGui(int, char*, char*);
extern void GuiManager_CloseGui(int, W33*);
extern int cDME_GetLobby(void);
extern int SFOLobby_CheckMissionLobby(int, int);
extern int SFOLobby_CellIsPlayerInCell(int);
extern V33* Gui_Canvas(void);
extern void GuiWidget_SendMessage(W33*, V33*, int, int, int);
}
extern "C" int GuiLobbyScreen_PushLobbyScreen(O33* self, int type) {
    int c = -1;
    int h;
    W33* w;
    switch (type) {
    case 1: c = 0x78; break;
    case 3: c = 0x7A; break;
    case 4: c = 0x7B; break;
    case 9: c = 0x7C; break;
    case 2: c = 0x79; break;
    case 6: c = 0x79; break;
    }
    if (type == 1 && self->f84 == 9) c = -1;
    h = -1;
    if (c != -1) {
        G33* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, 0, 0, 0, 0), 0, 0);
        FrontEnd_StartSplashThread(D_004FFC04);
    }
    w = 0;
    switch (type) {
    case 0: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineConnect", "ONLINECN"); break;
    case 1: w = GuiManager_OpenGui(Gui_Manager(), "GuiCommandCenter", "CMDCENTR"); break;
    case 2: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetJoinMission", "JOINMIS"); break;
    case 6: w = GuiManager_OpenGui(Gui_Manager(), "GuiMissionSetup", "MSNSETUP"); break;
    case 3: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetAgencyCell", "AGENTCEL"); break;
    case 4: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetContacts", "CONTACTS"); break;
    case 5: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineOptions", "ONLIPREF"); break;
    case 9: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetMessages", "NETMESS"); break;
    case 7: w = GuiManager_OpenGui(Gui_Manager(), "GuiAccountLogin", "ACNTLOGN"); break;
    }
    if (c != -1) FrontEnd_StopSplashThread(D_004FFC04);
    if (w) {
        if (type == 6 || type == 2) {
            int x = D_004FFC04->f248;
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CheckMissionLobby(p, x)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 3) {
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CellIsPlayerInCell(p)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 0 || type == 7) w->f10 = 1;
    }
    ((S33*)self)->v24();
    if (w) {
        V33* m;
        w->flags &= ~2;
        m = Gui_Canvas();
        m->v23(w, 0);
    }
    Gui_Canvas()->v24(self);
    if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    if (w) {
        w->flags |= 2;
        GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 2, 0);
    }
    return 1;
}
static inline void merge_flush_func_0033C320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C320 */

/* merge_units: begin func_0033C7C0 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */

#if 0 /* merge_units */
extern int cGameFrontEnd_PushMessageBox(void*, int, char*, char*, int, int);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((G33 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PopMessageBox(void*, int);
#endif /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((G33 *)(a0), (a1))) /* merge_units */

extern int SFOLobby_ContactInviteAgent(int, int);
extern unsigned char SFOLobby_GetErrorDetails(int, int);
extern void std_basic_string_char_char_traits_char_ctor_charP(String*, char*);
extern char* std_basic_string_char_char_traits_char_c_str(String*);
extern void String_Dtor(String*, int);

void GuiLobbyScreen_ContactInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = cDME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x39, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_ContactInviteAgent(lobby, buddy)) {
        void* g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x3A, name, 0, 0, 0), 0, 0);
    } else {
        int c;
        String a;
        String b;
        switch (SFOLobby_GetErrorDetails(lobby, 0)) {
        case 0x1E: c = 0x3C; break;
        case 0x25: c = 0x3D; break;
        case 0x1D: c = 0x17; break;
        case 0x2A: c = 0x3E; break;
        default: c = 0x3F; break;
        }
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x3B, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
        {
            char* t = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), t, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
}
#undef D_004FFC04 /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
static inline void merge_flush_func_0033C7C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C7C0 */

/* merge_units: begin func_0033C9E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */

#if 0 /* merge_units */
extern int cGameFrontEnd_PushMessageBox(void*, int, char*, char*, int, int);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((G33 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PopMessageBox(void*, int);
#endif /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((G33 *)(a0), (a1))) /* merge_units */

extern int SFOLobby_CellInviteAgent(int, int);

void GuiLobbyScreen_CellInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = cDME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x4A, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_CellInviteAgent(lobby, buddy)) {
        void* g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x4B, name, 0, 0, 0), 0, 0);
    } else {
        unsigned char r = SFOLobby_GetErrorDetails(lobby, 0);
        if (r == 0x3F) {
            String a;
            String b;
            std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x4C, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 0x55, 0, 0, 0, 0));
            {
                char* t = std_basic_string_char_char_traits_char_c_str(&b);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 5, std_basic_string_char_char_traits_char_c_str(&a), t, (int)self, 0x13);
            }
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
        } else {
            int c;
            String a;
            String b;
            switch (r) {
            case 0x1E: c = 0x50; break;
            case 0x1D: c = 0x17; break;
            case 0x1F: c = 0x4E; break;
            case 0x2A: c = 0x4F; break;
            default: c = 0x4D; break;
            }
            std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x4C, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
            {
                char* t = std_basic_string_char_char_traits_char_c_str(&b);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), t, 0, 0);
            }
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
        }
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
}
#undef D_004FFC04 /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
static inline void merge_flush_func_0033C9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C9E0 */
