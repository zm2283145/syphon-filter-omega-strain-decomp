#pragma cplusplus on
#include "types.h"

struct L_451050 { char p0[0x24C]; int f24C; char p250[0x23EC - 0x250]; int f23EC; char p23F0[0x2418 - 0x23F0]; char host[0x68]; int f2480; };

extern "C" {
void* memset(void*, int, unsigned int);
int strlen(const char*);
char* strncpy(char*, const char*, int);
int sprintf(char*, const char*, ...);
void String_Copy(char*, const char*);
int func_00469990(void*, void*);
int func_0046A378(void*);
void func_00447BB0(void);
void func_00451B00(L_451050*, int, char*, int);
extern char D_004C0F68[];
extern char D_004C0F70[];
extern char D_004C0F98[];
}

struct ConnReq_451050 {
    char proto[0x15];
    char host[0x13];
    int port;
    char name[0x40];
};

struct JoinReq_451050 {
    char proto[0x15];
    char host[0x13];
    int flag;
    int id;
    char name[0x40];
};

extern "C" int func_00451050(L_451050* self, char* name, int id) {
    ConnReq_451050 req;
    JoinReq_451050 join;

    if (self->f23EC == 0) {
        func_00451B00(self, 0x24, D_004C0F70, 0x187);
        return 0;
    }
    if (!name || !strlen(name)) return 0;
    strlen(name);
    memset(&req, 0, sizeof(req));
    req.port = 1;
    sprintf(req.proto, D_004C0F98, id);
    strncpy(req.host, self->host, 0x11);
    strncpy(req.name, name, 0x40);
    self->f24C = func_00469990(&req, (void*)func_00447BB0);
    if (self->f24C != 0) {
        func_00451B00(self, 1, D_004C0F70, 0x19E);
        return 0;
    }
    if (id != self->f2480) {
        memset(&join, 0, sizeof(join));
        String_Copy(join.proto, D_004C0F68);
        strncpy(join.host, self->host, 0x11);
        strncpy(join.name, name, 0x40);
        { enum { OFF, ON } e = id == 0 ? OFF : ON; join.flag = e; }
        join.id = id;
        self->f24C = func_0046A378(&join);
        if (self->f24C != 0) {
            func_00451B00(self, 1, D_004C0F70, 0x1B1);
            return 0;
        }
    }
    return 1;
}
