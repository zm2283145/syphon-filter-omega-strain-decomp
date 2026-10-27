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

int cInterfaceModel_IsInstanced(Unk3EE500* self) {
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
extern void viBufGetTs(void *p, float t);
void cInterfaceModel_SetFrame(Node_003EE510 *n, float t)
{
    int i;
    for (i = 0; i < n->nA; i++) {
        viBufGetTs(n->a[i], t);
    }
    for (i = 0; i < n->nB; i++) {
        if (n->b[i]->skip <= 0) {
            cInterfaceModel_SetFrame(n->b[i], t);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE510 */

/* merge_units: begin func_003EE5E0 */
#pragma push /* merge_units */
extern int cInterfaceModel_FilterChildren(Unk3EE5E0*, Vec4*);

/* Stores a vector at +0xA0, then forwards it to cInterfaceModel_FilterChildren. */
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
    return cInterfaceModel_FilterChildren(self, v);
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
It_3EE610 std_list_cInterfaceElementPtr_end(void* l);
void cLListIterator_cInterfaceElementPtr_ctor(It_3EE610* out, It_3EE610* in);
It_3EE610 std_list_cInterfaceElementPtr_begin(void* l);
void cAnimator_NextFrame(void* p, float f);
int cInterfaceModel_NextFrame(Self_3EE610* self, float f);
}
struct ItE_3EE610 : It_3EE610 { ItE_3EE610(const ItE_3EE610& o) { n = o.n; } ItE_3EE610(const It_3EE610& t) { cLListIterator_cInterfaceElementPtr_ctor((It_3EE610*)this, (It_3EE610*)&t); } };
struct Self_3EE610 {
    char pad0[0x60]; unsigned char b60; char pad61[0x6C - 0x61];
    unsigned short n6C; unsigned short n6E; char pad70[0x84 - 0x70];
    Self_3EE610** a84; void* p88; char l8C[0xD0 - 0x8C];
};
static inline ItE_3EE610 B0_3EE610(void* l) { return ItE_3EE610(std_list_cInterfaceElementPtr_begin(l)); }
static inline ItE_3EE610 E0_3EE610(void* l) { return ItE_3EE610(std_list_cInterfaceElementPtr_end(l)); }
static inline ItE_3EE610 B1_3EE610(void* l) { return B0_3EE610(l); }
static inline ItE_3EE610 BeginE_3EE610(void* l) { return B1_3EE610(l); }
static inline ItE_3EE610 End_3EE610(void* l) { return E0_3EE610(l); }
static inline bool Ne_3EE610(const It_3EE610& a, const ItE_3EE610& b) { return a.n != b.n; }

extern "C" int cInterfaceModel_NextFrame(Self_3EE610* self, float f)
{
    if (self->b60) {
        It_3EE610 it = ItE_3EE610(BeginE_3EE610(self->l8C));
        while (Ne_3EE610(it, End_3EE610(self->l8C))) {
            cAnimator_NextFrame(it.n->val, f);
            it.n = it.n->next;
        }
        { int i; for (i = 0; i < self->n6E; i++) cInterfaceModel_NextFrame(self->a84[i], f); }
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
extern "C" float cInterfaceModel_NumFrames(O3EE740* o) {
    int i;
    int j;
    float m = 0.0f;
    for (i = 0; i < o->n6C; i++) {
        float v = o->items[i]->get();
        if (v > m) m = v;
    }
    for (j = 0; j < o->n6E; j++) {
        float v = cInterfaceModel_NumFrames(o->kids[j]);
        if (v > m) m = v;
    }
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE740 */

/* merge_units: begin func_003EE830 */
#pragma push /* merge_units */
void cInterfaceModel_SetPerspective(char* self, char value) {
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
int std_basic_string_char_char_traits_char_compare_charP(void* s, const char* name);
int cString_opEq(void* s, const char* name);
int std_opEq_basicstringR_charP(void* s, const char* name);
void* func_003EEB20(void* s);
Node_003EE840* cInterfaceModel_FindChild(Node_003EE840* n, const char* name);
}
static inline Node_003EE840* F3(Node_003EE840* n, const char* name) {
    int i;
    if (cString_opEq(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = cInterfaceModel_FindChild(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node_003EE840* F2(Node_003EE840* n, const char* name) {
    int i;
    if (std_opEq_basicstringR_charP(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F3(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node_003EE840* F1(Node_003EE840* n, const char* name) {
    int i;
    if (std_basic_string_char_char_traits_char_compare_charP(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F2(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
extern "C" Node_003EE840* cInterfaceModel_FindChild(Node_003EE840* n, const char* name) {
    int i;
    if (std_basic_string_char_char_traits_char_compare_charP(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node_003EE840* r = F1(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EE840 */
