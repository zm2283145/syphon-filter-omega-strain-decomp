/*
 * Libs/SFOLib/Source/charActionMsg: 1 file, 003FF2C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin globalization_3FF2C0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int words[2]; } Reader;
extern unsigned int D_0055D488;
extern int cMessage_RegisterFields(Reader* r);
extern int NetMessageField(Reader* r, unsigned char* out, int size, int count);

/* Opens a reader and reads two bytes; on success clears D_0055D488 and returns 1. */
unsigned char cCharActionMsg_RegisterFields(void)
{
    Reader r;
    unsigned char bytes[8]; /* header buffer; only the first two bytes are read here */
    unsigned char ok = 0;
    if (cMessage_RegisterFields(&r) && NetMessageField(&r, &bytes[0], 1, 1) == 0 && NetMessageField(&r, &bytes[1], 1, 1) == 0) {
        ok = 1;
        D_0055D488 = 0;
    }
    return ok;
}
static inline void merge_flush_globalization_3FF2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end globalization_3FF2C0 */
