#include "types.h"
typedef struct Msg_002C9510 { void* vt; char pad4[0x2C]; } Msg_002C9510;
typedef struct PStr_002C9510 { unsigned char len; char s[0x80]; } PStr_002C9510;
typedef struct Self_002C9510 {
    char pad0[0x28]; unsigned char b28; char pad29[0xE]; unsigned char b37; unsigned char b38;
    char pad39[0x30C - 0x39]; int f30C;
} Self_002C9510;
typedef struct G_002C9510 { char pad[0x2409]; unsigned char b2409; } G_002C9510;
typedef struct W_002C9510 { char pad[0x278]; unsigned char b278; } W_002C9510;
extern char D_00571DC0[];
extern char D_0055A700[];
extern unsigned char D_0051EF68;
extern char D_004FFC90[];
extern char D_004FFB50[];
extern char D_004F2CC0[];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
extern int D_004FFD30;
extern char D_005381F0[];
void func_00412ED0(void* p);
W_002C9510* func_001698C0(void);
void func_003D1730(void* p);
G_002C9510* func_004294C0(void);
void func_0042A770(void);
int func_004147A0(void);
void func_0041E0F0(int a, int b, int c, int d, int e);
char* strncpy(char* d, const char* s, int n);
void* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void func_002C9AF0(Self_002C9510* self, int v);
void func_0042A680(void);
void func_00165950(W_002C9510* w);
void func_002C9EE0(Self_002C9510* self);
void func_00145160(int a);
void func_002CCA40(int a, int b, int c);
void func_0037A9F0(void* p);
void func_002C9510(Self_002C9510* self)
{
    if (self->b37) {
        func_00412ED0(D_00571DC0);
        func_001698C0()->b278 = 0;
        func_003D1730(D_0055A700);
        switch (self->b38) {
        case 0: {
            unsigned char had = 0;
            G_002C9510* g = func_004294C0();
            void* svc;
            int a;
            PStr_002C9510 buf;
            Msg_002C9510 m1;
            Msg_002C9510 m2;
            if (g) {
                had = 1;
                func_0042A770();
                if (D_0051EF68)
                    g->b2409 = 0;
            }
            D_0051EF68 = 0;
            a = func_004147A0();
            func_0041E0F0(a, func_004147A0(), 0x10, 5, 0);
            {
                char* d = buf.s;
                const char* s = D_004FFC90;
                int n = 0;
                while ((*d++ = *s++) != 0) {
                    if (++n >= 0x7E) {
                        n++;
                        *d = '\n';
                        d[1] = 0;
                        break;
                    }
                }
                buf.len = n;
            }
            strncpy(D_004FFC90, "FRONTEND", 0x80);
            svc = Service_Lookup(D_004FFB50, D_004F2CC0);
            Event_Construct(&m1, D_004F5370);
            m1.vt = D_004DE220;
            Event_Send(&m1, svc, 1);
            m1.vt = D_004DE220;
            cMessage_dtor(&m1, 0);
            Event_Construct(&m2, D_004F5378);
            m2.vt = D_004DE200;
            Event_Send(&m2, svc, 1);
            m2.vt = D_004DE200;
            cMessage_dtor(&m2, 0);
            strncpy(D_004FFC90, buf.s, 0x80);
            {
                unsigned char o = *(unsigned char*)&self->f30C;
                self->f30C = 0xFF;
                func_002C9AF0(self, o);
            }
            if (had)
                func_0042A680();
            break;
        }
        case 1:
            func_00165950(func_001698C0());
            break;
        }
        func_002C9EE0(self);
        func_00145160(D_004FFD30);
        func_002CCA40(0x2003, 0, 0);
        self->b37 = 0;
        self->b28 = 1;
        func_0037A9F0(D_005381F0);
    }
}