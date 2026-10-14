/* _sceFs_Rcv_Intr (libkernl filestub.c; newer double-buffered version of the SDK 2.2 source).
   dst is pinned to t0 in the two case-2 copy loops (global-alloc priority otherwise gives the src base t0). */
typedef unsigned int size_t;
typedef struct { char v[4]; } SceFsVersion;
typedef struct { char v[0x144]; } SceFsDirent;
typedef struct { char v[0x40]; } SceFsStatRec;
extern void *memcpy(void *, const void *, size_t);
extern int iSignalSema(int);
extern int D_00486240;
extern int D_00486238;
extern char D_004E5480[];
extern volatile int D_004861B8[32];

void func_00110DA8(int *arg)
{
    int id;
    int cmd;
    int buf;
    int size;
    int addr;
    int len;
    int *q;
    int i;
    int k;
    int idx;
    char *pkt;

    D_00486238 = D_00486240 ? arg[3] : 0;
    pkt = (char *)((int)(D_004E5480 + D_00486238 * 0x440) | 0x20000000);
    *(SceFsVersion *)&id = *(SceFsVersion *)(pkt + 0x0);
    *(SceFsVersion *)&cmd = *(SceFsVersion *)(pkt + 0x4);
    *(SceFsVersion *)&buf = *(SceFsVersion *)(pkt + 0x8);
    *(SceFsVersion *)&size = *(SceFsVersion *)(pkt + 0xC);
    if (id >= 0)
        memcpy((void *)buf, pkt + 0x10, size);
    switch (cmd) {
    case 2:
        q = (int *)(pkt + 0x14);
        if (q[0] > 0) {
            register char *dst asm("$8") = (char *)q[2];
            char *udst = (char *)((int)dst | 0x20000000);

            for (i = 0; i < q[0]; i++) {
                char *src = (char *)q + 0x10;

                unsigned char c = src[i];

                udst[i] = c;
                dst[i] = c;
            }
        }
        if (q[1] > 0) {
            register char *dst asm("$8") = (char *)q[3];
            char *udst = (char *)((int)dst | 0x20000000);

            for (i = 0; i < q[1]; i++) {
                char *src = (char *)q + 0x50;

                unsigned char c = src[i];

                udst[i] = c;
                dst[i] = c;
            }
        }
        break;
    case 11:
        if (*(int *)buf > 0) {
            *(SceFsVersion *)&addr = *(SceFsVersion *)(pkt + 0x14);
            *(SceFsDirent *)addr = *(SceFsDirent *)(pkt + 0x18);
        }
        break;
    case 12:
        *(SceFsVersion *)&addr = *(SceFsVersion *)(pkt + 0x14);
        *(SceFsStatRec *)addr = *(SceFsStatRec *)(pkt + 0x18);
        break;
    case 23:
    case 25:
    case 26:
        *(SceFsVersion *)&addr = *(SceFsVersion *)(pkt + 0x14);
        *(SceFsVersion *)&len = *(SceFsVersion *)(pkt + 0x18);
        k = len;
        if (1024 < (unsigned int)k) {
            len = 1024;
            k = 1024;
        }
        memcpy((void *)addr, pkt + 0x1C, k);
        break;
    }
    if (id < 0) {
        id = -id;
        for (i = 0; i < 32; i++) {
            if (D_004861B8[i] == id) {
                D_004861B8[i] = -1;
                break;
            }
        }
    } else {
        iSignalSema(id);
    }
}