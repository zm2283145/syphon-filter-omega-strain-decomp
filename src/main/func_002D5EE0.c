#include "types.h"
typedef struct { char pad[0x14]; unsigned char b14; } C2D5EE0;
typedef struct { char pad[0x30]; C2D5EE0* x30; } M2D5EE0;
typedef struct { char pad[0x58]; M2D5EE0* x58; } A2D5EE0;
typedef struct { char pad[0xC]; unsigned short hC; } D2D5EE0;
typedef struct { char pad[0x30]; D2D5EE0* x30; char pad34[0x150 - 0x34]; unsigned short id; } S2D5EE0;
typedef struct { char pad[0x30]; char x30[4]; } X2D5EE0;
typedef struct { char* p; int n; } B2D5EE0;
extern A2D5EE0* cNPC_Human(S2D5EE0* s, X2D5EE0* x);
extern void cNPC_RemoveFromActiveList(D2D5EE0* d);
extern char* nGobjManager_LookupGOBJ_cObjectIdR(unsigned short* id);
extern void cHuman_CreateGobjController(A2D5EE0* a, int n, B2D5EE0* b, int c);
extern void func_00148CD0(M2D5EE0* m, void* p);
void cNetNPC_ConvertToNpc(S2D5EE0* s, X2D5EE0* x)
{
    A2D5EE0* a = cNPC_Human(s, x);
    cNPC_RemoveFromActiveList(s->x30);
    if (s->id) {
        B2D5EE0 b;
        char* o = nGobjManager_LookupGOBJ_cObjectIdR(&s->id);
        b.n = s->x30->hC - 1;
        b.p = o + 0xC;
        cHuman_CreateGobjController(a, 2, &b, 0);
    } else {
        cHuman_CreateGobjController(a, 2, 0, 0);
    }
    {
        M2D5EE0* m = a->x58;
        m->x30->b14 = 1;
        func_00148CD0(m, x);
    }
}