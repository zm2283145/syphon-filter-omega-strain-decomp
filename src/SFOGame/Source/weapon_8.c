/*
 * SFOGame/Source/weapon: 5 files, 00147110-00147400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147110 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* x0; int x4; void* x8; } S_7110;
extern void* g_WeaponDatabase;
extern void WeaponDb_OnModelLoaded(void* db, int a, void* b, int c);
void cWeaponDB_GunStreamReturn(S_7110* self, int a, int flag)
{
    if (flag) {
        void* b = self->x8;
        int c = self->x4;
        b = b ? b : self->x0;
        WeaponDb_OnModelLoaded(g_WeaponDatabase, a, b, c);
    }
}
static inline void merge_flush_func_00147110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147110 */

/* merge_units: begin func_00147150 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strlen(const char *);

#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
extern char D_0049B1D0[];
extern char D_0049B308[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
char* strrchr(const char* s, int c);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(void* h, char* name, int x, int f);
int cFileMan_Open(void* h);
int cWeaponDB_GetShellCasing(void* self, int x);
void gunList_LoadGunInit(void* o, char* name, int idx, int x, int a, int b, int c, int d);
void WeaponDb_CloneModel(void* self, char* name, void* o);
int GetFileStreamMan(void);
void cFileStreamMan_StreamRequest(int q, void* h, void* cb, void* o, int a, int b, int c);
#if 0 /* merge_units */
void cWeaponDB_GunStreamReturn(void);
#endif /* merge_units */

}
inline void* operator new(unsigned int, void* p) { return p; }
struct E7150 { E7150() {} char pad[0x20]; };
struct V7150 { float x, y, z, w; };
struct O7150 {
    char pad0[0x140];
    E7150 e[12];
    char pad2C0[0x3E0 - 0x2C0];
    V7150 mn;
    V7150 mx;
    char pad400[0x20];
    O7150() {
        mn.x = 3.4028235e38f; mn.y = 3.4028235e38f; mn.z = 3.4028235e38f; mn.w = 1.0f;
        mx.x = -3.4028235e38f; mx.y = -3.4028235e38f; mx.z = -3.4028235e38f; mx.w = 1.0f;
    }
};
struct R7150 { char pad[0x10C]; int x10C; char pad110[0x140 - 0x110]; };
struct S7150 { char pad0[0x14]; R7150* recs; char pad18[4]; char hog[0xB4 - 0x1C]; int xB4; };
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, n, D_0049B1D0, line);
}
extern "C" void cWeaponDB_LoadGun(S7150* self, char* name, O7150** out, int idx, int a, int b, int c)
{
    char buf[0x100];
    char* p;
    int x;
    *out = 0;
    Libc_Strcpy(buf, name);
    p = strrchr(buf, '.');
    if (!p) p = &buf[strlen(buf)];
    Libc_Strcpy(p, D_0049B308);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(self->hog, buf, self->xB4, 1);
    if ((unsigned char)cFileMan_Open(self->hog)) return;
    x = 0;
    if (idx >= 0) x = cWeaponDB_GetShellCasing(self, ((R7150*)((char*)self->recs + idx * 0x140))->x10C);
    {
        *out = new (SD_Alloc(sizeof(O7150), 0x153)) O7150;
    }
    gunList_LoadGunInit(*out, buf, idx, x, a, 1, b, c);
    WeaponDb_CloneModel(self, buf, *out);
    cFileStreamMan_StreamRequest(GetFileStreamMan(), self->hog, (void*)cWeaponDB_GunStreamReturn, *out, 0, 1, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00147150 */

/* merge_units: begin func_00147390 */
#pragma push /* merge_units */
extern void cWeaponDB_UnloadLevelSpecific(void* self);
#if 0 /* merge_units */
extern void cFileMan_dtor(void* p, int flag);
#endif /* merge_units */
void* cFileMan_dtor(void* entry, int flags); /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

extern void cDB_dtor(void* self, int flag);
extern void operator_delete(void* p);
void* cWeaponDB_dtor(char* self, short flag)
{
    if (self) {
        cWeaponDB_UnloadLevelSpecific(self);
        cFileMan_dtor(self + 0x1C, -1);
        cDB_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00147390(void) {}
#undef cFileMan_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147390 */

/* merge_units: begin func_00147400 */
#pragma push /* merge_units */
#include "fileman_entry.h"

typedef struct { void* buffer; int unk4; int index; int unkC; char pad[4]; int unk14; } Obj_147400;

typedef struct {
    char pad00[0x64];
    int dmg[3];
    char pad70[0xBC - 0x70];
    unsigned char dmgType;
    char padBD[0x11C - 0xBD];
    int x11C;
    char pad120[0x130 - 0x120];
    int x130;
    int x134;
    unsigned char x138;
    char pad139[3];
    int x13C;
} WeaponRec_147400;

typedef struct { int magic; int count; } WdbHdr_147400;

typedef struct {
    int pad0;
    WdbHdr_147400* hdr;
    char* data;
    int padC;
    int pad10;
    WeaponRec_147400* recs;
    unsigned char loaded;
} WeaponDb_147400;

extern int sprintf(char* buf, const char* fmt, ...);
extern unsigned char cDB_LoadDB(WeaponDb_147400* db, void* entry);
extern Obj_147400* cAgentData_Record_ctor_int_int(Obj_147400* self, int a, int b);
#if 0 /* merge_units */
extern int cArray_Record_PushBackActual(void* v, Obj_147400* value);
#endif /* merge_units */
int cArray_Record_PushBackActual(); /* merge_units */


extern char D_0049B310[];
extern char D_0048B2F8[];
extern int D_004926E0;
extern char g_UnlockRows[];

unsigned char cWeaponDB_LoadOnce(WeaponDb_147400* db)
{
    char path[0x80];
    FileManEntry e;
    Obj_147400 tmp;
    int i;
    unsigned char r;

    sprintf(path, D_0049B310, D_0048B2F8);
    cFileMan_ctor_charP_cFileIOP_bool(&e, path, 0, 0);
    db->loaded = cDB_LoadDB(db, &e);
    db->recs = (WeaponRec_147400*)(db->data + 0x10);
    if (db->hdr->magic != 4) {
        cFileMan_dtor(&e, -1);
        return 0;
    }
    if (db->loaded) {
        for (i = 0; i < db->hdr->count; i++) {
            cArray_Record_PushBackActual(g_UnlockRows, cAgentData_Record_ctor_int_int(&tmp, i, D_004926E0++));
            db->recs[i].x138 = 0;
            db->recs[i].x130 = -1;
            db->recs[i].x134 = -1;
            db->recs[i].x13C = 0;
            db->recs[i].x11C = 0;
            if (db->recs[i].dmgType == 1) {
                db->recs[i].dmg[0] /= 5;
                db->recs[i].dmg[1] /= 5;
                db->recs[i].dmg[2] /= 5;
            }
        }
    }
    r = db->loaded;
    cFileMan_dtor(&e, -1);
    return r;
}
static inline void merge_flush_func_00147400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147400 */

/* merge_units: begin func_00147600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "weapon_types.h"

extern int std_vector_imp_Record_insert(WeaponRec24Vec* v, WeaponRec24* pos, int n, WeaponRec24* value);

/* push_back on a vector of 24-byte elements. */
int cArray_Record_PushBackActual(WeaponRec24Vec* v, WeaponRec24* value) {
    return std_vector_imp_Record_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00147600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147600 */
