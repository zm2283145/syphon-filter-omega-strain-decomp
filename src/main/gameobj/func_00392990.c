#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma opt_common_subs off

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { *(__int128*)this = *(const __int128*)&o; }
    V4& operator=(const V4& o) { *(__int128*)this = *(const __int128*)&o; return *this; }
} __attribute__((aligned(16)));

struct ActorModel {
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
    virtual V4 GetPos();
};
struct ActorModelData {
    void* vt;
    char pad04[0x34];
    int lod;              /* 0x38 */
    char pad3C[0x24];
    char part60[0x2DF0];  /* 0x60 */
    char part2E50[4];     /* 0x2E50 */
};

extern "C" V4 D_00535D40;
extern "C" unsigned char D_00535D60;
extern "C" unsigned char D_00535D61;
extern "C" int D_0053B350;
extern "C" void Skm_Draw(void* a, void* b, int c, int d, int e, int f);

static inline int Vec4_Equal_(V4* a, V4* b) {
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}

static inline bool Neq(V4* a, V4* b) { return !Vec4_Equal_(a, b); }
extern "C" void ActorModel_Draw(ActorModel* self) {
    ActorModelData* d = (ActorModelData*)self;
    V4 pos = self->GetPos();
    if (Neq(&D_00535D40, &pos)) {
        V4* dst = &D_00535D40;
        V4* s = &pos;
        asm { .set reorder }  /* scheduling barrier: lets the lui fill the branch delay slot */
        *(__int128*)dst = *(__int128*)s;
        D_00535D60 = 1;
        D_00535D61 = 1;
    }
    if (D_0053B350 != 0) {
        Skm_Draw(d->part60, d->part2E50, d->lod, 0, 0, 1);
    } else {
        Skm_Draw(d->part60, d->part2E50, d->lod, 0, 0, 0);
    }
}












