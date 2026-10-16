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
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseLogicUpdate();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cEnvSettings_v0B();
extern "C" void cEnvSettings_v0C();
extern "C" void cEnvSettings_v0E();
extern "C" void cEnvSettings_v0F();
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void func_00141850();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void func_003CCFF0();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void func_003CD1C0();
extern "C" void PathObj_GetPosition();
extern "C" void func_003CD420();
extern "C" void func_003CD4A0();
extern "C" void func_003CD520();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CE9D0();
extern "C" void func_003CEA00();
extern "C" void Object_HandleMessage();
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
void * const D_004D9E00[68] = { (void*)0x0, (void*)0x0, (void*)cEnvSettings_dtor, (void*)Object_HandleMessage, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cEnvSettings_v0B, (void*)cEnvSettings_v0C, (void*)func_003CEA00, (void*)cEnvSettings_v0E, (void*)cEnvSettings_v0F, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001784F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001784F0 */

/* merge_units: begin func_00178580 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
extern "C" void Light_Disable();
extern "C" void Light_SetPosition();
extern "C" void Light_Enable();
extern "C" void func_001479A0();
extern "C" void Light_GetCoronaSize();
extern "C" void Light_GetCoronaFlag();
extern "C" void PointLightComp_Start();
extern "C" void func_00147A00();
extern "C" void func_00147A10();
extern void * const D_004D9F10[];
extern char D_004D9240[];
extern char D_004D9280[];
extern char D_00535D20[];
extern unsigned char D_00535D62;
void LightMgr_RemoveFromTable(void* pool, void* p);
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
extern "C" S_8580* func_00178580(S_8580* self, short flag)
{
    S_8580* s = self;
    if (s) {
        VT(s) = ((char*)D_004D9F10);
        if (s) {
            VT(s) = D_004D9240;
            s->id = -1;
            self->Shutdown();
            D_00535D62 = 1;
            if (s)
                VT(s) = D_004D9280;
        }
        if (flag > 0)
            LightMgr_RemoveFromTable(D_00535D20, s);
    }
    return s;
}
#pragma opt_common_subs reset
void * const D_004D9F10[16] = { (void*)0x0, (void*)0x0, (void*)func_00178580, (void*)PointLightComp_Start, (void*)0x1479E0, (void*)func_00147A00, (void*)func_00147A10, (void*)func_001479A0, (void*)Light_GetCoronaSize, (void*)Light_GetCoronaFlag, (void*)Light_SetPosition, (void*)Light_Enable, (void*)Light_Disable, (void*)0x1479F0, (void*)0x0, (void*)0x0 };
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
Light_178630* LightMgr_AllocPoint(void* pool, int n, int id);
V4_178630* Vec4_SetFromVec3W(V4_178630* out, V3_178630* in, float w);
void LevelLight_CreateDirectional(Light_178630* l, int a, V4_178630* c);
int IdMgr_FindCollision(int region, int id);
void* World_GetActorArray(void);
Vec_178630* func_001339A0(void* arr);
void PtrVec_Begin(It_178630* out, Vec_178630* v);
void PtrVec_End(It_178630* out, Vec_178630* v);
void func_00133980(It_178630* out, It_178630* in);
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
    l = LightMgr_AllocPoint(D_00535D20, 1, lo);
    if (l) {
        LevelLight_CreateDirectional(l, 1, Vec4_SetFromVec3W(&tmp, &obj->color, 0.0f));
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
        *(int*)(base + 0x90 + off) = IdMgr_FindCollision(hi, *p); }
    obj->actor = 0;
    if (r->version >= 0x3A) {
        find = *(unsigned char*)r->cur;
        r->cur++;
        Align_178630(r);
    } else {
        find = 1;
    }
    if (find) {
        void* arr = World_GetActorArray();
        PtrVec_End(&te, func_001339A0(arr));
        func_00133980(&end, &te);
        PtrVec_Begin(&tb, func_001339A0(arr));
        func_00133980(&it, &tb);
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
