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
extern int cArray_Record_PushBackActual(void* v, Obj_147400* value);
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
