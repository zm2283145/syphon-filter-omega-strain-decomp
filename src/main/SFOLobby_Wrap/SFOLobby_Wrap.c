/*
 * main/SFOLobby_Wrap: 6 files, 00443EA0-00444020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00443EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void func_00443EA0(void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, "SFOLobby_Wrap.cc", 0x3A);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00443EA0 */

/* merge_units: begin func_00443F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);                      
int memset(int, int, int);                              
extern char D_004C0B20;
extern unsigned char D_00533880;
}
extern "C" int func_00443F40(int arg0) {
    int temp_s1;

    if (arg0 <= 0) {
        return 0;
    }
    {
        AllocGuard g;
    temp_s1 = Mem_Alloc(0, arg0, &D_004C0B20, 0x1D);
    }
    if (temp_s1 == 0) {
        return 0;
    }
    memset(temp_s1, 0, arg0);
    return temp_s1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00443F40 */

/* merge_units: begin func_00444020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Wrap.cc (ends 0x00443F40) and SFOLobby_Account.cc;
 * lobby flag accessors.
 */


extern unsigned char D_00584240;
extern char D_00584241;
extern char D_005842C8;
extern char D_005842CC[];
extern int func_002EBC48(void* obj);

int func_00444020(int value) {
    D_005842C8 = value;
    return func_002EBC48(D_005842CC);
}

void func_00444040(int value) {
    D_00584241 = value;
}

void func_00444050(int value) {
    D_00584240 = value;
}

int func_00444060(void) {
    return D_00584240;
}
#pragma pop /* merge_units */
/* merge_units: end func_00444020 */

/* merge_units: begin func_00444070 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off

extern "C" {
#if 0 /* merge_units */
void* memset(void*, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((void *)memset((int)(a0), (a1), (int)(a2))) /* merge_units */

void String_Copy(char*, const char*);
int func_002CF2C0(char*, void*);
int func_002CF5E0(void);
#if 0 /* merge_units */
void func_002EBC48(int*);
#endif /* merge_units */
#define func_002EBC48(a0) ((void)func_002EBC48((void *)(a0))) /* merge_units */


int func_004446E0(int);
void SFOLobby_CallUpdateHook(char*, int, int);
void func_00445230(void);
extern unsigned char D_00584231;
extern unsigned char D_00584237;
extern int D_00584528;
extern char* D_00585E60;
extern char D_004C0B38[];
}

static inline bool Poll(void) {
    int now = 0;
    func_002EBC48(&now);
    if (now - D_00584528 > 30000) return false;
    SFOLobby_CallUpdateHook(D_00585E60, 0, 0);
    return true;
}

static inline int Busy(void) {
    int r = func_002CF5E0();
    if (r) return r;
    return 0;
}

extern "C" int func_00444070(int arg) {
    if (!D_00584231) return 0;
    if (arg) {
        char buf[0x15];
        memset(buf, 0, sizeof(buf));
        String_Copy(buf, D_004C0B38);
        if (func_002CF2C0(buf, (void*)func_00445230) == 0) {
            D_00584528 = 0;
            func_002EBC48(&D_00584528);
            SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
            while (D_00584237 == 0) {
                if (!Poll()) break;
                if (func_004446E0(0)) break;
            }
        }
    }
    if (Busy()) return -12;
    D_00584231 = 0;
    return 0;
}
#undef memset /* merge_units */
#undef func_002EBC48 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444070 */

