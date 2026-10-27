/*
 * SFOGame/Source/hud: 1 file, 002465B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002465B0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y; } B8P_2465B0;
typedef struct { float x, y, w, h; } B8R_2465B0;
unsigned char PointInRect(B8P_2465B0* p, B8R_2465B0* r) {
    unsigned char res = 0;
    unsigned char iny = 0;
    unsigned char inx = 0;
    if (p->x >= r->x && p->x <= r->x + r->w) inx = 1;
    if (inx && p->y >= r->y) iny = 1;
    if (iny && p->y <= r->y + r->h) res = 1;
    return res;
}
static inline void merge_flush_func_002465B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002465B0 */
