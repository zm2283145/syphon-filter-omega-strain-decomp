#pragma cplusplus on
#pragma exceptions off
#include "types.h"
extern "C" {
typedef struct { char pad[0xC]; int id; } Target_286570;
typedef struct { char pad[0xA4]; float f; } Aux_286570;
typedef struct {
    char pad0[0x10];
    float cooldown;
    char pad14[0x40];
    unsigned char busy;
    char pad55[7];
    Target_286570* target;
    int targetId;
    char pad64[4];
    Aux_286570* aux;
} Turret_286570;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char cTurret_Aim(Turret_286570* t, float dt);
extern void cTank_Fire(Turret_286570* t, Target_286570* tgt, unsigned char valid, unsigned char r);
}
struct Obj_286570 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67();
    virtual int Set(int on);
};
struct Own_286570 { Obj_286570* obj; };
static inline bool Null_286570(void* p) { return !p; }
static inline int Flag_286570(void) { return g_IsMultiplayer ? D_005721C0 : 1; }

extern "C" int cTurret_Stop(Own_286570* self)
{
    return self->obj->Set(1);
}

extern "C" void cTurret_NextFrame(Turret_286570* t, float dt)
{
    Target_286570* tgt;
    unsigned char r;
    unsigned char valid;
    if (!(t->cooldown <= 0.0f)) t->cooldown -= dt;
    r = cTurret_Aim(t, dt);
    tgt = t->target;
    valid = 1;
    if (!Null_286570(tgt) && tgt->id != t->targetId) valid = 0;
    tgt = valid ? tgt : 0;
    if (tgt && !t->busy && r && t->cooldown <= 0.0f) {
        if (!g_IsMultiplayer || Flag_286570() || !(t->aux->f <= 1.0f))
            cTank_Fire(t, tgt, valid, r);
    }
}


