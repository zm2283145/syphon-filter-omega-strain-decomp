/*
 * main/GuiMissionStatList: 2 files, 00351DA0-00351E50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351DA0 */
#pragma push /* merge_units */
#include "types.h"
int func_00329930(void *, void *);
int func_003517B0(void *, void *);
typedef struct { int w[15]; } W15;
typedef struct { char p0[0xC]; unsigned char fC; char pD[3]; W15 f10; char f4C[0x10]; } E351;
static inline void asg351(E351 *d, E351 *s) { func_00329930(d, s); d->fC = s->fC; d->f10 = s->f10; func_003517B0(d->f4C, s->f4C); }
E351 *func_00351DA0(E351 *first, E351 *last, E351 *dest) {
    while (first < last) {
        --last; --dest;
        asg351(dest, last);
    }
    return dest;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351DA0 */

/* merge_units: begin func_00351E50 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0013BCB0();                                  
int func_00351EE0(char * , char * );                    

char * func_00351E50(char * arg0, char * arg1) {
    char * var_a0;
    char * var_v1;
    char * temp_s2;

    func_0013BCB0();
    var_a0 = arg0 + 0x10;
    var_v1 = arg1 + 0x10;
    F_(arg0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
    do {
        F_(var_a0, 0x0, unsigned char) = F_(var_v1, 0x0, unsigned char);
        F_(var_a0, 0x4, int) = F_(var_v1, 0x4, int);
        F_(var_a0, 0x8, int) = F_(var_v1, 0x8, int);
        var_a0 += 0xC;
        var_v1 += 0xC;
    } while (var_a0 != arg0 + 0x4C);
    temp_s2 = arg0 + 0x4C;
    func_00351EE0(temp_s2, arg1 + 0x4C);
    F_(temp_s2, 0xC, unsigned char) = F_(arg1, 0x58, unsigned char);
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351E50 */
