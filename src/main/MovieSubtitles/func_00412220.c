#include "types.h"

typedef struct SubVec4 { float x, y, z, w; } SubVec4;

typedef struct Sub412220 {
    char pad00[0x50];
    void* src;          /* 0x50 */
    char pad54[0x60 - 0x54];
    char* lines[3];     /* 0x60 */
    int pos[3];         /* 0x6C */
    int count;          /* 0x78 */
    char pad7C[4];
    SubVec4 color;      /* 0x80 */
    int lens[3];        /* 0x90 */
    float f9C;          /* 0x9C */
    float fA0;          /* 0xA0 */
    int iA4;            /* 0xA4 */
    int iA8;            /* 0xA8 */
    char padAC[0xB4 - 0xAC];
    int iB4;            /* 0xB4 */
} Sub412220;

extern int func_00412210(void* src);
extern int func_004121F0(void* src);
extern int func_004121D0(void* src);
extern char* func_00412190(void* src, int col);
extern int strlen(const char* s);
extern SubVec4* func_00412180(void* src);
extern SubVec4* func_00412150(SubVec4* dst, SubVec4* src);
extern float func_00412130(void* src);
extern float func_00412110(void* src);
extern int func_004120F0(void* src);
extern void func_004120C0(void* src);
extern void func_00412050(Sub412220* self);

void func_00412220(Sub412220* self) {
    int i;
    self->iB4 = 0;
    if (func_00412210(self->src)) {
        self->iA4 = func_004121F0(self->src);
        self->count = func_004121D0(self->src);
        for (i = 0; i < self->count; i++) {
            self->lines[i] = func_00412190(self->src, i);
            self->lens[i] = strlen(self->lines[i]);
            self->pos[i] = 0;
        }
        func_00412150(&self->color, func_00412180(self->src));
        self->f9C = func_00412130(self->src);
        self->fA0 = func_00412110(self->src);
        self->iA8 = func_004120F0(self->src);
        func_004120C0(self->src);
    } else {
        func_00412050(self);
    }
}
