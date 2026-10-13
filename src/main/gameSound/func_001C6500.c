/* retail keeps the dead skeleton of (t && *t) ? t : D with t propagated to $zero: opt_dead_code off */
#include "types.h"
typedef union { int i; char* s; } ScriptArg_1C63B0;
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; } Msg_1C63B0;
extern unsigned char D_005721C8;
extern void* D_004FFC2C;
extern char D_0049F490[];
extern char D_0051F098[];
extern char D_004DE280[];
extern void func_00241DA0(void* hud, char* a, char* b);
extern void* Loc_LookupText(char* key);
extern void Hud_PostNotification(void* hud, void* text);
extern void Event_Construct(Msg_1C63B0* m, void* type);
extern int Loc_FindKeyThunk(char* s);
extern void Transport_Send(int a, Msg_1C63B0* m, int b, int c);
extern void cMessage_dtor(Msg_1C63B0* m, int f);
/* script: add a PDA quip (name, text) and broadcast it when networked */
#pragma opt_dead_code off
int Script_AddPDAQuip(ScriptArg_1C63B0* args)
{
    char* a[1];
    char* text;
    char* name;
    a[0] = args[0].s;
    name = *(char**)a;
    if (name) {
        { char* t0 = 0; text = (t0 && *t0) ? t0 : D_0049F490; }
        func_00241DA0(D_004FFC2C, name, text);
        {
            void* hud = D_004FFC2C;
            Hud_PostNotification(hud, Loc_LookupText(D_0049F490));
        }
        if (D_005721C8) {
            Msg_1C63B0 m;
            Msg_1C63B0* p = &m;
            Event_Construct(p, D_0051F098);
            m.w24 = 0;
            m.vt = D_004DE280;
            m.b28 = 2;
            p->key0 = name ? Loc_FindKeyThunk(name) : -1;
            p->key1 = text ? Loc_FindKeyThunk(text) : -1;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
    }
    return 0;
}


