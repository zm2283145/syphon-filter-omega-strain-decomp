/*
 * main/guiManager: 2 files, 0041A0D0-0041A100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041A0D0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiTextEditWidget". */
int func_0041A0D0(void* self, const char* name)
{
    return strcmp("GuiTextEditWidget", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041A0D0 */

/* merge_units: begin func_0041A100 */
#pragma push /* merge_units */
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS41A100;
typedef struct { union { SS41A100 s; unsigned int w; } h; unsigned int size; } Str41A100;
typedef struct { char p[0x48]; Str41A100 text; char p50[0x3C]; int cursor; } W41A100;
static inline unsigned int Size41A100(Str41A100* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }
int func_0041A100(W41A100* w, int pos)
{
    int len = Size41A100(&w->text);
    if (pos == -1) pos = len;
    if (len < pos) { w->cursor = len; return 0; }
    if (pos < 0) { w->cursor = 0; return 0; }
    w->cursor = pos;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041A100 */
