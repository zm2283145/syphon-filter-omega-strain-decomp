/*
 * main/scriptBase: 4 files, 003D5C30-003D5EB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D5C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Array constructor helper: (array, ctor, dtor, element size, count). */
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern L4Elem30* func_003D5AA0(L4Elem30*, int);
L4Elem30* func_003D5CD0(L4Elem30* self);

Unk3D5C30* func_003D5C30(Unk3D5C30* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk0C = -1;
    return self;
}

Unk3D5C50* func_003D5C50(Unk3D5C50* self) {
    self->unk00 = 0;
    self->unk64 = 0;
    self->unk70[0] = 0.0f;
    self->unk70[1] = 0.0f;
    self->unk70[2] = 0.0f;
    self->unk70[3] = 1.0f;
    return self;
}

Unk3D5C80* func_003D5C80(Unk3D5C80* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    __construct_array(self->elems, func_003D5CD0, func_003D5AA0, sizeof(L4Elem30), 6);
    return self;
}

L4Elem30* func_003D5CD0(L4Elem30* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk10[0] = 0.0f;
    self->unk10[1] = 0.0f;
    self->unk10[2] = 0.0f;
    self->unk10[3] = 1.0f;
    self->unk20[0] = 0.0f;
    self->unk20[1] = 0.0f;
    self->unk20[2] = 0.0f;
    self->unk20[3] = 0.0f;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D5C30 */

/* merge_units: begin func_003D5D10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct ANode { ANode* prev; ANode* next; int val; };
struct APred { int pad; int* p; bool operator()(const int& x) const { return x == *p; } };
struct AIter {
    ANode* n;
    AIter() {}
    AIter(ANode* q) : n(q) {}
    int& operator*() const { return n->val; }
    AIter& operator++() { n = n->next; return *this; }
    bool operator==(const AIter& o) const { return n == o.n; }
    bool operator!=(const AIter& o) const { return n != o.n; }
};
struct AList {
    int size; ANode head;
    AIter begin() { return AIter(head.next); }
    AIter end() { return AIter(&head); }
};
extern "C" void func_00383420(AIter*, AList*, AIter*, AIter*);

extern "C" void func_003D5D10(AList* l, APred pred)
{
    AIter e = l->end();
    for (AIter i = l->begin(); i != e;) {
        if (pred(*i)) {
            AIter j = i;
            for (++j; j != e; ++j)
                if (!pred(*j)) break;
            {
                AIter r, a, b;
                a = i; b = j;
                func_00383420(&r, l, &a, &b);
                i = r;
            }
            if (i == e) break;
        }
        ++i;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D5D10 */

/* merge_units: begin func_003D5DD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void func_00397F80(void* p, int flags);
void operator_delete(void* p);
}
extern "C" void* func_003D5DD0(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            Mem_Free(0, b, "scriptBase.cc", 0x222);
        }
        {
            void* m = (char*)self + 8;
            if (m)
                func_00397F80(m, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D5DD0 */

/* merge_units: begin func_003D5EB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                      
int func_003D6010(...);                            
int memcpy(...);                            
int strlen(...);                                    
extern char D_004BD3B0;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * func_003D5EB0(char * arg0, int arg1, int arg2, int arg3) {
    int temp_v1;
    int var_v0;
    int var_s1;
    char * temp_s0;
    int temp_s0_2;

    temp_s0 = arg0 + 8;
    func_003D6010(temp_s0);
    var_s1 = 0;
    F_(temp_s0, 0xC, signed char) = 1;
    if (arg1 != 0) {
        temp_v1 = strlen(arg1) + 1; temp_s0_2 = (temp_v1 + 0x1F) / 32 * 32;
        {
            AllocGuard g;
        var_s1 = Mem_Alloc(0, temp_s0_2, &D_004BD3B0, 0x130);
        }
        memcpy(var_s1, arg1, temp_s0_2);
    }
    F_(arg0, 0x0, int) = var_s1;
    F_(arg0, 0x20, int) = arg2;
    F_(arg0, 0x34, signed char) = (signed char) (arg3 != 0);
    F_(arg0, 0x18, int) = arg3;
    F_(arg0, 0x1C, int) = 0;
    F_(arg0, 0x28, int) = -1;
    F_(arg0, 0x2C, int) = 0;
    F_(arg0, 0x24, int) = 0;
    F_(arg0, 0x35, signed char) = 0;
    F_(arg0, 0x38, int) = 0;
    F_(arg0, 0x40, signed char) = 0;
    F_(arg0, 0x41, signed char) = 0;
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D5EB0 */
