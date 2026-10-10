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
void func_002AEB40(String* str, int a, int b) {
    Tag tag;
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    String_Replace(str, 0, size, a, b, tag);
}
