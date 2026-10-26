/* same-unit callee stubs: weak, in a section the link discards (the real functions are defined elsewhere); restore retail delay-slot choices */
typedef struct { int w[67]; } N_002F9000;
typedef struct { int x0; int x4; int x8; void *xC; N_002F9000 *x10; N_002F9000 *x14; unsigned char *x18; } S_002F9000;
extern int GetKeyMaster(int);
extern S_002F9000 *GetKeyChain(int, int);
extern S_002F9000 *NewKeyChain(void);
extern void AppendKeyChain(int, S_002F9000 *);
extern int IsNullRSAKey(void *);
int __attribute__((weak, section(".dtors_drop"))) IsNullRCKey(unsigned char *a0) { return 0; }
extern void KM_SetPublicKey(int, int, void *);
void __attribute__((weak, section(".dtors_drop"))) KM_AddSymmetricKey(int a, int b, unsigned char *c) { }
int KM_CopyKeys(int a, int b, int c, int d)
{
    S_002F9000 *s;
    S_002F9000 *t;
    int h;
    h = GetKeyMaster(a);
    if (h == 0) return -1;
    s = GetKeyChain(h, b);
    if (s == 0) return -1;
    h = GetKeyMaster(c);
    if (h == 0) return -1;
    t = GetKeyChain(h, d);
    if (t == 0) {
        t = NewKeyChain();
        t->x8 = d;
        AppendKeyChain(h, t);
    }
    if (IsNullRSAKey(s->xC) == 0) KM_SetPublicKey(c, d, s->xC);
    if (IsNullRCKey(s->x18) == 0) {
        KM_AddSymmetricKey(c, d, s->x18);
        *t->x10 = *s->x10;
        *t->x14 = *s->x14;
    }
    return 0;
}
