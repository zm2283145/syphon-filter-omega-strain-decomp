typedef struct { char b[0x40]; } B2F8C50;
typedef struct { int a, b; int key; int c; void *h10; void *h14; B2F8C50 *h18; } E2F8C50;
extern void *GetKeyMaster(int);
extern int IsNullRCKey(B2F8C50 *);
extern E2F8C50 *GetKeyChain(void *, int);
extern E2F8C50 *NewKeyChain(void);
extern void AppendKeyChain(void *, E2F8C50 *);
extern void func_002FB2D8(void *, int);
extern void RCInitialize(void *, B2F8C50 *);
int KM_AddSymmetricKey(int id, int key, B2F8C50 *src)
{
    void *p;
    E2F8C50 *e;
    p = GetKeyMaster(id);
    if (p == 0) return -1;
    if (IsNullRCKey(src)) return -1;
    e = GetKeyChain(p, key);
    if (e == 0) {
        e = NewKeyChain();
        e->key = key;
        AppendKeyChain(p, e);
    }
    if (e->h18 == 0) func_002FB2D8(&e->h18, 0x40);
    if (e->h10 == 0) func_002FB2D8(&e->h10, 0x10C);
    if (e->h14 == 0) func_002FB2D8(&e->h14, 0x10C);
    *e->h18 = *src;
    RCInitialize(e->h10, src);
    RCInitialize(e->h14, src);
    return 0;
}