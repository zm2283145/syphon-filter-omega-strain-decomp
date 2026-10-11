#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#include "v4_asm_copy.h"
struct N_3CD420 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0x40 - 4];
    V4 pos;
    unsigned char dirty;
};
struct X_3CD420 { char pad[0x50]; N_3CD420* n; };
#pragma push
#pragma opt_common_subs off
extern "C" void func_003CD090(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop

