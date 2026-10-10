#pragma cplusplus on
#include "types.h"
struct BitsD8D0 {
    int w[1];
    BitsD8D0() {}
    BitsD8D0(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; }
    BitsD8D0& operator=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
    BitsD8D0& operator&=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] &= o.w[i]; return *this; }
};
extern "C" int func_001ED8D0(BitsD8D0* out, const BitsD8D0& a, const BitsD8D0& b) {
    BitsD8D0 t(a);
    t &= b;
    *out = t;
    return 0;
}