typedef struct { char b[0x40]; } B2F8A28;
typedef struct { char p[0x18]; int arg; int a, b; void *h24; void *h28; B2F8A28 *h2C; } T2F8A28;
extern T2F8A28 *GetKeyMaster(int);
extern int IsNullRCKey(B2F8A28 *);
extern void func_002FB2D8(void *, int);
extern void RCInitialize(void *, B2F8A28 *);
int KM_SetGameSessionKey(int id, int arg, B2F8A28 *src)
{
    T2F8A28 *p = GetKeyMaster(id);
    if (p == 0) return -1;
    if (IsNullRCKey(src)) return -1;
    if (p->h2C == 0) func_002FB2D8(&p->h2C, 0x40);
    if (p->h24 == 0) func_002FB2D8(&p->h24, 0x10C);
    if (p->h28 == 0) func_002FB2D8(&p->h28, 0x10C);
    p->arg = arg;
    *p->h2C = *src;
    RCInitialize(p->h24, src);
    RCInitialize(p->h28, src);
    return 0;
}