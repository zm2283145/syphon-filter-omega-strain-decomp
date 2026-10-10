#include "types.h"
#pragma cplusplus on
class O266 { public: int pad; virtual ~O266(); };
typedef struct { int a; int b; unsigned char flag; char pad[3]; O266* child; char sub[4]; } S266;
extern "C" void func_00263080(S266*);
extern "C" void func_00266710(void*);
extern "C" void func_00266410(S266* p) {
    p->flag = 0;
    func_00263080(p);
    func_00266710(&p->sub);
    if (p->child) {
        delete p->child;
        p->child = 0;
    }
}