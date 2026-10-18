#include "types.h"
typedef struct { int a, b, c, d; } Q37B000;
typedef struct { char p0[0xFC4]; Q37B000 cur; char pD4[4]; Q37B000 prev; char pE8[0x10]; } H37B000;
typedef struct {
    H37B000 h; /* 0x000 */
    char pad[0x1020 - sizeof(H37B000)];
    int buf; int p1024; int count; int f102C; int f1030; int f1034; int f1038; int* arr; int f1040;
    char p1044[0xC]; int max1050; int max1054; char p1058[8]; int f1060;
} R37B000;
/* Frame flip: keeps the peaks, swaps buffers, snapshots the current quad and clears the counters. */
void Video_RollFrameStats(R37B000* r)
{
    int i;
    r->max1050 = r->max1050 > r->f102C ? r->max1050 : r->f102C;
    r->max1054 = r->max1054 > r->f1030 ? r->max1054 : r->f1030;
    r->buf ^= 1;
    {
        H37B000* e = (H37B000*)((char*)r + r->buf * 56);
        e->prev.a = e->cur.a; e->prev.b = e->cur.b; e->prev.c = e->cur.c; e->prev.d = e->cur.d;
    }
    r->f1040 = 0;
    r->f1034 = 0;
    r->f102C = 0;
    r->f1038 = 0;
    r->f1030 = 0;
    for (i = 0; i < r->count; i++) r->arr[i] = 0;
    r->f1060 = -1;
}
