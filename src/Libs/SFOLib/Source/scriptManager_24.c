/*
 * Libs/SFOLib/Source/scriptManager: 2 files, 003E0CD0-003E0CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E0CD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_ClassDefPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_003E0CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E0CD0 */

/* merge_units: begin func_003E0CE0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int String_CompareNoCase(int, int);
int **std_vector_EnumDefPtr_opIndex(char * , int);
extern char * D_00554F30;

int cScriptInterpreter_findEnum(int d0, int arg1) {
    int i;
    int n = F_(D_00554F30, 0x4, int);
    for (i = 0; i < n; i++) {
        if (String_CompareNoCase(arg1, **std_vector_EnumDefPtr_opIndex(D_00554F30, i)) == 0) {
            return *(int *)((char *)F_(D_00554F30, 0x8, int) + (i * 4));
        }
    }
    return 0;
}
static inline void merge_flush_func_003E0CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E0CE0 */
