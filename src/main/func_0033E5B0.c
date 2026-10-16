#pragma cplusplus on
#include "types.h"
struct Str5B0 { int d[4]; };
struct Nm5B0 { char c[0x20]; };
struct Rest5B0 { int w[11]; };
struct Info5B0 { int id; Nm5B0 name; Rest5B0 rest; };
struct Cfg5B0 { char pad[0xB5]; unsigned char fB5; };
struct O5B0 {
    char pad0[0x88]; Cfg5B0* f88; char pad8C[0xA8 - 0x8C]; int fa8;
    char padAC[0x110 - 0xAC]; int id; Nm5B0 name; Rest5B0 rest;
};
struct Ent5B0 { char pad0[0x24]; int f24; char pad28[0x34 - 0x28]; int f34; int f38; char pad3C[0x134 - 0x3C]; char nm[0x10]; };
struct FE5B0 { char pad0[0x35]; char f35; char pad36[0x188 - 0x36]; char ls[0x24C - 0x188]; int f24C; char pad250[4]; int f254; };
struct Lobby5B0 { char pad0[0x255C]; int f255C; int f2560; };
extern "C" {
extern Lobby5B0* DME_GetLobby(void);
extern void DME_Update(void);
extern FE5B0* D_004FFC04;
extern char D_004B9C60[];
extern char D_004B9C98[];
extern char* D_00533000;
extern unsigned char D_00532FF0;
extern int D_00532FF8;
extern int D_005721A8;
extern char D_004FFBA0;
extern char D_004FFBA1;
extern char D_004FFB50[];
extern char D_004FFC90[];
extern int D_004ACB30[];
extern char* D_0048C160[];
extern char* func_0033CE30(O5B0*, unsigned char, char*, int, int, int);
extern int FrontEnd_OpenPopup(FE5B0*, int, char*, char*, O5B0*, int);
extern void FrontEnd_ClosePopup(FE5B0*, int);
extern void String_CtorCStr_13B480(Str5B0*, const char*);
extern char* String_CStr(void*);
extern void String_Dtor(Str5B0*, int);
extern char* strncpy(char*, const char*, int);
extern char* strchr(const char*, int);
extern int strlen(const char*);
extern Ent5B0* func_0044E060(Lobby5B0*, int);
extern int func_0044E430(Lobby5B0*, int);
extern void func_0044E340(Lobby5B0*);
extern unsigned char func_00452FF0(Lobby5B0*, int);
extern void func_004536B0(Lobby5B0*);
extern void func_0012EE30(char*);
extern void App_GetInstance(void);
extern void App_InitSystemsOnce(void);
extern void LevelSelect_SetLevel(void*, int);
extern unsigned long long Time_GetMilliseconds(void);
extern void func_002CC260(int, int);
extern char* Loc_LookupText(char*);
extern void func_0042B1F0(void);
}
extern "C" void func_0033E5B0(O5B0* o, Info5B0* info, int arg2) {
    Str5B0 a1;
    Str5B0 b1;
    Str5B0 a2;
    Str5B0 b2;
    Str5B0 a3;
    Str5B0 b3;
    Str5B0 a4;
    Str5B0 a5;
    Str5B0 b5;
    char buf[0x10];
    Lobby5B0* lobby;
    int h;
    char* name;
    bool fail;
    Ent5B0* e;
    if (!o->fa8 || !DME_GetLobby()) return;
    lobby = DME_GetLobby();
    {
        FE5B0* g = D_004FFC04;
        h = FrontEnd_OpenPopup(g, 0, D_004B9C60, func_0033CE30(o, 0x15, 0, 0, 0, 0), 0, 0);
    }
    name = 0;
    if (info->rest.w[7] >= 0 && info->rest.w[7] < 9) {
        int lv = D_004ACB30[info->rest.w[7]];
        if (lv != -1) {
            int cur = D_004FFC04->f24C;
            if (cur == -1 || lv == cur) name = D_0048C160[lv];
        }
    }
    if (name && name[0]) {
        strncpy(D_004FFC90, name, 0x80);
    } else {
        String_CtorCStr_13B480(&a1, func_0033CE30(o, 0x66, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b1, func_0033CE30(o, 0x68, info->name.c, 0, 0, 0));
        {
            char* tb = String_CStr(&b1);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a1), tb, 0, 0);
        }
        FrontEnd_ClosePopup(D_004FFC04, h);
        String_Dtor(&b1, 0);
        String_Dtor(&a1, 0);
        return;
    }
    fail = false;
    e = func_0044E060(lobby, info->rest.w[9]);
    if (!e) fail = true;
    if (!fail) {
        int* pk = &e->f34;
        if (e->f38 != info->rest.w[7]) fail = true;
    if (!fail) {
        if (*pk != info->id) {
            if (o->f88 && o->f88->fB5 && e->nm[0]) {
                if (arg2) {
                    char* p = strchr(e->nm, 9);
                    int len = p ? p - e->nm : strlen(e->nm);
                    if (len < 1 || len > 15) fail = true;
                    else strncpy(buf, e->nm, len);
                    if (!fail) {
                        o->id = info->id;
                        o->name = info->name;
                        o->rest.w[0] = info->rest.w[0];
                        o->rest.w[1] = info->rest.w[1];
                        o->rest.w[2] = info->rest.w[2];
                        o->rest.w[3] = info->rest.w[3];
                        o->rest.w[4] = info->rest.w[4];
                        o->rest.w[5] = info->rest.w[5];
                        o->rest.w[6] = info->rest.w[6];
                        o->rest.w[7] = info->rest.w[7];
                        o->rest.w[8] = info->rest.w[8];
                        o->rest.w[9] = info->rest.w[9];
                        o->rest.w[10] = info->rest.w[10];
                        {
                            String_CtorCStr_13B480(&a2, func_0033CE30(o, 0x89, 0, 0, 0, 0));
                            String_CtorCStr_13B480(&b2, func_0033CE30(o, 0x8A, buf, 0, 0, 0));
                            {
                                char* tb = String_CStr(&b2);
                                FrontEnd_OpenPopup(D_004FFC04, 4, String_CStr(&a2), tb, o, 0x1E);
                            }
                            FrontEnd_ClosePopup(D_004FFC04, h);
                            String_Dtor(&b2, 0);
                            String_Dtor(&a2, 0);
                        }
                        return;
                    }
                }
            } else {
                fail = true;
            }
        }
    }
    }
    if (fail) {
        String_CtorCStr_13B480(&a3, func_0033CE30(o, 0x66, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b3, func_0033CE30(o, 0x68, info->name.c, 0, 0, 0));
        {
            char* tb = String_CStr(&b3);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a3), tb, 0, 0);
        }
        FrontEnd_ClosePopup(D_004FFC04, h);
        String_Dtor(&b3, 0);
        String_Dtor(&a3, 0);
        return;
    }
    {
        int n = e->f24;
        int saved;
        void* ls;
        if (n < 1 || n > 4) n = 4;
        D_004FFC04->f254 = n;
        func_0012EE30(D_004FFB50);
        App_GetInstance();
        App_InitSystemsOnce();
        lobby->f2560 = lobby->f255C;
        saved = D_004FFC04->f24C;
        ls = D_004FFC04->ls;
        LevelSelect_SetLevel(ls, D_004ACB30[info->rest.w[7]]);
        if (func_0044E430(lobby, info->rest.w[9])) {
            bool timeout;
            int deadline = (int)Time_GetMilliseconds() + 60000;
            while (!D_00532FF0 && deadline > Time_GetMilliseconds()) {
                func_002CC260(0, 0);
                func_004536B0(lobby);
                DME_Update();
            }
            timeout = false;
            if (!D_00532FF0) timeout = true;
            if (!timeout && (D_00532FF8 != 0) == 1) {
                D_004FFBA1 = D_004FFBA0;
                D_004FFBA0 = 3;
                D_004FFC04->f35 = 1;
            } else {
                char* msg;
                String_CtorCStr_13B480(&a4, func_0033CE30(o, 0x66, 0, 0, 0, 0));
                msg = Loc_LookupText(timeout ? D_004B9C98 : D_00533000);
                FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a4), msg, 0, 0);
                if (timeout) {
                    int s = D_005721A8;
                    D_005721A8 = 0;
                    func_0042B1F0();
                    if (s) D_005721A8 = s;
                } else {
                    func_0042B1F0();
                }
                func_0044E340(lobby);
                lobby->f255C = lobby->f2560;
                LevelSelect_SetLevel(ls, saved);
                String_Dtor(&a4, 0);
            }
        } else {
            int code;
            switch (func_00452FF0(lobby, 0)) {
            case 2: code = 0x6A; break;
            case 0x33: code = 0x6E; break;
            case 0x35: code = 0x6B; break;
            case 0x36: code = 0x6C; break;
            case 0x37: code = 0x6D; break;
            case 0x39: code = 0x76; break;
            default: code = 0x68; break;
            }
            {
                String_CtorCStr_13B480(&a5, func_0033CE30(o, 0x66, 0, 0, 0, 0));
                String_CtorCStr_13B480(&b5, func_0033CE30(o, code, info->name.c, 0, 0, 0));
                {
                    char* tb = String_CStr(&b5);
                    FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a5), tb, 0, 0);
                }
                LevelSelect_SetLevel(ls, saved);
                String_Dtor(&b5, 0);
                String_Dtor(&a5, 0);
            }
        }
    }
    FrontEnd_ClosePopup(D_004FFC04, h);
    D_00532FF0 = 0;
    D_00532FF8 = 0;
    D_00533000 = 0;
}
