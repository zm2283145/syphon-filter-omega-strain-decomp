#include "types.h"
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C0EE0;
typedef struct { int a, b, c; char f; } Inner_1C0EE0;
typedef struct { int cap; int count; char* data; } VV_1C0EE0;
extern int D_004FFBE4;
extern VV_1C0EE0* D_004FFBE8;
extern int Pop_FindTag(PopReader_1C0EE0* r, int tag);
extern void func_00165E60(void* a, char* name, int x);
extern void* func_001698C0(void);
extern void func_001C10A0(Inner_1C0EE0* t);
extern void func_001C4410(VV_1C0EE0* v, int n, Inner_1C0EE0* fill);
extern void func_0013A040(Inner_1C0EE0* t, int flags);
extern void func_001396D0(void* v, int n);
extern void PtrVec_PushBack_1C1080(void* v, int* x);
#pragma opt_strength_reduction off
void Loader_InitNodeGroups(void* a0, PopReader_1C0EE0* r)
{
    D_004FFBE4 = 0;
    if (r->cur) {
        int mis;
        func_00165E60(func_001698C0(), "Initializing Node Groups...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A505247)) {
            int n;
            n = *(int*)r->cur;
            r->cur += 4;
            if (n) {
                VV_1C0EE0* vv;
                Inner_1C0EE0 tmp;
                int m;
                int i;
                D_004FFBE4 = n;
                vv = D_004FFBE8;
                func_001C10A0(&tmp);
                tmp.f = 1;
                func_001C4410(vv, n, &tmp);
                func_0013A040(&tmp, -1);
                for (i = 0; i < n; i++) {
                    int j;
                    int off = i * 16;
                    m = *(int*)r->cur;
                    r->cur += 4;
                    func_001396D0(vv->data + off, m);
                    for (j = 0; j < m; j++) {
                        int v[1];
                        v[0] = *(int*)r->cur;
                        r->cur += 4;
                        PtrVec_PushBack_1C1080(vv->data + off, v);
                    }
                }
            }
        }
    }
}
#pragma opt_strength_reduction reset