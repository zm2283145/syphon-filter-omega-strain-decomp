#include "types.h"

typedef struct SurfE6 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
} SurfE6;

typedef struct SurfOwnerE6 {
    char pad0[3];
    unsigned char kind;
    char pad4[0x28];
    int key;
} SurfOwnerE6;

extern signed char D_004E9F98;
extern int D_004F4FD0;
extern SurfE6 D_004E9FA0;
extern unsigned char D_004E9FA2;
extern void func_00131BC0(void);
extern void __register_global_object(void*, void*, void*);
extern char* func_00183AF0(SurfOwnerE6* owner, int* key);

/* Returns the surface entry for an index, or a static default for old formats. */
typedef struct { SurfOwnerE6* owner; } SurfRefE6;
typedef struct { int pad; SurfRefE6* ref; } SurfCtxE6;
SurfE6* func_001E1DC0(SurfCtxE6* ctx, int index)
{
    int key[1];
    SurfOwnerE6* owner = ctx->ref->owner;
    if (owner->kind < 3) {
        if (D_004E9F98 == 0) {
            D_004E9FA0.a = 0;
            D_004E9FA2 = 0;
            __register_global_object(&D_004E9FA0, func_00131BC0, &D_004F4FD0);
            D_004E9F98 = 1;
        }
        return &D_004E9FA0;
    }
    key[0] = owner->key;
    return (SurfE6*)(func_00183AF0(owner, key) + index * 16);
}