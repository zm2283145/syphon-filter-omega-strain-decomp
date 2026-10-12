#include "types.h"

typedef struct { int w[0x1340 / 4]; } __attribute__((aligned(16))) NetCfg_44BAB0;
typedef struct {
    char hdr[0x80];
    NetCfg_44BAB0 cfg;
} NetProfile_44BAB0;
typedef struct {
    char pad0[0x180];
    int f180;
    char pad184[0x1F7C - 0x184];
    char user[0x80];
    char pass[0x84];
    char user2[0x80];
    char pass2[0x84];
    unsigned char f2184;
    char pad2185[0x23B0 - 0x2185];
    int f23B0;
    unsigned char f23B4;
    char pad23B5[0x23D8 - 0x23B5];
    int f23D8;
    int f23DC;
} NetConn_44BAB0;
typedef struct {
    char a[0x80];
    char b[0x84];
    char c[0x210 - 0x104];
} AuthMsg_44BAB0;

extern NetCfg_44BAB0 D_005849C0;
extern int D_00585CCC;
extern char D_004C0D70[];
extern char D_004C0E40[];
extern char D_004C0E60[];
extern void String_Copy(char* d, const char* s);
extern void func_0010D3E0(int);
extern int func_003A6700(int);
extern int func_00442C20(NetConn_44BAB0*, char*, char*);
extern int func_0044B7A0(NetConn_44BAB0*);
extern int func_0044C760(NetConn_44BAB0*);
extern int func_0044CD20(NetConn_44BAB0*);
extern NetProfile_44BAB0* func_0044F290(int, int);
extern void func_0044F470(int, AuthMsg_44BAB0*);
extern void func_00451B00(NetConn_44BAB0*, int, char*, int);
extern void func_00452C70(NetConn_44BAB0*, int);
extern int func_00452CD0(NetConn_44BAB0*);
extern void func_00452F70(NetConn_44BAB0*, int, int);
extern void* memset(void*, int, unsigned int);
int func_0044BDE0(NetConn_44BAB0*, NetCfg_44BAB0*);
void func_0044BFF0(NetConn_44BAB0*);

/* hand-written quad copy loop (retail uses addi) */
static inline void QuadCopy_44BAB0(void* d0, const void* s0, int n0) {
    int n = n0;
    __int128 t;
    const void* src = s0;
    void* dst = d0;
    asm {
        .set noreorder
    loop:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -1
        addiu src, src, 0x10
        bgtz n, loop
        sq t, -0x10(dst)
        .set reorder
    }
}

int func_0044BAB0(NetConn_44BAB0* self, int id, unsigned char flag) {
    NetProfile_44BAB0* prof;
    AuthMsg_44BAB0 msg;

    func_00452F70(self, 2, 1);
    self->f23B4 = flag;
    self->f23B0 = 0;
    prof = func_0044F290(self->f23D8, id);
    if (prof == 0) {
        func_00451B00(self, 0x34, D_004C0D70, 0x1B8);
        return 0;
    }
    func_0010D3E0(0);
    QuadCopy_44BAB0(&D_005849C0, &prof->cfg, sizeof(NetCfg_44BAB0) / 16);
    func_0010D3E0(0);
    if (D_00585CCC == 3) {
        if (func_003A6700(D_00585CCC) == 0) {
            func_00451B00(self, 0xE, D_004C0D70, 0x1D0);
            return 0;
        }
    } else if (D_00585CCC == 1) {
        if (func_003A6700(D_00585CCC) == 0) {
            func_00451B00(self, 0xE, D_004C0D70, 0x1D9);
            return 0;
        }
    } else if (D_00585CCC == 2) {
        func_00451B00(self, 4, D_004C0D70, 0x1E1);
        return 0;
    } else {
        func_00451B00(self, 4, D_004C0D70, 0x1E7);
        return 0;
    }
    if (func_0044BDE0(self, &D_005849C0) == 0) {
        func_0044BFF0(self);
        return 0;
    }
    if (func_00452CD0(self) == 0) {
        func_0044BFF0(self);
        return 0;
    }
    if (self->f23B4 != 0 && func_0044B7A0(self) == 0) {
        func_00452C70(self, 1);
        func_0044BFF0(self);
        return 0;
    }
    if (self->f2184 != 0) {
        if (func_00442C20(self, self->user, self->pass) == 0) {
            func_00452C70(self, 1);
            func_0044BFF0(self);
            return 0;
        }
        memset(&msg, 0, sizeof(msg));
        String_Copy(msg.a, D_004C0E40);
        String_Copy(msg.b, self->user);
        String_Copy(msg.c, D_004C0E60);
        func_0044F470(self->f23DC, &msg);
    } else {
        if (func_00442C20(self, self->user2, self->pass2) == 0) {
            func_00452C70(self, 1);
            func_0044BFF0(self);
            return 0;
        }
        if (func_0044C760(self) == 0) {
            func_00452C70(self, 1);
            func_0044BFF0(self);
            return 0;
        }
        if (func_0044CD20(self) == 0) {
            func_00452C70(self, 1);
            func_0044BFF0(self);
            return 0;
        }
        self->f180 = -1;
    }
    func_00451B00(self, 0, D_004C0D70, 0x233);
    return 1;
}




