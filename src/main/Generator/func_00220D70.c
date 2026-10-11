#include "types.h"
typedef struct { void* vtable; char pad04[0x18]; int size; signed char kind; char pad21[3]; int target; } Msg_220D70;
typedef struct { char pad[0xC]; char sub[4]; int id; char pad14[0x18]; unsigned char state; char pad2d[0xCC - 0x2D]; int mask; } G_220D70;
extern unsigned char D_005721C8;
void Event_Construct(Msg_220D70* msg, void* type);
void cMessage_dtor(Msg_220D70* msg, int flags);
extern char D_0055D498[];
extern char D_004E0860[];
void func_003FF650(Msg_220D70* msg, int id, int x);
void func_0043B190(void* t);
void func_0043A030(void* t, void* p);
void cGenerator_v18(G_220D70* g, int bit)
{
    if (D_005721C8) {
        int t[1];
        Msg_220D70 msg;
        if (bit >= 0)
            g->mask &= ~(1 << bit);
        if (g->mask == 0) {
            func_0043B190(t);
            func_0043A030(t, g->sub);
            g->state = 0;
        }
        Event_Construct(&msg, D_0055D498);
        msg.target = bit;
        msg.vtable = D_004E0860;
        msg.size = 0x40;
        msg.kind = 4;
        func_003FF650(&msg, g->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    } else {
        g->state = 0;
    }
}