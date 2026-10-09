/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0040BF50(L4Tagged*);   /* first function of GobjMan.cc */

/* Calls func_0040BF50 on the record at +0xC if its tag is 0xBEBAAFDE. */
void func_003CB4F0(Unk3CB4F0* self) {
    unsigned int magic = 0xBEBAAFDE;
    L4Tagged* rec = self->unk0C;

    if (rec->tag == magic) {
        func_0040BF50(rec);
    }
}
