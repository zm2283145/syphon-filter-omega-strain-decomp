#include "types.h"
#pragma cplusplus on
typedef struct { void* vtbl; char pad04[0x18]; int size; char pad20[4]; int id; char pad28[8]; } C1Msg_21A9;
class C1Ch_21A9 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void Reset(int arg);
};
typedef struct { char p0[0x10]; int target; char p14[0x2C - 0x14]; unsigned char flag; char p2d[0x78 - 0x2D]; int n; C1Ch_21A9** ch; } C1Obj_21A9;
extern "C" unsigned char D_005721C8;
extern "C" char D_0055D498[];
extern "C" char D_004E0860[];
extern "C" void Event_Construct(C1Msg_21A9* m, void* type);
extern "C" void func_003FF650(C1Msg_21A9* m, int target, int x);
extern "C" void cMessage_dtor(C1Msg_21A9* m, int flags);
#pragma opt_strength_reduction off
extern "C" void func_0021A940(C1Obj_21A9* o)
{
    int i;
    if (D_005721C8) {
        C1Msg_21A9 msg;
        Event_Construct(&msg, D_0055D498);
        msg.vtbl = D_004E0860;
        msg.id = -1;
        msg.size = 0x40;
        func_003FF650(&msg, o->target, -1);
        msg.vtbl = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
    o->flag = 0;
    for (i = 0; i < o->n; i++)
        o->ch[i]->Reset(-1);
}