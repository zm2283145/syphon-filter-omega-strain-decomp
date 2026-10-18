/*
 * main/interface_model: 7 files, 003EE500-003EE840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EE500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int func_003EE500(Unk3EE500* self) {
    return 0 < self->unk8C;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE500 */

/* merge_units: begin func_003EE510 */
#pragma push /* merge_units */
typedef struct Node_003EE510 {
    char pad0[0x6C];
    unsigned short nA;
    unsigned short nB;
    char pad70[0x10];
    void **a;
    struct Node_003EE510 **b;
    char pad88[4];
    int skip;
} Node_003EE510;
extern void IeElement_EvaluateAt(void *p, float t);
void IeNode_PropagateTrackColour(Node_003EE510 *n, float t)
{
    int i;
    for (i = 0; i < n->nA; i++) {
        IeElement_EvaluateAt(n->a[i], t);
    }
    for (i = 0; i < n->nB; i++) {
        if (n->b[i]->skip <= 0) {
            IeNode_PropagateTrackColour(n->b[i], t);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE510 */

/* merge_units: begin func_003EE5E0 */
#pragma push /* merge_units */
extern int IeNode_PropagateColour(Unk3EE5E0*, Vec4*);

/* Stores a vector at +0xA0, then forwards it to IeNode_PropagateColour. */
int func_003EE5E0(Unk3EE5E0* self, Vec4* v) {
    float x;
    float y;
    float z;
    float w;

    x = v->x;
    self->unkA0.x = x;
    y = v->y;
    self->unkA0.y = y;
    z = v->z;
    self->unkA0.z = z;
    w = v->w;
    self->unkA0.w = w;
    return IeNode_PropagateColour(self, v);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE5E0 */

/* merge_units: begin func_003EE610 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct LNode_3EE610 { struct LNode_3EE610* prev; struct LNode_3EE610* next; void* val; } LNode_3EE610;
struct It_3EE610 { LNode_3EE610* n; };

struct Self_3EE610;
extern "C" {
It_3EE610 func_003ED850(void* l);
void func_003ED860(It_3EE610* out, It_3EE610* in);
It_3EE610 func_003ED870(void* l);
void IeElement_UpdateAnimation(void* p, float f);
int IeNode_Update(Self_3EE610* self, float f);
}
struct ItE_3EE610 : It_3EE610 { ItE_3EE610(const ItE_3EE610& o) { n = o.n; } ItE_3EE610(const It_3EE610& t) { func_003ED860((It_3EE610*)this, (It_3EE610*)&t); } };
struct Self_3EE610 {
    char pad0[0x60]; unsigned char b60; char pad61[0x6C - 0x61];
    unsigned short n6C; unsigned short n6E; char pad70[0x84 - 0x70];
    Self_3EE610** a84; void* p88; char l8C[0xD0 - 0x8C];
};
static inline ItE_3EE610 B0_3EE610(void* l) { return ItE_3EE610(func_003ED870(l)); }
static inline ItE_3EE610 E0_3EE610(void* l) { return ItE_3EE610(func_003ED850(l)); }
static inline ItE_3EE610 B1_3EE610(void* l) { return B0_3EE610(l); }
static inline ItE_3EE610 BeginE_3EE610(void* l) { return B1_3EE610(l); }
static inline ItE_3EE610 End_3EE610(void* l) { return E0_3EE610(l); }
static inline bool Ne_3EE610(const It_3EE610& a, const ItE_3EE610& b) { return a.n != b.n; }

extern "C" int IeNode_Update(Self_3EE610* self, float f)
{
    if (self->b60) {
        It_3EE610 it = ItE_3EE610(BeginE_3EE610(self->l8C));
        while (Ne_3EE610(it, End_3EE610(self->l8C))) {
            IeElement_UpdateAnimation(it.n->val, f);
            it.n = it.n->next;
        }
        { int i; for (i = 0; i < self->n6E; i++) IeNode_Update(self->a84[i], f); }
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE610 */

/* merge_units: begin func_003EE740 */
#pragma push /* merge_units */
#pragma cplusplus on
class E3EE740 {
public:
    virtual void v0();
    virtual float get();
};
struct O3EE740 {
    char pad0[0x6C];
    unsigned short n6C;
    unsigned short n6E;
    char pad70[0x10];
    E3EE740** items;
    O3EE740** kids;
};
extern "C" float func_003EE740(O3EE740* o) {
    int i;
    int j;
    float m = 0.0f;
    for (i = 0; i < o->n6C; i++) {
        float v = o->items[i]->get();
        if (v > m) m = v;
    }
    for (j = 0; j < o->n6E; j++) {
        float v = func_003EE740(o->kids[j]);
        if (v > m) m = v;
    }
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE740 */

/* merge_units: begin func_003EE830 */
#pragma push /* merge_units */
void IeNode_SetFlag61(char* self, char value) {
    self[97] = value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE830 */

/* merge_units: begin func_003EE840 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
struct Node_003EE840 { char pad[0x6E]; unsigned short count; char p70[0x84 - 0x70]; Node_003EE840** kids; };
extern "C" {
int String_AssignCStr_1C43A0(void* s, const char* name);
int func_003EEAC0(void* s, const char* name);
int func_003EEAF0(void* s, const char* name);
void* func_003EEB20(void* s);
Node_003EE840* IeNode_FindNode(Node_003EE840* n, const char* name);
}
static inline Node_003EE840* F3(Node_003EE840* n, const char* name) {
    int i;
    if (func_003EEAC0(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = IeNode_FindNode(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node_003EE840* F2(Node_003EE840* n, const char* name) {
    int i;
    if (func_003EEAF0(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F3(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node_003EE840* F1(Node_003EE840* n, const char* name) {
    int i;
    if (String_AssignCStr_1C43A0(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F2(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
extern "C" Node_003EE840* IeNode_FindNode(Node_003EE840* n, const char* name) {
    int i;
    if (String_AssignCStr_1C43A0(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F1(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE840 */
