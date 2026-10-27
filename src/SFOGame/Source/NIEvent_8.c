/*
 * SFOGame/Source/NIEvent: 3 files, 002394A0-00239590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002394A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cFXKeyPtr_dtor)
static inline void merge_flush_func_002394A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002394A0 */

/* merge_units: begin func_00239590 */
#pragma push /* merge_units */
#include "types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_vector_cFXKeyPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239590 */

/* merge_units: begin func_002395A0 */
#pragma push /* merge_units */
typedef struct { char data[0x9C]; } SubObj;
typedef struct {
    void* vtable;          /* +0x00 */
    char pad04[0x20 - 4];
    unsigned char flag;    /* +0x20 */
    char pad21[0x78 - 0x21];
    SubObj a;              /* +0x78 */
    SubObj b;              /* +0x114 */
    char pad1B0[0x1D0 - 0x1B0];
} Event; /* 0x1D0-byte stack object */
extern char g_Game[];
extern char D_004DADF0[]; /* vtable used while tearing down */
extern void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Event* e, void* src, void* arg);
extern void QueueMessage_cMessageR_cSystemP_int(Event* e, const char* name, int enable);
extern void cFileMan_dtor(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);

/* Builds a temporary event from self+0x10 and arg, dispatches it as g_Game, then destroys it. */
void cStopSndFXKey_Execute(char* self, void* arg)
{
    Event e;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&e, self + 0x10, arg);
    e.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&e, g_Game, 1);
    e.vtable = D_004DADF0;
    cFileMan_dtor(&e.b, -1);
    cFileMan_dtor(&e.a, -1);
    cMessage_dtor(&e, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002395A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002395A0 */
