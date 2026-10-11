typedef struct { int a; int h; int b, c, d, e, f; } E2BBF98;
typedef struct { int a, b; } O2BBF98;
typedef struct { int a, b, n; O2BBF98 v; } R2BBF98;
extern E2BBF98 D_00518A08[];
extern char D_0051AAC0[], D_00518A40[];
extern int D_0048C09C;
extern int func_0026A8C8(int);
extern void *memset(void *, int, unsigned int);
extern int sceDbcSendData3(int, int, void *, void *, void *);
extern void func_002BB660();
extern R2BBF98 *func_002BB520(int);
int func_002BBF98(int idx, O2BBF98 *out)
{
    int cmd[4];
    R2BBF98 *r;
    if (func_0026A8C8(D_00518A08[idx].h) == 3) return 0;
    cmd[0] = 0x2080;
    memset(D_0051AAC0, 0, 0x100);
    D_0048C09C = 10;
    while (sceDbcSendData3(D_00518A08[idx].h, D_0048C09C, cmd, D_00518A40, func_002BB660) != 1);
    r = func_002BB520(D_00518A08[idx].h);
    if (r->n == 0) return 0;
    *out = r->v;
    return r->n;
}