#pragma cplusplus on
#include "types.h"
struct V2C4EA0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual unsigned char v32(); };
struct T2C4EA0 { V2C4EA0 v; char pad[0x44]; int x48; char pad4C[0x1E4 - 0x4C]; int x1E4; };
struct S2C4EA0 { char pad[0x58]; T2C4EA0* p58; };
extern "C" void func_002C4EA0(int val, S2C4EA0* s)
{
    if (s->p58) {
        unsigned char t = s->p58->v.v32();
        switch (t) {
        case 2:
            s->p58->x1E4 = val;
            break;
        case 4:
            s->p58->x48 = val;
            break;
        }
    }
}