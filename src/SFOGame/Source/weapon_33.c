/*
 * SFOGame/Source/weapon: 3 files, 00147630-00147840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147630 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00147630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147630 */

/* merge_units: begin func_00147840 */
#pragma push /* merge_units */
int cWeaponDB_GetEntry(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a1 < 0;
    if (cond) goto L00147860;
    v0 = *(int*)((char*)a0 + 4);
    v0 = *(int*)((char*)v0 + 4);
    v0 = a1 < v0;
    cond = v0 != 0;
    if (cond) goto L00147868;
L00147860:;
    a1 = 0;
L00147868:;
    v0 = *(int*)((char*)a0 + 20);
    v1 = a1 << 2;
    v1 = v1 + a1;
    v1 = v1 << 6;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147840 */

/* merge_units: begin func_00147880 */
#pragma push /* merge_units */
typedef struct { int a[4]; } Q_7880;
typedef struct { char pad[0x2C0]; Q_7880 e[16]; short x3C0; char pad2[0x40C - 0x3C2]; unsigned char count; } T_7880;
typedef struct { char pad[0xCC]; T_7880* t; } S_7880;
static const unsigned int dat_00489CE0[8] = { 0xFF0000, 0x1, 0x401FF06, 0xFF020404, 0x2010105, 0x3030202, 0xFFFF0105, 0xFF };
extern int D_0055DE90;
Q_7880* cWeaponDB_GetShellCasing(S_7880* self, int id)
{
    signed char k;
    T_7880* t;
    if (id < 0)
        return 0;
    k = ((signed char*)dat_00489CE0)[id];
    if (k < 0)
        return 0;
    t = self->t;
    if (t) {
        if (!(k < t->count))
            return 0;
        D_0055DE90 = t->x3C0;
        return &t->e[k];
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147880 */
