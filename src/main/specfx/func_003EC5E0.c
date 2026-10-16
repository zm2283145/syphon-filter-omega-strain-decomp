#pragma cplusplus on
#include "types.h"
class OC5E0 {
public:
    int m0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct NC5E0 { int m0; NC5E0* next; OC5E0** data; };
extern "C" {
void List_Begin(int* out, void* list);
void func_003EC6B0(NC5E0** out, int* in);
void func_003EC6A0(int* out, void* list);
void func_003EC690(NC5E0** out, int* in);
}
extern "C" void func_003EC5E0(void* self)
{
    NC5E0* e;
    NC5E0* it;
    int t1;
    int t2;
    NC5E0* n;
    List_Begin(&t1, self);
    func_003EC6B0(&it, &t1);
    for (n = it; func_003EC6A0(&t2, self), func_003EC690(&e, &t2), n != e; n = n->next)
        (*n->data)->v4();
}