#include "types.h"
typedef struct { int a; int n; } T450A90;
extern int* func_0044F290(T450A90* t, int i);
int* func_00450A90(T450A90* t, int id) {
    int n;
    int i;
    if (!t || !(n = t->n)) return 0;
    for (i = 0; i < n; i++) {
        int* e = func_0044F290(t, i);
        if (id == *e) return e;
    }
    return 0;
}