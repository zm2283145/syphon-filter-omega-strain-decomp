#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
#pragma opt_dead_code off
typedef struct { int f0; int f4; } P_437640;
extern unsigned char D_005723C8;
extern unsigned char D_00582B88;
extern void* D_00583870;
extern unsigned char D_00582D28;
extern unsigned char D_00582D20;
extern unsigned char D_00583050;
extern void* D_00497548;
extern int D_00582D08;
extern unsigned char D_00583860;
int func_002EB650(P_437640** out, void* s);
void func_002EC460(void* s);
int lgAudStartRecording(void* p);
int lgAudStopRecording(void* p);
int func_0042B1A0(int v);

static inline int Owner_437640(void)
{
    P_437640* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline void Release_437640(void)
{
    int o = Owner_437640();
    if (o == NetLocalId()) {
        func_002EC460(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = func_0042B1A0(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437640(int id, void* sess, int kind)
{
    P_437640* x;
    P_437640* h;
    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(&h, sess) == 0 && kind == -2 && h->f4 == NetLocalId()) {
        if (D_00583860) {
            if (D_00582B88) {
                int r = lgAudStartRecording(D_00497548);
                if (r == 0) D_00583050 = 1;
                else if (r == 0x80000006) D_00582B88 = 0;
            }
            D_00583860 = 0;
            D_00582D20 = 1;
        } else {
            Release_437640();
        }
    }
    if (0) func_002EB650(&x, 0); /* dead under opt_dead_code off: reserves retail's unused 0x2C stack slot */
    D_005723C8 = 0;
}

