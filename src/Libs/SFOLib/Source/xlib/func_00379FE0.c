#include "types.h"
typedef struct { char pad[0xD0]; unsigned char ready; } R_79FE0;
void FlushCache(int a);
static inline void Kick_79FE0(void* tag, int qwc)
{
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
    *(volatile int*)0x1000A020 = qwc;
    *(volatile int*)0x1000E010 = 4;
    if (((unsigned int)tag & 0x70000000) == 0x70000000) {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag | 0x80000000;
    } else {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag;
        FlushCache(0);
    }
    asm volatile ("sync");
    *(volatile int*)0x1000A000 = 0x181;
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
}
void XLib_ClearVram(R_79FE0* self, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned long* p = (unsigned long*)0x70000000;
    *p++ = 0x8009 | ((unsigned long)0x10000000 << 32);
    *p++ = 0xE;
    *p++ = 1;
    *p++ = 0x1A;
    *p++ = 0x100000;
    *p++ = 0x4C;
    *p++ = 0;
    *p++ = 0x18;
    *p++ = 0x04000000 | ((unsigned long)0x04000000 << 32);
    *p++ = 0x40;
    *p++ = 0;
    *p++ = 0x47;
    *p++ = 6;
    *p++ = 0;
    *p++ = (unsigned long)r | ((unsigned long)g << 8) | ((unsigned long)b << 16) | ((unsigned long)a << 24) | ((unsigned long)0x3F800000 << 32);
    *p++ = 1;
    *p++ = 0;
    *p++ = 4;
    *p++ = 0x40004000;
    *p++ = 4;
    Kick_79FE0((void*)0x70000000, 0xA);
    self->ready = 1;
}