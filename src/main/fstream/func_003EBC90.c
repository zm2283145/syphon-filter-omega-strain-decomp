#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"

struct Sub_EBC90 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
struct Req_EBC90 {
    int frame;
    unsigned char state;
    char pad5[3];
    char* file;
    void (*cb)(Sub_EBC90*, int, int);
    int user;
    unsigned char owned;
};

extern "C" {
void func_0036DEF0(char* f);
int FileMan_GetSize(char* f);
int func_003EBDD0(Sub_EBC90* s, int size);
void func_0036D950(char* f, int* data, int size);
}

static inline Sub_EBC90* ReqSub_EBC90(Req_EBC90* r)
{
    return r->file ? (Sub_EBC90*)(r->file + 0x88) : 0;
}

static inline int SubData_EBC90(Sub_EBC90* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int func_003EBC90(Req_EBC90* r)
{
    Sub_EBC90* s = ReqSub_EBC90(r);
    func_0036DEF0(r->file);
    int data = 0;
    int size = FileMan_GetSize(r->file);
    if (!func_003EBDD0(s, size))
        return 0;
    r->state = 1;
    if (!s->bC) {
        data = SubData_EBC90(s);
        func_0036D950(r->file, &data, size);
    } else {
        if (r->state == 1 || r->state == 3) {
            Sub_EBC90* t = ReqSub_EBC90(r);
            if (SubData_EBC90(t)) {
                t->bC = 1;
                r->state = 3;
                r->cb(t, r->user, 1);
            }
        }
        return 0;
    }
    return 1;
}


