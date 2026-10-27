/*
 * Libs/SFOLib/Source/guiTextEditWidget: 1 file, 0041BBE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiManager_41BBE0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef union Str {
    struct { unsigned int word; unsigned int length; char* data; } l;
    struct { unsigned int isLong : 1; unsigned int length : 7; } s;
    char inl[12];
} Str;

typedef struct Alloc { char unused; } Alloc;

extern "C" {
Str* std_basic_string_char_char_traits_char_do_replace(Str* s, unsigned int pos, unsigned int n, const char* first, const char* last, Alloc a);
void Libc_Fprintf(int, const char*);
void Libc_Abort(void);
extern char* D_00489738;
extern char D_004BF1D0[];
}

template <class T> static inline const T& Min(const T& a, const T& b) { return b < a ? b : a; }

extern "C" Str* func_0041BBE0(Str* self, unsigned int pos, unsigned int n1, const Str* str, unsigned int pos2, unsigned int n2)
{
    unsigned int rem;
    Alloc a;
    const char* data;
    unsigned int len;
    if (!(str->l.word & 1)) {
        data = (const char*)str + 1;
        len = (unsigned char)str->s.length;
    } else {
        data = str->l.data;
        len = str->l.length;
    }
    if (len < pos2) {
        Libc_Fprintf(*(int*)(D_00489738 + 0xC), D_004BF1D0);
        Libc_Abort();
    }
    data += pos2;
    rem = len - pos2; n2 = Min(n2, rem);
    return std_basic_string_char_char_traits_char_do_replace(self, pos, n1, data, data + n2, a);
}
static inline void merge_flush_guiManager_41BBE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiManager_41BBE0 */
