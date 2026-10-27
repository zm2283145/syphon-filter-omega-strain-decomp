#include "types.h"

typedef struct { int nameHash; int keyHash; char name[0x20]; int unk28; } InvItem; /* size 0x2C */
typedef struct { int unk0; int count; InvItem* data; } InvVector;
extern InvVector D_00587FF0;
char D_004C3358[] = "D_%s"; /* key format */
extern char* Libc_Strcpy(char* dst, const char* src);         /* Libc_Strcpy */
extern int sprintf(char* buf, const char* fmt, ...);      /* sprintf */
extern int nGlobalization_GetStringIndex(const char* s);                        /* string hash */
extern void ItemRegTable_Append(InvVector* v, InvItem* pos, int n, InvItem* value);

/* Registers an inventory item under name (hashes of the id and of its formatted key). */
void cInventory_RegisterItem(const char* id, const char* name)
{
    char key[0x20];
    InvItem item;
    item.unk28 = 0;
    Libc_Strcpy(item.name, name);
    sprintf(key, D_004C3358, id);
    item.nameHash = nGlobalization_GetStringIndex(id);
    item.keyHash = nGlobalization_GetStringIndex(key);
    ItemRegTable_Append(&D_00587FF0, D_00587FF0.data + D_00587FF0.count, 1, &item);
}
