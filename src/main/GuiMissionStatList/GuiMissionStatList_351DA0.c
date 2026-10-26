/*
 * main/GuiMissionStatList: 2 files, 00351DA0-00351E50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351DA0 */
#pragma push /* merge_units */
#include "types.h"
int cString_opAssign(void *, void *);
int cArray_StatsRequirement_opAssign(void *, void *);
typedef struct { int w[15]; } W15;
typedef struct { char p0[0xC]; unsigned char fC; char pD[3]; W15 f10; char f4C[0x10]; } E351;
static inline void asg351(E351 *d, E351 *s) { cString_opAssign(d, s); d->fC = s->fC; d->f10 = s->f10; cArray_StatsRequirement_opAssign(d->f4C, s->f4C); }
E351 *std_copy_backward_MissionStats_copy_backward(E351 *first, E351 *last, E351 *dest) {
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
int String_CopyCtor();                                  
int std_vector_StatsRequirement_ctor(char * , char * );                    

char * MissionStats_ctor(char * arg0, char * arg1) {
    char * var_a0;
    char * var_v1;
    char * temp_s2;

    String_CopyCtor();
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
    std_vector_StatsRequirement_ctor(temp_s2, arg1 + 0x4C);
    F_(temp_s2, 0xC, unsigned char) = F_(arg1, 0x58, unsigned char);
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351E50 */
