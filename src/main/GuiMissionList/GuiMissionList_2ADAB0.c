/*
 * main/GuiMissionList: 3 files, 002ADAB0-002ADE60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ADAB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct S_002ADAB0 {
    char pad0[0x88]; void* p88; char pad8C[0xC]; void* p98; char pad9C[0x64]; int f100; char s104[0x5C]; void* p160;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004ABB08[];
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
int func_0033CE30(S_002ADAB0* self, int a, char* b, int c, int d, int e);
void GuiKeyboard_Open(void* pg, int a, char* b, S_002ADAB0* c, int d, int e, int f);
void* DME_GetLobby(void);
char* String_CStr(void* s);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_002ADAB0* d, int e);
int func_0044D9C0(void* g, int a);
void FrontEnd_ClosePopup(void* ui, int id);
int SFOLobby_LookupAccountId(void* g, char* t);
int func_00452FF0(void* g, int a);
void func_0033C7C0(S_002ADAB0* self, int r, char* t);
void func_0033D8E0(S_002ADAB0* self, int a);
int func_0033DF00(S_002ADAB0* self, void* w, int msg, int sub, char* text);
}
extern "C" int func_002ADAB0(S_002ADAB0* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 2 && w == self->p160) {
        void* pg = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiKeyboard", "KEYBOARD");
        if (pg)
            GuiKeyboard_Open(pg, func_0033CE30(self, 0x40, 0, 0, 0, 0), D_004ABB08, self, 0xF, 0xC, 0);
        return 1;
    }
    if (m == 0x1A) {
        if (sub == 0xD) {
            void* g = DME_GetLobby();
            if (g) {
                int h;
                char* nm = String_CStr(self->s104);
                void* ui = D_004FFC04;
                h = FrontEnd_OpenPopup(ui, 0, D_004ABB08, func_0033CE30(self, 0x36, nm, 0, 0, 0), 0, 0);
                if (func_0044D9C0(g, self->f100)) {
                    char* nm2 = String_CStr(self->s104);
                    void* ui2 = D_004FFC04;
                    FrontEnd_OpenPopup(ui2, 2, D_004ABB08, func_0033CE30(self, 0x37, nm2, 0, 0, 0), 0, 0);
                } else {
                    char* nm3 = String_CStr(self->s104);
                    void* ui3 = D_004FFC04;
                    FrontEnd_OpenPopup(ui3, 2, D_004ABB08, func_0033CE30(self, 0x38, nm3, 0, 0, 0), 0, 0);
                }
                FrontEnd_ClosePopup(D_004FFC04, h);
            }
            return 1;
        }
        if (sub == 0xC) {
            if (text && *text) {
                void* g = DME_GetLobby();
                if (g) {
                    int r = SFOLobby_LookupAccountId(g, text);
                    if ((unsigned char)func_00452FF0(g, 0)) {
                        void* ui = D_004FFC04;
                        FrontEnd_OpenPopup(ui, 2, D_004ABB08, func_0033CE30(self, 0x17, text, 0, 0, 0), 0, 0);
                    } else {
                        func_0033C7C0(self, r, text);
                    }
                }
            }
            return 1;
        }
    }
    if (m == 0 && w != self->p88) {
        if (w == self->p98)
            func_0033D8E0(self, 3);
        else if (w == self->p160)
            func_0033D8E0(self, 4);
        else
            func_0033D8E0(self, 1);
    }
    return func_0033DF00(self, w, msg, sub, text);
}
#pragma pop /* merge_units */
/* merge_units: end func_002ADAB0 */

/* merge_units: begin func_002ADE00 */
#pragma push /* merge_units */
#include "active_flag_release.h"

/* Stop and release when active. */
DEFINE_ACTIVE_FLAG_RELEASE(func_002ADE00, SFOLobby_LeaveContactsState)
#pragma pop /* merge_units */
/* merge_units: end func_002ADE00 */

/* merge_units: begin func_002ADE60 */
#pragma push /* merge_units */
typedef struct { char pad[0xB4]; unsigned char bB4; unsigned char bB5; } P2ADE60;
typedef struct { char pad[0x255C]; int mode; } G2ADE60;
typedef struct { char pad0[0x80]; unsigned char shown; char pad81[7]; P2ADE60* p88; char pad8C[0xAC - 0x8C]; char mAC[0x1C]; char mC8[4]; } S2ADE60;
#if 0 /* merge_units */
extern G2ADE60* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((G2ADE60 *)DME_GetLobby()) /* merge_units */

extern void func_004426B0(G2ADE60* g);
extern void App_CardWaitPoll(void);
extern void SFOLobby_EnterContactsState(G2ADE60* g, void* cb, void* a, void* b);
void func_002ADE60(S2ADE60* s)
{
    if (!s->shown) {
        G2ADE60* g = DME_GetLobby();
        if (g) {
            if (g->mode == 4)
                func_004426B0(g);
            SFOLobby_EnterContactsState(g, App_CardWaitPoll, s->mAC, s->mC8);
        }
        if (s->p88) {
            s->p88->bB4 = 1;
            s->p88->bB5 = 1;
        }
        s->shown = 1;
    }
}
#undef DME_GetLobby /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002ADE60 */
