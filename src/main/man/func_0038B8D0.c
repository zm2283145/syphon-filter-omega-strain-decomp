#include "types.h"
typedef struct { unsigned char pad[7]; unsigned char count; unsigned char* data; unsigned char pad2[4]; } Grp_B8D0;
typedef struct {
    unsigned char pad0[0x1EC0];
    Grp_B8D0 groups[0x48];
    unsigned char* bufs[0x20];
    unsigned short numGroups;
} Model_B8D0;
void func_0038B8D0(Model_B8D0* m)
{
    unsigned int i;
    unsigned int n;
    unsigned char* d;
    unsigned char* buf;
    unsigned int j;
    unsigned char* p;
    unsigned int c;
    unsigned int k;
    for (i = 0; i < m->numGroups; i++) {
        buf = m->bufs[i];
        if (buf != 0) {
            n = m->groups[i].count;
            d = m->groups[i].data; d += 2;
            for (j = 0; j < n; j++) {
                c = d[1];
                d += 2;
                p = buf;
                buf += 0x20;
                for (k = 0; k < c; k++) {
                    if (*p != 0) *p = 0x5A;
                    p++;
                }
            }
        }
    }
}