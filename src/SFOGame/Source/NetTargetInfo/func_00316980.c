#pragma cplusplus on
#include "types.h"
struct V316980 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual unsigned char v32(); };
struct T316980 { V316980 v; char pad[0x40]; int x48; char pad4C[0x1E0 - 0x48]; int x1E0; };
struct S316980 { char pad[0x58]; T316980* p58; };
extern "C" void cTargetInfo_Creation(int val, S316980* s)
{
    if (s->p58) {
        unsigned char t = s->p58->v.v32();
        switch (t) {
        case 2:
            s->p58->x1E0 = val;
            break;
        case 4:
            s->p58->x48 = val;
            break;
        }
    }
}