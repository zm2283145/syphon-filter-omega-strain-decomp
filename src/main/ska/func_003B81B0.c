#pragma cplusplus on

#include "types.h"

/* copy_backward over 0x180-byte elements (base part, then the member at +0x10). */
struct Elem_3B81B0 { unsigned char head[0x10]; unsigned char body[0x170]; };

extern "C" {
void func_003B6F70(Elem_3B81B0* dst, const Elem_3B81B0* src);
void func_003B6DC0(void* dst, const void* src);
}

extern "C" Elem_3B81B0* func_003B81B0(Elem_3B81B0* first, Elem_3B81B0* last, Elem_3B81B0* dest)
{
    while (first < last) {
        --last;
        --dest;
        func_003B6F70(dest, last);
        func_003B6DC0(dest->body, last->body);
    }
    return dest;
}