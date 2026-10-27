#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Eq_8EC0 {};
struct Pred_8EC0 { Eq_8EC0 op; int* ref; Pred_8EC0(Eq_8EC0 o, int* r) : op(o), ref(r) {} };
struct Str_8EC0 { int a, b, c; };
struct Item_8EC0 { char pad[0x14]; Str_8EC0 str; };
extern "C" {
extern char D_004E0220[];
extern char D_004E0800[];
extern char D_004BDFB0[];
void std_list_imp_voidPtr_remove_if(void* list, Pred_8EC0 p);
char* GetTextSystem(void);
void String_Dtor(Str_8EC0*, int);
void cMemMan_Deallocate(int, void*, char*, int);
void operator_delete(void*);
}
static inline Pred_8EC0 MakePred_8EC0(int* p) { Eq_8EC0 c; return Pred_8EC0(c, p); }
struct O_8EC0 { void* vt; char pad[0x70]; Item_8EC0* id; };
extern "C" O_8EC0* cInterfaceElement_dtor(O_8EC0* self, short del)
{
    if (self) {
        self->vt = D_004E0220;
        if (self->id) {
            int id = (int)self->id;
            Eq_8EC0 e;
            char* x = GetTextSystem();
            std_list_imp_voidPtr_remove_if(x + 0x10, MakePred_8EC0(&id));
            {
                Item_8EC0* p = self->id;
                AllocGuard g;
                if (p) {
                    Str_8EC0* s = &p->str;
                    if (s) String_Dtor(s, 0);
                }
                cMemMan_Deallocate(0, p, D_004BDFB0, 0x41);
            }
        }
        if (self) self->vt = D_004E0800;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}


