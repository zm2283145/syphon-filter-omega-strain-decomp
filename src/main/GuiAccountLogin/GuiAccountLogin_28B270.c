/*
 * main/GuiAccountLogin: 2 files, 0028B270-0028B2C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028B270 */
#pragma push /* merge_units */
#include "types.h"

typedef struct SsoString {
    union {
        unsigned int word;          /* 0x00, bit 0 = long mode */
        struct {
            unsigned char isLong : 1;
            unsigned char shortLen : 7;
        } bits;
    } mode;
    int longLen;                /* 0x04 */
    char* longData;             /* 0x08 */
} SsoString;

extern void String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, signed char tag);

/* Assigns the range [first, last) to the string, replacing its whole contents. */
void func_0028B270(SsoString* str, const char* first, const char* last) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    if (str->mode.word & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->mode.bits.shortLen;
    }
    String_Replace(str, 0, len, first, last, tag[0]);
}
#pragma pop /* merge_units */
/* merge_units: end func_0028B270 */

/* merge_units: begin func_0028B2C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate, run the base constructor, set the vtable and mode. */
extern "C" { char D_004A9840[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INT(func_0028B2C0, 0xB0, D_004A9840, GuiScreen_ctor, D_004DD120, 0x84, 7)
#pragma pop /* merge_units */
/* merge_units: end func_0028B2C0 */
