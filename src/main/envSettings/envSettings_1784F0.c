/*
 * main/envSettings: range (3 files, 001784F0-00178630)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001784F0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void* p);
extern "C" void cGOBJ_dtor(void* self, int flag);
class VDel { public: int a; virtual ~VDel(); };
extern "C" void cGOBJ_ReceiveDamage();
extern "C" void cGOBJ_NextFrame();
extern "C" void cGOBJ_CriticalNextFrame();
extern "C" void cGOBJ_UpdateMotion();
extern "C" void cGOBJ_CriticalUpdateMotion();
extern "C" void cGOBJ_Die();
extern "C" void cGOBJ_Disable();
extern "C" void cGOBJ_IsEnabled();
extern "C" void cGOBJ_Enable();
extern "C" void cGOBJ_Activate();
extern "C" void cGOBJ_CreateXform();
extern "C" void cGOBJ_ScriptGetRealObj();
extern "C" void cEnvSettings_getSOBJClassId();
extern "C" void cEnvSettings_ScriptHandleMessage();
extern "C" void cEnvSettings_v0E();
extern "C" void cEnvSettings_Load();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGOBJ_GetFloorPlane();
extern "C" void cGOBJ_GetBBox();
extern "C" void func_00140E90();
extern "C" void cGOBJ_GetHealthState();
extern "C" void cGOBJ_IsGeneratorCreated();
extern "C" void cGOBJ_GetTargetPosition();
extern "C" void cGOBJ_GetLosPosition();
extern "C" void cGOBJ_HasHeadset();
extern "C" void cGOBJ_SetStatus();
extern "C" void cGOBJ_GetStatus();
extern "C" void cGOBJ_GetChildList_void();
extern "C" void cGOBJ_GetChildList_void_2();
extern "C" void cGOBJ_ScaleBBox();
extern "C" void cGOBJ_GetTargetPriority();
extern "C" void cGOBJ_GetMovementState();
extern "C" void cGOBJ_GetSubTargetAimAdjust();
extern "C" void cGOBJ_GetNumSubTargets();
extern "C" void cGOBJ_IsAimed();
extern "C" void cGOBJ_InitNetwork();
extern "C" void cGOBJ_IsNetworked();
extern "C" void cGOBJ_CheckBullet();
extern "C" void cGOBJ_GetTransform_ForFloorTravel();
extern "C" void cGOBJ_GetCameraCollisionReferencePoint();
extern "C" void cGOBJ_GetTransform_ForCameraTracking();
extern "C" void cGOBJ_GetTransform_ForTeleporting();
extern "C" void cGOBJ_GetCenterOfMass();
extern "C" void cGOBJ_GetActivationPoint();
extern "C" void cGOBJ_v35();
extern "C" void cGOBJ_GetMatrix();
extern "C" void cGOBJ_SetTranslation_ResetPhysics();
extern "C" void cGOBJ_SetRotation_ResetPhysics();
extern "C" void cGOBJ_SetTransform_ResetPhysics();
extern "C" void cGOBJ_ApplyTranslation();
extern "C" void cGOBJ_ApplyLocalRotation();
extern "C" void cGOBJ_ApplyTransform();
extern "C" void cGOBJ_SetTranslation();
extern "C" void cGOBJ_SetRotation();
extern "C" void cGOBJ_SetTransform();
extern "C" void cGOBJ_Deactivate();
extern "C" void cGOBJ_NetDeactivate();
extern "C" void cGOBJ_NetActivate();
extern "C" void cGOBJ_Render();
extern "C" void cGOBJ_ProcessMessage();
extern "C" void cGOBJ_HandleMessage();
extern void * const D_004D9E00[];
typedef struct { void* vt; char pad[0x9C]; VDel* xA0; } S_84F0;
extern "C" S_84F0* cEnvSettings_dtor(S_84F0* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004D9E00);
        if (self->xA0)
            delete self->xA0;
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9E00[68] = { (void*)0x0, (void*)0x0, (void*)cEnvSettings_dtor, (void*)cGOBJ_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cGOBJ_ScriptGetRealObj, (void*)cGOBJ_IsNetworked, (void*)cSystem_SendCreated, (void*)cGOBJ_NetActivate, (void*)cGOBJ_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cEnvSettings_getSOBJClassId, (void*)cEnvSettings_ScriptHandleMessage, (void*)cGOBJ_ProcessMessage, (void*)cEnvSettings_v0E, (void*)cEnvSettings_Load, (void*)cGOBJ_NextFrame, (void*)cGOBJ_CriticalNextFrame, (void*)cGOBJ_UpdateMotion, (void*)cGOBJ_CriticalUpdateMotion, (void*)cGOBJ_Render, (void*)cGOBJ_Activate, (void*)cGOBJ_Deactivate, (void*)cGOBJ_Enable, (void*)cGOBJ_Disable, (void*)cGOBJ_IsEnabled, (void*)cGOBJ_HasHeadset, (void*)cGOBJ_SetStatus, (void*)cGOBJ_GetStatus, (void*)cGOBJ_IsGeneratorCreated, (void*)cGOBJ_GetChildList_void_2, (void*)cGOBJ_GetChildList_void, (void*)cGOBJ_GetBBox, (void*)cGOBJ_ScaleBBox, (void*)cGOBJ_CreateXform, (void*)cGOBJ_SetTransform, (void*)cGOBJ_SetRotation, (void*)cGOBJ_SetTranslation, (void*)cGOBJ_ApplyTransform, (void*)cGOBJ_ApplyLocalRotation, (void*)cGOBJ_ApplyTranslation, (void*)cGOBJ_SetTransform_ResetPhysics, (void*)cGOBJ_SetRotation_ResetPhysics, (void*)cGOBJ_SetTranslation_ResetPhysics, (void*)cGOBJ_GetTargetPriority, (void*)cGOBJ_GetLosPosition, (void*)cGOBJ_GetTargetPosition, (void*)cGOBJ_GetMovementState, (void*)func_00140E90, (void*)cGOBJ_GetSubTargetAimAdjust, (void*)cGOBJ_GetNumSubTargets, (void*)cGOBJ_IsAimed, (void*)cGOBJ_GetMatrix, (void*)cGOBJ_v35, (void*)cGOBJ_GetActivationPoint, (void*)cGOBJ_GetCenterOfMass, (void*)cGOBJ_GetTransform_ForTeleporting, (void*)cGOBJ_GetTransform_ForCameraTracking, (void*)cGOBJ_GetCameraCollisionReferencePoint, (void*)cGOBJ_GetTransform_ForFloorTravel, (void*)cGOBJ_GetFloorPlane, (void*)cGOBJ_InitNetwork, (void*)cGOBJ_ReceiveDamage, (void*)cGOBJ_CheckBullet, (void*)cGOBJ_GetHealthState, (void*)cGOBJ_Die };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001784F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001784F0 */

