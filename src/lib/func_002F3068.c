typedef struct { char b[32]; } Blk2F3068;
typedef struct S2F3068 { struct S2F3068 *a, *b; int c; int d; int pad[4]; Blk2F3068 key; } S2F3068;
extern S2F3068 *func_002F3010(int c);
S2F3068 *func_002F3068(int c, Blk2F3068 *key)
{
    S2F3068 *p = func_002F3010(c);
    if (p) {
        p->key = *key;
        p->d = 0;
    }
    return p;
}
