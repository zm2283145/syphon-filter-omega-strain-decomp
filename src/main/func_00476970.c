/*
 * Matched functions (byte-identical with the retail executable).
 * cActivateBodyTossMsg method; address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "loose05_types.h"

extern unsigned char* D_005061D0; /* write cursor of a byte stream */

/* Appends the message's byte at +0x24 to the stream and advances the cursor. */
void cActivateBodyTossMsg_v04(BodyTossMsg* self) {
    unsigned char value;

    value = self->unk24;
    *D_005061D0 = value;
    D_005061D0 = D_005061D0 + 1;
}
