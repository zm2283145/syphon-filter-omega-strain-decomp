#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } Obj_52C0;
typedef struct {
    char pad0[0x118];
    Obj_52C0* objs[24];
    unsigned char avail[24];
    char pad190[0x1CC - 0x190];
    int f1CC;
} Self_52C0;
extern char D_004FFB50;
extern char* D_0048C160[];
int Agent_GetSelected(void*, int);
int func_00332FE0(int, __int128);
__int128 func_003FDA40(char*);

int func_002952C0(Self_52C0* self) {
    int idx;
    int k;
    int i;
    idx = -1;
    for (k = 0; k < 0x11; k++) {
        if (func_00332FE0(Agent_GetSelected(&D_004FFB50, -1), func_003FDA40(D_0048C160[k]))) idx = k;
    }
    if (idx == 0 || self->f1CC == -1) return 0x16;
    if (idx != -1) return idx;
    if (((unsigned char*)self)[0x18F]) return 0x17;
    for (i = 0; i < 24; i++) {
        if (self->avail[i]) break;
    }
    if (i == 24) {
        for (i = 0; i < 24; i++) {
            Obj_52C0* o = self->objs[i];
            if (o && (o->flags & 4) && (o->flags & 2)) break;
        }
    }
    if (i == 24) return -1;
    return i;
}