#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
typedef struct { int f0; int f4; } P_437950;
extern unsigned char D_00582B88;
extern void* D_00583870;
extern unsigned char D_00582D28;
extern void* D_00497548;
extern int D_00582D08;
extern unsigned char D_00583860;
void func_002EB650(P_437950** out, void* s);
void func_002EC460(void* s);
int func_00325A28(void* p);
int func_0042B1A0(int v);
int func_002EC3C8(void* s);

static inline int Owner_437950(void)
{
    P_437950* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline int OwnerW_437950(void) { return Owner_437950(); }
static inline void Release_437950(void)
{
    int o = Owner_437950();
    if (o == NetLocalId()) {
        func_002EC460(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (func_00325A28(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = func_0042B1A0(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437950(int on)
{
    if (D_00582B88) {
        if (!on) {
            Release_437950();
        } else if (on) {
            if (D_00582D08 < func_0042B1A0(1)) {
                int o = OwnerW_437950();
                if (o != NetLocalId()) {
                    D_00583860 = 1;
                    if (func_002EC3C8(D_00583870)) D_00583860 = 0;
                }
            }
        }
    } else {
        Release_437950();
    }
}