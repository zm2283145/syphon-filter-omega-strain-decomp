/*
 * SFOGame/Source/GuiAgentInfo: 2 files, 003652D0-00365300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003652D0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentDisplay")) returned 0. */
int GuiAgentDisplay_IsClass(void) {
    return strcmp(((int*)"GuiAgentDisplay")) == 0;
}
static inline void merge_flush_func_003652D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003652D0 */

/* merge_units: begin func_00365300 */
#pragma push /* merge_units */
typedef struct { int words[3]; } SsoString;
typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(SsoString* s, int capacity);
extern void* std_basic_string_char_char_traits_char_do_replace(SsoString* s, int pos, int count, const char* first, const char* last, Allocator alloc);

/* String constructor from a C string. */
SsoString* String_CtorCStr_365300(SsoString* self, const char* text)
{
    Allocator alloc;
    int len;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    len = strlen(text);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, text, text + len, alloc);
    return self;
}
static inline void merge_flush_func_00365300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365300 */
