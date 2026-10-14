typedef struct { char b[0x40]; } B2F8C50;
typedef struct { int a, b; int key; int c; void *h10; void *h14; B2F8C50 *h18; } E2F8C50;
extern void *func_002F7D68(int);
extern int func_002F7D28(B2F8C50 *);
extern E2F8C50 *func_002F7ED8(void *, int);
extern E2F8C50 *func_002F7DB8(void);
extern void func_002F7EA0(void *, E2F8C50 *);
extern void func_002FB2D8(void *, int);
extern void func_002F3698(void *, B2F8C50 *);
int func_002F8C50(int id, int key, B2F8C50 *src)
{
    void *p;
    E2F8C50 *e;
    p = func_002F7D68(id);
    if (p == 0) return -1;
    if (func_002F7D28(src)) return -1;
    e = func_002F7ED8(p, key);
    if (e == 0) {
        e = func_002F7DB8();
        e->key = key;
        func_002F7EA0(p, e);
    }
    if (e->h18 == 0) func_002FB2D8(&e->h18, 0x40);
    if (e->h10 == 0) func_002FB2D8(&e->h10, 0x10C);
    if (e->h14 == 0) func_002FB2D8(&e->h14, 0x10C);
    *e->h18 = *src;
    func_002F3698(e->h10, src);
    func_002F3698(e->h14, src);
    return 0;
}