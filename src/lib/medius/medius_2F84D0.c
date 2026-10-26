typedef struct { char b[0x40]; } B2F84D0;
typedef struct { int a, b; int key; B2F84D0 *data; } E2F84D0;
extern void *GetKeyMaster(int);
extern E2F84D0 *GetKeyChain(void *, int);
extern int IsNullRSAKey(B2F84D0 *);
extern void *memset(void *, int, unsigned int);
extern E2F84D0 *NewKeyChain(void);
extern void AppendKeyChain(void *, E2F84D0 *);
extern void func_002FB2D8(void *, int);
int KM_SetPublicKey(int id, int key, B2F84D0 *src)
{
    void *p;
    E2F84D0 *e;
    p = GetKeyMaster(id);
    if (p == 0) return -1;
    e = GetKeyChain(p, key);
    if (IsNullRSAKey(src)) {
        if (e != 0) { if (e->data) memset(e->data, 0, 0x40); }
    } else {
        if (e == 0) {
            e = NewKeyChain();
            e->key = key;
            AppendKeyChain(p, e);
        }
        if (e->data == 0) func_002FB2D8(&e->data, 0x40);
        *e->data = *src;
    }
    return 0;
}