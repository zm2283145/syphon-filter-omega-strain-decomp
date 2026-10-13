#pragma cplusplus on
#include "types.h"
struct L45CFB0 { char p[0x14]; unsigned short flags; };
struct W45CFB0 { char p[0x50]; L45CFB0* label; unsigned char b54, b55; char p56[2]; char m58[0xC]; unsigned char b64; };
extern "C" {
void* String_CStr(void* s);
void func_0041BEB0(L45CFB0* l, void* s, int z);
void func_0041E0F0(void* w, void* src, int kind, int a, int b);
}
#pragma push
extern "C" void func_0045CFB0(W45CFB0* w, int a)
{
    if (w->label) {
        if (a) w->b55 = 0;
        else {
            w->b54 = 0;
            if (w->b55) {
                func_0041BEB0(w->label, String_CStr(w->m58), 0);
                func_0041E0F0(w->label, w->label, 10, w->b64, 0);
            }
        }
        bool on = w->b55 || w->b54; L45CFB0* l = w->label; if ((unsigned char)on) l->flags |= 2; else l->flags &= ~2;
    }
}
#pragma pop
