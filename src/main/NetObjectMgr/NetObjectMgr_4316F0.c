/*
 * main/NetObjectMgr: range (5 files, 004316F0-00431900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#include "message_pack.h"

/* merge_units: begin func_004316F0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004316F0;
typedef struct { R1Tree_004316F0 tree; } R1Own_004316F0;
extern void std_tree_pair_int_value_compare_dtor_void_5(R1Tree_004316F0* t, short del);
extern void operator_delete(void* p);
R1Own_004316F0* cAssocArray_int_tNetObjectPtr_dtor(R1Own_004316F0* o, short del)
{
    if (o) {
        R1Tree_004316F0* t = &o->tree;
        if (t)
            std_tree_pair_int_value_compare_dtor_void_5(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004316F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004316F0 */

/* merge_units: begin func_00431750 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004E0EC0[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004E0EC0;

extern "C" {
char D_004BFBE0[] = "NetPlayGameMsg.hh";
}
DEFINE_MESSAGE_CLONE(cNetPlayGameMsg_v01, Msg_0020E560, 0x24, D_004BFBE0, 0x10, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431750 */

/* merge_units: begin func_00431850 */
#pragma push /* merge_units */
extern volatile unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern unsigned char D_00572400;

/* Set the network state flag while holding the shared operation guard. */
int cNetPlayGameMsg_NetReceive(void)
{
    if (D_005723C8 == 0)
        D_005723C8 = 1;
    if (D_005721D0 != 0)
        D_00572400 = 1;
    D_005723C8 = 0;
    return 8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431850 */

/* merge_units: begin func_00431890 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* p);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_00582738;
#if 0 /* merge_units */
extern int cNetPlayGameMsg_NetReceive();
#endif /* merge_units */
#define cNetPlayGameMsg_NetReceive() (cNetPlayGameMsg_NetReceive()) /* merge_units */

unsigned char cNetPlayGameMsg_NetRegister(void) {
    int buf[4];
    unsigned char r = 0;
    if (NetRegisterMessageStart() == 0 && Event_UnpackHeader(buf + 2) != 0 &&
        NetMsg_RegisterType(&D_00582738, 2, cNetPlayGameMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
#undef cNetPlayGameMsg_NetReceive /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431890 */

/* merge_units: begin func_00431900 */
#pragma push /* merge_units */
#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b)

DEFINE_MESSAGE_PACK_PRE(cNetPlayGameMsg_v02, 8, D_00582738, PACK_PRE, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00431900 */
