#include "types.h"
#pragma cplusplus on
#pragma exceptions off
#include "alloc_guard.h"
struct CaNode { int a; int b; int c; };
extern "C" {
extern int D_0049D010;
extern char D_0049C088[];
void* Mem_Alloc(int, int, char*, int);
}
struct CaBase { char p[0x4C]; int type; };
struct CaOwner : CaBase { char p50[0x3214]; void* link; };
extern "C" void func_003D9D30(CaNode* n, void* link);
struct CaComp { char p[0x18]; CaNode* node; char p1c[0x14]; CaBase* owner; };
extern "C" void Component_AttachOwner(CaComp* c, CaBase* o)
{
    c->owner = o;
    if (o && o->type == D_0049D010) {
        CaOwner* p = (CaOwner*)o;
        if (p->link) {
            if (p->link) {
                if (!c->node) {
                    CaNode* n;
                    {
                        AllocGuard g;
                        n = (CaNode*)Mem_Alloc(0, 12, D_0049C088, 0x49);
                    }
                    if (n) { n->a = 0; n->b = 0; n->c = -1; }
                    c->node = n;
                }
                func_003D9D30(c->node, p->link);
            }
        }
    }
}
