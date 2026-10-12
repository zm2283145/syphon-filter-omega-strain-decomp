typedef struct { int x0, x4, x8, xC, x10; char x14; char pad[0x1B]; } SockP;
typedef struct { int used; int sock; char pad[0x14]; } SBB7C8;
extern SBB7C8 D_00518A08[];
extern char D_0051AAC0[];
extern int func_002BB788(void);
extern void *memset(void *, int, unsigned int);
extern int sceDbcCreateSocket(SockP *, char *, char *);
int func_002BB7C8(SockP *in)
{
    SockP s;
    int i;
    int r;
    i = func_002BB788();
    if (i < 0) return -1;
    s.x0 = in->x0;
    s.x8 = in->x8;
    s.xC = in->xC;
    s.x10 = in->x10;
    s.x0 |= 1;
    s.x4 = 2;
    s.x14 = 0;
    memset(D_0051AAC0, 0, 0x100);
    r = sceDbcCreateSocket(&s, D_0051AAC0, D_0051AAC0 + 0x80);
    D_00518A08[i].sock = r;
    if (r < 0) return -1;
    D_00518A08[i].used = 1;
    return i;
}





