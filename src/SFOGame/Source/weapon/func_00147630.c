#include "types.h"
#pragma mpwc_relax on
int Alloc_Lock();
int EnableIntc();
int cDB_LoadDB();
int cMemMan_Deallocate(int, void*, char*, int);
int cFileMan_dtor();
int cFileMan_ctor_charP_cFileIOP_bool();
int sprintf();
void* memcpy(void*, const void*, unsigned int);
extern char D_0048B2F8;
extern char D_0049B1D0;
extern char D_0049B310;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

typedef struct {
    char p0[0x64];
    int a64, a68, a6C;
    char p70[0xBC - 0x70];
    unsigned char kind;
    char pBD[0xD8 - 0xBD];
    int d8;
    char pDC[0x11C - 0xDC];
    int x11C;
    char p120[0x130 - 0x120];
    int x130, x134;
    unsigned char b138, b139;
    char p13A[2];
    int x13C;
} WEnt;

typedef struct {
    int pad;
    int count;
} WHdr;

typedef struct {
    int pad0;
    WHdr* hdr;
    char* data;
    int size;
    char p10[8];
    unsigned char loaded;
} WDb;


void cWeaponDB_Reload(WDb* db) {
    int spE0[36];
    int sp40[40];

    WEnt* src;
    WEnt* dst;
    int i;
    char* p;
    char* old;

    old = db->data;
    src = (WEnt*)(old + 0x10);
    sprintf(spE0, &D_0049B310, &D_0048B2F8);
    cFileMan_ctor_charP_cFileIOP_bool(sp40, spE0, 0, 0);
    db->loaded = cDB_LoadDB(db, sp40);
    for (i = 0, dst = (WEnt*)(db->data + 0x10); i < db->hdr->count; i++, src++, dst++) {
        dst->x13C = src->x13C;
        dst->x11C = src->x11C;
        dst->x134 = src->x134;
        dst->d8 = src->d8;
        dst->b138 = src->b138;
        dst->b139 = src->b139;
        dst->x130 = src->x130;
        if (dst->kind == 1) {
            dst->a64 /= 5;
            dst->a68 /= 5;
            dst->a6C /= 5;
        }
    }
    memcpy(old, db->data, db->size);
    p = db->data;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    cMemMan_Deallocate(0, p, &D_0049B1D0, 0x10B);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    db->data = old;
    db->hdr = (WHdr*)db->data;
    cFileMan_dtor(sp40, -1);
}
