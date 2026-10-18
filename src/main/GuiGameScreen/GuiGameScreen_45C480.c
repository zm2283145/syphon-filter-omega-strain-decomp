/*
 * main/GuiGameScreen: range (2 files, 0045C480-0045C540)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0045C480 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int WeaponDb_Get(int, int);
int WeaponInv_GetHeldItem(int);
int WeaponInv_HolsterCurrent(int, int);
int WeaponInv_SlotOfItem(int, int);
int Player_EquipItem(char * , int);
extern char * D_004FFC0C;
extern int D_004FFD30;

void GuiGameScreen_EquipSelected(char * arg0) {
    int temp_a1;
    int temp_s2;
    int temp_a1_2;
    char * temp_s1;
    int temp_v0;

    temp_a1 = F_(arg0, 0x90, int);
    if (temp_a1 != -1) {
        temp_a1_2 = temp_a1 * 4;
        temp_s2 = *(int *)((char *)F_(arg0, 0x78, int) + temp_a1_2);
        temp_s1 = (char *)(F_(D_004FFC0C, 0x30, int));
        if (temp_s2 != -2) {
            if ((WeaponInv_SlotOfItem(temp_s2, temp_a1_2) & 0xFF) < 6) {
                temp_v0 = WeaponDb_Get(D_004FFD30, temp_s2);
                if ((temp_v0 != 0) && (temp_v0 != WeaponInv_GetHeldItem(F_(temp_s1, 0x3524, int)))) {
                    Player_EquipItem(D_004FFC0C, temp_s2);
                }
            }
        } else {
            WeaponInv_HolsterCurrent(F_(temp_s1, 0x3524, int), temp_a1_2);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045C480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045C480 */

/* merge_units: begin func_0045C540 */
#pragma push /* merge_units */
typedef struct { char p[0x6C]; void* f6C; char p70[4]; int count; char p78[0x18]; int sel; char p94[8]; unsigned char b9C; } W45C540;
extern void GuiGameScreen_FillWeaponPanels(W45C540* w);
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* w, void* src, int kind, int a, int b);
void GuiGameScreen_StepWeaponSelect(W45C540* w, int dir)
{
    int i;
    if (w->count <= 1) return;
    w->b9C = 1;
    i = w->sel + (dir ? 1 : -1);
    if (i < 0) i = w->count - 1; else if (!(i < w->count)) i = 0;
    w->sel = i;
    GuiGameScreen_FillWeaponPanels(w);
    GuiWidget_SendEvent(w->f6C, Gui_GetScreenStack(), 0x10, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045C540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045C540 */
