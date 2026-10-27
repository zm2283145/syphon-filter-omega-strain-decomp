/*
 * SFOGame/Source/GuiEndGameObjectives: 5 files, 00462CE0-00462F30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00462CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00462CE0, func_00461FA0, D_004C2568)
static inline void merge_flush_func_00462CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462CE0 */

/* merge_units: begin func_00462DD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */

#include "loose05_types.h"

void func_00462DD0(Word4* self) {
    self->unk04 = 0;
}
static inline void merge_flush_func_00462DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462DD0 */

/* merge_units: begin func_00462DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004E17C0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiObjectives_ctor(void* self, int a, int b);
void cQuipList_ctor(void* p);
}
struct O462DE0 { void* vtable; char pad4[0x8C]; char p90[0x1C0]; };
extern "C" O462DE0* GuiEndGameObjectives_Create(void)
{
    O462DE0* p;
    {
        AllocGuard guard;
        p = (O462DE0*)cMemMan_Allocate(0, 0x250, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiObjectives_ctor(p, 1, 0);
        p->vtable = D_004E17C0;
        cQuipList_ctor(p->p90);
    }
    return p;
}
static inline void merge_flush_func_00462DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462DE0 */

/* merge_units: begin message_462EB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_payload_dtor_460ec0.h"

/* Message destructor: payload members, then base. */
DEFINE_MESSAGE_PAYLOAD_DTOR_460EC0(func_00462EB0)
static inline void merge_flush_message_462EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_462EB0 */

/* merge_units: begin func_00462F30 */
#pragma push /* merge_units */
void* func_00462F30(void* self) {
    return self;
}
static inline void merge_flush_func_00462F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462F30 */
