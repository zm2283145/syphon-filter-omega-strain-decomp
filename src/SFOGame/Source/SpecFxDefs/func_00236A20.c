#pragma cplusplus on
#include "types.h"
#include "q4r.h"

inline void* operator new(unsigned int, void* p) { return p; }

struct cMatrix {
    Vec4 r[4];
};
struct tInit {
    unsigned char light;
    cMatrix* mat;
    int partFx0;
};
struct cWeaponFx {
    char pad[0x14];
    void* vt;
};
struct cParticleFx {
    signed char flag;
    unsigned char active;
    char pad2[2];
    void* vt;
    int effectDefId;
    int particle;
    cMatrix mat;
};
struct tRGB {
    float r, g, b;
    tRGB(float r_, float g_, float b_) { float t = r_; r = t; g = t; b = b_; }
};
struct tRGBA { float r, g, b, a; };

extern "C" {
extern char D_004DBAE0[];
extern char D_004D9200[];
extern char D_004D9280[];
extern char D_004DBE90[];
extern signed char D_0048AD80;
extern char g_LightMgr[];
void cSfxBundle_ctor(cWeaponFx* self);
cParticleFx* cSpecFx_opNew(int size);
struct cPointLight* cLightMan_AddLight(void*, int);
tRGBA* tRGBA_ctor_tRGBR_float(tRGBA*, const tRGB*, float);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(struct cPointLight*, int, tRGBA*, Vec4*, int);
void LightEffect_SetInner(struct cPointLight*, float);
void LightEffect_SetOuter(struct cPointLight*, float);
void cSfxScheduler_AddItem(cWeaponFx* self, void* obj, float x, float y);
}

struct cPointLight {
    int pad0;
    void* vt;
    cPointLight(Vec4* pos, const tRGB& col)
    {
        tRGBA v;
        cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(this, 4, tRGBA_ctor_tRGBR_float(&v, &col, 0.0f), pos, 3);
        vt = D_004D9200;
        LightEffect_SetInner(this, 0.0f);
        LightEffect_SetOuter(this, 10.0f);
    }
};

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" cWeaponFx* cWeaponFx_ctor(cWeaponFx* self0, tInit* init0)
{
    cWeaponFx* self = self0;
    tInit* init = init0;
    cPointLight* lightSrc;
    cParticleFx* particleFx0;

    cSfxBundle_ctor(self0);
    self->vt = D_004DBAE0;
    lightSrc = 0;
    particleFx0 = 0;
    if (init->light) {
        lightSrc = new (cLightMan_AddLight(g_LightMgr, 4)) cPointLight(&init->mat->r[3], tRGB(1.0f, 1.0f, 0.7f));
    }
    if (init->partFx0 > 0) {
        cParticleFx* o = cSpecFx_opNew(0x50);
        if (o != 0) {
            cMatrix* src = init->mat;
            cMatrix* dst;
            __int128 qa;
            __int128 qb;
            o->vt = D_004D9280;
            o->flag = D_0048AD80;
            o->active = 0;
            o->vt = D_004DBE90;
            o->effectDefId = init->partFx0;
            o->particle = 0;
            dst = &o->mat;
            /* retail two-register quad matrix copy idiom */
            Q4COPY_N(dst, src, qa, qb);
        }
        particleFx0 = o;
    }
    if (lightSrc) {
        cSfxScheduler_AddItem(self, lightSrc, 0.0f, 0.1f);
    }
    if (particleFx0) {
        { float z = 0.0f; cSfxScheduler_AddItem(self, particleFx0, z, z); }
    }
    return self;
}
