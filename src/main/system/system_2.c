/*
 * main/system: 2 files, 003CB330-003CB4B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CB330 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "system_types.h"
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);
int operator_delete(...);
extern char D_004BD1A8;                     /* "system.cc" */
extern char D_004BD1E8;                     /* "system.hh" */
extern char D_004DFDE0;                     /* Receiver vtable */
extern unsigned char D_00533880;
}
/* Receiver destructor: frees the owned buffer; deletes self when (short)flags > 0. */
extern "C" Receiver * Receiver_Destruct(Receiver * self, long long flags) {
    ReceiverBuf *buf;
    void *data;

    if (self != NULL) {
        self->vtable = &D_004DFDE0;
        self->magic = 0;
        self->id = RECEIVER_DEAD_ID;
        buf = self->buf;
        if (buf != NULL) {
            {
                AllocGuard g;
            if (buf != NULL) {
                data = buf->data;
                if (data != NULL) {
                    {
                        AllocGuard g;
                    Mem_Free(0, data, &D_004BD1E8, 0x34);
                    }
                }
            }
            Mem_Free(0, buf, &D_004BD1A8, 0x54);
            }
        }
        if (((long long) (flags << 0x30) >> 0x30) > 0) {
            operator_delete(self);
        }
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB330 */

/* merge_units: begin func_003CB4B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Receiver base-class constructor.
 */

#include "system_types.h"

#if 0 /* merge_units */
extern char D_004DFDE0[];   /* Receiver vtable */
#endif /* merge_units */
#define D_004DFDE0 ((char*)&D_004DFDE0) /* merge_units */


/* Initializes the Receiver base fields; owner is stored at +8. */
Receiver* Receiver_Construct(Receiver* self, void* owner) {
    self->vtable = D_004DFDE0;
    self->magic = RECEIVER_MAGIC;
    self->owner = owner;
    self->id = -1;
    self->unk10 = -1;
    self->enabled = 1;
    self->buf = 0;
    return self;
}
#undef D_004DFDE0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CB4B0 */
