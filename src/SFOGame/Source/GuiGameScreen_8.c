/*
 * SFOGame/Source/GuiGameScreen: 2 files, 0045D8D0-0045D960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045D8D0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int GuiWidget_onRender();                            
int GuiGameScreen_DrawWeaponPanelText();                            
int GuiGameScreen_WeaponRestoreTransparency();                            
int GuiGameScreen_WeaponSaveTransparency();                                  
extern char * g_Hud;

void GuiGameScreen_onRender(char * arg0) {
    if (F_(g_Hud, 0x6A8, unsigned char) == 0) {
        if (F_(F_(arg0, 0x6C, int), 0x14, unsigned short) & 2) {
            GuiGameScreen_WeaponSaveTransparency();
            GuiWidget_onRender(arg0);
            GuiGameScreen_WeaponRestoreTransparency(arg0);
            if (F_(arg0, 0xD4, int) == 1) {
                GuiGameScreen_DrawWeaponPanelText(arg0);
            }
        } else {
            GuiWidget_onRender();
        }
    }
}
static inline void merge_flush_func_0045D8D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045D8D0 */

/* merge_units: begin func_0045D960 */
#pragma push /* merge_units */
/* GuiGameScreen_onAdvanceTime (proto GuiGameScreen::onAdvanceTime): hides finished subtitles, shows who is
 * talking on the headset, and animates the weapon-select panel (open/close state and per-panel fade). */
#pragma cplusplus on
#pragma opt_pulloutconstants off
struct GuiWidget { char pad0[0x14]; unsigned short mFlags; char pad16[0x54 - 0x16]; float f54; };
struct GuiGameScreen : GuiWidget {
    char pad58[0x68 - 0x58];
    GuiWidget* mSubTitles;
    GuiWidget* mWeaponSelect;
    char pad70[0xA0 - 0x70];
    GuiWidget* mWeaponSelectActivePanel;
    GuiWidget* mWeaponSelectAnimWidget;
    GuiWidget* mWeaponSelectWeaponPanels[5];
    float mWeaponSelectWeaponFade[5];
    int mWeaponSelectCurrentState;
    int mWeaponSelectTargetState;
    char padD8[0xDC - 0xD8];
    int mWeaponSelectNumOpen;
    char padE0[0x120 - 0xE0];
    GuiWidget* mHeadset;
    GuiWidget* mHeadsetTalking;
};
extern "C" {
extern unsigned char D_00582B88;
extern int D_00582CF0;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern int D_00494178;
extern char g_Game[];
extern char D_004C2268[];
extern char D_004C2270[];
extern char D_004C2278[];
extern int D_00497ACC[];
extern int D_00497AEC[];
void GuiWidget_onAdvanceTime(GuiGameScreen* self);
int GuiSubTitleDisplay_IsFinishedPlaying(GuiWidget* w);
int HeadsetSemaphore_GetOwner(int a);
void NetGetMyClientIndex(int* slot, int session);
char* cGameSystem_GetClientPlayerName(void* game, int slot);
int sprintf(char* buf, const char* fmt, ...);
void GuiTextWidget_SetText(GuiWidget* w, const char* text, int f);
void GuiWidget_SendMessage(void* self, void* w, int msg, int a, int b);
void GuiGameScreen_onAdvanceTime(GuiGameScreen* self, float timeStep);
}
static inline int LocalSlot(void)
{
    int session = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}
/* max.s/min.s: C has no expression that emits these. */
static inline float Max(float a, float b)
{
    float r;
    asm { max.s r, a, b }
    return r;
}
static inline float Min(float a, float b)
{
    float r;
    asm { min.s r, a, b }
    return r;
}
void GuiGameScreen_onAdvanceTime(GuiGameScreen* self, float timeStep)
{
    int owner;
    char* name;
    char nameBuf[64];
    float curFrame;
    float step;
    int i;
    float min;
    float fade;
    GuiWidget_onAdvanceTime(self);
    if (self->mSubTitles && (self->mSubTitles->mFlags & 2) && GuiSubTitleDisplay_IsFinishedPlaying(self->mSubTitles))
        self->mSubTitles->mFlags &= ~2;
    if (D_00582B88) {
        self->mHeadset->mFlags |= 2;
        owner = HeadsetSemaphore_GetOwner(D_00582CF0);
        if (owner >= 0 && owner < 4) {
            if (owner == LocalSlot()) {
                self->mHeadsetTalking->mFlags &= ~2;
                GuiTextWidget_SetText(self->mHeadset, D_004C2268, 0);
                GuiWidget_SendMessage(self, self->mHeadset, 0xA, 1, 0);
            } else {
                self->mHeadsetTalking->mFlags |= 2;
                name = cGameSystem_GetClientPlayerName(g_Game, owner);
                sprintf(nameBuf, D_004C2270, 0x11, name);
                GuiTextWidget_SetText(self->mHeadset, nameBuf, 0);
                GuiWidget_SendMessage(self, self->mHeadset, 0xA, 2, 0);
            }
        } else {
            self->mHeadsetTalking->mFlags &= ~2;
            GuiTextWidget_SetText(self->mHeadset, D_004C2268, 0);
            GuiWidget_SendMessage(self, self->mHeadset, 0xA, 0, 0);
        }
    } else {
        self->mHeadset->mFlags &= ~2;
    }
    if (self->mWeaponSelect) {
    *(int*)&curFrame = 0;
    GuiWidget_SendMessage(self, self->mWeaponSelectAnimWidget, 9, (int)&curFrame, 0);
    curFrame = Min((float)D_00497AEC[self->mWeaponSelectNumOpen], curFrame);
    if (self->mWeaponSelectTargetState != self->mWeaponSelectCurrentState) {
        if (self->mWeaponSelectTargetState == 1) {
            if (curFrame == (float)D_00497AEC[self->mWeaponSelectNumOpen]) {
                self->mWeaponSelectCurrentState = 1;
                GuiWidget_SendMessage(self, self->mWeaponSelectActivePanel, 6, (int)D_004C2278, 0);
            }
        } else if (curFrame == (float)D_00497ACC[self->mWeaponSelectNumOpen]) {
            self->mWeaponSelectCurrentState = 0;
            self->mWeaponSelect->mFlags &= ~2;
        }
    }
    if (self->mWeaponSelect->mFlags & 2) {
    {
        int s = D_00497ACC[self->mWeaponSelectNumOpen];
        int e = D_00497AEC[self->mWeaponSelectNumOpen];
        curFrame -= (float)s;
        step = (float)(e - s) / (float)self->mWeaponSelectNumOpen;
    }
    for (i = 0; i < self->mWeaponSelectNumOpen; i++) {
        min = (float)i * step;
        if (curFrame >= min + step)
            fade = 0.0f;
        else if (curFrame < min)
            fade = 1.0f;
        else
            fade = 1.0f - (curFrame - min) / step;
        self->mWeaponSelectWeaponPanels[i]->f54 = Min(Max(fade, 0.0f), 1.0f);
        self->mWeaponSelectWeaponFade[i] = fade;
    }
    }
    }
}
static inline void merge_flush_func_0045D960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045D960 */
