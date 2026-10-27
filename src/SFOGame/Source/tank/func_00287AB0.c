#pragma cplusplus on
#include "types.h"
struct S376FF0;
struct ModelAB0 { char pad[0x68]; int* list; };
class ObjAB0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual ModelAB0* GetModel();
};
struct TgtAB0 { char pad[0x14]; float x; float y; };
struct EntAB0 { TgtAB0* p; float x; float y; };
struct SelfAB0 { ObjAB0* obj; void* own; EntAB0 e[2]; int n; float last; unsigned char on; };
extern "C" int cVU1Model_GetAnimTextures(int* o, void** out, int max);
static inline float SignAB0(float v) {
    if (v < -0.1f) return -1.0f;
    else if (v > 0.1f) return 1.0f;
    else return 0.0f;
}
extern "C" unsigned char cTread_ctor(SelfAB0* s)
{
    int* list = s->obj->GetModel()->list;
    int has = *list != 0;
    if (has) {
        if (!s->on) {
            void* buf[2];
            int i;
            s->n = cVU1Model_GetAnimTextures(list, buf, 2);
            s->on = 1;
            for (i = 0; i < s->n; i++) {
                EntAB0* e;
                float x, y;
                e = &s->e[i];
                e->p = (TgtAB0*)buf[i];
                x = e->p->x;
                y = e->p->y;
                e->x = SignAB0(-x);
                e->y = SignAB0(y);
            }
        }
    } else {
        s->on = 0;
    }
    return s->on;
}



