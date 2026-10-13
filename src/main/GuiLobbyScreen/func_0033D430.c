#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct O33D430 { void* vt; };
extern "C" {
extern char D_004DE830[];
extern char D_004E1220[];
extern int D_00532FD8;
extern void* D_00532FE0;
void String_Dtor(void* p, int f);
void func_0041F370(void* p, int f);
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
extern "C" O33D430* func_0033D430(O33D430* self, short del)
{
    if (self) {
        self->vt = D_004DE830;
        if (D_00532FD8) {
            D_00532FD8--;
            if (D_00532FD8 == 0) {
                void* p = D_00532FE0;
                if (p) {
                    AllocGuard g;
                    if (p)
                        String_Dtor(p, 0);
                    Mem_Free(0, p, "GuiLobbyScreen.cc", 0x6F);
                }
                D_00532FE0 = 0;
            }
        }
        if (self) {
            self->vt = D_004E1220;
            func_0041F370(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}