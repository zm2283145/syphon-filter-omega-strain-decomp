/*
 * SFOGame/Source/flashlight: 1 file, 0045B610
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045B610 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cFlashlight_SetState: switch the flashlight on/off (sound, inventory notice, create/destroy its lights) */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Pt1FsV4;
struct Pt1FsId { int a, b, c, d; Pt1FsId() {} } __attribute__((aligned(16)));
typedef struct { char d[0x9C]; } Pt1FsStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Pt1FsStr s78;
    Pt1FsStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Pt1FsSnd;
struct Pt1FsLightBase { signed char kind; unsigned char flag1; };
struct Pt1FsLight : Pt1FsLightBase {
    virtual void Destroy(int flags);
    VPAD8(a)
    virtual void Enable();
    char pad8[4];
    float intensity;
    char pad10[8];
    int id;
    unsigned char enabled;
    unsigned char aux;
    unsigned char type;
    char pad1F;
    Pt1FsV4 pos;
    Pt1FsV4 dir;
    int extra;
};
struct Pt1FsActor {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual Pt1FsId GetId();
    char pad4[0x3524 - 4];
    void* weapons;
};
typedef struct Pt1FsSelf {
    unsigned char on;
    char pad1[3];
    Pt1FsActor* owner;
    Pt1FsLight* beam;
    Pt1FsLight* glow;
    float level;
    char pad14[4];
    int visId;
} Pt1FsSelf;
extern char g_FlashlightClickSound[];
extern char g_Game[];
extern char D_004DAE30[];
extern char g_LightMgr[];
extern char D_004D9280[];
extern char D_004D9240[];
extern char D_004D9200[];
extern "C" void cDazzleLight_DazzleCoversScreen();
extern "C" void cDazzleLight_GetDazzlePct();
extern "C" void cDazzleLight_GetAttenDist();
extern "C" void cDazzleLight_dtor();
extern "C" void cLightSrc_Deactivate();
extern "C" void cLightSrc_SetPosition();
extern "C" void cLightSrc_Activate();
extern "C" void func_001479A0();
extern "C" void PointLightComp_Start();
extern "C" void func_00147A00();
extern "C" void func_00147A10();
void * const D_004E15E0[16] = { (void*)0x0, (void*)0x0, (void*)cDazzleLight_dtor, (void*)PointLightComp_Start, (void*)0x1479E0, (void*)func_00147A00, (void*)func_00147A10, (void*)func_001479A0, (void*)cDazzleLight_GetDazzlePct, (void*)cDazzleLight_DazzleCoversScreen, (void*)cLightSrc_SetPosition, (void*)cLightSrc_Activate, (void*)cLightSrc_Deactivate, (void*)cDazzleLight_GetAttenDist, (void*)0x0, (void*)0x0 };
extern char g_TargetVisMgr[];
extern signed char D_004979B0;
extern unsigned char g_LevelLightsDirty;
extern "C" void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(Pt1FsSnd* e, void* preset, Pt1FsId* id);
extern "C" void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" void cFileMan_dtor(Pt1FsStr* s, int flag);
extern "C" void cWeapon_SetHardpointActivation(void* weapons, int item, int state);
extern "C" Pt1FsLight* cLightMan_AddLight(void* pool, int kind);
extern "C" Pt1FsV4* tRGBA_ctor_float_float_float_float(Pt1FsV4* out, float r, float g, float b, float a);
extern "C" Pt1FsV4* cVector_ctor_float_float_float_float(Pt1FsV4* out, float x, float y, float z, float w);
extern "C" void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Pt1FsLight* l, int flags, Pt1FsV4* color, Pt1FsV4* pos, int range);
extern "C" void cTargetManager_AddGobj(void* reg, int id);
extern "C" void cTargetManager_RemoveGobj(void* reg, int id);

extern "C" void cFlashlight_SetState(Pt1FsSelf* self, int on)
{
    if ((unsigned char)on == self->on)
        return;
    if (self->owner) {
        Pt1FsId id = self->owner->GetId();
        Pt1FsSnd snd;
        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&snd, g_FlashlightClickSound, &id);
        snd.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
        cWeapon_SetHardpointActivation(self->owner->weapons, 7, on);
        snd.vt = D_004DAE30;
        cFileMan_dtor(&snd.s114, -1);
        cFileMan_dtor(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    }
    self->on = on;
    if (self->on) {
        Pt1FsLight* l = cLightMan_AddLight(g_LightMgr, 4);
        if (l) {
            *(void**)((char*)l + 4) = D_004D9280;
            l->kind = D_004979B0;
            l->flag1 = 0;
            *(void**)((char*)l + 4) = D_004D9240;
            l->intensity = 0.0f;
            l->enabled = 0;
            l->aux = 3;
            l->type = 4;
            l->pos.x = 0.0f;
            l->pos.y = 0.0f;
            l->pos.z = 0.0f;
            l->pos.w = 0.0f;
            l->dir.x = 0.0f;
            l->dir.y = 0.0f;
            l->dir.z = 0.0f;
            l->dir.w = 1.0f;
            g_LevelLightsDirty = 1;
            l->id = 0;
            *(void**)((char*)l + 4) = D_004D9200;
        }
        self->beam = l;
        l = cLightMan_AddLight(g_LightMgr, 4);
        if (l) {
            Pt1FsV4 color;
            Pt1FsV4 pos;
            cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(l, 0x40, tRGBA_ctor_float_float_float_float(&color, 1.0f, 1.0f, 1.0f, 1.0f), cVector_ctor_float_float_float_float(&pos, 0.0f, 0.0f, 0.0f, 0.0f), 0x10);
            *(void**)((char*)l + 4) = ((char*)D_004E15E0);
            l->extra = 0;
        }
        self->glow = l;
        self->level = -1.0f;
        if (self->beam) {
            cTargetManager_AddGobj(g_TargetVisMgr, self->visId);
            self->beam->Enable();
        }
        if (self->glow)
            self->glow->Enable();
    } else {
        if (self->beam) {
            cTargetManager_RemoveGobj(g_TargetVisMgr, self->visId);
            if (self->beam)
                self->beam->Destroy(1);
            self->beam = 0;
        }
        if (self->glow) {
            if (self->glow)
                self->glow->Destroy(1);
            self->glow = 0;
        }
    }
}
static inline void merge_flush_func_0045B610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045B610 */
