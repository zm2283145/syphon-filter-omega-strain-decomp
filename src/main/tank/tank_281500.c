/*
 * main/tank: 2 files, 00281500-00281620
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00281500 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A9380[] = "netBackpackMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetBackpackMsg_v01, 0x30, D_004A9380, 0x1C, D_004DCEF0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C))
#pragma pop /* merge_units */
/* merge_units: end func_00281500 */

/* merge_units: begin func_00281620 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor;

extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
extern void Event_Construct(Visitor* v, void* arg);
extern void func_00281680(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor on the stack, applies it to self and destroys it. */
void func_00281620(void* self)
{
    Visitor v;
    Event_Construct(&v, D_005061B0);
    v.vtable = D_004DCEF0;
    func_00281680(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00281620 */
