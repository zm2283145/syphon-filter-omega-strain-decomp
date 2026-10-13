#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct {
    int f0;
    char name[0x10];
    int port;
    char pad[0x18];
} Info;
typedef struct {
    int f0;
    int f4;
    Info d;
} G;
typedef struct {
    char name[0x10];
    unsigned short port;
} Q;
extern Info D_00588070;
extern G D_00520300;
extern void (*D_00520338)(G *);
extern char *strncpy(char *, const char *, unsigned int);
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, Q **);

void func_002E6298(const char *name, unsigned short port, int err)
{
    void *p = 0;
    Q *q = 0;

    if (err == 0) {
        D_00588070.port = port;
        strncpy(D_00588070.name, name, 0x10);
        if (func_002E51B8(0, &p) == 0 && p && func_002E52D8(0, F(p, unsigned int, 0x400), &q) == 0 && q) {
            strncpy(q->name, name, 0x10);
            q->port = port;
        }
    }
    D_00520300.f0 = 1;
    D_00520300.f4 = err ? 0x25 : 0;
    D_00520300.d = D_00588070;
    D_00520338(&D_00520300);
}