/* merge_units: begin func_00178580 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
extern "C" void cLightSrc_Deactivate();
extern "C" void cLightSrc_SetPosition();
extern "C" void cLightSrc_Activate();
extern "C" void func_001479A0();
extern "C" void Light_GetCoronaSize();
extern "C" void Light_GetCoronaFlag();
extern "C" void PointLightComp_Start();
extern "C" void func_00147A00();
extern "C" void func_00147A10();
extern void * const D_004D9F10[];
extern char D_004D9240[];
extern char D_004D9280[];
extern char g_LightMgr[];
extern unsigned char g_LevelLightsDirty;
void cLightMan_RemoveLight(void* pool, void* p);
}
class S_8580 {
public:
    int a;
    VPAD8(x) VPAD2(y)
    virtual void Shutdown();
    int id;
};
#define VT(p) (*(void**)((char*)(p) + 4))
#pragma opt_common_subs off
extern "C" S_8580* cAmbientLight_dtor(S_8580* self, short flag)
{
    S_8580* s = self;
    if (s) {
        VT(s) = ((char*)D_004D9F10);
        if (s) {
            VT(s) = D_004D9240;
            s->id = -1;
            self->Shutdown();
            g_LevelLightsDirty = 1;
            if (s)
                VT(s) = D_004D9280;
        }
        if (flag > 0)
            cLightMan_RemoveLight(g_LightMgr, s);
    }
    return s;
}
#pragma opt_common_subs reset
void * const D_004D9F10[16] = { (void*)0x0, (void*)0x0, (void*)cAmbientLight_dtor, (void*)PointLightComp_Start, (void*)0x1479E0, (void*)func_00147A00, (void*)func_00147A10, (void*)func_001479A0, (void*)Light_GetCoronaSize, (void*)Light_GetCoronaFlag, (void*)cLightSrc_SetPosition, (void*)cLightSrc_Activate, (void*)cLightSrc_Deactivate, (void*)0x1479F0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178580 */

/* merge_units: begin func_00178630 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4_178630 { float x, y, z, w; };
struct LightBase_178630 { int f0; };
struct Light_178630 : LightBase_178630 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void SetColor(V4_178630* c); virtual void Apply();
};
struct V3_178630 { float x, y, z; };
struct Actor_178630 { char pad0[0xC]; unsigned int id; char pad10[0x49 - 0x10]; unsigned char type; };
struct It_178630 { Actor_178630** p; };
struct Vec_178630;
struct Reader_178630 { int version; int a, b; char* cur; };
struct EnvSettings_178630 {
    void* vt; char pad4[8]; int id; char pad10[0x60 - 0x10];
    float f60, f64, f68, f6C, f70, f74, f78; unsigned char b7C; char pad7D[3]; float f80;
    V3_178630 color; int collision[4]; Light_178630* light; Actor_178630* actor;
};
extern "C" {
#if 0 /* merge_units */
extern char D_004D9E00[];
#endif /* merge_units */
#define D_004D9E00 ((char*)&D_004D9E00) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9F10[];
#endif /* merge_units */
#define D_004D9F10 ((char*)&D_004D9F10) /* merge_units */

