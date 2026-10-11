typedef struct { int x; } A;
typedef struct { char p[0x18]; int f18; char p2[0x848 - 0x1C]; int f848; } B;
extern unsigned int func_002F3220(B *);
extern int func_003138C0(int, int *, char *, int);
extern int func_002D9EC8(A *, B *, int, char *, int);
extern int func_002D8AD8(A *);
extern int func_002F4180(int, int);
extern int func_002F3228(B *, int);
extern int func_002F3238(B *, int);
int func_002D88C0(A *a, B *b)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    unsigned int flags = func_002F3220(b);
    if (flags & 0x2000) {
        int sum = 0;
        from[0] = 0;
        do {
            n = func_003138C0(b->f848, from, buf, 0x800);
            sum += n;
            if (sum == 0 || n != 0) total += func_002D9EC8(a, b, from[0], buf, n);
        } while (n != 0);
        if (!(flags & 0x4000)) {
            func_002F4180(func_002D8AD8(a), b->f848);
            b->f848 = 0;
            func_002F3228(b, 0x1000);
        }
        func_002F3238(b, 0x2000);
    } else if (flags & 0x1000) func_002D9EC8(a, b, b->f18, buf, 0);
    return total;
}


