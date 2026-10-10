#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern unsigned char D_0055A2F8;
extern char D_0055A2E0[];
extern char D_004BDFC8[];
void List_End(void* list, void* item);
}
class F8Ev { public: int a; int b; virtual ~F8Ev(); };
extern "C" void EventQueue_Admit(F8Ev* e)
{
    if (D_0055A2F8) {
        F8Ev* p = e;
        if (p) {
            AllocGuard g;
            p->~F8Ev();
            Mem_Free(0, p, D_004BDFC8, 0x27);
        }
        return;
    }
    List_End(D_0055A2E0, &e);
}
