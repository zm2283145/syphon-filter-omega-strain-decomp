#include "types.h"
typedef struct { float v[4]; } LosVec_f3;
typedef struct {
    LosVec_f3 from;
    LosVec_f3 to;
    unsigned char active; char pad21[3];
    int count;
    void* data;
    char pad2C[4];
    char buf[0xA0];
    int f110; int f114; int f118; int cap;
} LosQuery_f3;
typedef struct { char pad[0xC]; unsigned char ready; } LosSub_f3;
typedef struct {
    void* vtable; char pad4[0x1C];
    LosSub_f3 sub; char pad2D[3];
    char coll30[0xC];
    char coll3C[0xC];
    int f48;
} LosReceiver_f3;
extern char D_004EA0B0[];
extern char D_004D90A0[];
extern void Receiver_Construct(LosReceiver_f3* r, void* type);
extern LosVec_f3* Vec4_GetZero(void);
extern void Vec4_Assign(LosVec_f3* d, LosVec_f3* s);
extern void func_00136060(void* buf);
extern void func_00136020(LosSub_f3* sub, int arg, LosQuery_f3* q);
extern void ScalarCollection_Init(void* c);
LosReceiver_f3* LosReceiver_Construct(LosReceiver_f3* self, int arg)
{
    LosQuery_f3 q;
    LosSub_f3* sub;
    Receiver_Construct(self, D_004EA0B0);
    self->vtable = D_004D90A0;
    Vec4_Assign(&q.from, Vec4_GetZero());
    Vec4_Assign(&q.to, Vec4_GetZero());
    q.active = 0;
    q.data = q.buf;
    q.count = 0;
    func_00136060(q.buf);
    q.cap = 4;
    q.f110 = 0;
    q.f114 = 0;
    q.f118 = 0;
    sub = &self->sub;
    func_00136020(sub, arg, &q);
    sub->ready = 1;
    q.active = 0;
    ScalarCollection_Init(self->coll30);
    ScalarCollection_Init(self->coll3C);
    self->f48 = 0;
    return self;
}