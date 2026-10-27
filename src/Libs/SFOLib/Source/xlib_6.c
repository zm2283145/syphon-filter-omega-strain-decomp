/*
 * Libs/SFOLib/Source/xlib: 1 file, 0037B0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037B0C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                       
int std_list_deleter_tDataDelRec_generic_iterator_ctor(...);                        
int std_list_deleter_tDataDelRec_tail(...);                          
char * details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_9(...);                        
int std_list_deleter_tDataDelRec_erase_listdeleter(...);              
extern unsigned char g_ProfileLockEnabled;
}
#pragma inline_depth(10)
static inline int ite0(char *l) { int r; std_list_deleter_tDataDelRec_generic_iterator_ctor(&r, std_list_deleter_tDataDelRec_tail(l)); return r; }
static inline void er0(char *l, char *n) { int sp84; char *sp80; sp80 = n; std_list_deleter_tDataDelRec_erase_listdeleter(&sp84, l, &sp80); }
static inline void er1(char *l, char *n) { er0(l, n); }
static inline int ite1(char *l) { return ite0(l); }
extern "C" void XLib_DeferDeleteDmaData(char * arg0, int arg1) {
    int temp_s3;
    char * var_s2;
    char * temp_s1;
    int temp_s0;
    int temp_s0_2;

    if (F_(arg0, 0x1108, int) != 0) {
        var_s2 = (char *)(F_(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_9(arg0 + 0x110C), 0x4, int));
        while (ite0(arg0 + 0x1108) != (int)var_s2) {
                F_(var_s2, 0x10, int) = (int) (F_(var_s2, 0x10, int) - 1);
                if ((F_(var_s2, 0x10, int) == 0) || (arg1 != 0)) {
temp_s1 = var_s2;
var_s2 = (char *)(F_(var_s2, 0x4, int));
temp_s0 = F_(temp_s1, 0xC, int);
                    if (temp_s0 == -1) {
                        temp_s0_2 = F_(temp_s1, 0x8, int);
                        {
                            AllocGuard g;
                        cMemMan_Deallocate(0, temp_s0_2, "xlib.cc", 0x812);
                        }
                    } else {
                        temp_s3 = F_(temp_s1, 0x8, int);
                        {
                            AllocGuard g;
                        cMemMan_Deallocate(temp_s0, temp_s3, "xlib.cc", 0x814);
                        }
                    }
                    er0(arg0 + 0x1108, temp_s1);
                } else {
                    var_s2 = (char *)(F_(var_s2, 0x4, int));
                }
        }
    }
}
static inline void merge_flush_func_0037B0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037B0C0 */
