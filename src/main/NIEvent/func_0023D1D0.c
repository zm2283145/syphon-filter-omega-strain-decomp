#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#include "q4r.h"
#include "vc_copy.h"

/* Rebuilds the cached transform: row 3 takes the position, rows 0-2 are left as they were on the stack. */

typedef struct Q16 { __int128 q; } Q16;
typedef struct M64 { __int128 r[3]; Q16 t; } M64;

class Obj {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void Update(); /* 0x120 */
    virtual void v47(); virtual void v48();
    virtual unsigned char TestA(float dt); /* 0x12C */
    virtual unsigned char TestB(float dt); /* 0x130 */

    char pad04[0x5C];
    int state;          /* 0x60 */
    char pad64[0x7C];
    Q16 pos;            /* 0xE0 */
    M64 mtx;            /* 0xF0 */
};

extern "C" void NiEventLight_Step(Obj* self, float dt)
{
    unsigned char a = self->TestA(dt);
    unsigned char b = self->TestB(dt);
    if (a || b) {
        if (self->state != 3) {
            M64 m; __int128 t; __int128 qa; M64* d; M64* s; __int128 qb; Q16* pt;
            pt = &m.t; t = VLoadF(&self->pos); s = &m; d = &self->mtx; VStoreN(pt, t);
            Q4COPY_N(d, s, qa, qb)
        }
        self->Update();
    }
}




