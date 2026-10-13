#pragma cplusplus on
#include "types.h"
struct Mgr_002A8D60 { char pad[0x268]; int f268; };
struct S_002A8D60 { char pad0[0x98]; void* p98; void* p9C; void* pA0; char padA4[0x160 - 0xA4]; void* p160; void* p164; void* p168; };
extern "C" {
extern Mgr_002A8D60* D_004FFC04;
extern char* D_0048BBD8;
extern char* D_0048BBE0;
void func_0033C320(S_002A8D60* self, int a);
int func_0033D8C0(S_002A8D60* self);
void func_0033D8E0(S_002A8D60* self, int a);
void* DME_GetLobby(void);
void func_004515F0(void* g, int a);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void func_0033D800(S_002A8D60* self);
int func_0033DF00(S_002A8D60* self, void* w, int msg, int sub, char* text);
}
extern "C" int func_002A8D60(S_002A8D60* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x1A && sub == 0xB) {
        func_0033C320(self, 1);
        return 1;
    }
    if (m == 2) {
        if (w == self->p164) {
            D_004FFC04->f268 = 2;
            func_0033C320(self, 5);
            return 1;
        }
        if (w == self->p160) {
            if ((unsigned char)func_0033D8C0(self) == 2) {
                char* t;
                func_0033D8E0(self, 0);
                if (DME_GetLobby())
                    func_004515F0(DME_GetLobby(), 1);
                t = Loc_LookupText(D_0048BBD8);
                if (t && self->p160)
                    func_0041BEB0(self->p160, t, 0);
            } else {
                char* t;
                func_0033D8E0(self, 2);
                if (DME_GetLobby())
                    func_004515F0(DME_GetLobby(), 0);
                t = Loc_LookupText(D_0048BBE0);
                if (t && self->p160)
                    func_0041BEB0(self->p160, t, 0);
            }
            return 1;
        }
        if (w == self->p168) {
            func_0033D800(self);
            return 1;
        }
    }
    if (m == 0) {
        if (w == self->p9C)
            func_0033D8E0(self, 2);
        else if (w == self->p98)
            func_0033D8E0(self, 0);
        else if (w == self->pA0)
            func_0033D8E0(self, 2);
        else if (w == self->p164)
            func_0033D8E0(self, 4);
        else if (w == self->p168)
            func_0033D8E0(self, 0);
    }
    return func_0033DF00(self, w, msg, sub, text);
}