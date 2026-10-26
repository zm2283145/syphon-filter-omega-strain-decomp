/*
 * main/NetObj: range (3 files, 003FBEC0-003FC000)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "int_map_subscript.h"
#pragma push
#pragma cplusplus on
#include "int_tree_find.h"
#pragma pop

/* merge_units: begin func_003FBEC0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Net_GetClock(int);                               
int cNetObjectMgr_NextFrame();                                  
int cNPCInfoObject_Setup(char *);                               
int cNPCInfoObject_dtor(char *, int);                            
int cNPCInfoObject_ctor(char *);                               
int cHeadSet_NextFrame(int);                                 
int func_0043AA30(char *);                               
int cGenInfoObject_ctor(char *);                               
static unsigned int dat_00493A18[2] = { 0x1, 0x0 };
extern int D_0055C7B8;
extern signed char D_005724D0;

void Net_Pump(void) {
    int sp1C;
    int sp18;

    D_005724D0 = 1;
    if ((*(unsigned char*)dat_00493A18) != 0) {
        (*(unsigned char*)dat_00493A18) = 0;
    }
    cNPCInfoObject_ctor(&sp1C);
    cNPCInfoObject_Setup(&sp1C);
    cGenInfoObject_ctor(&sp18);
    func_0043AA30(&sp18);
    D_0055C7B8 = Net_GetClock(0) + 0x64;
    cNetObjectMgr_NextFrame();
    cHeadSet_NextFrame(0);
    cNPCInfoObject_dtor(&sp1C, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBEC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBEC0 */

/* merge_units: begin func_003FBF40 */
#pragma push /* merge_units */
/* map<int, {int, int}>::operator[] with value {0, -2} */
typedef struct { int key; int a; int b; } PBF40;
DEFINE_INT_MAP_SUBSCRIPT(std_tree_pair_int_value_compare_cAllocator_pair_find_or_insert_intR_2, PBF40, FrameTree_Insert_3FC520, (v.a = 0, v.b = -2))
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FBF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FBF40 */

/* merge_units: begin func_003FC000 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find an int key in a tree; end() when absent. */
DEFINE_INT_TREE_FIND(std_tree_pair_int_value_compare_cAllocator_pair_find_intR_2)
#pragma pop /* merge_units */
/* merge_units: end func_003FC000 */
