#ifndef SFOINI_STRING_H
#define SFOINI_STRING_H
/* MSL string representation shared by the SFOini source section. */
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
#endif
