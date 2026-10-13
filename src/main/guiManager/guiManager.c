/*
 * main/guiManager: 2 files, 00418FD0-00419020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418FD0 */
#pragma push /* merge_units */
#include "loose04_types.h"

typedef struct GuiManager GuiManager;

extern GuiWidget* func_00418B10(GuiManager* self, char** cursor, GuiWidget* existing);
extern void func_00419530(GuiManager* self, GuiWidget* widget);

/* Read a widget hierarchy and register the root when creation succeeds. */
GuiWidget* func_00418FD0(GuiManager* self, char** cursor, GuiWidget* existing) {
    GuiWidget* widget = func_00418B10(self, cursor, existing);
    if (widget != 0) {
        func_00419530(self, widget);
    }
    return widget;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418FD0 */

/* merge_units: begin func_00419020 */
#pragma push /* merge_units */
#include "types.h"

extern void func_0036DEF0(void* f);
extern char* FileMan_ReadData(void* f);
extern void func_0036DEC0(void* f);
#if 0 /* merge_units */
extern int func_00418FD0(void* self, char** cursor, int c);
#endif /* merge_units */
#define func_00418FD0(a0, a1, a2) ((int)func_00418FD0((GuiManager *)(a0), (a1), (GuiWidget *)(a2))) /* merge_units */


static inline char Rd8_419020(char* volatile* c) { char* t = *c; char v = *t; *c = t + 1; return v; }

int func_00419020(void* self, void* file, int c)
{
    char* volatile p;
    char a;
    char b;
    char d;
    int r;
    func_0036DEF0(file);
    p = FileMan_ReadData(file);
    a = Rd8_419020(&p);
    b = Rd8_419020(&p);
    d = Rd8_419020(&p);
    if (a != 'G' || b != 'U' || d != 'I') return 0;
    p = (char*)(((int)p + 3) & ~3);
    p += 2;
    r = func_00418FD0(self, (char**)&p, c);
    func_0036DEC0(file);
    return r;
}
#undef func_00418FD0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419020 */
