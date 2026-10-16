/*
 * main/DME: 3 files, 0042AEC0-0042AFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042AEC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_005724B0;
extern int func_002EAD30(void* callback);
extern int func_002EC4F8(void);
extern int DME_AddGameAddress(int, int);

/* Sets D_005724B0 to 3 and installs DME_AddGameAddress via func_002EAD30; falls back to func_002EC4F8 on failure. */
int func_0042AEC0(void) {
    int ret;

    D_005724B0 = 3;
    ret = func_002EAD30(DME_AddGameAddress);
    if (ret == 0) {
        ret = func_002EC4F8();
    }
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042AEC0 */

/* merge_units: begin func_0042AF00 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002E9320(char *);                               
int func_002E9480(char *);                               
int func_002E94E0(char *, char *);                        
int func_002EA4F0(char *, char *);                        
int func_002EC168(int, int);                            
extern signed char D_00572418;
extern signed char D_00572419;
extern signed char D_0057241A;
extern signed char D_0057241B;
#if 0 /* merge_units */
extern signed char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(signed char*)&D_005724B0) /* merge_units */

extern char func_002CAA70;
extern char sfo_malloc_2CA9B0;

void func_0042AF00(void) {
    int sp40[8];
    int sp20[8];
    int sp10[4];
    int temp_v0;

    D_00572418 = 0;
    D_00572419 = 0;
    D_0057241A = 0;
    D_0057241B = 0;
    temp_v0 = func_002EA4F0(&func_002CAA70, &sfo_malloc_2CA9B0);
    if (temp_v0 == 0) {
        if (temp_v0 == 0) {
            func_002E9480(sp40);
            if (func_002E94E0(sp40, sp20) == 0) {
                func_002E9320(sp10);
                if (func_002EC168(0x6000, 0x6000) == 0) {
                    D_005724B0 = 1;
                }
            } else {
                D_005724B0 = 2;
            }
        } else {
            D_005724B0 = 2;
        }
    }
}
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042AF00 */

/* merge_units: begin func_0042AFC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_002E9320(char* buffer);
#endif /* merge_units */
#define func_002E9320(a0) (func_002E9320((a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_002EC168(int first, int second);
#endif /* merge_units */
#define func_002EC168(a0, a1) (func_002EC168((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(unsigned char*)&D_005724B0) /* merge_units */


/* Read the library version and update connection state when setup returns zero. */
void func_0042AFC0(void)
{
    char version[16];
    func_002E9320(version);
    if (!func_002EC168(0x6000, 0x6000))
        D_005724B0 = 1;
}
#undef func_002E9320 /* merge_units */
#undef func_002EC168 /* merge_units */
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042AFC0 */
