#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct M4 { V4 r[4]; };
struct L45D070 { char p[0x14]; unsigned short flags; char p16[0x3E]; int font; };
struct O45D070 { char p[0x30]; M4 mtx; int unk70; };
struct W45D070 { char p[0x50]; L45D070* label; unsigned char b54, b55; char p56[2]; char m58[0xC]; unsigned char b64; };
extern "C" {
void String_CtorCStr_13B480(void* s);
void String_Dtor(void* s, int z);
void func_0013D680(void* d, void* s);
int func_0036AA50(int font, const char* s, int n);
void func_003E8040(O45D070* o, M4* m);
void func_003ECB50(V4* out, float f, int x);
int func_003EE840(int a, void* b);
void func_0041BEB0(L45D070* l, const char* s, int z);
void* GuiWidget_FindChildByName(void* w, void* id);
int func_0041E0F0(void* w, void* src, int kind, int a, int b);
void func_0045CFB0(W45D070* w, int a);
extern char D_004C2238[];
extern char D_004C2250[];
extern char D_005861C8;
extern M4 D_005861D0;
extern char D_00586210;
extern unsigned char D_00497B10;
extern float D_00586220;
extern float D_00586224;
extern float D_00586228;
extern float D_0058622C;
}
inline void M4Copy(M4* d, M4* s) { M4* dd = d; M4* ss = s; __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(dd), "r"(ss) : "memory"); }
inline void M4CopyB(M4* d, M4* s) { __int128* dd = (__int128*)d; __int128 a, b; __int128* ss = (__int128*)s; a = ss[0]; b = ss[1]; dd[0] = a; a = ss[2]; dd[1] = b; b = ss[3]; dd[2] = a; dd[3] = b; }
inline void V4Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
inline void V4Scale(V4* o, V4* i, float f) { V4* oo = o; V4* ii = i; int tt; asm { .set noreorder; lqc2 vf1, 0x0(ii); mfc1 tt, f; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(oo); .set reorder } }
#pragma push
#pragma opt_propagation off
extern "C" void func_0045D070(W45D070* w, const char* text, unsigned char color, int a)
{
    O45D070* obj;
    float width;
    M4 m;
    V4 s;
    V4 t;
    V4 v;
    if (w->label) {
        if (text == 0 || *text == 0) {
            func_0045CFB0(w, a);
            return;
        }
        if (a) {
            char str[0xC];
            w->b55 = 1;
            String_CtorCStr_13B480(str);
            func_0013D680(w->m58, str);
            String_Dtor(str, 0);
            w->b64 = color;
        } else {
            w->b54 = 1;
        }
        w->label->flags |= 2;
        func_0041BEB0(w->label, text, 0);
        { L45D070* l = w->label; func_0041E0F0(l, l, 10, color, 0); }
        { void* id = GuiWidget_FindChildByName(w, D_004C2238); obj = 0;
        if (!func_0041E0F0(w, id, 5, (int)&obj, 0)) return; }
        if (!obj) return;
        if (!D_005861C8) {
            M4Copy(&D_005861D0, &obj->mtx);
            D_005861C8 = 1;
        }
        if (!D_00586210) D_00586210 = 1;
        if (D_00497B10) {
            int h = func_003EE840(obj->unk70, D_004C2250);
            if (h) {
                func_003ECB50(&v, 0.0f, h);
                D_00586220 = v.x;
                D_00586224 = v.y;
                D_00586228 = v.z;
                D_0058622C = v.w;
                D_00586228 -= 70.0f;
            }
            D_00497B10 = 0;
        }
        { int font = w->label->font; if (font) width = func_0036AA50(font, text, 0x200);
        else width = 0.0f; }
        if (width > D_00586228 && D_00586228 > 0.0f) {
            M4CopyB(&m, &D_005861D0);
            V4Copy(&s, &m.r[0]);
            __int128 tt = 0;
            V4Scale(&s, &s, width / D_00586228);
            { float x, y, z, ww; ww = s.w; z = s.z; y = s.y; x = s.x; m.r[0].w = ww; m.r[0].z = z; m.r[0].y = y; m.r[0].x = x; }
            { V4* sp3 = &m.r[3]; V4* tp = &t; V4Copy(tp, sp3); }
            { float hw = (width - D_00586228); t.x += hw / 2.0f; }
            V4Copy(&m.r[3], &t);
            func_003E8040(obj, &m);
        } else {
            func_003E8040(obj, &D_005861D0);
        }
    }
}
#pragma pop
