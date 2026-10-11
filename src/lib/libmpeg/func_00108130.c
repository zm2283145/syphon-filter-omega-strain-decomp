typedef struct { int a; long b; long c; } Pic8130;
extern void func_00108048(void *);
extern unsigned int func_00107ED8(void *, int);
extern void func_0010BF08(void *);
extern void func_001086F0(void *);
extern void func_00108250(void *);
extern void func_0010B488(int, Pic8130 *);

int func_00108130(char *m)
{
    Pic8130 s;
    for (;;) {
        if (*(int *)(m + 0x10A0)) return -1;
        func_00108048(m);
        switch (func_00107ED8(m, 32)) {
        case 0x1B3:
            func_0010BF08(m);
            break;
        case 0x1B8:
            func_001086F0(m);
            break;
        case 0x100:
            func_00108250(m);
            s.a = 5;
            s.b = -1;
            s.c = -1;
            func_0010B488(*(int *)(m + 0x870), &s);
            *(long *)(m + 0x848) = s.c;
            *(long *)(m + 0x840) = s.b;
            return *(int *)(m + 0x168);
        case 0x1B7:
            return 0;
        }
    }
}