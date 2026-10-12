typedef unsigned int size_t;
typedef struct { int d[0x27]; } BlkA;
typedef struct { int d[0x15]; } BlkB;
typedef struct {
    int pad0;
    int arg;
    BlkA a;
    void (*cb)(void);
    int padA8[3];
    int f8;
    int padB8;
    int fc;
    int padC0[3];
    BlkB b;
    int pad120[4];
} ConnParam;
typedef struct {
    int f0;
    int f4;
    char name[0x10];
    int f18;
    int f1C;
    char f20;
    char pad21[0xF];
    int f30;
    int f34;
    char f38[0x40];
    char f78[0x11];
    char f89;
    char pad8A[0x12];
    BlkB b;
    int fF0;
    int fF4;
    int fF8;
    int fFC;
} ConnSetup;
void *memset(void *, int, size_t);
size_t strlen(const char *);
char *strncpy(char *, const char *, size_t);
int func_002EA5B0(ConnParam *);

void func_0046BA68(ConnSetup *o, const char *s1, const char *s2, int a3, int a4)
{
    ConnParam p;
    memset(o, 0, 0x100);
    func_002EA5B0(&p);
    o->b = p.b;
    o->f0 = 1;
    o->f34 = a4;
    if (s1)
        strncpy(o->f78, s1, strlen(s1) + 1);
    else
        o->f78[0] = 0;
    o->fF0 = 0x100;
    memset(o->f38, 0, 0x40);
    o->f89 = 0;
    o->f4 = 1;
    strncpy(o->name, s2, strlen(s2) + 1);
    o->f18 = a3;
    o->f1C = 0;
    o->f20 = 0;
    o->f30 = 0;
    o->fF4 = 0;
    o->fF8 = 0;
    o->fFC = 0;
}

