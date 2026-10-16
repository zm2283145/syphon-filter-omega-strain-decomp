/*
 * main/gobj: 2 files, 003D2600-003D2630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003D2600(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D2610(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003D2620(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D2600 */

/* merge_units: begin func_003D2630 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int List_Erase(char *, int, char *);                     
int func_0015AF40(char *, int *);                        
int func_003D2110(char *, int);                          
int func_003D2180(char *, int);                          
int func_003D2710(int *, char *);                        
int func_003D2720(char *, char *);                        
int func_003D2740(char *);                               
int *func_003D2760(char *);                            
int func_003D2770(char *, char *);                          
int func_003D2780(char *);                               

void func_003D2630(int arg0, int arg1) {
    int sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    int sp34;

    func_003D2780(&sp3C);
    func_003D2180(&sp38, arg0);
    func_003D2770(&sp3C, &sp38);
    func_003D2110(&sp34, arg0);
    while (func_003D2720(&sp3C, &sp34) != 0) {
        { int v = *func_003D2760(&sp3C); if (v == arg1) break; }
        func_003D2740(&sp3C);
        func_003D2110(&sp34, arg0);
    }
    func_003D2710(&sp4C, &sp3C);
    sp48 = sp4C;
    func_0015AF40(&sp40, &sp48);
    List_Erase(&sp44, arg0, &sp40);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D2630 */
