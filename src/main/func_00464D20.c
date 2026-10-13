#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
typedef struct { int prev; int next; void* obj; } N_464D20;
typedef struct { int n; N_464D20* head; } L_464D20;
typedef struct { char pad[0x28]; L_464D20 l; } M_464D20;
typedef struct { char pad[0x6A4]; void* f6A4; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } G_464D20;
typedef struct { char pad[0x178]; int f178; } P_464D20;
typedef struct { char pad[0x6C]; unsigned char b6C; unsigned char b6D; char pad6E[2]; int f70; void* f74; } O_464D20;
extern void* D_00582CF0;
extern unsigned char D_00582B88;
unsigned int D_00497BF0[2] = { 0xFFFFFFFF, 0x0 };
extern unsigned char D_004FFC29;
extern void* D_004FFC04;
extern G_464D20* D_004FFC2C;
extern P_464D20* D_004FFC0C;
int func_00437600(void* p);
int func_004651F0(void);
void func_00437950(int v);
int func_0042B1A0(int v);
int func_002CAB70(void* p);
int func_0045BD00(void* p);
void func_00242740(G_464D20* g);
M_464D20* Gui_GetScreenStack(void);
void func_00465870(O_464D20* o, float dt);

static inline int IsMine_464D20(void)
{
    void* p = D_00582CF0;
    if (p) {
        return func_00437600(p) == NetLocalId();
    }
    return 0;
}

void func_00464D20(O_464D20* o, float dt)
{
    if (D_005721C8) {
        if (o->b6C) {
            unsigned char act = func_004651F0();
            if (!D_00582B88 || !act) {
                if (IsMine_464D20()) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                    act = 0;
                    o->b6C = 0;
                    o->f70 = 0;
                    o->b6D = 0;
                }
            }
            if (act) {
                if (!o->b6D) {
                    o->b6D = 1;
                    o->f70 = func_0042B1A0(1) + 200;
                } else if (D_00582B88 && o->f70 < func_0042B1A0(1)) {
                    if (D_005721C8) {
                        func_00437950(1);
                    } else {
                        o->f70 = 0;
                        o->b6D = 0;
                    }
                }
            }
        } else {
            if (o->b6D) {
                if (!func_004651F0() || o->f70 < func_0042B1A0(1)) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                } else if (!D_004FFC29 && !func_002CAB70(D_004FFC04) && !D_004FFC2C->b6A9 && !D_004FFC2C->b6A8
                           && !D_004FFC2C->b6AA && !func_0045BD00(D_004FFC2C->f6A4) && !D_004FFC0C->f178) {
                    func_00242740(D_004FFC2C);
                }
            }
            o->f70 = 0;
            o->b6D = 0;
        }
        if (IsMine_464D20()) {
            int t = (*(int*)D_00497BF0);
            if (t > -1) {
                if (t < func_0042B1A0(1)) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                    o->b6C = 0;
                }
            } else {
                (*(int*)D_00497BF0) = func_0042B1A0(1) + 15000;
            }
        } else {
            (*(int*)D_00497BF0) = -1;
        }
        {
            M_464D20* m = Gui_GetScreenStack();
            L_464D20* l = &m->l;
            if (l->n) o->f74 = l->head->obj;
        }
    }
    func_00465870(o, dt);
}