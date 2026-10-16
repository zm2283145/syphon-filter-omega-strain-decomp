/*
 * main/gameFrontEnd: range (2 files, 002C7C40-002C7CB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_002C7C40 */
#pragma push /* merge_units */
#pragma opt_propagation off
extern long long Time_GetMilliseconds(void);
extern int D_0048C368;
extern int D_0051EF98;
extern char* func_002CCA30(void);
extern void func_002C8840(char* s);
void func_002C7C40(int a, int b)
{
    char buf[0x100];
    char* fmt;
    int t = Time_GetMilliseconds();
    D_0048C368 = b;
    D_0051EF98 = t;
    fmt = "gamedata\\frontend\\lang\\%s\\%s.tdx";
    sprintf(buf, fmt, func_002CCA30(), a);
    func_002C8840(buf);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C7C40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C7C40 */

/* merge_units: begin func_002C7CB0 */
#pragma push /* merge_units */
extern int D_0051EF78;
extern int D_0048C360;
extern int D_0051EF88;
extern int D_0051EF90;
#if 0 /* merge_units */
extern unsigned long long Time_GetMilliseconds(void);
#endif /* merge_units */
#define Time_GetMilliseconds() ((unsigned long long)Time_GetMilliseconds()) /* merge_units */

extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(int, int, int, int, int);

int func_002C7CB0(char* self) {
    float f;
    long long t;
    int h;

    if (*(unsigned char*)(self + 0x2D) == 0) {
        return 1;
    }
    t = D_0051EF78 + D_0048C360;
    if (t < Time_GetMilliseconds()) {
        return 1;
    }
    h = D_0051EF88;
    if (h != 0 && D_0051EF90 != 0) {
        f = 0.0f;
        GuiWidget_SendEvent(Gui_GetScreenStack(), h, 9, (int)&f, 0);
        if (D_0051EF90 == (int)f) {
            return 1;
        }
    }
    return 0;
}
#undef Time_GetMilliseconds /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C7CB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C7CB0 */