void cGOBJ_ctor(EnvSettings_178630* obj, int* id, int kind, int* out);
Light_178630* cLightMan_AddLight(void* pool, int n, int id);
V4_178630* tRGBA_ctor_tRGBR_float(V4_178630* out, V3_178630* in, float w);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR(Light_178630* l, int a, V4_178630* c);
int nGobjManager_LookupGOBJ_int_int(int region, int id);
void* nGobjManager_GetGOBJList(void);
Vec_178630* cObjList_cGOBJPtr_GetList(void* arr);
void cArray_cGOBJPtr_Begin(It_178630* out, Vec_178630* v);
void cArray_cGOBJPtr_End(It_178630* out, Vec_178630* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It_178630* out, It_178630* in);
}
static inline int Read_178630(Reader_178630* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt_178630(Reader_178630* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void ReadFloat_178630(Reader_178630* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void Align_178630(Reader_178630* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline int Ne_178630(It_178630* a, It_178630* b) { return (a->p == b->p) ^ 1; }
/* Environment settings object: reads light/fog parameters and finds the zone actor. */
extern "C" EnvSettings_178630* cEnvSettings_ctor(EnvSettings_178630* obj, Reader_178630* r)
{
    It_178630 end;
    It_178630 it;
    int gid;
    int out;
    It_178630 te;
    It_178630 tb;
    int ids[4];
    V4_178630 zero;
    V4_178630 tmp;
    int hi, lo, i;
    int* p;
    unsigned char find;
    Light_178630* l;
    out = 0;
    gid = 0;
    cGOBJ_ctor(obj, &gid, 7, &out);
    obj->vt = D_004D9E00;
    hi = Read_178630(r);
    lo = Read_178630(r);
    obj->id = lo | (hi << 16);
    ReadFloat_178630(r, &obj->f70);
    ReadFloat_178630(r, &obj->f74);
    ReadFloat_178630(r, &obj->f78);
    ReadFloat_178630(r, &obj->f68);
    ReadFloat_178630(r, &obj->f6C);
    ReadFloat_178630(r, &obj->f60);
    ReadFloat_178630(r, &obj->f64);
    ReadFloat_178630(r, &obj->color.x);
    ReadFloat_178630(r, &obj->color.y);
    ReadFloat_178630(r, &obj->color.z);
    l = cLightMan_AddLight(g_LightMgr, 1, lo);
    if (l) {
        cLightSrc_ctor_eLightSrcTypes_tRGBAR(l, 1, tRGBA_ctor_tRGBR_float(&tmp, &obj->color, 0.0f));
        *(void**)((char*)l + 4) = D_004D9F10;
    }
    obj->light = l;
    if (obj->light) {
        zero.x = 0; zero.y = 0; zero.z = 0; zero.w = 0;
        obj->light->SetColor(&zero);
        obj->light->Apply();
    }
    ReadInt_178630(r, &ids[0]);
    ReadInt_178630(r, &ids[1]);
    ReadInt_178630(r, &ids[2]);
    ReadInt_178630(r, &ids[3]);
    obj->b7C = *(unsigned char*)r->cur;
    r->cur++;
    p = ids;
    Align_178630(r);
    if (r->version >= 0x37)
        ReadFloat_178630(r, &obj->f80);
    else
        obj->f80 = 0.45f;
    { int off; char* base = (char*)obj; for (i = 0, off = 0; i < 4; i++, p++, off += 4)
        *(int*)(base + 0x90 + off) = nGobjManager_LookupGOBJ_int_int(hi, *p); }
    obj->actor = 0;
    if (r->version >= 0x3A) {
        find = *(unsigned char*)r->cur;
        r->cur++;
        Align_178630(r);
    } else {
        find = 1;
    }
    if (find) {
        void* arr = nGobjManager_GetGOBJList();
        cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr));
        cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te);
        cArray_cGOBJPtr_Begin(&tb, cObjList_cGOBJPtr_GetList(arr));
        cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&it, &tb);
        while (Ne_178630(&it, &end)) {
            Actor_178630* a = *it.p;
            if (a->type == 5 && hi == (a->id & 0xFF0000) >> 16) {
                obj->actor = a;
                break;
            }
            it.p++;
        }
    }
    return obj;
}
#undef D_004D9E00 /* merge_units */
#undef D_004D9F10 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178630 */
