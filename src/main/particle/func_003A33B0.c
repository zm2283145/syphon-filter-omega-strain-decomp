#include "types.h"

typedef struct PSys {
    char pad000[0x74];
    struct PSys* sub;           /* 0x74 */
    char pad078[0xE0 - 0x78];
    float dx;                   /* 0xE0 */
    float dy;                   /* 0xE4 */
    float dz;                   /* 0xE8 */
    char pad0EC[0x104 - 0xEC];
    int mode;                   /* 0x104 */
    char pad108[0x10C - 0x108];
    float sx;                   /* 0x10C */
    float sy;                   /* 0x110 */
    float sz;                   /* 0x114 */
    float half;                 /* 0x118 */
    char pad11C[0x130 - 0x11C];
    unsigned char flag130;      /* 0x130 */
    unsigned char flag131;      /* 0x131 */
} PSys;

typedef enum { F_OFF, F_ON } FlagE;

typedef struct PHandle {
    char pad00[0x08];
    PSys* system;
} PHandle;

void func_003A33B0(PHandle* h, int mode, int on, float x, float y, float z) {
    PSys* s = h->system;
    if (s->sub) s = s->sub;
    s->mode = mode;
    s->flag130 = on ? F_OFF : F_ON;
    s->sx = x;
    s->sy = y;
    s->sz = z;
    s->half = 0.5f * s->sy;
    s->dx = s->sy;
    s->dy = s->sy;
    s->dz = s->sy;
    s->flag131 = 1;
}
