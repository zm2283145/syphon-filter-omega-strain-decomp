/*
 * SFOGame/Source/GuiChatWindow: 1 file, 002AEC90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AEC90 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x64]; int f64; int f68; int f6c; int f70; } O2AE;
extern unsigned int strlen(const char*);
extern int sprintf(char*, const char*, ...);
extern void GuiMLTextWidget_AddText(O2AE*, char*);
extern void GuiMLTextWidget_UpdateScrollBars(O2AE*);
void GuiChatWindow_AddChatLine(O2AE* o, char* name, char* msg, int team) {
    char buf[0x80];
    unsigned char atEnd;
    if (!name || !*name || !msg || !*msg) return;
    atEnd = 0;
    if (!(o->f68 < o->f70 - o->f64)) atEnd = 1;
    if (strlen(name) >= 0x10) return;
    if (strlen(msg) >= 0x41) return;
    if (team) sprintf(buf, "(%c%s%c): %s\n", 0x11, name, 0x10, msg);
    else sprintf(buf, "%c%s%c: %s\n", 0x11, name, 0x10, msg);
    GuiMLTextWidget_AddText(o, buf);
    if (atEnd) {
        o->f68 = o->f70 - o->f64;
        if (o->f68 < 0) o->f68 = 0;
        GuiMLTextWidget_UpdateScrollBars(o);
    }
}
static inline void merge_flush_func_002AEC90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AEC90 */
