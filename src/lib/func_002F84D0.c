typedef struct { char b[0x40]; } B2F84D0;
typedef struct { int a, b; int key; B2F84D0 *data; } E2F84D0;
extern void *func_002F7D68(int);
extern E2F84D0 *func_002F7ED8(void *, int);
extern int func_002F7CE8(B2F84D0 *);
extern void *memset(void *, int, unsigned int);
extern E2F84D0 *func_002F7DB8(void);
extern void func_002F7EA0(void *, E2F84D0 *);
extern void func_002FB2D8(void *, int);
int func_002F84D0(int id, int key, B2F84D0 *src)
{
    void *p;
    E2F84D0 *e;
    p = func_002F7D68(id);
    if (p == 0) return -1;
    e = func_002F7ED8(p, key);
    if (func_002F7CE8(src)) {
        if (e != 0) { if (e->data) memset(e->data, 0, 0x40); }
    } else {
        if (e == 0) {
            e = func_002F7DB8();
            e->key = key;
            func_002F7EA0(p, e);
        }
        if (e->data == 0) func_002FB2D8(&e->data, 0x40);
        *e->data = *src;
    }
    return 0;
}