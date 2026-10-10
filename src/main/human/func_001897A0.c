#include "types.h"
typedef struct { int top; int bits[1]; } E7PSet;
static inline unsigned char E7Has(E7PSet* s, int n) { return ((s->bits[n / 32] >> (n & 31)) & 1) != 0; }
void AnimPriority_Helper1(E7PSet* s) {
    int i;
    for (i = 31; i >= 0 && !E7Has(s, i); i--) {
    }
    if (!E7Has(s, i)) {
        s->top = -1;
    } else {
        s->top = i;
    }
}