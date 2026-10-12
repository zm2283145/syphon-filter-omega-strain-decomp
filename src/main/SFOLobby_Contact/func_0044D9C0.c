#include "types.h"
typedef struct { char name[0x15]; char id[0x13]; int key; } R44D9;
typedef struct {
    char pad[0x238];
    int f238;
    char p23C[4];
    int f240;
    char p244[8];
    int f24c;
    char pad2[0x21B8];
    unsigned char b2408;
    char p2409[0xF];
    char f2418[0x164];
    int f257c;
} O44D9;
extern void func_00452F70(O44D9*, int, int);
extern void* memset(void*, int, int);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int func_00443E70(void);
extern int func_0046A550(R44D9*, void*);
extern void func_004466F0();
extern void func_00451B00(O44D9*, int, char*, int);
extern int func_004534A0(O44D9*, int, int, int);
extern char D_004C0ED0[];
extern char D_004C0EC0[];
extern int D_00497890;
int func_0044D9C0(O44D9* o, int key) {
    R44D9 rec;
    if (key < 0) {
        func_00451B00(o, 0x29, D_004C0ED0, 0x14C);
        return 1;
    }
    memset(&rec, 0, 0x2C);
    String_Copy(rec.name, D_004C0EC0);
    strncpy(rec.id, o->f2418, 0x11);
    rec.key = key;
    o->f24c = func_0046A550(&rec, func_004466F0);
    if (o->f24c) {
        func_00451B00(o, 1, D_004C0ED0, 0x15A);
        return 0;
    }
    key = func_00443E70();
    o->f238 = 0;
    o->b2408 = 1;
    while (o->f238 == 0) {
        func_00452F70(o, 0, 0);
        if (!func_004534A0(o, key, D_00497890, 0)) {
            o->b2408 = 0;
            func_00451B00(o, 2, D_004C0ED0, 0x16A);
            return 0;
        }
    }
    o->b2408 = 0;
    o->f257c = 0;
    if (!o->f240) {
        func_00451B00(o, 0x29, D_004C0ED0, 0x175);
        return 0;
    }
    func_00451B00(o, 0, D_004C0ED0, 0x17B);
    return 1;
}
