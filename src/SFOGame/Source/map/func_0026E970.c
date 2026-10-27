#pragma cplusplus on
/* Batch flush of per-object keys into the global batcher D_00542DC0 (count/size live at +0x7D0/+0x7D4). */
#include "types.h"

class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual int get(); };
struct Item { char pad[0x38]; int a; float b; };
struct Batch {
    int key[125];
    int flag[125];
    int out[125];
    float val[125];
    int count;
    unsigned int size;
    int x;
};
struct Vec { int unk0; int count; Obj** data; };

extern "C" {
extern Batch D_00542DC0;
Item** std_vector_cVUM_GOBJPtr_opIndex_uint_2(Vec* v, int i);
void cBBoxMan_StartVisibilityTest(Batch* b);
void cBBoxMan_EndVisibilityTest(Batch* b);
}

#pragma opt_strength_reduction off
extern "C" void ProcessVisibility(Vec* v) {
    int first;
    int last;
    int i;
    int k;

    if (v->count != 0) {
        D_00542DC0.count = 0;
        first = 0;
        last = 0;
        D_00542DC0.size = 5;
        i = 0;
        /* retail places the loop entry test out of line after the body */
        goto guard;
    body:
        {
            int r = v->data[i]->get();
            D_00542DC0.key[D_00542DC0.count] = r;
            D_00542DC0.flag[D_00542DC0.count] = 0;
            D_00542DC0.count++;
            D_00542DC0.size += 2;
            if (D_00542DC0.size > 0xF9) {
                cBBoxMan_StartVisibilityTest(&D_00542DC0);
                cBBoxMan_EndVisibilityTest(&D_00542DC0);
                for (k = 0; first < last; first++, k++) {
                    int o = D_00542DC0.out[k];
                (*std_vector_cVUM_GOBJPtr_opIndex_uint_2(v, first))->a = o;
                    (*std_vector_cVUM_GOBJPtr_opIndex_uint_2(v, first))->b = D_00542DC0.val[k];
                }
                D_00542DC0.count = 0;
                first = last;
                D_00542DC0.size = 5;
            }
            last = i;
            i++;
        }
    cond:
        if (i < v->count) goto body;
    post:
        if (first <= last) {
            cBBoxMan_StartVisibilityTest(&D_00542DC0);
            cBBoxMan_EndVisibilityTest(&D_00542DC0);
            for (k = 0; last >= first; first++, k++) {
                int o = D_00542DC0.out[k];
                (*std_vector_cVUM_GOBJPtr_opIndex_uint_2(v, first))->a = o;
                (*std_vector_cVUM_GOBJPtr_opIndex_uint_2(v, first))->b = D_00542DC0.val[k];
            }
        }
        return;
    guard:
        if (0 < v->count) goto cond;
        goto post;
    }
}


