#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)

struct TblTC {
    int pad[3];
    float f[1];
};

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* func_00234BB0(void* self, int n);
extern char D_0053B544[];
extern char D_004BC5D0[];
extern char D_004DFAC8[];
extern char D_004DFAB8[];
extern char D_004DFAD8[];
extern int D_0053B5A0;
extern int D_0053B5A8;
extern int D_0053B5B0;
extern int D_0053B5B8;
extern TblTC D_0053B6A0;
}

struct DescTC {
    char pad0[4];
    unsigned char b4;
    char pad5[0x4C - 5];
    float x4C;
};

struct V4TC {
    float x, y, z, w;
};

struct NodeTC {
    void* vt;
    NodeTC* next;
    NodeTC* prev;
    char padC[0x70 - 0xC];
    unsigned char b70;
};

struct HeadTC {
    void* vt;
    NodeTC* next;
    NodeTC* prev;
};

struct TracerTC {
    void* vt;
    HeadTC head;
    HeadTC tail;
    int count;
    int x20;
    DescTC* desc;
    char pad28[0x50 - 0x28];
    float x50;
    float x54;
    float x58;
    float x5C;
    int x60;
    int x64;
    unsigned char b68;
    unsigned char b69;
    unsigned char b6A;
};

extern "C" {
NodeTC* func_003A0EA0(void* p, NodeTC* ins, DescTC* d, int a, float f);
NodeTC* func_00398E20(void* p, NodeTC* ins, DescTC* d, int a, float f);
NodeTC* func_0039F860(void* p, NodeTC* ins, DescTC* d, int a, float f, V4TC* v);
NodeTC* func_0039B3A0(void* p, NodeTC* ins, DescTC* d, int a, float f, V4TC* v);
TracerTC* Tracer_Create(TracerTC* self, int name, int a3, float f);
}

static inline void* AllocTC(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

static inline NodeTC* New1TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x180, 0x52D);
    if (t)
        t = func_003A0EA0(t, 0, self->desc, a3, self->x50);
    return (NodeTC*)t;
}

static inline NodeTC* New2TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x180, 0x533);
    if (t) {
        V4TC v;
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        t = func_0039F860(t, 0, self->desc, a3, self->x50, &v);
    }
    return (NodeTC*)t;
}

static inline NodeTC* New3TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x140, 0x537);
    if (t) {
        V4TC v;
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        t = func_0039B3A0(t, 0, self->desc, a3, self->x50, &v);
    }
    return (NodeTC*)t;
}

static inline NodeTC* New4TC(TracerTC* self, int a3)
{
    void* t = AllocTC(0x130, 0x53B);
    if (t)
        t = func_00398E20(t, 0, self->desc, a3, self->x50);
    return (NodeTC*)t;
}

extern "C" TracerTC* Tracer_Create(TracerTC* self, int name, int a3, float f)
{
    NodeTC* t;
    NodeTC* p;

    HeadTC* hd = &self->head;
    HeadTC* tl = &self->tail;
    void* a = D_004DFAD8;
    void* b = D_004DFAB8;
    self->vt = D_004DFAC8;
    self->head.vt = a;
    self->head.vt = b;
    self->tail.vt = a;
    self->tail.vt = b;
    self->head.next = (NodeTC*)tl;
    self->head.prev = (NodeTC*)hd;
    self->tail.next = (NodeTC*)tl;
    self->tail.prev = (NodeTC*)hd;
    self->count = 0;
    self->x50 = 0;
    self->b68 = 0;
    self->x20 = 0;
    self->x64 = 0;
    self->x5C = 1.0f;
    self->b6A = 0;
    self->head.next = (NodeTC*)tl;
    self->head.prev = (NodeTC*)hd;
    self->tail.next = (NodeTC*)tl;
    self->tail.prev = (NodeTC*)hd;
    self->count = 0;
    self->desc = *(DescTC**)func_00234BB0(D_0053B544, name);
    if (self->desc->b4 == 1) {
        t = New1TC(self, a3);
    } else if (name == D_0053B5A0) {
        t = New2TC(self, a3);
    } else if (name == D_0053B5A8 || name == D_0053B5B0 || name == D_0053B5B8) {
        t = New3TC(self, a3);
    } else {
        t = New4TC(self, a3);
    }
    self->x58 = self->desc->x4C * (2.0f * (((float*)&D_0053B6A0)[t->b70 + 3] - 0.5f));
    self->x54 = f + f * self->x58;
    p = self->tail.prev;
    t->next = (NodeTC*)&self->tail;
    t->prev = p;
    p->next = t;
    self->tail.prev = t;
    self->count++;
    return self;
}

