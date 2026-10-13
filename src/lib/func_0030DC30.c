typedef struct {
    char pad0[0xC];
    int state;
    char pad10[0x2033 - 0x10];
    unsigned char started;
} St;
typedef struct {
    char pad0[0x58];
    St *st;
} Obj;
void func_0030DC30(Obj *o, int a1, int a2, int a3)
{
    if (o == 0) return;
    if (a1 == 0 && a3 == 2) {
        o->st->state = 5;
        return;
    }
    if (o->st->started == 0) {
        o->st->started = 1;
        o->st->state = 3;
        return;
    }
    o->st->state = 8;
}
