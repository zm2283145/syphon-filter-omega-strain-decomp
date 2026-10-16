/*
 * main/GuiSliderWidget: 3 files, 0043F6F0-0043F850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043F6F0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int GuiWidget_BroadcastEvent(char * , int, int, int);                 
int func_0041E2B0();                                  

void GuiSliderWidget_OnLoseFocus(char * arg0) {
    char * temp_v0;
    int temp_a0;
    int temp_t1;
    int temp_t0;
    float r;

    func_0041E2B0();
    F_(arg0, 0x48, int) = 1;
    temp_a0 = F_(arg0, 0x48, int);
    if (F_((char *)temp_a0 + (int)arg0, 0x4C, unsigned char) != 0) {
        temp_t1 = F_(arg0, 0x68, int);
        temp_v0 = (char *)(temp_a0 * 4) + (int)(arg0);
        temp_t0 = F_(temp_v0, 0x50, int);
        r = (float) (F_(arg0, 0x64, int) - temp_t1) / (float) (F_(arg0, 0x6C, int) - temp_t1);
        GuiWidget_BroadcastEvent(arg0, 0xA, temp_t0 + (int) (r * (float) (F_(temp_v0, 0x58, int) - temp_t0)), 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043F6F0 */

/* merge_units: begin func_0043F7A0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                 
int func_0041E330();                                  

void GuiSliderWidget_OnGainFocus(char * arg0) {
    float r_;
    char * temp_v0;
    int temp_a0;
    int temp_t1;
    int temp_t0;

    func_0041E330();
    F_(arg0, 0x48, int) = 0;
    temp_a0 = F_(arg0, 0x48, int);
    if (F_((char *)temp_a0 + (int)arg0, 0x4C, unsigned char) != 0) {
        temp_t1 = F_(arg0, 0x68, int);
        temp_v0 = (char *)(temp_a0 * 4) + (int)(arg0);
        temp_t0 = F_(temp_v0, 0x50, int);
        r_ = (float) (F_(arg0, 0x64, int) - temp_t1) / (float) (F_(arg0, 0x6C, int) - temp_t1);
        GuiWidget_BroadcastEvent(arg0, 0xA, temp_t0 + (int) (r_ * (float) (F_(temp_v0, 0x58, int) - temp_t0)), 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043F7A0 */

/* merge_units: begin func_0043F850 */
#pragma push /* merge_units */
typedef struct { char p[0x10]; int f10; int f14; } D43F850;
typedef struct { char p[0x4C]; unsigned char vis[4]; int x0[2]; int x1[2]; } W43F850;
extern void GuiWidget_Init(W43F850* w);
extern int GuiWidget_SendEvent(W43F850* w, W43F850* src, int kind, int a, int out);
extern char D_004C01D0[];
extern char D_004C01E0[];
static int D_004976C0[] = { (int)D_004C01D0, (int)D_004C01E0 };
void GuiSliderWidget_Init(W43F850* w)
{
    int i;
    D43F850* d[1];
    GuiWidget_Init(w);
    for (i = 0; i < 2; i++) {
        d[0] = 0;
        if (GuiWidget_SendEvent(w, w, 4, D_004976C0[i], (int)d) && d[0]) {
            w->vis[i] = 1;
            w->x0[i] = d[0]->f10;
            w->x1[i] = d[0]->f14;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043F850 */
