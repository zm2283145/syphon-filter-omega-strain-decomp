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

extern void func_0013D710(String*, int, int, int);

/* Calls func_0013D710(str, size(str), 0, arg). */
void func_0029F5B0(String* str, int arg) {
    int size;
    if (str->l.cap & 1) {
        size = str->l.size;
    } else {
        size = (unsigned char)str->s.size;
    }
    func_0013D710(str, size, 0, arg);
}
