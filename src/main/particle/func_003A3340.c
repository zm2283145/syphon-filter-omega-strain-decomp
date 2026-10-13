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
    char pad108[0x11C - 0x108];
    float z;                    /* 0x11C */
    char pad120[0x130 - 0x120];
    unsigned char flag130;      /* 0x130 */
    unsigned char flag131;      /* 0x131 */
} PSys;

typedef enum { F_OFF, F_ON } FlagE;
typedef struct PHandle {
    char pad00[0x08];
    PSys* system;
} PHandle;

void func_003A3340(PHandle* h, int mode, float* seg, int on) {
    PSys* s = h->system;
    if (s->sub) s = s->sub;
    s->mode = mode;
    s->flag130 = on ? F_OFF : F_ON;
    s->dx = seg[4] - seg[0];
    s->dy = seg[5] - seg[1];
    s->dz = seg[6] - seg[2];
    s->z = seg[2];
    s->flag131 = 0;
}

