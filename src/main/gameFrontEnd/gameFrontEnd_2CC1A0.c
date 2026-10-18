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
DEFINE_DIRECT_BASE_DTOR(func_002CC1A0, func_00299360)
#pragma pop /* merge_units */
/* merge_units: end func_002CC1A0 */

/* merge_units: begin func_002CC200 */
#pragma push /* merge_units */
extern void* D_004FFC04;
extern void func_002CBD40(void* p);
void func_002CC200(int mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_002CBD40(D_004FFC04);
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

extern unsigned char D_0051EEB0;
extern char D_0055A300[];
void FrontEnd_DrawGui(struct ObjCC260*);
void FrontEnd_UpdateGui(struct ObjCC260*);
void Pad_Reset(void*);
void* Gui_GetScreenStack(void);
void GuiCanvas_UpdatePads(void*);
void GuiWidget_BroadcastEvent(void*, int, int, int);

void App_CardWaitPoll(int arg0, int arg1)
{
    int i;

    if (D_0051EEB0 != 0) {
        return;
    }
    D_0051EEB0 = 1;
    if (arg0 == 0) {
        if (D_004FFC04->b310 == 0 || arg1 == 0x3039) {
            FrontEnd_UpdateGui(D_004FFC04);
            FrontEnd_DrawGui(D_004FFC04);
        }
    } else if (arg0 == 1) {
        Pad_Reset(D_0055A300);
        GuiCanvas_UpdatePads(Gui_GetScreenStack());
        if (D_004FFC04->b310 == 0) {
            FrontEnd_UpdateGui(D_004FFC04);
            FrontEnd_DrawGui(D_004FFC04);
        }
    } else if (arg0 == 2) {
        if (arg1 == 2) {
            GuiWidget_BroadcastEvent(Gui_GetScreenStack(), 0x2001, 0, 0);
            if (D_004FFC04->b310 == 0) {
                for (i = 0; i < 3; i++) {
                    FrontEnd_UpdateGui(D_004FFC04);
                    FrontEnd_DrawGui(D_004FFC04);
                }
            }
        }
    } else if (arg0 == 3) {
        GuiWidget_BroadcastEvent(Gui_GetScreenStack(), 0x2002, arg1, 0);
    }
    D_0051EEB0 = 0;
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
extern void* D_004FFD2C;
extern char D_004ACFA8[];
extern int D_005383D4;
extern void Options_Load(void* p);
extern void func_002CC980(void);
extern char* func_003CBA90(char* key);
extern void FrontEnd_StartGui(ObjC3E0* o, int a);
extern HudC3E0* App_GetInstance(void);
void FrontEnd_FirstEntry(ObjC3E0* o)
{
    if ((*(unsigned char*)dat_0048C248)) {
        char* s;
        Options_Load(D_004FFD2C);
        o->b2C = 0;
        func_002CC980();
        s = func_003CBA90(D_004ACFA8);
        if (s)
            strncpy(o->name, s, 0x40);
        (*(unsigned char*)dat_0048C248) = 0;
    }
    FrontEnd_StartGui(o, 0);
    D_005383D4 = (App_GetInstance()->mode == 2) ? 0x32 : 0x3C;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC3E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC3E0 */
