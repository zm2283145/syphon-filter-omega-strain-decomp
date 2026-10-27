/*
 * SFOGame/Source/game: 5 files, 00135F50-00136080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00135F50 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "member_dtor_chain.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(std_vector_deleter_cLosRequest_cCollisionModelList_Game_dtor, func_00135C90)
static inline void merge_flush_func_00135F50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135F50 */

/* merge_units: begin func_00135FB0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_00135FB0, func_0013A130)
static inline void merge_flush_func_00135FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00135FB0 */

/* merge_units: begin func_00136020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_imp_cLosRequest_cCollisionModelList_Game_init(Rel*, int, int);

/* Zeroes the three words, then initializes from (a1, a2) via std_vector_imp_cLosRequest_cCollisionModelList_Game_init. */
Rel* std_vector_imp_cLosRequest_cCollisionModelList_Game_ctor(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    std_vector_imp_cLosRequest_cCollisionModelList_Game_init(r, a1, a2);
    return r;
}

/* Clears bytes +0x60, +0x62 and words +0x80, +0x84. */
char* cLosResult_ctor_void(char* self) {
    self[96] = 0;
    self[98] = 0;
    *(int*)(self + 128) = 0;
    *(int*)(self + 132) = 0;
    return self;
}
static inline void merge_flush_func_00136020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136020 */

/* merge_units: begin func_00136080 */
#pragma push /* merge_units */
extern char D_004E1D88[];
extern char D_004E1D90[];
extern char D_004E1D94[];
extern char D_004E1D98[];
extern char D_004E1D9C[];

int cVector_GetZero(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004E1D88;
    cond = v0 != 0;
    if (cond) goto L001360B8;
    v0 = 0 + 1;
    *(int*)(char*)D_004E1D90 = 0;
    *(char*)(char*)D_004E1D88 = v0;
    *(int*)(char*)D_004E1D94 = 0;
    *(int*)(char*)D_004E1D98 = 0;
    *(int*)(char*)D_004E1D9C = 0;
L001360B8:;
    v0 = (int)D_004E1D90;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136080 */

/* merge_units: begin func_001360D0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cMemMan_Allocate(int, int, int *, int);                      
int std_vector_cCollisionFace_reserve(int , int);                       
int cArrayCapacity_Int(int *);                           
int std_vector_cCollisionFace_ctor(int );                            
int std_vector_imp_cCollisionFace_reserve(int , int);                       
extern int D_004EA0C0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cCollisionSystem_cBox_InitStatics(int arg0) {
    int sp3C;
    int temp_s1;

    if (D_004EA0C0 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s1 = cMemMan_Allocate(0, 0x10, ((int*)"collision.hh"), 0xAE6);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s1 != NULL) {
            sp3C = arg0;
            std_vector_cCollisionFace_ctor(temp_s1);
            std_vector_cCollisionFace_reserve(temp_s1, cArrayCapacity_Int(&sp3C));
            F_(temp_s1, 0xC, signed char) = 1;
        }
        D_004EA0C0 = temp_s1;
        return;
    }
    std_vector_imp_cCollisionFace_reserve(D_004EA0C0, arg0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001360D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001360D0 */
