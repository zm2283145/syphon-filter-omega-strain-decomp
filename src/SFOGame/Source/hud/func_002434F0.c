/* best cHud_UpdateEdgeCallouts: score 116 (0xb88 vs 0xb80) - draft d37 */
#pragma cplusplus on
#pragma inline_depth(10)
struct Vec4_H;
struct M4_H;
extern "C" {
float cVector_X_void(Vec4_H* v);
float cVector_Y_void(Vec4_H* v);
float cVector_Z_void(Vec4_H* v);
void cMatrix_SetWithAxisAngle(M4_H* m, float x, float y, float z, float a);
}

struct V4_H {
    float x, y, z, w;
    V4_H() {}
    V4_H(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4_H(const V4_H& o) { V4_H* d = this; const V4_H* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V4_H& operator=(const V4_H& o) { V4_H* d = this; const V4_H* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct V4C_H : V4_H { V4C_H(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
struct Vec4_H { float x, y, z, w; };
struct Row_H { float x, y, z, w; } __attribute__((aligned(16)));
struct M4_H {
    Row_H r[4];
    M4_H() {}
    M4_H(const M4_H& o) { M4_H* d = this; __int128 t0; __int128 t1; const M4_H* s = &o; asm volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct Rect_H { float x, y, w, h; };
struct Pt_H { float x, y; Pt_H() {} Pt_H(float a, float b) { x = a; y = b; } };
struct Word_H { int value; };

class String_H {
public:
    String_H(const char* s);
    ~String_H();
    const char* CStr();
    char pad[0xC];
};

static inline V4_H Xf2_H(const M4_H* m, const V4_H& v0) {
    V4_H v; V4_H* p;
    { V4_H* d = &v; const V4_H* s = &v0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    p = &v;
    asm volatile("lqc2 vf8, 0x0(%0)\n\tlqc2 vf4, 0x0(%1)\n\tlqc2 vf5, 0x10(%1)\n\tlqc2 vf6, 0x20(%1)\n\tlqc2 vf7, 0x30(%1)\n\tvmulax.xyzw ACC, vf4, vf8x\n\tvmadday.xyzw ACC, vf5, vf8y\n\tvmaddaz.xyzw ACC, vf6, vf8z\n\tvmaddw.xyzw vf12, vf7, vf8w\n\tsqc2 vf12, 0x0(%0)" : : "r"(p), "r"(m) : "memory");
    return *p;
}
static inline V4_H Xf_H(const M4_H* m, const V4_H& v0) { return Xf2_H(m, v0); }
static inline V4_H Xf3_H(const M4_H* m, const V4_H& v0) { return Xf_H(m, v0); }
static inline V4_H Xf4_H(const M4_H* m, const V4_H& v0) { return Xf3_H(m, v0); }
static inline M4_H MMul_H(const M4_H* a, const M4_H* b) {
    M4_H r;
    asm volatile("lqc2 vf4, 0x0(%1)\n\tlqc2 vf5, 0x10(%1)\n\tlqc2 vf6, 0x20(%1)\n\tlqc2 vf7, 0x30(%1)\n\tlqc2 vf8, 0x0(%2)\n\tlqc2 vf9, 0x10(%2)\n\tlqc2 vf10, 0x20(%2)\n\tlqc2 vf11, 0x30(%2)\n\t"
        "vmulax.xyzw ACC, vf4, vf8x\n\tvmadday.xyzw ACC, vf5, vf8y\n\tvmaddaz.xyzw ACC, vf6, vf8z\n\tvmaddw.xyzw vf12, vf7, vf8w\n\t"
        "vmulax.xyzw ACC, vf4, vf9x\n\tvmadday.xyzw ACC, vf5, vf9y\n\tvmaddaz.xyzw ACC, vf6, vf9z\n\tvmaddw.xyzw vf13, vf7, vf9w\n\t"
        "vmulax.xyzw ACC, vf4, vf10x\n\tvmadday.xyzw ACC, vf5, vf10y\n\tvmaddaz.xyzw ACC, vf6, vf10z\n\tvmaddw.xyzw vf14, vf7, vf10w\n\t"
        "vmulax.xyzw ACC, vf4, vf11x\n\tvmadday.xyzw ACC, vf5, vf11y\n\tvmaddaz.xyzw ACC, vf6, vf11z\n\tvmaddw.xyzw vf15, vf7, vf11w\n\t"
        "sqc2 vf12, 0x0(%0)\n\tsqc2 vf13, 0x10(%0)\n\tsqc2 vf14, 0x20(%0)\n\tsqc2 vf15, 0x30(%0)" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline V4_H Sub_H(const V4_H& a, const V4_H& b) {
    V4_H r;
    asm volatile("lqc2 vf1, 0x0(%1)\n\tlqc2 vf2, 0x0(%2)\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Nrm_H(V4_H& v) {
    asm volatile("lqc2 vf1, 0x0(%0)\n\tvmul.xyz vf2, vf1, vf1\n\tvmulax.w ACC, vf0, vf2x\n\tvmadday.w ACC, vf0, vf2y\n\tvmaddz.w vf3, vf0, vf2z\n\tvrsqrt Q, vf0w, vf3w\n\tvwaitq\n\tvmulq.xyz vf1, vf1, Q\n\tsqc2 vf1, 0x0(%0)" : : "r"(&v) : "memory");
}
static inline V4_H Crs_H(const V4_H& a, const V4_H& b) {
    V4_H r;
    asm volatile("lqc2 vf1, 0x0(%1)\n\tlqc2 vf2, 0x0(%2)\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf3, vf2, vf1\n\tvsubw.w vf3, vf0, vf0w\n\tsqc2 vf3, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Dot_H(const V4_H& a0, const V4_H& b0) {
    const V4_H* a = &a0;
    const V4_H* b = &b0;
    float ret = 0.0f;
    int rv0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}static inline float Clamp_H(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "=f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }

struct AxI_H { int x, y, z, w; AxI_H(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; } };
static inline void Rot_H(M4_H* m, const AxI_H& ax, float a) {
    float x = cVector_X_void((Vec4_H*)&ax);
    float y = cVector_Y_void((Vec4_H*)&ax);
    cMatrix_SetWithAxisAngle(m, x, y, cVector_Z_void((Vec4_H*)&ax), a);
}

extern "C" unsigned char PointInRect(Pt_H* p, Rect_H* r);
static inline unsigned char OnScr_H(const V4_H& p, Rect_H* r) {
    Pt_H pt(p.x, p.y);
    return PointInRect(&pt, r);
}

class Node3D_H {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0xC];
    M4_H mtx;
    unsigned char b50;
};
struct Cam_H { char pad[0x50]; Node3D_H* node; char pad54[0xC]; float fov; };
class Obj_H {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V4_H GetPos(int id);
};
struct Font_H { char pad[0xD0]; struct Glyph_H* fD0; };
struct Glyph_H { float f0; float f4; };
struct Text_H { char pad[0x14]; char name[0xC]; int f20; char pad24[0x30]; float f54; };
struct Sprite_H {
    char pad0[4];
    float f4, f8, fC, f10;
    unsigned char b14;
    char pad15[3];
    unsigned char b18;
    char pad19[0x70 - 0x19];
    Font_H* f70;
    Text_H* f74;
};
struct Marker_H { char pad[0x60]; Sprite_H* f60; char pad64[0xC]; V4_H pos; };
struct Ent_H { char pad[8]; int id; Sprite_H* sprite; Marker_H* marker; float dist; unsigned char b18; };
struct Node_H { Node_H* prev; Node_H* next; Ent_H* data; };
struct Str_H { char pad[0xC]; };
extern "C" { void std_basic_string_char_char_traits_char_ctor_basicstringR(Str_H* s, const char* c); const char* std_basic_string_char_char_traits_char_c_str(Str_H* s); void String_Dtor(Str_H* s, int f); }
struct Hud_H { char pad[0x40]; float f40, f44, f48, f4C; char pad50[0x6E8 - 0x50]; char list[4]; };

extern "C" {
extern int D_00538200;
extern int D_00538204;
extern int D_004F7DA0[];
extern char g_CameraObject[];
extern char D_00587D90[];
void std_list_deleter_voidPtr_begin_void_2(Word_H* w, void* l);
int* std_list_tCalloutPtr_generic_iterator_1_ctor(int* dst, int value);
void std_list_tCalloutPtr_end_void_2(Word_H* w, void* l);
Word_H* cConstLListIterator_tCalloutPtr_ctor(Word_H* dst, Word_H* src);
unsigned char PointInRect(Pt_H* p, Rect_H* r);
Obj_H* nGobjManager_LookupGOBJ_cObjectIdR(Ent_H* e);
int func_00159570(void* l);
Cam_H** cLList_cCAMERA_GOBJPtr_Front(void* l);
float Libc_Tanf(float);
float Libc_Atanf(float);
float Math_Acos(float);
float cVector_X_void(Vec4_H* v);
float cVector_Y_void(Vec4_H* v);
float cVector_Z_void(Vec4_H* v);
void cMatrix_SetWithAxisAngle(M4_H* m, float x, float y, float z, float a);
int TextObj_GetLineCount(Text_H* t);
int cFont_GetCharH(int a);
Sprite_H* cInterfaceModel_CreateInstance(int a);
void cTextArea_SetText(Text_H* t, const char* s);
void cInterfaceElement_Destroy(Sprite_H* s);
void cInterfaceElement_SetFilterColor(Sprite_H* s, void* p);
void cInterfaceElement_SetLocation(Sprite_H* s, V4_H* p);
}

static inline void SetP_H(Marker_H* m, V4_H p) { m->pos = p; }
static inline void SetP2_H(Marker_H* m, const V4_H& p) { m->pos = V4_H(p); }
static inline void SetP3_H(Marker_H* m, const V4_H& p) { V4_H t(p); m->pos = t; }
extern "C" void cHud_UpdateEdgeCallouts(Hud_H* self)
{
    float w;
    float hw;
    float nhw;
    float h;
    float hh;
    float nhh;
    Rect_H rect;
    Word_H it; Word_H e2; int r; Word_H tmp; Word_H e;

    w = (float)D_00538200;
    hw = w / 2.0f;
    h = (float)D_00538204;
    hh = h / 2.0f;
    nhw = -hw;
    nhh = -hh;

    rect.w = w;
    rect.h = h;
    rect.x = nhw;
    rect.y = nhh;
    std_list_deleter_voidPtr_begin_void_2(&tmp, self->list);
    std_list_tCalloutPtr_generic_iterator_1_ctor(&r, tmp.value);
    for (it.value = r; std_list_tCalloutPtr_end_void_2(&e, self->list), cConstLListIterator_tCalloutPtr_ctor(&e2, &e), it.value != e2.value; it.value = (int)((Node_H*)it.value)->next) {
        Ent_H* ent = ((Node_H*)it.value)->data;
        if (ent->marker && ent->sprite && ent->b18 && ent->sprite->b18) {
            V4_H pos = ent->marker->pos;

            if (!(pos.z < 0.0f)) {
                if (OnScr_H(pos, &rect)) goto clamp;
            }
            {
                Obj_H* o = nGobjManager_LookupGOBJ_cObjectIdR(ent);
                Cam_H* cam;
                Node3D_H* node;
                float fov;
                float dist;
                float vfov;
                if (!o) continue;
                cam = func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0;
                node = cam->node;
                if (node->b50) node->Update();
                {
                M4_H* mtx = &node->mtx;
                fov = cam->fov;
                dist = (w / 2.0f) / Libc_Tanf(fov);
                vfov = Libc_Atanf((h / 2.0f) / dist);
                {
                V4_H campos(*(V4_H*)&mtx->r[3]);
                V4_H tgt(o->GetPos(ent->id));
                    float ang = 0.0f;
                    float sign;
                    V4_H a = Xf4_H(mtx, V4C_H(0.0f, 1.0f, 0.0f, 0.0f));
                    V4_H d = Sub_H(tgt, campos);
                    a.z = d.z = 0.0f;
                    Nrm_H(a);
                    Nrm_H(d);
                    V4_H c = Crs_H(a, d);
                    sign = Dot_H(c, V4C_H(0.0f, 0.0f, 1.0f, 0.0f));
                    ang = Math_Acos(Dot_H(d, a));
                    if (ang < fov) {
                        float x = dist * Libc_Tanf(ang);
                        pos.x = (sign > 0.0f) ? -x : x;
                    } else {
                        pos.x = (sign > 0.0f) ? nhw : hw;
                    }
                    ang *= (sign > 0.0f) ? 1.0f : -1.0f;
                    {
                        M4_H rot;
                        Rot_H(&rot, AxI_H(0, 0, 0x3F800000, 0), ang);
                        {
                            M4_H m2 = MMul_H(&rot, mtx);
                            V4_H a2 = Xf4_H(&m2, V4C_H(0.0f, 1.0f, 0.0f, 0.0f));
                            V4_H d2 = Sub_H(tgt, campos);

                            float sign2;
                            float ang2;
                            Nrm_H(a2);
                            Nrm_H(d2);
                            V4_H c2 = Crs_H(a2, d2);
                            sign2 = Dot_H(c2, Xf3_H(&m2, V4C_H(1.0f, 0.0f, 0.0f, 0.0f)));
                            ang2 = Math_Acos(Dot_H(d2, a2));
                            if (ang2 < vfov) {
                                float y = dist * Libc_Tanf(ang2);
                                y = (sign2 <= 0.0f) ? -y : y;
                                pos.y = y;
                            } else {
                                pos.y = (sign2 <= 0.0f) ? nhh : hh;
                            }
                        }
                    }
                }
                }
            }
clamp:
            {
                unsigned char cur;
                Rect_H sz;
                Sprite_H* sp;
                Text_H* t;
                int dir;
                int i;
                bool clip;
                float lim;
                sz.x = self->f40;
                sz.y = self->f44;
                sz.w = self->f48;
                sz.h = self->f4C;
                sp = ent->marker->f60;
                t = sp->f74;
                if (t) {
                    Glyph_H* g;
                    int k = t->f20;
                    if (k) {
                        g = sp->f70->fD0;
                        float top = g->f4 - (float)(TextObj_GetLineCount(t) * cFont_GetCharH(k));
                        if (top < sz.y) {
                            float dd = sz.y - top;
                            sz.y -= dd;
                            sz.h += dd;
                        }
                    }
                }
                dir = 3;
                for (i = 0; i < 4; i++) {
                    Font_H* fv = ent->sprite->f70; if ((Font_H*)D_004F7DA0[i] == fv) {
                        cur = i;
                        break;
                    }
                }
                clip = 0;
                if (pos.x + sz.x < nhw) {
                    pos.x = nhw - sz.x;
                    dir = 0;
                    clip = 1;
                }
                if (!(pos.x < hw)) {
                    dir = 1;
                    clip = 1;
                    pos.x = (hw - sz.w) - sz.x;
                }
                if (!(sz.h + (pos.y + sz.y) <= hh)) {
                    if ((unsigned char)dir) dir = 2;
                    clip = 1;
                    pos.y = (hh - sz.h) - sz.y;
                }
                lim = 112.0f + nhh;
                if (pos.y + sz.y < lim) {
                    if ((unsigned char)dir) dir = 3;
                    clip = 1;
                    pos.y = lim - sz.y;
                }
                if (!clip || ent->dist <= 3600.0f) {
                    pos.z = 10.0f;
                    if ((unsigned char)dir != cur) {
                        Sprite_H* old = ent->sprite;
                        Str_H name;
                        std_basic_string_char_char_traits_char_ctor_basicstringR(&name, old->f74->name);
                        ent->sprite = cInterfaceModel_CreateInstance(D_004F7DA0[(unsigned char)dir]);
                        cTextArea_SetText(ent->sprite->f74, std_basic_string_char_char_traits_char_c_str(&name));
                        Sprite_H* ss = ent->sprite; Text_H* h74 = ss->f74; h74->f54 = Clamp_H(1.0f, 0.0f, 1.0f);
                        {
                            Sprite_H* ns = ent->sprite;
                            ns->f4 = old->f4;
                            ns->f8 = old->f8;
                            ns->fC = old->fC;
                            ns->f10 = old->f10;
                            ns->b14 = old->b14;
                        }
                        cInterfaceElement_Destroy(old);
                        { Marker_H* m6; Sprite_H* s6; s6 = ent->sprite; m6 = ent->marker; m6->f60 = s6; }
                        cInterfaceElement_SetFilterColor(ent->sprite, D_00587D90);
                        String_Dtor(&name, 0);
                    }
                    SetP_H(ent->marker, pos);

                    cInterfaceElement_SetLocation(ent->marker->f60, &pos);
                }
            }
        }
    }
}