/* merge_units: begin func_004441D0 */
#pragma push /* merge_units */
typedef struct B48 { int w[12]; } B48;
typedef struct P8 { int a; int b; } P8;
typedef struct P64 { P8 p[8]; } P64;
typedef struct S17 { char c[17]; } S17;
typedef struct Info {
    int id;          /* 0x00 */
    B48 blk;         /* 0x04 */
    int f34;         /* 0x34 */
    P64 pairs;     /* 0x38 */
    S17 s1;          /* 0x78 */
    S17 s2;          /* 0x89 */
} Info;
typedef struct Req {
    int id;
    B48 blk;
    int f34;
    P64 pairs;
    S17 s1;
    S17 s2;
    int f9C;
} Req;
extern Info D_005842DC;
extern short D_0058438E;
extern short D_00584390;
extern char D_00584378[];
int func_00444FF0(int, int, int, int);
int func_00444EC0(void);
int func_002D0850(void*);
int func_004449C0(int, int, int, int);
int func_002CF420(Req*, int*);
void func_002EBCE0(void*);
void func_002D0560(void*);
int MGCLUpdate(void);
#if 0 /* merge_units */
void memset(void*, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((void)memset((int)(a0), (a1), (a2))) /* merge_units */



static inline int Inner_4441D0(Req* req, int* out, char* buf138) {
    int ret;
    if (D_005842DC.blk.w[0] != 0) {
        req->id = D_005842DC.id;
        req->blk = D_005842DC.blk;
        req->f34 = D_005842DC.f34;
        req->pairs = D_005842DC.pairs;
        req->s1 = D_005842DC.s1;
        req->s2 = D_005842DC.s2;
        req->f9C = 0;
    } else {
        return -12;
    }
    ret = func_002CF420(req, out);
    if (ret != 0) return ret;
    D_00584390 = 0;
    D_0058438E = 1;
    func_002EBCE0(buf138);
    func_002D0560(D_00584378);
    ret = MGCLUpdate();
    if (ret != 0) return ret;
    return 0;
}

int func_004441D0(int a0, int a1, int a2, int a3) {
    int out;
    char buf138[4];
    char bufF0[0x48];
    Req req;

    if (!(unsigned char)func_00444FF0(1, 4, 1, 0)) return -12;
    if (func_00444EC0() != 0) return -12;
    if (func_002D0850(bufF0) != 0) return -12;
    if (func_004449C0(a0, a1, a2, a3) != 0) return -12;
    memset(&req, 0, sizeof(req));
    memset(&out, 0, 4);
    return Inner_4441D0(&req, &out, buf138) != 0 ? -12 : 0;
}
#undef memset /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004441D0 */

/* merge_units: begin func_00444460 */
#pragma push /* merge_units */
typedef struct Req444 {
    char kind[0x15];
    char name[0x40];
    char data[0x18];
    char pad6D[0x155 - 0x6D];
    char str[0x178 - 0x155];
    int a;          /* 0x178 */
    int b;          /* 0x17C */
    int c;          /* 0x180 */
    int d;          /* 0x184 */
    int e;          /* 0x188 */
    int f;          /* 0x18C */
    int g;          /* 0x190 */
    int h;          /* 0x194 */
    int i;          /* 0x198 */
    int j;          /* 0x19C */
    char pad1A0[0x1D0 - 0x1A0];
    int one;        /* 0x1D0 */
} Req444;
#if 0 /* merge_units */
extern void* memset(void* d, int c, unsigned int n);
#endif /* merge_units */
#define memset(a0, a1, a2) ((void *)memset((int)(a0), (a1), (int)(a2))) /* merge_units */


extern void* memcpy(void* d, const void* s, unsigned int n);
#if 0 /* merge_units */
extern void String_Copy(char* d, const char* s);
#endif /* merge_units */
#define String_Copy(a0, a1) (String_Copy((a0), (a1))) /* merge_units */


extern int func_002D0A38(Req444* r, void* cb);
#if 0 /* merge_units */
extern void func_002EBC48(int* t);
#endif /* merge_units */
#define func_002EBC48(a0) ((void)func_002EBC48((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int func_004446E0(int x);
#endif /* merge_units */
#define func_004446E0(a0) (func_004446E0((a0))) /* merge_units */


#if 0 /* merge_units */
extern void SFOLobby_CallUpdateHook(int h, int a, int b);
#endif /* merge_units */
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((char *)(a0), (a1), (a2))) /* merge_units */


extern void func_004446A0(void);
extern char D_00584398[];
extern char D_005843B4[];
extern int D_0058423C;
extern int D_005844F4;
extern int D_005844F8;
extern int D_005844FC;
#if 0 /* merge_units */
extern int D_00585E60;
#endif /* merge_units */
#define D_00585E60 (*(int*)&D_00585E60) /* merge_units */


static inline unsigned char Poll444(void) {
    int now = 0;
    func_002EBC48(&now);
    if (now - D_00584528 > 30000) return 0;
    SFOLobby_CallUpdateHook(D_00585E60, 0, 0);
    return 1;
}
int func_00444460(const char* name, const void* data, const char* str, int a, int b, int c, int d, int e,
                  int f, int g, int h, int i, int j) {
    Req444 req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.kind, D_004C0B38);
    String_Copy(req.name, name);
    memcpy(req.data, data, 0x18);
    String_Copy(req.str, str);
    req.one = 1;
    req.f = f;
    req.a = a;
    req.g = g;
    req.h = h;
    req.i = i;
    req.j = j;
    req.e = e;
    req.b = b;
    req.c = c;
    req.d = d;
    memset(D_00584398, 0, 0x180);
    D_005844F4 = c;
    D_005844F8 = b;
    D_005844FC = d;
    String_Copy(D_005843B4, name);
    D_0058423C = 0;
    if (func_002D0A38(&req, func_004446A0)) return 0;
    D_00584528 = 0;
    func_002EBC48(&D_00584528);
    SFOLobby_CallUpdateHook(D_00585E60, 2, 1);
    while (!D_0058423C) {
        if (!Poll444()) return 0;
        if (func_004446E0(0)) return 0;
    }
    return D_0058423C == 1;
}
#undef memset /* merge_units */
#undef String_Copy /* merge_units */
#undef func_002EBC48 /* merge_units */
#undef func_004446E0 /* merge_units */
#undef SFOLobby_CallUpdateHook /* merge_units */
#undef D_00585E60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00444460 */
