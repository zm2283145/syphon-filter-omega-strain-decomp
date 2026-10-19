/*
 * main/GuiMissionStatList: 2 files, 003527F0-00352910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003527F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V3527F0 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004BABF0[];
extern char D_004BAC78[];
}
static inline void Cp3527F0(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector constructed from the range [first, last). */
extern "C" void func_003527F0(V3527F0* v, char* first, char* last)
{
    v->count = v->cap = last - first;
    if (v->count > 0x6000000) {
        Libc_Fprintf(D_00489738->stream, D_004BABF0);
        Libc_Abort();
    }
    if (v->count) {
        { char** pdata = &v->data; *pdata = TStr_Alloc(v->count, D_004BAC78, 0x5C); }
        Cp3527F0(v->data, first, last);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003527F0 */

/* merge_units: begin func_00352910 */
#pragma push /* merge_units */
#pragma cplusplus on

struct V352910 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004BAC10[];
extern char D_004BACB8[];
}
static inline void Cp352910(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector assign(first, last): grows the buffer when needed, then copies. */
extern "C" void func_00352910(V352910* v, char* first, char* last)
{
    unsigned int n = last - first;
    if (v->cap < n) {
        if (n > 0x6000000) {
            Libc_Fprintf(D_00489738->stream, D_004BAC10);
            Libc_Abort();
        }
        v->count = 0;
        if (v->data) {
            if (v->data) TStr_Free(v->data, D_004BACB8, 0x64);
            v->data = 0;
            v->cap = 0;
        }
        { char** pdata = &v->data; *pdata = TStr_Alloc(n, D_004BAC78, 0x5C); }
        v->cap = n;
    }
    Cp352910(v->data, first, last);
    v->count = n;
}
#pragma pop /* merge_units */
/* merge_units: end func_00352910 */
