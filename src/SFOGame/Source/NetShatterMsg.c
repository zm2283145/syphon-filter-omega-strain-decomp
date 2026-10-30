/*
 * SFOGame/Source/NetShatterMsg: 2 files, 003167C0-00316860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003167C0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Global_Shatter(int, int, int);                      
int nGobjManager_LookupGOBJ_cObjectIdR(int *);                       
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
int cNetShatterMsg_NetShatterMsgCallback(int d0, int d1, int d2, char * arg3) {
    struct { char pad20[4]; int f24; int f28[2]; } sl;
    int temp_v0;
    int temp_s0;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_005721D0 != 0) {
        sl.f28[0] = F_(arg3, 0x8, int);
        sl.f24 = F_(arg3, 0xC, int);
        temp_s0 = nGobjManager_LookupGOBJ_cObjectIdR(sl.f28);
        temp_v0 = nGobjManager_LookupGOBJ_cObjectIdR(&sl.f24);
        if ((temp_s0 != 0) && (temp_v0 != 0)) {
            Global_Shatter(temp_s0, temp_v0, 1);
        }
    }
    D_005723C8 = 0;
    return 0x10;
}
#pragma pop
static inline void merge_flush_func_003167C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003167C0 */

/* merge_units: begin func_00316860 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { int a; int b; } Proto_0020E420;
extern int D_0052ACB8;
extern int cNetShatterMsg_NetShatterMsgCallback(int, int, int, char*);

NETREG_BEGIN(cNetShatterMsg_InitNet, Proto_0020E420)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(&D_0052ACB8, cNetShatterMsg_NetShatterMsgCallback)
static inline void merge_flush_func_00316860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316860 */
