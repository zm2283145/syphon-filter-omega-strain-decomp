#include "types.h"
typedef struct { int cap; int count; void** data; } C5PtrVec;
#pragma opt_lifetimes off
static inline void** C5Copy(void** s, void** e, void** d) {
    while (s < e) *d++ = *s++;
    return d;
}
void** PtrVector_Erase(C5PtrVec* v, void** first, void** last) {
    void** end;
    int n;
    if (first == last) return first;
    end = v->data + v->count;
    n = end - last;
    if (n != 0) C5Copy(last, end, first);
    v->count -= last - first;
    return first;
}