#include "types.h"
typedef struct { char pad[0x14]; unsigned char b14; } C2D29C0;
typedef struct { char pad[0x30]; C2D29C0* x30; } M2D29C0;
typedef struct { char pad[0x58]; M2D29C0* x58; } A2D29C0;
typedef struct { char pad[0xC]; unsigned short hC; } D2D29C0;
typedef struct { char pad[0x30]; D2D29C0* x30; char pad34[0x150 - 0x34]; unsigned short id; } S2D29C0;
typedef struct { char pad[0x30]; char x30[4]; } X2D29C0;
typedef struct { char* p; int n; } B2D29C0;
extern A2D29C0* func_00158540(S2D29C0* s, X2D29C0* x);
extern void func_0015AD70(D2D29C0* d);
extern char* Object_LookupById(unsigned short* id);
extern void Actor_InitComponents(A2D29C0* a, int n, B2D29C0* b, int c);
extern void func_00148CD0(M2D29C0* m, void* p);
void func_002D29C0(S2D29C0* s, X2D29C0* x)
{
    A2D29C0* a;
    void* p = x->x30;
    a = func_00158540(s, x);
    func_0015AD70(s->x30);
    if (s->id) {
        B2D29C0 b;
        char* o = Object_LookupById(&s->id);
        b.n = s->x30->hC - 1;
        b.p = o + 0xC;
        Actor_InitComponents(a, 2, &b, 0);
    } else {
        Actor_InitComponents(a, 2, 0, 0);
    }
    {
        M2D29C0* m = a->x58;
        m->x30->b14 = 1;
        func_00148CD0(m, p);
    }
}