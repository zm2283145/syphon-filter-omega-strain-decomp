#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Sub_EBAD0 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
struct Req_EBAD0 {
    int frame;
    unsigned char state;
    char pad5[3];
    char* file;
    void (*cb)(Sub_EBAD0*, int, int);
    int user;
    unsigned char owned;
};

extern "C" {
extern char D_004BE010;
void Mem_Free(int a, void* p, char* file, int line);
void func_0036E220(char* f, int a);
}

static inline Sub_EBAD0* ReqSub_EBAD0(Req_EBAD0* r)
{
    return r->file ? (Sub_EBAD0*)(r->file + 0x88) : 0;
}

static inline int SubData_EBAD0(Sub_EBAD0* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int func_003EBAD0(Req_EBAD0* r, int release)
{
    Sub_EBAD0* s = ReqSub_EBAD0(r);
    if (release) {
        if (SubData_EBAD0(s)) {
            r->cb(s, r->user, 0);
            {
                int p = s->n0;
                if (p) {
                    { AllocGuard g; Mem_Free(1, (void*)p, &D_004BE010, 0x56); }
                    s->n0 = 0;
                    s->n8 = 0;
                    s->n4 = 0;
                    s->bC = 0;
                }
            }
        }
    }
    if (r->owned) {
        char* f = r->file;
        AllocGuard g;
        func_0036E220(f, -1);
        Mem_Free(0, f, &D_004BE010, 0x134);
    }
    r->cb = 0;
    r->user = 0;
    r->frame = 0;
    r->file = 0;
    r->state = 6;
    r->owned = 0;
    return 1;
}
