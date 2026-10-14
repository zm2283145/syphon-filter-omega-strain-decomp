/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A0020-002A0070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0020 */
#pragma push /* merge_units */
#include "types.h"
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;
extern void String_Replace(StrHdr* str, int pos, int count, const char* first, const char* last, char alloc);
void func_002A0020(StrHdr* str, const char* first, const char* last)
{
    volatile char alloc[4];
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Replace(str, 0, len, first, last, alloc[0]);
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0020 */

/* merge_units: begin func_002A0070 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004AAD88[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(func_002A0070, 0x124, D_004AAD88, GuiOnlineConnect_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_002A0070 */
