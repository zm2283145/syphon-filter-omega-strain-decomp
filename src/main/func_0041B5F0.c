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

extern void String_Replace(String*, int, int, char*, Tag*, Tag);

/* Appends one character to the string (insert at end). */
void String_PushBack_41B5F0(String* str, char c) {
    Tag tag;
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    String_Replace(str, size, 0, &c, &tag, tag);
}
