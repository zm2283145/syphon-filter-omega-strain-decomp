/*
 * Libs/SFOLib/Source/interface_model: 2 files, 003ED250-003ED290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ED250 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { __int128 r[4]; } M_D250;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D250 m[8]; } S_D250;
void XLib_SetView(S_D250* s, M_D250* src) {
    M_D250* d; __int128 qa, qb; int one;
    int t = s->top;
    asm { .set reorder; lq qa, 0x0(src) }
    asm { .set reorder; lq qb, 0x10(src) }
    d = &s->m[t];
    
    asm { .set reorder; sq qa, 0x0(d) }
    one = 1;
    asm { .set reorder; lq qa, 0x20(src) }
    asm { .set reorder; sq qb, 0x10(d) }
    asm { .set reorder; lq qb, 0x30(src) }
    asm { .set reorder; sq qa, 0x20(d) }
    asm { .set reorder; sq qb, 0x30(d) }
    s->flag = one;
}
static inline void merge_flush_func_003ED250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED250 */

/* merge_units: begin func_003ED290 */
#pragma push /* merge_units */
typedef struct { __int128 r[4]; } M_D290;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D290 m[8]; } S_D290;
void XLib_PushView(S_D290* s) {
    M_D290* d; M_D290* p; __int128 qa; __int128 qb; S_D290* b;
    int t = s->top; p = &s->m[t];
    b = (S_D290*)((char*)s + (t + 1) * 64);
    asm { .set reorder; lq qa, 0x0(p) }
    d = &b->m[0];
    asm { .set reorder; lq qb, 0x10(p) }
    asm { .set reorder; sq qa, 0x0(d) }
    asm { .set reorder; lq qa, 0x20(p) }
    asm { .set reorder; sq qb, 0x10(d) }
    asm { .set reorder; lq qb, 0x30(p) }
    asm { .set reorder; sq qa, 0x20(d) }
    asm { .set reorder; sq qb, 0x30(d) }
    s->top++;
}
static inline void merge_flush_func_003ED290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED290 */
