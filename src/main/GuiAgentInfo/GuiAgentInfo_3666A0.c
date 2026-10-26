/*
 * main/GuiAgentInfo: 2 files, 003666A0-003666F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003666A0 */
#pragma push /* merge_units */
#include "types.h"

/* Short-string-optimized string: bit 0 of the first word selects the long form. */
typedef union String {
    struct {
        unsigned int cap;
        int size;
        char* data;
    } l;
    struct {
        unsigned char isLong : 1;
        unsigned char size : 7;
        char data[11];
    } s;
} String;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern void String_Replace(String*, int, int, int, int, Tag);

/* Calls String_Replace(str, 0, size(str), a, b, tag). */
void func_003666A0(String* str, int a, int b) {
    Tag tag;
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    String_Replace(str, 0, size, a, b, tag);
}
#pragma pop /* merge_units */
/* merge_units: end func_003666A0 */

/* merge_units: begin func_003666F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_erase_destroy.h"

/* Erase a range from a vector of 60-byte elements. */
DEFINE_ERASE_ELEMENT(Elem60, 60)
DEFINE_VECTOR_ERASE_DESTROY(func_003666F0, Elem60, std_msl_copy_cSkaSliderValue_copy, cSkaSliderValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003666F0 */
