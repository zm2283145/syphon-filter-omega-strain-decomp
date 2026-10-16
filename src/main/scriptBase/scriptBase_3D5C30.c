/*
 * main/scriptBase: 2 files, 003D5C30-003D5D10
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
