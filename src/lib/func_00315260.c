typedef struct { int addrB; int addrA; int portB; int portA; } Src5260;
typedef enum { T0, T1, T2 } Ty5260;
typedef struct { Ty5260 typeA; char addrA[0x10]; int portA; Ty5260 typeB; char addrB[0x10]; int portB; } Dst5260;
extern void *memset(void *d, int c, unsigned int n);
extern void func_002F4E20(int a, char *dst);
int func_00315260(Src5260 *s, Dst5260 *d)
{
    if (s == 0) return 0x17;
    if (d == 0) return 0x17;
    memset(d, 0, 0x30);
    d->typeA = 2;
    d->portA = s->portA;
    func_002F4E20(s->addrA, d->addrA);
    d->typeB = 1;
    d->portB = s->portB;
    func_002F4E20(s->addrB, d->addrB);
    return 0;
}
