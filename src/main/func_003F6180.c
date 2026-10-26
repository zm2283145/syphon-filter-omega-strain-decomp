#include "types.h"

/* func_003F6180: movie audio feed - while the IOP side has room, interleave one 0x100-byte
 * block per channel from the stream ring into the SPU staging buffer (ADPCM loop flags set at
 * the ring start/end) and DMA it to the IOP. */

typedef struct { void* src; void* dest; int size; int attr; } Dma6180;

typedef struct Strm6180 {
    int state;
    char pad04[0x14];
    int nch;        /* 0x18 */
    int chunk;      /* 0x1C */
    char pad20[0x14];
    unsigned char* start; /* 0x34 */
    int wr;         /* 0x38 */
    int avail;      /* 0x3C */
    int len;        /* 0x40 */
    char pad44[4];
    void* iop;      /* 0x48 */
    char pad4C[4];
    int sent;       /* 0x50 */
    char pad54[0xC];
    int spu;        /* 0x60 */
} Strm6180;

extern unsigned char D_0055C110[];
extern int func_003A6BD0(void);
extern void func_003A6BE0(int n, int at);
extern void FlushCache(int);
extern int sceSifSetDma(Dma6180*, int);
extern int sceSifDmaStat(int);

static inline int SendDma(Dma6180* t)
{
    int r;
    while ((r = sceSifSetDma(t, 1)) == 0) {
    }
    return r;
}

void func_003F6180(Strm6180* s)
{
    Dma6180 t;
    int room = 0;
    int* rp = &room; /* unused: room is address-taken in retail (kept in its stack slot) */
    int i;
    int at;
    unsigned char* fe;
    int off;
    int id;
    unsigned char* fa;
    unsigned char* fb;
    unsigned char* buf;
    switch (s->state) {
    case 1:
        if (s->avail < 0x1000) return;
        room = 0x1000 - s->sent;
        break;
    case 2:
        room = (func_003A6BD0() - s->spu + 0x1000) & 0xFFF;
        break;
    case 3:
        return;
    }
    /* retail places the buffer-address setup after the loop and enters the loop at its test */
    goto setup;
    do {
        i = 0;
        if (i < s->nch) {
            off = 0;
            do {
                unsigned char* d = D_0055C110;
                int n = 0;
                unsigned char* p = s->start + (s->len + (s->wr - s->avail)) % s->len;
                p += i * s->chunk;
                do {
                    int k;
                    for (k = 0; k < s->chunk; k++) {
                        *d++ = *p++;
                        n++;
                    }
                    p += s->chunk * (s->nch - 1);
                } while (n < 0x100);
                if (s->spu + 0x100 == 0x1000) *fe = 3;
                if (s->spu == 0) {
                    *fa = 6;
                    *fb = 2;
                }
                {
                    at = s->spu + off;
                    FlushCache(0);
                    t.src = buf;
                    t.dest = s->iop;
                    t.size = 0x100;
                    t.attr = 0;
                    id = SendDma(&t);
                    while (sceSifDmaStat(id) >= 0) {
                    }
                    func_003A6BE0(0x100, at);
                }
                i++;
                off += 0x1000;
            } while (i < s->nch);
        }
        s->spu = (s->spu + 0x100) % 0x1000;
        room -= 0x100;
        s->avail -= s->nch << 8;
        s->sent += 0x100;
test:;
    } while (room >= 0x100 && s->avail >= s->nch << 8);
    return;
setup:
    fe = &D_0055C110[0xF1];
    fa = &D_0055C110[1];
    fb = &D_0055C110[0x11];
    buf = D_0055C110;
    goto test;
}
