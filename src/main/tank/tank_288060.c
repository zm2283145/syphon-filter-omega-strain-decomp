/*
 * main/tank: 3 files, 00288060-002882B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00288060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

class VObj288060 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(void* who, int flag);
};

typedef struct {
    char pad[0x14];
    unsigned short x14;
    char pad16[0xE];
    VObj288060* x24;
} Ent288060;

typedef struct {
    char pad[0x48];
    unsigned char x48;
    char pad49[3];
    float x4C;
} Self288060;

typedef struct {
    char pad[8];
    Self288060* x8;
} Cam288060;

typedef struct {
    char pad[0x20];
    Ent288060* x20;
    char pad24[8];
    Cam288060* x2C;
} Game288060;

typedef struct {
    char pad[0x59D];
    unsigned char x59D;
} Cfg288060;

typedef struct {
    char pad[0x39];
    char name[0x103];
    int x13C;
} Ui288060;

extern "C" int D_0048B3F0;
extern "C" Cfg288060* g_MemCard;
extern "C" unsigned char D_004FFBB8;
extern "C" unsigned char D_004FFBB1;
extern "C" Ui288060* D_004FFC04;
extern "C" char D_004A95E8[];
extern "C" signed char g_GameState;
extern "C" signed char g_PrevGameState;

extern "C" Ent288060* GuiWidget_FindChild_charP(Self288060* self, int id);
extern "C" unsigned char GuiTitleScreen_SavedAgentExists(void);
extern "C" Game288060* Gui_Canvas(void);
extern "C" void GuiCanvas_SetFocus(Game288060* g, int v);
extern "C" int cTimer_GetMillisecondTime(void);
extern "C" float _f_ulltof(int t);
extern "C" void Libc_Strcpy(char* dst, const char* src);
extern "C" void GuiWidget_onAdvanceTime(Self288060* self, float dt);

extern "C" void GuiTitleScreen_onAdvanceTime(Self288060* self, float dt)
{
    Ent288060* e = GuiWidget_FindChild_charP(self, D_0048B3F0);
    unsigned char flag = g_MemCard->x59D != 0;
    if (e) {
        unsigned char s = GuiTitleScreen_SavedAgentExists();
        if (!s && Gui_Canvas()->x20 == e) {
            GuiCanvas_SetFocus(Gui_Canvas(), e->x24->v17(e, 1));
        }
        if (s) {
            e->x14 |= 4;
        } else {
            e->x14 &= ~4;
        }
    }
    D_004FFBB8 = flag;
    if (self->x48) {
        if (Gui_Canvas()->x2C->x8 != self) {
            self->x4C = _f_ulltof(cTimer_GetMillisecondTime()) / 1000.0f;
        } else {
            float t = _f_ulltof(cTimer_GetMillisecondTime()) / 1000.0f;
            if (D_004FFBB1 && t - self->x4C > 30.0f) {
                D_004FFC04->x13C = 1;
                Libc_Strcpy(D_004FFC04->name, D_004A95E8);
                g_PrevGameState = g_GameState;
                g_GameState = 4;
            }
        }
    }
    GuiWidget_onAdvanceTime(self, dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_00288060 */

/* merge_units: begin func_00288260 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
float _f_ulltof(int);
#endif /* merge_units */
#define _f_ulltof(a0) ((float)_f_ulltof((a0))) /* merge_units */
                             
#if 0 /* merge_units */
int cTimer_GetMillisecondTime();
#endif /* merge_units */
#define cTimer_GetMillisecondTime() ((int)cTimer_GetMillisecondTime()) /* merge_units */
                                

int GuiTitleScreen_onInput(int arg0) {
    F_(arg0, 0x4C, float) = (float) (_f_ulltof(cTimer_GetMillisecondTime()) / 1000.0f);
    return 0;
}
#undef _f_ulltof /* merge_units */
#undef cTimer_GetMillisecondTime /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00288260 */

/* merge_units: begin func_002882B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int cGameSystem_GetAgentData(void*, int);
extern void* g_Game;
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern int GuiTitleScreen_VerifyMemCard(Unk288A80*, int);
extern int cGameFrontEnd_PlayMusic(int, int);
extern int cAgentData_Clear(int);
extern int GuiWidget_onWake(Unk288A80*);

int GuiTitleScreen_onWake(Unk288A80* self) {
    GuiWidget_onWake(self);
    cAgentData_Clear(cGameSystem_GetAgentData(&g_Game, -1));
    cGameFrontEnd_PlayMusic(D_004FFC04, 0);
    return GuiTitleScreen_VerifyMemCard(self, 0);
}
#undef D_004FFC04 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002882B0 */
