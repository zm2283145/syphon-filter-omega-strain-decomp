typedef enum { TyEnum_0 } TyEnum;
typedef struct { TyEnum a, b, c, d, e; } Msg;
typedef struct { char pad[0x438]; int f438; } T;
extern void (*D_0048C470)(Msg *);
extern int D_0048C474;
extern int func_002E51B8(unsigned int, T **);
extern int func_002E4CA8(int);
extern void *memset(void *, int, unsigned int);
void func_002E6178(int code)
{
    Msg m;
    unsigned int p[1];
    p[0] = 0;
    if (func_002E51B8(0, (T **)p)) return;
    if (p[0] == 0) return;
    func_002E4CA8(0);
    if (D_0048C470 == 0) return;
    memset(&m, 0, sizeof(m));
    m.b = ((T *)p[0])->f438;
    m.a = 0;
    m.c = 1;
    if (code == 0xB) m.d = 0xE; else m.d = 0x25;
    m.e = D_0048C474;
    D_0048C470(&m);
}


