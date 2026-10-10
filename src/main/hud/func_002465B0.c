#include "types.h"
typedef struct { float x, y; } B8P_2465B0;
typedef struct { float x, y, w, h; } B8R_2465B0;
unsigned char func_002465B0(B8P_2465B0* p, B8R_2465B0* r) {
    unsigned char res = 0;
    unsigned char iny = 0;
    unsigned char inx = 0;
    if (p->x >= r->x && p->x <= r->x + r->w) inx = 1;
    if (inx && p->y >= r->y) iny = 1;
    if (iny && p->y <= r->y + r->h) res = 1;
    return res;
}