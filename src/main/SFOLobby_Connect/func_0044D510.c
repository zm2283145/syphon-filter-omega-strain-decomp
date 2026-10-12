#include "types.h"
typedef struct { char name[0x15]; char id[0x13]; int f28; unsigned char b2c; char pw[0x20]; char pad[3]; } R44D;
typedef struct { char pad[0xFC]; char ffc[0x1C]; char f118[0x134]; int f24c; char pad2[0x213E]; char f238e[0x22]; int f23b0; unsigned char b23b4; char pad3[0x63]; char f2418[0x20]; } O44D;
extern void func_0044F7E0(char*);
extern int func_0044D200(O44D*);
extern int func_0044CBE0(O44D*);
extern int func_004688D8(char*);
extern void func_00451B00(O44D*, int, char*, int);
extern char D_004C0E80[];
extern char D_004C0E78[];
extern void* memset(void*, int, int);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern void* memcpy(void*, const void*, int);
extern void func_004691D8(R44D*);
extern void func_0044C620(O44D*);
extern int func_0044D3D0(O44D*);
int func_0044D510(O44D* o) {
    R44D rec;
    func_0044F7E0(o->ffc);
    func_0044F7E0(o->f118);
    if (!func_0044D200(o)) return 0;
    if (!func_0044CBE0(o)) return 0;
    o->f24c = func_004688D8(o->f2418);
    if (o->f24c) {
        func_00451B00(o, 0x13, D_004C0E80, 0x25);
        return 0;
    }
    if (!o->b23b4 || o->f23b0 == 0x20) {
        memset(&rec, 0, 0x50);
        String_Copy(rec.name, D_004C0E78);
        strncpy(rec.id, o->f2418, 0x11);
        rec.f28 = 0;
        if (!o->f23b0) {
            o->f23b0 = 0x20;
            String_Copy(o->f238e, "*******************************");
        }
        rec.b2c = o->f23b0;
        memcpy(rec.pw, o->f238e, 0x20);
        func_004691D8(&rec);
    }
    func_0044C620(o);
    if (!func_0044D3D0(o)) return 0;
    return 1;
}
