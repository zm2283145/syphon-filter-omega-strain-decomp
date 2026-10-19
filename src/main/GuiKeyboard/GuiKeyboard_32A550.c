/*
 * main/GuiKeyboard: 2 files, 0032A550-0032A5A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032A550 */
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
void func_0032A550(SsoString* str, const char* first, const char* last) {
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
/* merge_units: end func_0032A550 */

/* merge_units: begin func_0032A5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct VRElem20 { int w[11]; };
struct V32A5A0 { unsigned int cap; unsigned int count; VRElem20* data; };
extern "C" {
extern char D_004B88C0[];
void* func_00139BC0(unsigned int size, void* p);
void func_0032A730(void* dst, const VRElem20* src);
}
extern "C" void func_0032A5A0(V32A5A0* v, const VRElem20* first, const VRElem20* last)
{
    unsigned int n = last - first;
    if (v->count > 0x22E8BA) {
        func_00123BE8(D_00489738->stream, "vector length error\n");
        Libc_Abort();
    }
    if (n) {
        VRElem20** pdata = &v->data;
        *pdata = (VRElem20*)TStr_Alloc(n * sizeof(VRElem20), D_004B88C0, 0x5C);
        v->cap = n;
        VRElem20* p = v->data;
        for (; first != last; first++, p++) {
            void* o = func_00139BC0(sizeof(VRElem20), p);
            if (o) func_0032A730(o, first);
            v->count++;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A5A0 */
