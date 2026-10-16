#include "types.h"

typedef struct Dev100 {
    char pad000[0x100];
    void* port; /* 0x100 */
} Dev100;

extern void func_0026BB28(void* port, int count, unsigned char* cmd, int len, unsigned char* data);

/* Sends command 3 with two data bytes built from the flags. */
void func_00369920(Dev100* dev, int on, int mode) {
    unsigned char data[3];
    unsigned char cmd;
    cmd = 3;
    data[0] = (on != 0) + ((mode << 1) & 0xFE);
    data[1] = (mode & 0x80) != 0;
    func_0026BB28(dev->port, 1, &cmd, 2, data);
}
