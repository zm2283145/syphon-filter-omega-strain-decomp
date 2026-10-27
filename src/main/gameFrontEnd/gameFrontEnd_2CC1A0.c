/*
 * main/gameFrontEnd: range (4 files, 002CC1A0-002CC3E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
char *strncpy(void *, const void *, int);

/* merge_units: begin func_002CC1A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_tAchievementInfo_dtor_void_2, func_00299360)
#pragma pop /* merge_units */
/* merge_units: end func_002CC1A0 */

/* merge_units: begin func_002CC200 */
#pragma push /* merge_units */
extern void* D_004FFC04;
extern void cGameFrontEnd_LobbySetAgentStats(void* p);
void cGameFrontEnd_LobbyStatsCallback(int mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        cGameFrontEnd_LobbySetAgentStats(D_004FFC04);
        break;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC200 */

/* merge_units: begin func_002CC260 */
#pragma push /* merge_units */
struct ObjCC260 { char pad[0x310]; unsigned char b310; };
#if 0 /* merge_units */
extern struct ObjCC260* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(struct ObjCC260 **)&D_004FFC04) /* merge_units */

extern unsigned char g_DebugTriangle;
extern char D_0055A300[];
void cGameFrontEnd_Render(struct ObjCC260*);
void cGameFrontEnd_NextFrame(struct ObjCC260*);
void cJoystick_Poll(void*);
void* Gui_Canvas(void);
void GuiCanvas_ProcessInput_void(void*);
void GuiWidget_SendChildrenMessage(void*, int, int, int);

void cGameFrontEnd_LobbyCallback(int arg0, int arg1)
{
    int i;

    if (g_DebugTriangle != 0) {
        return;
    }
    g_DebugTriangle = 1;
    if (arg0 == 0) {
        if (D_004FFC04->b310 == 0 || arg1 == 0x3039) {
            cGameFrontEnd_NextFrame(D_004FFC04);
            cGameFrontEnd_Render(D_004FFC04);
        }
    } else if (arg0 == 1) {
        cJoystick_Poll(D_0055A300);
        GuiCanvas_ProcessInput_void(Gui_Canvas());
        if (D_004FFC04->b310 == 0) {
            cGameFrontEnd_NextFrame(D_004FFC04);
            cGameFrontEnd_Render(D_004FFC04);
        }
    } else if (arg0 == 2) {
        if (arg1 == 2) {
            GuiWidget_SendChildrenMessage(Gui_Canvas(), 0x2001, 0, 0);
            if (D_004FFC04->b310 == 0) {
                for (i = 0; i < 3; i++) {
                    cGameFrontEnd_NextFrame(D_004FFC04);
                    cGameFrontEnd_Render(D_004FFC04);
                }
            }
        }
    } else if (arg0 == 3) {
        GuiWidget_SendChildrenMessage(Gui_Canvas(), 0x2002, arg1, 0);
    }
    g_DebugTriangle = 0;
}
#undef D_004FFC04 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC260 */

/* merge_units: begin func_002CC3E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; unsigned char b2C; char pad2[0x2AC - 0x2D]; char name[0x40]; } ObjC3E0;
typedef struct { char pad[0x250]; unsigned char mode; } HudC3E0;
static unsigned int dat_0048C248[2] = { 0x1, 0x0 };
extern void* g_OptionsRecord;
extern char D_004ACFA8[];
extern int D_005383D4;
extern void cGameOptions_Load(void* p);
extern void SFOLevels_SetupMissionInfo(void);
extern char* cSFOini_GetKeyValue(char* key);
extern void cGameFrontEnd_InitGui(ObjC3E0* o, int a);
extern HudC3E0* GetMachine(void);
void cGameFrontEnd_Init(ObjC3E0* o)
{
    if ((*(unsigned char*)dat_0048C248)) {
        char* s;
        cGameOptions_Load(g_OptionsRecord);
        o->b2C = 0;
        SFOLevels_SetupMissionInfo();
        s = cSFOini_GetKeyValue(D_004ACFA8);
        if (s)
            strncpy(o->name, s, 0x40);
        (*(unsigned char*)dat_0048C248) = 0;
    }
    cGameFrontEnd_InitGui(o, 0);
    D_005383D4 = (GetMachine()->mode == 2) ? 0x32 : 0x3C;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC3E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC3E0 */
