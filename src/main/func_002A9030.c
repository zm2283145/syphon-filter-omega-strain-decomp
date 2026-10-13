#pragma cplusplus on
#include "types.h"
struct VObj2A { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct Lobby2A { char p[0x255C]; int state; };
struct Sub2A { char p[0xB4]; unsigned char flag; };
struct W2A9030 { char p[0x80]; unsigned char done; char p81[7]; Sub2A* sub; char p8c[0x20]; char mAC[0x1C]; char mC8[0x1C]; char mE4[0x7C]; VObj2A* label; };
extern "C" {
extern char* D_0048BBC8;
extern char* D_0048BBD0;
extern char* D_0048BBD8;
extern char D_004A7520[];
extern char D_004AB6B8[];
extern char D_004FFB50[];
extern char* D_004FFC04;
void func_002CC260();
Lobby2A* func_004294C0(void);
void func_004426B0(Lobby2A*);
int func_004518F0(Lobby2A*, void (*)(), void*, void*, void*);
int func_0033CE30(W2A9030*, int, int, int, int, int);
void func_002CAE30(char*, int, char*, int, W2A9030*, int);
VObj2A* func_0041DB80(W2A9030*, char*);
void func_0041BEB0(VObj2A*, char*, int);
char* Agent_GetSelected(void*, int);
void func_0033D8E0(W2A9030*, int);
void func_004515F0(Lobby2A*, int);
char* Loc_LookupText(char*);
}


extern "C" void func_002A9030(W2A9030* self)
{
    if (!self->done) {
        Lobby2A* l = func_004294C0();
        VObj2A* o;
        char* s;
        if (l) {
            if (l->state == 4) func_004426B0(l);
            if (!func_004518F0(l, func_002CC260, self->mAC, self->mC8, self->mE4)) {
                char* g = D_004FFC04;
                func_002CAE30(g, 2, D_004AB6B8, func_0033CE30(self, 0x5A, 0, 0, 0, 0), self, 0xB);
            }
        }
        o = func_0041DB80(self, D_0048BBD0);
        o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
        if (o) func_0041BEB0(o, D_004FFC04 + 0x1C8, 0);
        o = func_0041DB80(self, D_0048BBC8);
        o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
        if (o) func_0041BEB0(o, Agent_GetSelected(D_004FFB50, -1) + 0x95C, 0);
        func_0033D8E0(self, 0);
        if (func_004294C0()) func_004515F0(func_004294C0(), 1);
        s = Loc_LookupText(D_0048BBD8);
        if (s && self->label) func_0041BEB0(self->label, s, 0);
        if (self->sub) self->sub->flag = 0;
        self->done = 1;
    }
}