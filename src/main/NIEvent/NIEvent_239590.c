/*
 * main/NIEvent: range (2 files, 00239590-002395A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00239590 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* func_00239590(PtrVec* v, int i) {
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
extern void SoundStopMsg_Ctor(Event* e, void* src, void* arg);
extern void Event_Send(Event* e, const char* name, int enable);
extern void FileMan_Release(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);

/* Builds a temporary event from self+0x10 and arg, dispatches it as g_Game, then destroys it. */
void func_002395A0(char* self, void* arg)
{
    Event e;
    SoundStopMsg_Ctor(&e, self + 0x10, arg);
    e.flag = 1;
    Event_Send(&e, g_Game, 1);
    e.vtable = D_004DADF0;
    FileMan_Release(&e.b, -1);
    FileMan_Release(&e.a, -1);
    cMessage_dtor(&e, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002395A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002395A0 */
