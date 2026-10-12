#include "types.h"

typedef struct Strm6480 {
    int state;
    char pad04[0x30];
    int start;
    int wr;
    int avail;
    int len;
    char pad44[4];
    int base;
    int size;
    int off;
    char pad54[4];
    int pos;
} Strm6480;

extern int func_003A6C10(void);
extern void func_003F6940(int* p1, int* n1, int* p2, int* n2, Strm6480* t, int x);
extern int func_003F6630(Strm6480* s, int p1, int n1, int p2, int n2, int at, int room, int start, int rest);

void func_003F6480(Strm6480* s)
{
    int p1;
    int p2;
    int n1;
    int n2;
    int got = 0;
    switch (s->state) {
    case 1:
        p1 = s->base + s->off % s->size;
        n1 = s->size - s->off;
        p2 = 0;
        n2 = 0;
        break;
    case 2:
        func_003F6940(&p1, &n1, &p2, &n2, s, (func_003A6C10() & 0xFFFFFF) - s->base);
        break;
    case 3:
        return;
    }
    {
        int len = s->len;
        int avail = s->avail;
        int at = s->start + (len + (s->wr - avail)) % len;
        int blocks = avail / 1024 * 1024;
        int room = s->start + len - at;
        int rest;
        room = room < blocks ? room : blocks;
        rest = blocks - room;
        if (n1 + n2 >= 0x400 && room + rest >= 0x400)
            got = func_003F6630(s, p1, n1, p2, n2, at, room, s->start, rest);
    }
    s->avail -= got;
    s->off += got;
    s->pos = (s->pos + got) % s->size;
}


