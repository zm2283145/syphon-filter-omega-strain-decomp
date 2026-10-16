#include "types.h"
typedef struct { char pad[0x14]; unsigned char b14; } C2D5EE0;
typedef struct { char pad[0x30]; C2D5EE0* x30; } M2D5EE0;
typedef struct { char pad[0x58]; M2D5EE0* x58; } A2D5EE0;
typedef struct { char pad[0xC]; unsigned short hC; } D2D5EE0;
typedef struct { char pad[0x30]; D2D5EE0* x30; char pad34[0x150 - 0x34]; unsigned short id; } S2D5EE0;
typedef struct { char pad[0x30]; char x30[4]; } X2D5EE0;
typedef struct { char* p; int n; } B2D5EE0;
extern A2D5EE0* AiController_GetActor(S2D5EE0* s, X2D5EE0* x);
extern void NpcThinkList_RemoveActor(D2D5EE0* d);
extern char* Object_LookupById(unsigned short* id);
extern void Actor_InitComponents(A2D5EE0* a, int n, B2D5EE0* b, int c);
extern void func_00148CD0(M2D5EE0* m, void* p);
void func_002D5EE0(S2D5EE0* s, X2D5EE0* x)
{
    A2D5EE0* a = AiController_GetActor(s, x);
    NpcThinkList_RemoveActor(s->x30);
    if (s->id) {
        B2D5EE0 b;
        char* o = Object_LookupById(&s->id);
        b.n = s->x30->hC - 1;
        b.p = o + 0xC;
        Actor_InitComponents(a, 2, &b, 0);
    } else {
        Actor_InitComponents(a, 2, 0, 0);
    }
    {
        M2D5EE0* m = a->x58;
        m->x30->b14 = 1;
        func_00148CD0(m, x);
    }
}