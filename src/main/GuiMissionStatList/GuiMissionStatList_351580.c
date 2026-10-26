/*
 * main/GuiMissionStatList: 2 files, 00351580-003515D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351580 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; } SsoString;

extern void String_Replace(SsoString* self, int pos, int n, const char* first, const char* last, Alloc alloc);

/* Assigns [first, last) to the string by replacing its whole contents. */
void func_00351580(SsoString* self, const char* first, const char* last)
{
    Alloc alloc;
    String_Replace(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, first, last, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_00351580 */

/* merge_units: begin func_003515D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_erase_destroy.h"

DEFINE_ERASE_ELEMENT(Elem3515D0, 0x5C)
DEFINE_VECTOR_ERASE_DESTROY(std_vector_imp_MissionStats_erase, Elem3515D0, std_msl_copy_MissionStats_copy, MissionStats_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003515D0 */
