#include "types.h"

typedef struct Phase {
    float lo;
    float hi;
} Phase;

int Phase_Overlaps(const Phase* a, const Phase* b) {
    float alo = a->lo;
    float ahi = a->hi;
    if (!(ahi < alo) && !(b->hi < b->lo)) {
        return alo <= b->hi && ahi > b->lo;
    }
    if (ahi < alo && !(b->hi < b->lo)) {
        float bhi = b->hi;
        float blo = b->lo;
        return (alo - 1.0f <= bhi && ahi > blo) || (alo <= bhi && 1.0f + ahi > blo);
    }
    if (!(ahi < alo) && b->hi < b->lo) {
        float bhi = b->hi;
        float blo = b->lo;
        return (alo <= bhi && ahi > blo - 1.0f) || (alo <= 1.0f + bhi && ahi > blo);
    }
    return alo <= 1.0f + b->hi && 1.0f + ahi > b->lo;
}

