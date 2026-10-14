typedef struct { char pad[0x34]; int v; } Inner;
typedef struct { int a, b; Inner *in; } Node;
typedef struct { int a; Node *head; } List;
extern void func_002F33E0(List *, int);void func_002F3450(List *l) { while (l->head) func_002F33E0(l, l->head->in->v); }