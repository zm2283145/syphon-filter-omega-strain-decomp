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
void func_0013B180(int* out, void* list);
void func_003EC6B0(NC710** out, int* in);
void func_003EC6A0(int* out, void* list);
void func_003EC690(NC710** out, int* in);
void func_0015AF40(int* out, NC710** in);
void func_00138DA0(int* out, void* list, int* in);
}
extern "C" void func_003EC710(HC710* self, void* list, float dt)
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
    func_0013B180(&t1, list);
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
            func_00138DA0(&t4, list, &t3);
        } else {
            n = n->next;
        }
    }
}


