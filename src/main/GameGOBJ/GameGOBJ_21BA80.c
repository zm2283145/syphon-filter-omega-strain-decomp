/*
 * main/GameGOBJ: range (3 files, 0021BA80-0021BCB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

/* merge_units: begin func_0021BA80 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DAEF0[];

struct Msg_0021BA80 : ClonedMessageBase {
    int a24;
    unsigned char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DAEF0; p->a24 = s->a24; p->b28 = s->b28;

extern "C" {
char D_004A4A28[] = "gamegobj.hh";
}
DEFINE_MESSAGE_CLONE(func_0021BA80, Msg_0021BA80, 44, D_004A4A28, 163, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021BA80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021BA80 */

/* merge_units: begin func_0021BB90 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DAF10[];

struct Msg_0021BB90 : ClonedMessageBase {
    int a24;
    int a28;
    int a2C;
    int a30;
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004DAF10; p->a24 = s->a24; p->a28 = s->a28; p->a2C = s->a2C; p->a30 = s->a30;

extern "C" {
char D_004A4A38[] = "gamegobj.hh";
}
DEFINE_MESSAGE_CLONE(cGOBJTriggerEventMsg_v01, Msg_0021BB90, 52, D_004A4A38, 112, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021BB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021BB90 */

/* merge_units: begin func_0021BCB0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void func_0036E220(void* member, int flags);
void cGOBJ_dtor(void* self, int flags);
void operator_delete(void* allocation);
extern char D_004DAF30[];
}

struct SoundGobj0021BCB0 {
    void* vtable;
    char base[0x5C];
    char payload[0x48];
    char memberA[0x9C];
    char memberB[4];
};

extern "C" SoundGobj0021BCB0* cSoundGOBJ_dtor(SoundGobj0021BCB0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAF30;
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021BCB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021BCB0 */
