#pragma cplusplus on
#include "types.h"

struct Vec3D6580 {
    int* data;
    int* end;
    int pad;
    int count;
    int cap;
};

struct Obj3D6580 {
    char pad[0xA4];
    Vec3D6580 v;
};

extern "C" {
extern char D_004BD428[];
extern char D_004BD418[];
void* func_00398320(unsigned int size, int pool, char* file, int line);
void func_003D6680(void* allocation, int pool, int flags, char* file, int line);
void* memcpy(void*, const void*, unsigned int);
}

extern "C" void func_003D6580(Obj3D6580* o, int x)
{
    if (o->v.count + 1 > o->v.cap) {
        int* p;
        o->v.cap += 500;
        p = (int*)func_00398320(o->v.cap * 4, 0, D_004BD428, 0xCE);
        if (o->v.data) {
            memcpy(p, o->v.data, o->v.count * 4);
        }
        o->v.end = p + (o->v.end - o->v.data);
        if (o->v.data) {
            func_003D6680(o->v.data, 0, 1, D_004BD418, 0xD3);
        }
        o->v.data = p;
    }
    o->v.count++;
    *o->v.end++ = x;
}

