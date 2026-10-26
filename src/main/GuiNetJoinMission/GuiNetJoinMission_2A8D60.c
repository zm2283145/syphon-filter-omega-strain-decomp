/*
 * main/GuiNetJoinMission: 3 files, 002A8D60-002A9030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A8D60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Mgr_002A8D60 { char pad[0x268]; int f268; };
struct S_002A8D60 { char pad0[0x98]; void* p98; void* p9C; void* pA0; char padA4[0x160 - 0xA4]; void* p160; void* p164; void* p168; };
extern "C" {
extern Mgr_002A8D60* D_004FFC04;
extern char* D_0048BBD8;
extern char* D_0048BBE0;
void GuiScreen_Navigate(S_002A8D60* self, int a);
int GuiMissionLobbyScreen_GetDisplayMode(S_002A8D60* self);
void GuiMissionLobbyScreen_SetDisplayMode(S_002A8D60* self, int a);
void* DME_GetLobby(void);
void SFOLobby_LobbySetDisplay(void* g, int a);
char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
void func_0033D800(S_002A8D60* self);
int GuiMenuScreen_HandleEvent(S_002A8D60* self, void* w, int msg, int sub, char* text);
}
extern "C" int GuiNetJoinMission_HandleEvent(S_002A8D60* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x1A && sub == 0xB) {
        GuiScreen_Navigate(self, 1);
        return 1;
    }
    if (m == 2) {
        if (w == self->p164) {
            D_004FFC04->f268 = 2;
            GuiScreen_Navigate(self, 5);
            return 1;
        }
        if (w == self->p160) {
            if ((unsigned char)GuiMissionLobbyScreen_GetDisplayMode(self) == 2) {
                char* t;
                GuiMissionLobbyScreen_SetDisplayMode(self, 0);
                if (DME_GetLobby())
                    SFOLobby_LobbySetDisplay(DME_GetLobby(), 1);
                t = Loc_LookupText(D_0048BBD8);
                if (t && self->p160)
                    GuiTextWidget_SetText(self->p160, t, 0);
            } else {
                char* t;
                GuiMissionLobbyScreen_SetDisplayMode(self, 2);
                if (DME_GetLobby())
                    SFOLobby_LobbySetDisplay(DME_GetLobby(), 0);
                t = Loc_LookupText(D_0048BBE0);
                if (t && self->p160)
                    GuiTextWidget_SetText(self->p160, t, 0);
            }
            return 1;
        }
        if (w == self->p168) {
            func_0033D800(self);
            return 1;
        }
    }
    if (m == 0) {
        if (w == self->p9C)
            GuiMissionLobbyScreen_SetDisplayMode(self, 2);
        else if (w == self->p98)
            GuiMissionLobbyScreen_SetDisplayMode(self, 0);
        else if (w == self->pA0)
            GuiMissionLobbyScreen_SetDisplayMode(self, 2);
        else if (w == self->p164)
            GuiMissionLobbyScreen_SetDisplayMode(self, 4);
        else if (w == self->p168)
            GuiMissionLobbyScreen_SetDisplayMode(self, 0);
    }
    return GuiMenuScreen_HandleEvent(self, w, msg, sub, text);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A8D60 */

/* merge_units: begin func_002A8FD0 */
#pragma push /* merge_units */
#include "active_flag_release.h"

/* Stop and release when active. */
DEFINE_ACTIVE_FLAG_RELEASE(GuiNetJoinMission_Deactivate, SFOLobby_LeaveRoom)
#pragma pop /* merge_units */
/* merge_units: end func_002A8FD0 */

/* merge_units: begin func_002A9030 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VObj2A { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct Lobby2A { char p[0x255C]; int state; };
struct Sub2A { char p[0xB4]; unsigned char flag; };
struct W2A9030 { char p[0x80]; unsigned char done; char p81[7]; Sub2A* sub; char p8c[0x20]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x7C]; VObj2A* label; };
extern "C" {
extern char* D_0048BBC8;
extern char* D_0048BBD0;
extern char D_004A7520[];
extern char D_004AB6B8[];
extern char g_Game[];
#if 0 /* merge_units */
extern char* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(char **)&D_004FFC04) /* merge_units */

void App_CardWaitPoll();
#if 0 /* merge_units */
Lobby2A* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((Lobby2A *)DME_GetLobby()) /* merge_units */

void SFOLobby_MissionScreenExit(Lobby2A*);
int SFOLobby_JoinRoom(Lobby2A*, void (*)(), void*, void*, void*);
int GuiScreen_GetLobbyString(W2A9030*, int, int, int, int, int);
void FrontEnd_OpenPopup(char*, int, char*, int, W2A9030*, int);
VObj2A* GuiWidget_FindChildByName(W2A9030*, char*);
#if 0 /* merge_units */
void GuiTextWidget_SetText(VObj2A*, char*, int);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (a1), (a2))) /* merge_units */

char* Agent_GetSelected(void*, int);
#if 0 /* merge_units */
void GuiMissionLobbyScreen_SetDisplayMode(W2A9030*, int);
#endif /* merge_units */
#define GuiMissionLobbyScreen_SetDisplayMode(a0, a1) (GuiMissionLobbyScreen_SetDisplayMode((S_002A8D60 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void SFOLobby_LobbySetDisplay(Lobby2A*, int);
#endif /* merge_units */
#define SFOLobby_LobbySetDisplay(a0, a1) (SFOLobby_LobbySetDisplay((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* Loc_LookupText(char*);
#endif /* merge_units */
#define Loc_LookupText(a0) (Loc_LookupText((a0))) /* merge_units */

}


extern "C" void GuiNetJoinMission_Activate(W2A9030* self)
{
    if (!self->done) {
        Lobby2A* l = DME_GetLobby();
        VObj2A* o;
        char* s;
        if (l) {
            if (l->state == 4) SFOLobby_MissionScreenExit(l);
            if (!SFOLobby_JoinRoom(l, App_CardWaitPoll, self->mAC, self->mC8, self->mE4)) {
                char* g = D_004FFC04;
                FrontEnd_OpenPopup(g, 2, D_004AB6B8, GuiScreen_GetLobbyString(self, 0x5A, 0, 0, 0, 0), self, 0xB);
            }
        }
        o = GuiWidget_FindChildByName(self, D_0048BBD0);
        o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
        if (o) GuiTextWidget_SetText(o, D_004FFC04 + 0x1C8, 0);
        o = GuiWidget_FindChildByName(self, D_0048BBC8);
        o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
        if (o) GuiTextWidget_SetText(o, Agent_GetSelected(g_Game, -1) + 0x95C, 0);
        GuiMissionLobbyScreen_SetDisplayMode(self, 0);
        if (DME_GetLobby()) SFOLobby_LobbySetDisplay(DME_GetLobby(), 1);
        s = Loc_LookupText(D_0048BBD8);
        if (s && self->label) GuiTextWidget_SetText(self->label, s, 0);
        if (self->sub) self->sub->flag = 0;
        self->done = 1;
    }
}
#undef D_004FFC04 /* merge_units */
#undef DME_GetLobby /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef GuiMissionLobbyScreen_SetDisplayMode /* merge_units */
#undef SFOLobby_LobbySetDisplay /* merge_units */
#undef Loc_LookupText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A9030 */
