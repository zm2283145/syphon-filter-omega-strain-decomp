typedef struct { int value; } Word;
typedef struct Node3D { struct Node3D* prev; struct Node3D* next; int f8; int fC; int f10[3]; int f1C; char pad20[0x10]; float f30; float f34; } Node3D;
typedef struct { int size; Node3D hdr; } List3D;
typedef struct { int pad; Node3D* nodes_unused; Node3D* data; } Vec3D;
typedef struct {
    int f0;
    List3D list;
    char padx[0x10 - 4 - sizeof(List3D) > 0 ? 0x10 - 4 - sizeof(List3D) : 1];
} Dummy;
typedef struct {
    int f0;
    int size;
    Node3D* prev;
    Node3D* next;
    char vec[0xC];
    unsigned char b1C;
} Obj3D;
extern Node3D* func_003D0DC0(void* l);
extern Word* func_003D0DB0(Word* w, void* v);
extern Word* func_003D0DA0(Word* w, void* v);
extern void func_003D0D90(Word* w, void* v);
extern Word* func_003D0D80(Word* d, Word* s);
extern void func_003D0D70(Word* w, void* v);
extern int func_00189540(void* p);
extern void func_0036A330(int a0, int a1, void* a2, float x, float y, float z, float p, float q, float r);
extern void func_003CFAB0(int c);
extern void func_003D10B0(Word* out, int* size, Word* first, Word* last);
static inline int ne3D(Node3D* n, Word* w) { return n != (Node3D*)w->value; }
void func_003D0C10(Obj3D* o)
{
    Word end, end2, b, d, it, e, out, first, last, a, c;
    Word* pe;
    Node3D* n;
    Word* pf;
    Node3D* m;
    if (o->b1C) {
        func_003D0DB0(&it, func_003D0DC0(&o->size)->next);
        n = (Node3D*)it.value;
        func_003D0DA0(&e, func_003D0DC0(&o->size));
        end.value = e.value;
        pe = &end;
        for (; ne3D(n, pe); n = n->next) {
            int* s = (int*)((char*)n + 0x10);
            func_0036A330(s[3], func_00189540(s), s + 4, *(float*)(s + 8), *(float*)(s + 9), 0.001f, 0.0f, 0.0f, 0.0f);
        }
        func_003D0D90(&a, o->vec);
        func_003D0D80(&b, &a);
        m = (Node3D*)b.value;
        func_003D0D70(&c, o->vec);
        func_003D0D80(&d, &c);
        end2.value = d.value;
        pf = &end2;
        for (; ne3D(m, pf); m = m->next)
            func_003CFAB0(m->f8);
    }
    last.value = (int)&o->prev;
    first.value = (int)o->next;
    func_003D10B0(&out, &o->size, &first, &last);
}
