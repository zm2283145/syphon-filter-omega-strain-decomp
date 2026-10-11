#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct P_A580 { char pad[0x1C]; void* data; };
extern "C" {
extern void* D_004EE620;
extern unsigned char D_004EE628;
extern unsigned char D_005723C8;
extern char D_0049C800[];
void Mem_Free(int pool, void* p, char* file, int line);
int func_002EB650(P_A580** out);
}
#pragma define_section REENT_DTOR ".dtors_drop" far_absolute RX
struct Reent_A580 { Reent_A580() { if (!D_005723C8) D_005723C8 = 1; } __declspec(weak) __declspec(REENT_DTOR) ~Reent_A580() { D_005723C8 = 0; } };
extern "C" void func_0016A580(void)
{
    Reent_A580 r;
    {
        P_A580* p;
        if (!func_002EB650(&p)) {
            void* old = D_004EE620;
            void* nv = p->data;
            if (old && !D_004EE628) {
                AllocGuard g;
                Mem_Free(0, old, D_0049C800, 0x1FE);
            }
            D_004EE620 = nv;
            D_004EE628 = 1;
        }
    }
}