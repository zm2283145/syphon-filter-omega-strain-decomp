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
BaDeq* _cdeque_imp_cSkaSystem_RequestPtr_1_ctor(BaDeq* self, unsigned int n, char** value, void* alloc);
BaDeq* _cdeque_imp_cSkaSystem_RequestPtr_1_opAssign(BaDeq* self, const BaDeq* x);
void _cdeque_deleter_int_1_reserve(BaDeq* self, unsigned int n);
void _cdeque_deleter_int_1_push_back(BaDeq* self, char** value);
void* Mem_PlacementNew(unsigned int size, void* p);
void BlendRecord_CopyConstruct(void* self, const void* src);
void _cdeque_deleter_common_int_swap(BaDeq* x, BaDeq* y);
void _cdeque_imp_cSkaSystem_RequestPtr_1_dtor(BaDeq* self, short flag);
BlockArray* alloc_ptr_cSkaSystem_Request_int_allocator(BaGuard* g);
char* alloc_ptr_cSkaSystem_Request_int_get(BaGuard* g);
int alloc_ptr_cSkaSystem_Request_int_capacity(BaGuard* g);
void cAllocator_cSkaSystem_Request_deallocate(BlockArray* owner, char* p, int n);
BaDeq* details_compressed_pair_imp_cAllocator_int_int_1_second(BlockArray* self);
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
            Libc_Fprintf(D_00489738->stream, "deque::push_back length error");
            Libc_Abort();
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
            _cdeque_imp_cSkaSystem_RequestPtr_1_ctor(&tmp, self->blocks.size * 2, &zero, &alloc);
            if (self->blocks.size) {
                _cdeque_imp_cSkaSystem_RequestPtr_1_opAssign(&tmp, &self->blocks);
            } else {
                char* z;
                _cdeque_deleter_int_1_reserve(&tmp, 2);
                z = 0;
                _cdeque_deleter_int_1_push_back(&tmp, &z);
            }
            {
                char* z;
                tmp.data[(tmp.start + tmp.size - 1) % tmp.cap] = nb;
                z = 0;
                _cdeque_deleter_int_1_push_back(&tmp, &z);
            }
            {
                void* o = Mem_PlacementNew(0xF8, nb);
                if (o)
                    BlendRecord_CopyConstruct(o, src);
            }
            g.p = 0;
            _cdeque_deleter_common_int_swap(&tmp, &self->blocks);
            self->count++;
            _cdeque_imp_cSkaSystem_RequestPtr_1_dtor(&tmp, 0);
            if (alloc_ptr_cSkaSystem_Request_int_get(&g))
                cAllocator_cSkaSystem_Request_deallocate(alloc_ptr_cSkaSystem_Request_int_allocator(&g), alloc_ptr_cSkaSystem_Request_int_get(&g), alloc_ptr_cSkaSystem_Request_int_capacity(&g));
            return;
        } else {
            /* fresh loads (the retail code does not reuse cap/size from the test above) */
            char** slot = &self->blocks.data[(*(unsigned int*)((char*)self + 8) + *(unsigned int*)((char*)self + 4) - 1) % *(unsigned int*)((char*)self + 0)];
            char* z;
            *slot = TStr_Alloc(0x7C0, D_004BCFA8, 0x5C);
            z = 0;
            _cdeque_deleter_int_1_push_back(&self->blocks, &z);
        }
    }
    {
        BaDeq* d = details_compressed_pair_imp_cAllocator_int_int_1_second(self);
        char* blk = self->blocks.data[(self->blocks.start + (idx >> 3)) % d->cap];
        void* o = Mem_PlacementNew(0xF8, blk + (idx & 7) * 0xF8);
        if (o)
            BlendRecord_CopyConstruct(o, src);
        self->count++;
    }
}