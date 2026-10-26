typedef struct { char pad[0x34]; int v; } Inner;
typedef struct { int a, b; Inner *in; } Node;
typedef struct { int a; Node *head; } List;
extern void RemoveRefFromSet(List *, int);void CleanupPlayerSet(List *l) { while (l->head) RemoveRefFromSet(l, l->head->in->v); }