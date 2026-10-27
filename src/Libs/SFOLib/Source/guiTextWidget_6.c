/*
 * Libs/SFOLib/Source/guiTextWidget: 2 files, 0041D300-0041D350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041D300 */
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

extern void std_basic_string_char_char_traits_char_do_replace(SsoString* str, int pos, int count, const char* first, const char* last, signed char tag);

/* Assigns the range [first, last) to the string, replacing its whole contents. */
void func_0041D300(SsoString* str, const char* first, const char* last) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    if (str->mode.word & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->mode.bits.shortLen;
    }
    std_basic_string_char_char_traits_char_do_replace(str, 0, len, first, last, tag[0]);
}
static inline void merge_flush_func_0041D300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041D300 */

/* merge_units: begin func_0041D350 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004BF368[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(ConcreteWidgetClassRep_GuiTextWidget_Create, 0x80, D_004BF368, GuiTextWidget_ctor)
static inline void merge_flush_func_0041D350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041D350 */
