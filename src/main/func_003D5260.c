#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x51]; unsigned char b51; unsigned char b52; } F6Info;
struct F6Act { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual F6Info* GetInfo(); char pad[0x34]; int x38; char pad2[0x14]; int x50; };
typedef struct { F6Act* actor; int x4; int arg; char pad[0x124]; } F6Ent;
typedef struct { int x0; int max; char pad[8]; F6Ent ents[219]; char pad2[0xB0]; int count; } F6Sys;
extern "C" int D_005392D0;
extern "C" void func_003D5260(F6Sys* s, F6Act* a, int arg)
{
    if (D_005392D0 & 0x60) {
        if (s->count < s->max && a->x38 != 0x80 && a->x50) {
            F6Info* p = a->GetInfo();
            if (p && (p->b52 || p->b51)) {
                F6Ent* e = &s->ents[s->count];
                e->actor = a;
                e->x4 = 0;
                e->arg = arg;
                s->count++;
            }
        }
    }
}