typedef struct Node2F39B8 {
    struct Node2F39B8 *next;
    struct Node2F39B8 *prev;
    int f8;
    int data;
} Node2F39B8;
typedef struct {
    int f0;
    int f4;
    int cnt8;
    int cntC;
    Node2F39B8 *h10;
    Node2F39B8 *h14;
    int cnt18;
    int cnt1C;
    int f20;
    Node2F39B8 *h24;
    Node2F39B8 *h28;
    int h2C;
} Obj2F39B8;
extern void func_002DC1F0(int h);
extern void func_00313660(int h);
extern int func_002FB3C0(void *pp);

void func_002F39B8(Obj2F39B8 *o)
{
    Node2F39B8 *a;
    Node2F39B8 *b;

    if (o->h2C) {
        func_002DC1F0(o->h2C);
        o->h2C = 0;
        o->f20 = 0;
    }
    while ((a = o->h14) != 0) {
        a->prev->next = a->next;
        o->cntC--;
        a->next->prev = a->prev;
        o->h14 = o->h14->prev;
        if (o->h14 == a)
            o->h14 = 0;
        func_00313660(a->data);
        func_002FB3C0(&a);
    }
    while ((a = o->h10) != 0) {
        a->prev->next = a->next;
        a->next->prev = a->prev;
        o->cnt8--;
        o->h10 = o->h10->prev;
        if (o->h10 == a)
            o->h10 = 0;
        func_00313660(a->data);
        func_002FB3C0(&a);
    }
    while ((b = o->h28) != 0) {
        b->prev->next = b->next;
        o->cnt1C--;
        b->next->prev = b->prev;
        o->h28 = o->h28->prev;
        if (o->h28 == b)
            o->h28 = 0;
        func_002DC1F0(b->data);
        func_002FB3C0(&b);
    }
    while ((b = o->h24) != 0) {
        b->prev->next = b->next;
        b->next->prev = b->prev;
        o->cnt18--;
        o->h24 = o->h24->prev;
        if (o->h24 == b)
            o->h24 = 0;
        func_002DC1F0(b->data);
        func_002FB3C0(&b);
    }
    func_002FB3C0(&o);
}

