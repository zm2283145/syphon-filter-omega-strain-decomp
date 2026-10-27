/*
 * SFOGame/Source/weapon: 2 files, 00147400-00147600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147400 */
#pragma push /* merge_units */
#include "types.h"
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
