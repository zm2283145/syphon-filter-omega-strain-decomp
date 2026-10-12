#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct BaDeq { unsigned int cap; unsigned int size; unsigned int start; char** data; };
struct BlockArray { BaDeq blocks; unsigned int first; unsigned int count; };
struct BaGuard { BlockArray* owner; int n; char* p; };
extern "C" {
extern signed char D_00542C88;
extern unsigned int D_004BCDF0;
extern char D_004BCFA8[];
BaDeq* func_003B9170(BaDeq* self, unsigned int n, char** value, void* alloc);
BaDeq* func_003B9070(BaDeq* self, const BaDeq* x);
void func_003B9E70(BaDeq* self, unsigned int n);
void func_003B9C20(BaDeq* self, char** value);
void* func_00139BC0(unsigned int size, void* p);
void BlendRecord_CopyConstruct(void* self, const void* src);
void func_003B9B80(BaDeq* x, BaDeq* y);
void func_00393DD0(BaDeq* self, short flag);
BlockArray* func_003B8CC0(BaGuard* g);
char* func_003B8CD0(BaGuard* g);
int func_003B8CB0(BaGuard* g);
void func_003B8C50(BlockArray* owner, char* p, int n);
BaDeq* func_003B8C40(BlockArray* self);
}
extern "C" void BlockArray_Append(BlockArray* self, const void* src)
{
    unsigned int idx = self->first + self->count;
    if (idx == (self->blocks.size == 0 ? 0 : (self->blocks.size - 1) * 8)) {
        if (D_00542C88 == 0) {
            D_004BCDF0 = 0xFFFFFFF0;
            D_00542C88 = 1;
        }
        if (self->count == D_004BCDF0) {
            func_00123BE8(D_00489738->stream, "deque::push_back length error");
            func_00121B60();
        }
        if (self->blocks.size == (self->blocks.cap == 0 ? 0 : self->blocks.cap - 1)) {
            char* nb = TStr_Alloc(0x7C0, D_004BCFA8, 0x5C);
            BaGuard g;
            BaDeq tmp;
            char* zero;
            int alloc;
            g.owner = self;
            g.n = 8;
            g.p = nb;
            zero = 0;
            func_003B9170(&tmp, self->blocks.size * 2, &zero, &alloc);
            if (self->blocks.size) {
                func_003B9070(&tmp, &self->blocks);
            } else {
                char* z;
                func_003B9E70(&tmp, 2);
                z = 0;
                func_003B9C20(&tmp, &z);
            }
            {
                char* z;
                tmp.data[(tmp.start + tmp.size - 1) % tmp.cap] = nb;
                z = 0;
                func_003B9C20(&tmp, &z);
            }
            {
                void* o = func_00139BC0(0xF8, nb);
                if (o)
                    BlendRecord_CopyConstruct(o, src);
            }
            g.p = 0;
            func_003B9B80(&tmp, &self->blocks);
            self->count++;
            func_00393DD0(&tmp, 0);
            if (func_003B8CD0(&g))
                func_003B8C50(func_003B8CC0(&g), func_003B8CD0(&g), func_003B8CB0(&g));
            return;
        } else {
            /* fresh loads (the retail code does not reuse cap/size from the test above) */
            char** slot = &self->blocks.data[(*(unsigned int*)((char*)self + 8) + *(unsigned int*)((char*)self + 4) - 1) % *(unsigned int*)((char*)self + 0)];
            char* z;
            *slot = TStr_Alloc(0x7C0, D_004BCFA8, 0x5C);
            z = 0;
            func_003B9C20(&self->blocks, &z);
        }
    }
    {
        BaDeq* d = func_003B8C40(self);
        char* blk = self->blocks.data[(self->blocks.start + (idx >> 3)) % d->cap];
        void* o = func_00139BC0(0xF8, blk + (idx & 7) * 0xF8);
        if (o)
            BlendRecord_CopyConstruct(o, src);
        self->count++;
    }
}