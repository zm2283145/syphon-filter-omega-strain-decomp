/*
 * SFOGame/Source/GuiNetContacts: 4 files, 002ADA10-002ADAB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiMissionList_2ADA10 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char b[0xC]; } String;
typedef struct { int id; char name[1]; } NameRec;
typedef struct { char pad[0x100]; int id; String name; } Obj2AD;
extern void* D_004FFC04;
const unsigned int D_004ABB08[2] = { 0x0, 0x0 };
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flag);
#if 0 /* merge_units */
extern int std_basic_string_char_char_traits_char_c_str(String* s);
#endif /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(void* s); /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) ((int)std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int GuiLobbyScreen_GetLobbyString(Obj2AD* o, int type, int a, int b, int c, int d);
#endif /* merge_units */
int GuiLobbyScreen_GetLobbyString(void*, int, int, int, int, int); /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PushMessageBox(void* mgr, int a, const char* text, int b, Obj2AD* o, int c);
#endif /* merge_units */
int cGameFrontEnd_PushMessageBox(void*, int, void*, int, void*, int); /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) ((void)cGameFrontEnd_PushMessageBox((a0), (a1), (void *)(a2), (a3), (void *)(a4), (a5))) /* merge_units */


/* Sets the id and name from rec, then registers the object (event 0x35) with the manager. */
void GuiNetContacts_SelectAgentRemove(Obj2AD* o, NameRec* rec)
{
    void* mgr;
    String tmp;
    int h;
    o->id = rec->id;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, rec->name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &tmp);
    String_Dtor(&tmp, 0);
    h = std_basic_string_char_char_traits_char_c_str(&o->name);
    mgr = D_004FFC04;
    cGameFrontEnd_PushMessageBox(mgr, 5, ((char*)D_004ABB08), GuiLobbyScreen_GetLobbyString(o, 0x35, h, 0, 0, 0), o, 0xD);
}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
static inline void merge_flush_GuiMissionList_2ADA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMissionList_2ADA10 */

/* merge_units: begin func_002ADAB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S_002ADAB0 {
    char pad0[0x88]; void* p88; char pad8C[0xC]; void* p98; char pad9C[0x64]; int f100; char s104[0x5C]; void* p160;
};
extern "C" {
#if 0 /* merge_units */
extern char D_004ABB08[];
#endif /* merge_units */
#define D_004ABB08 ((char*)&D_004ABB08) /* merge_units */

void* Gui_Manager(void);
void* GuiManager_OpenGui(void* a, char* b, char* c);
#if 0 /* merge_units */
int GuiLobbyScreen_GetLobbyString(S_002ADAB0* self, int a, char* b, int c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((void *)(a0), (a1), (int)(a2), (a3), (a4), (a5))) /* merge_units */

void GuiKeyboard_Display(void* pg, int a, char* b, S_002ADAB0* c, int d, int e, int f);
void* cDME_GetLobby(void);
char* std_basic_string_char_char_traits_char_c_str(void* s);
#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, int c, S_002ADAB0* d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (void *)(a2), (a3), (void *)(a4), (a5))) /* merge_units */

