#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct Pop_00238A50 { int version; int size; unsigned int base; char* cur; } Pop_00238A50;
typedef struct Vec_00238A50 { int a; int b; void** data; } Vec_00238A50;
typedef struct Trk_00238A50 { int owner; unsigned char f4; char pad5[3]; unsigned int f8; Vec_00238A50 vec; } Trk_00238A50;
typedef struct Cue_00238A50 { void* vt; float f4; int type; float fC; float f10; float f14; float f18; } Cue_00238A50;
extern "C" {
void* Mem_Alloc(int heap, int size, char* file, int line);
void PtrVector_Resize(Vec_00238A50* v, int n, void** fill);
void* func_00239610(void* p, Pop_00238A50* r, int owner);
void* func_002397F0(void* p, Pop_00238A50* r, int owner);
extern char D_004A6FA8[];
extern char D_004DC028[];
extern char D_004DC038[];
}
static inline float ReadF_00238A50(Pop_00238A50* r)
{
    float v = *(float*)r->cur;
    r->cur += 4;
    return v;
}
static inline void* Alloc_00238A50(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004A6FA8, line);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void func_00238A50(Trk_00238A50* self, int owner, Pop_00238A50* r)
{
    int n = (int)ReadF_00238A50(r);
    void* fill1 = 0;
    void* fill0 = 0;
    int i;
    PtrVector_Resize(&self->vec, 0, &fill0);
    PtrVector_Resize(&self->vec, n, &fill1);
    for (i = 0; i < n; i++) {
        int type;
        Cue_00238A50* c = 0;
        type = (int)ReadF_00238A50(r);
        switch (type) {
        case 0:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0xC, 0x6C3);
            if (p) {
                p->vt = D_004DC038;
                p->type = type;
                p->f4 = ReadF_00238A50(r);
            }
            c = p;
            }
            break;
        case 1:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1C, 0x6C7);
            if (p) {
                p->vt = D_004DC038;
                p->type = 1;
                p->f4 = ReadF_00238A50(r);
                p->vt = D_004DC028;
                p->f14 = *(float*)r->cur; r->cur += 4;
                p->f18 = *(float*)r->cur; r->cur += 4;
                p->fC = *(float*)r->cur; r->cur += 4;
                p->f10 = *(float*)r->cur; r->cur += 4;
            }
            c = p;
            }
            break;
        case 2:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1A0, 0x6CB);
            if (p)
                p = (Cue_00238A50*)func_002397F0(p, r, owner);
            c = p;
            }
            break;
        case 3:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0xC, 0x6CF);
            if (p) {
                p->vt = D_004DC038;
                p->type = type;
                p->f4 = ReadF_00238A50(r);
            }
            c = p;
            }
            break;
        case 4:
            {
            Cue_00238A50* p = (Cue_00238A50*)Alloc_00238A50(0x1A0, 0x6D3);
            if (p)
                p = (Cue_00238A50*)func_00239610(p, r, owner);
            c = p;
            }
            break;
        }
        if (c)
            self->vec.data[i] = c;
    }
    self->owner = owner;
    self->f8 = 0x80000000;
    self->f4 = 0;
}
#pragma pop