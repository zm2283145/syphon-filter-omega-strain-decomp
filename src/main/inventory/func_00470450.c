#include "types.h"

typedef struct { int nameHash; int keyHash; char name[0x20]; int unk28; } InvItem; /* size 0x2C */
typedef struct { int unk0; int count; InvItem* data; } InvVector;
extern InvVector D_00587FF0;
extern char D_004C3358[]; /* key format */
extern char* String_Copy(char* dst, const char* src);         /* String_Copy */
extern int sprintf(char* buf, const char* fmt, ...);      /* sprintf */
extern int Loc_FindKeyThunk(const char* s);                        /* string hash */
extern void func_00471290(InvVector* v, InvItem* pos, int n, InvItem* value);

/* Registers an inventory item under name (hashes of the id and of its formatted key). */
void Global_cInventory__RegisterItem(const char* id, const char* name)
{
    char key[0x20];
    InvItem item;
    item.unk28 = 0;
    String_Copy(item.name, name);
    sprintf(key, D_004C3358, id);
    item.nameHash = Loc_FindKeyThunk(id);
    item.keyHash = Loc_FindKeyThunk(key);
    func_00471290(&D_00587FF0, D_00587FF0.data + D_00587FF0.count, 1, &item);
}
