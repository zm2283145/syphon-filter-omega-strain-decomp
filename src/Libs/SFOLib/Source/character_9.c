/*
 * Libs/SFOLib/Source/character: 1 file, 003E5530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E5530 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int words[3]; } Reader;
extern char D_0055A1E0[];
extern void cCharActionMsg_Scalar_NetCharActionScalarReq();
extern int NetRegisterMessageStart(void);
extern unsigned char cCharActionMsg_RegisterFields(void);
extern int NetMessageField(Reader* r, void* out, int size, int count);
extern int NetRegisterApplicationMessage(void* table, void (*cb)());

/* Startup check chain; returns 1 when every step succeeds. */
unsigned char cCharActionMsg_Scalar_InitNet(void)
{
    Reader r;
    int value;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cCharActionMsg_RegisterFields() && NetMessageField(&r, &value, 4, 1) == 0
        && NetRegisterApplicationMessage(D_0055A1E0, cCharActionMsg_Scalar_NetCharActionScalarReq) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_character_3E5530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E5530 */
