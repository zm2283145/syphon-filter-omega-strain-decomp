typedef struct { char d[0x2C]; } E2AB90;
typedef struct { int first; int count; E2AB90* buf; } V2AB90;
extern void func_003282A0(E2AB90* e, int flag);
void func_0032AB90(V2AB90* v)
{
    E2AB90* b = v->buf;
    E2AB90* e = b + v->count;
    while (b < e) {
        --e;
        func_003282A0(e, -1);
    }
    v->count = 0;
}