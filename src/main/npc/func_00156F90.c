#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x24]; unsigned char kind; char pad2[3]; int on; } F6Ev;
extern "C" int* Event_GetType(F6Ev*);
extern "C" int D_004EE550;
extern "C" void func_0016E170(void*, int, int);
struct F6Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void SetMode(int m, int t); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void Alert(int a, int t); char pad[0x40]; char x44[4]; };
extern "C" unsigned char func_00156F90(F6Obj* self, F6Ev* e)
{
    unsigned char handled = 0;
    int t = *Event_GetType(e);
    if (t == D_004EE550) {
        unsigned char k = e->kind;
        if (k == 4) {
            if (e->on) {
                func_0016E170(self->x44, 1, 0);
            }
            handled = 1;
        } else if (k == 7) {
            func_0016E170(self->x44, 1, 0);
            self->Alert(1, 20);
        } else if (k == 0) {
            self->SetMode(0, 10);
            handled = 1;
        } else if (k == 1) {
            self->SetMode(1, 10);
            handled = 1;
        }
    }
    return handled;
}