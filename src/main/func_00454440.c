#include "types.h"
#include "sound_event.h"
typedef struct { unsigned char flag; char pad1[0x10]; char name[0x10]; } Item_454440;
typedef struct { int pad0; int count; Item_454440* items; } List_454440;
typedef struct { char pad[0x94]; int count; } Box_454440;
typedef struct { char pad[0x48]; Box_454440* box; void* f4C; char f50[4]; } S_454440;
extern List_454440* D_004FFC2C;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern void String_Copy(char*, char*);
extern void func_00459450(void*);
extern void func_004546C0(S_454440*, char*);
extern void func_004214C0(Box_454440*, int, int);
extern int func_0041EF10(S_454440*, void*, unsigned short, int, int);

#pragma push
#pragma opt_propagation off
int func_00454440(S_454440* self, void* ev, unsigned short code, int a3, int idx)
{
    char buf[0x10];
    SoundEvent msg;

    if (code == 0x14) {
        SoundEvent_Ctor(&msg, self->f50, 0);
        msg.kind = 1;
        Event_Send(&msg, D_004FFB50, 1);
        if (self->f4C)
            func_00459450(self->f4C);
        msg.vtable = D_004DADF0;
        FileMan_Release(&msg.req.b, -1);
        FileMan_Release(&msg.req.a, -1);
        cMessage_dtor(&msg, 0);
        return 1;
    }
    if (code == 0x13) {
        List_454440* l = D_004FFC2C;
        buf[0] = 0;
        if (l && idx < l->count) {
            String_Copy(buf, l->items[idx].name);
            l->items[idx].flag = 1;
        }
        func_004546C0(self, buf);
        if (self->box && idx < self->box->count)
            func_004214C0(self->box, idx, 1);
        return 1;
    }
    return func_0041EF10(self, ev, code, a3, idx);
}
#pragma pop

