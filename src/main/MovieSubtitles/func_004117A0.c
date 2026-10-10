#include "types.h"

typedef struct DmaBuf {
    int unk00;
    unsigned long long* packet; /* 0x04 */
    int unk08;
} DmaBuf; /* size 0x0C */

typedef struct DblBuf {
    DmaBuf bufs[2];        /* 0x00, packet ptrs at 0x04 / 0x10 */
    int current;           /* 0x18 */
    unsigned int tag;      /* 0x1C */
    unsigned int cur;      /* 0x20 */
    int a;                 /* 0x24 */
    int b;                 /* 0x28 */
    int c;                 /* 0x2C */
    int d;                 /* 0x30 */
    unsigned char ready;   /* 0x34 */
} DblBuf;

extern void func_001161A0(void);
extern void func_001161F8(void);

/* Initializes a double-buffered DMA packet chain when all four parameters are set. */
void func_004117A0(DblBuf* db, int a, int b, int c, int d) {
    if (a && b && c && d) {
        db->a = a;
        db->b = b;
        db->c = c;
        db->d = d;
        db->bufs[0].packet[0] = 0x70000000;
        db->bufs[0].packet[1] = 0;
        db->bufs[1].packet[0] = 0x70000000;
        db->bufs[1].packet[1] = 0;
        db->current = 1;
        func_001161A0();
        db->current ^= 1;
        db->cur = (unsigned int)db->bufs[db->current].packet;
        db->tag = db->cur | 0x20000000;
        func_001161F8();
        db->ready = 1;
    }
}
