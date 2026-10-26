/*
 * lib/medius: 5 files, 002DB140-002DB320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DB140 */
extern void *memset(void *, int, unsigned int);
extern char *Rt_MemoryAllocate(int);
extern char *D_0051F0D0;
unsigned int D_0048C440[2] = { 0x0, 0x0 };
void NetInitializeClients(void)
{
    char **pp = &D_0051F0D0;
    *pp = Rt_MemoryAllocate(0x400);
    (*(char*)D_0048C440) = 0;
    memset(*pp, 0, 0x400);
}
/* merge_units: end func_002DB140 */

/* merge_units: begin func_002DB188 */
extern int D_0048C450;
#if 0 /* merge_units */
extern int *D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(int **)&D_0051F0D0) /* merge_units */

int NetIGetClient(int *out, unsigned int a, unsigned int i)
{
    if (out == 0) return 0x17;
    *out = 0;
    if (i >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    if (a != D_0048C450) return 0;
    if (D_0051F0D0 != 0) {
        *out = D_0051F0D0[i];
        return 0;
    }
    return 0x15;
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB188 */

/* merge_units: begin func_002DB1F0 */
extern int NetGetClientInfo(unsigned int, unsigned int, int *);
int NetIGetClientStatus(int *out, unsigned int a, unsigned int i)
{
    int t;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (i < 0x100 && a < 4) {
        t = 0;
        r = NetGetClientInfo(a, i, &t);
        if (t != 0 && r == 0) *out = ((int *)t)[5];
        return 0;
    }
    return 8;
}
/* merge_units: end func_002DB1F0 */

/* merge_units: begin func_002DB270 */
typedef struct Ent {
    int f0;
    short f4, f6, f8, fA, fC;
    char fE;
} Ent;
#if 0 /* merge_units */
extern Ent **D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(Ent * **)&D_0051F0D0) /* merge_units */

extern int NetIsValidClientIndex(unsigned int);
#if 0 /* merge_units */
extern Ent *Rt_MemoryAllocate(int);
#endif /* merge_units */
#define Rt_MemoryAllocate(a0) ((Ent *)Rt_MemoryAllocate((a0))) /* merge_units */

Ent *NetCreateClient(unsigned int a, unsigned int i)
{
    Ent *p = 0;
    if (NetIsValidClientIndex(i) != 1) return 0;
    if (a < 4) {
        if (i < 0x100) {
            p = Rt_MemoryAllocate(0x1C);
            D_0051F0D0[i] = p;
            p->f0 = 0;
            p->f4 = 0;
            p->f6 = 0;
            p->f8 = 0;
            p->fA = 0;
            p->fC = 0;
            p->fE = 0;
        }
        return p;
    }
    return 0;
}
#undef D_0051F0D0 /* merge_units */
#undef Rt_MemoryAllocate /* merge_units */
/* merge_units: end func_002DB270 */

/* merge_units: begin func_002DB320 */
#if 0 /* merge_units */
extern int *D_0051F0D0;
#endif /* merge_units */
#define D_0051F0D0 (*(int **)&D_0051F0D0) /* merge_units */

extern void DmeFree(int *);
void NetFreeClient(unsigned int a, unsigned int i)
{
    if (NetIsValidClientIndex(i) == 1 && a < 4 && i < 0x100) {
        DmeFree(&D_0051F0D0[i]);
        /* barrier: retail keeps jal + epilogue, no tail call */
        __asm__ __volatile__("");
    }
}
#undef D_0051F0D0 /* merge_units */
/* merge_units: end func_002DB320 */
