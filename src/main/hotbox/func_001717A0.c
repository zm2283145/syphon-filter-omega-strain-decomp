#include "types.h"
#pragma cplusplus on
typedef struct TZEvt { char pad[0x24]; unsigned char kind; char pad2[0xB]; int arg; } TZEvt;
class TZ { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
 virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
 virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void f(int a); };
extern "C" int* Event_GetType(TZEvt* e);
extern "C" int D_004EE698;
extern "C" void func_00172400(TZ* self, int a);
extern "C" void func_00171ED0(TZ* self, int a);
extern "C" unsigned char TriggerZone_HandleEvent(TZ* self, TZEvt* e) {
    unsigned char r;
    int t = *Event_GetType(e);
    if (t == D_004EE698) {
        switch (e->kind) {
        case 0: func_00172400(self, e->arg); break;
        case 1: break;
        case 2: func_00171ED0(self, e->arg); break;
        case 3: self->f(e->arg); break;
        }
        r = 1;
    } else r = 0;
    return r;
}