int func_0044D9C0(void* g, int a);
void cGameFrontEnd_PopMessageBox(void* ui, int id);
int SFOLobby_GetAgentID(void* g, char* t);
int SFOLobby_GetErrorDetails(void* g, int a);
void GuiLobbyScreen_ContactInviteAgent(S_002ADAB0* self, int r, char* t);
void GuiMissionLobbyScreen_SetDisplayMode(S_002ADAB0* self, int a);
int GuiMissionLobbyScreen_onMessage(S_002ADAB0* self, void* w, int msg, int sub, char* text);
}
extern "C" int GuiNetContacts_onMessage(S_002ADAB0* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 2 && w == self->p160) {
        void* pg = GuiManager_OpenGui(Gui_Manager(), "GuiKeyboard", "KEYBOARD");
        if (pg)
            GuiKeyboard_Display(pg, GuiLobbyScreen_GetLobbyString(self, 0x40, 0, 0, 0, 0), D_004ABB08, self, 0xF, 0xC, 0);
        return 1;
    }
    if (m == 0x1A) {
        if (sub == 0xD) {
            void* g = cDME_GetLobby();
            if (g) {
                int h;
                char* nm = std_basic_string_char_char_traits_char_c_str(self->s104);
                void* ui = D_004FFC04;
                h = cGameFrontEnd_PushMessageBox(ui, 0, D_004ABB08, GuiLobbyScreen_GetLobbyString(self, 0x36, nm, 0, 0, 0), 0, 0);
                if (func_0044D9C0(g, self->f100)) {
                    char* nm2 = std_basic_string_char_char_traits_char_c_str(self->s104);
                    void* ui2 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(ui2, 2, D_004ABB08, GuiLobbyScreen_GetLobbyString(self, 0x37, nm2, 0, 0, 0), 0, 0);
                } else {
                    char* nm3 = std_basic_string_char_char_traits_char_c_str(self->s104);
                    void* ui3 = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(ui3, 2, D_004ABB08, GuiLobbyScreen_GetLobbyString(self, 0x38, nm3, 0, 0, 0), 0, 0);
                }
                cGameFrontEnd_PopMessageBox(D_004FFC04, h);
            }
            return 1;
        }
        if (sub == 0xC) {
            if (text && *text) {
                void* g = cDME_GetLobby();
                if (g) {
                    int r = SFOLobby_GetAgentID(g, text);
                    if ((unsigned char)SFOLobby_GetErrorDetails(g, 0)) {
                        void* ui = D_004FFC04;
                        cGameFrontEnd_PushMessageBox(ui, 2, D_004ABB08, GuiLobbyScreen_GetLobbyString(self, 0x17, text, 0, 0, 0), 0, 0);
                    } else {
                        GuiLobbyScreen_ContactInviteAgent(self, r, text);
                    }
                }
            }
            return 1;
        }
    }
    if (m == 0 && w != self->p88) {
        if (w == self->p98)
            GuiMissionLobbyScreen_SetDisplayMode(self, 3);
        else if (w == self->p160)
            GuiMissionLobbyScreen_SetDisplayMode(self, 4);
        else
            GuiMissionLobbyScreen_SetDisplayMode(self, 1);
    }
    return GuiMissionLobbyScreen_onMessage(self, w, msg, sub, text);
}
#undef D_004ABB08 /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
static inline void merge_flush_func_002ADAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ADAB0 */

/* merge_units: begin func_002ADE00 */
#pragma push /* merge_units */
#include "active_flag_release.h"

/* Stop and release when active. */
DEFINE_ACTIVE_FLAG_RELEASE(GuiNetContacts_Deactivate, SFOLobby_ContactScreenExit)
static inline void merge_flush_func_002ADE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ADE00 */

/* merge_units: begin func_002ADE60 */
#pragma push /* merge_units */
typedef struct { char pad[0xB4]; unsigned char bB4; unsigned char bB5; } P2ADE60;
typedef struct { char pad[0x255C]; int mode; } G2ADE60;
typedef struct { char pad0[0x80]; unsigned char shown; char pad81[7]; P2ADE60* p88; char pad8C[0xAC - 0x8C]; char mAC[0x1C]; char mC8[4]; } S2ADE60;
#if 0 /* merge_units */
extern G2ADE60* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((G2ADE60 *)cDME_GetLobby()) /* merge_units */


extern void SFOLobby_MissionScreenExit(G2ADE60* g);
extern void cGameFrontEnd_LobbyCallback(void);
extern void SFOLobby_ContactScreenStart(G2ADE60* g, void* cb, void* a, void* b);
void GuiNetContacts_Activate(S2ADE60* s)
{
    if (!s->shown) {
        G2ADE60* g = cDME_GetLobby();
        if (g) {
            if (g->mode == 4)
                SFOLobby_MissionScreenExit(g);
            SFOLobby_ContactScreenStart(g, cGameFrontEnd_LobbyCallback, s->mAC, s->mC8);
        }
        if (s->p88) {
            s->p88->bB4 = 1;
            s->p88->bB5 = 1;
        }
        s->shown = 1;
    }
}
#undef cDME_GetLobby /* merge_units */
static inline void merge_flush_func_002ADE60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ADE60 */
