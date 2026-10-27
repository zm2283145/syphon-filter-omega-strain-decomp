/*
 * SFOGame/Source/playerControls: 2 files, 0024A7A0-0024A820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0024A7A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char x20; int x24; unsigned char x28; char pad2[7]; } Ev24A7A0;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void cMessage_ctor_cMessageNameR(Ev24A7A0*, void*);
extern void QueueMessage_cMessageR_cSystemP_int(Ev24A7A0*, void*, int);
extern void cMessage_dtor(void*, int);
int cPlayerControls_EnterCrawl(void* self, void* target) {
    Ev24A7A0 ev;
    cMessage_ctor_cMessageNameR(&ev, g_ActorActionMsgClass);
    ev.vt = D_004E0840;
    ev.x24 = 9;
    ev.x20 = 1;
    ev.x28 = 0;
    QueueMessage_cMessageR_cSystemP_int(&ev, target, 1);
    ev.vt = D_004E0840;
    cMessage_dtor(&ev, 0);
    return 1;
}
static inline void merge_flush_func_0024A7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024A7A0 */

/* merge_units: begin func_0024A820 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "playerControls_types.h"

/* True when crouchZone is set and unk25 is clear. */
int cPlayerControls_HasEnteredCrawlHotbox(InputState* self) {
    int result = !(self->unk25 != 0);

    if (result) {
        result = self->crouchZone != 0;
    }
    return result;
}
static inline void merge_flush_func_0024A820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024A820 */
