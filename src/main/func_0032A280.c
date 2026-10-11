typedef struct { char d[0x20]; } E2A280;
typedef struct { int first; int count; E2A280* buf; } V2A280;
extern void func_003283F0(E2A280* e, int flag);
void func_0032A280(V2A280* v)
{
    E2A280* b = v->buf;
    E2A280* e = b + v->count;
    while (b < e) {
        --e;
        func_003283F0(e, -1);
    }
    v->count = 0;
}