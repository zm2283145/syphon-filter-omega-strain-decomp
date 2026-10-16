/*
 * main/specfx: 4 files, 003EC710-003EC9F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
class OC710 {
public:
    char m0;
    unsigned char m1;
    virtual ~OC710();
    virtual void v1();
    virtual void v2();
    virtual void v3(float dt);
};
struct SC710 { OC710* p0; float f4; float f8; unsigned char fC; };
struct NC710 { int m0; NC710* next; SC710* data; };
struct HC710 { char pad[0x10]; float f10; };
extern int D_0055C090;
extern "C" {
void List_Begin(int* out, void* list);
void func_003EC6B0(NC710** out, int* in);
void func_003EC6A0(int* out, void* list);
void func_003EC690(NC710** out, int* in);
void func_0015AF40(int* out, NC710** in);
void List_Erase(int* out, void* list, int* in);
}
extern "C" void Effect_UpdateSlots(HC710* self, void* list, float dt)
{
    NC710* e;
    NC710* it;
    NC710* old;
    int t4;
    int t3;
    int t1;
    int t2;
    SC710* s;
    NC710* n;
    List_Begin(&t1, list);
    func_003EC6B0(&it, &t1);
    for (n = it; func_003EC6A0(&t2, list), func_003EC690(&e, &t2), n != e; ) {
        s = n->data;
        if (!s->fC && !(self->f10 < s->f4)) {
            s->fC = 1;
            s->p0->v1();
        }
        if (s->fC)
            s->p0->v3(dt);
        if (!(s->f8 <= 0.0f) && !(self->f10 < s->f8))
            s->p0->m1 = 1;
        if (s->p0->m1) {
            NC710* cur = n;
            n = n->next;
            delete s->p0;
            s->p0 = 0;
            s->fC = 0;
            old = cur;
            D_0055C090--;
            func_0015AF40(&t3, &old);
            List_Erase(&t4, list, &t3);
        } else {
            n = n->next;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC710 */

/* merge_units: begin func_003EC8E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; void* vt; } TC8E0;
extern char D_004E0780[];
extern void func_003EC220(void* self, short del);
extern void operator_delete(void* p);
TC8E0* func_003EC8E0(TC8E0* self, short del)
{
    if (self) {
        self->vt = D_004E0780;
        if (self)
            func_003EC220(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC8E0 */

/* merge_units: begin func_003EC950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BE020[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_003EC950(void* node)
{
    AllocGuard guard;
    Mem_Free(0, node, D_004BE020, 0x18);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC950 */

/* merge_units: begin func_003EC9F0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { void* Mem_Alloc(int pool, int size, char* file, int line); }
extern "C" void* EffectComponent_Alloc(int size)
{
    AllocGuard guard;
    return Mem_Alloc(0, size, D_004BE020, 0x12);
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC9F0 */
