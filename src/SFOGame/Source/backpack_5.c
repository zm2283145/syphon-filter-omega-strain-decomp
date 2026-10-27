/*
 * SFOGame/Source/backpack: 3 files, 00255290-002553E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00255290 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x2F0]; unsigned char b2f0; } P255;
extern int g_WeaponDatabase;
extern int g_Hud;
extern char D_004A7B18[];
#if 0 /* merge_units */
extern int cBackpack_GetWeaponDbs(P255*, int*, int, int);
#endif /* merge_units */
int cBackpack_GetWeaponDbs(); /* merge_units */

#if 0 /* merge_units */
extern void cBackpack_GetAmmoCounts(P255*, int, int*, int*, int*);
#endif /* merge_units */
void cBackpack_GetAmmoCounts(); /* merge_units */

extern char* cWeaponDB_GetEntry(int, int);
extern int cWeapon_PickupAmmo_tWDBDataP_int(int, char*, int);
extern char* nGlobalization_GetString_charP(char*);
extern void cBackpack_TakeAmmo(P255*, int, int);
extern int sprintf(char*, const char*, ...);
extern void cHud_Message(int, char*);
unsigned char cBackpack_AutoTakeAmmo(P255* p, int arg) {
    int x[1];
    int y[1];
    int z[1];
    int ids[10];
    char buf[0x80];
    unsigned char any = 0;
    if (p->b2f0) {
        int db = g_WeaponDatabase;
        int n = cBackpack_GetWeaponDbs(p, ids, arg, 10);
        int i;
        for (i = 0; i < n; i++) {
            char* w;
            int amt;
            cBackpack_GetAmmoCounts(p, ids[i], x, y, z);
            w = cWeaponDB_GetEntry(db, ids[i]);
            amt = cWeapon_PickupAmmo_tWDBDataP_int(arg, w, z[0]);
            if (amt) {
                char* nm = nGlobalization_GetString_charP(w + 0x80);
                cBackpack_TakeAmmo(p, ids[i], amt);
                sprintf(buf, D_004A7B18, nm, nGlobalization_GetString_charP("PickupAmmo"));
                cHud_Message(g_Hud, buf);
                any = 1;
            }
        }
    }
    return any;
}
static inline void merge_flush_func_00255290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00255290 */

/* merge_units: begin func_002553E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cWeapon_GetWeaponSlot(int);                             

int cBackpack_GetWeaponDbs(int self, int *output, char * table) {
    char *slot;
    int count;
    int deferred;
    int index;
    int item;
    int fallback;

    slot = (char *)(self + 0x64);
    count = 0;
    deferred = -1;
    index = 0;
    do {
        if (F_(slot, 0xCC, int) != 0) {
            item = F_(slot, 0x24, int);
            if ((cWeapon_GetWeaponSlot(item) & 0xFF) == 6) {
                deferred = item;
            } else {
                *output = item;
                output += 1;
                count += 1;
            }
        } else if (F_(slot, 0xD0, unsigned char) != 0) {
            fallback = F_((table + (F_(slot, 0x0, unsigned char) * 0x10)), 0x8, int);
            if (fallback != -1) {
                *output = fallback;
                count += 1;
                output += 1;
            }
        }
        index += 1;
        slot += 0xD4;
    } while (index < 3);
    if (deferred >= 0) {
        if (count != 0) {
            if (deferred != F_(table, 0x68, int)) {
                goto append_deferred;
            }
        } else {
append_deferred:
            *output = deferred;
            count += 1;
        }
    }
    return count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002553E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002553E0 */

/* merge_units: begin func_00255500 */
#pragma push /* merge_units */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
typedef struct AmmoEntry{int primary[4];int secondary[4];int item,count;}AmmoEntry;
typedef struct AmmoSlot{unsigned char kind;char pad[3];AmmoEntry entries[5];int count;unsigned char active;char padD1[3];}AmmoSlot;
typedef struct BackpackQuery{char pad[0x64];AmmoSlot slots[3];}BackpackQuery;
void cBackpack_GetAmmoCounts(BackpackQuery*self,int item,int*lastPrimary,int*lastSecondary,int*total){
 AmmoSlot*slot;int i;AmmoEntry*entry;int j;int k;int kind;
 kind=cWeapon_GetWeaponSlot(item);slot=self->slots;i=0;kind=(unsigned char)kind;goto outer_test;
 outer_body:
 if(slot->kind==kind){entry=slot->entries;for(j=0;j<slot->count;j++,entry++){
  if(entry->item==item){*total=0;*lastPrimary=entry->primary[entry->count-1];*lastSecondary=entry->secondary[entry->count-1];k=0;if(k<entry->count){int*p=entry->primary;do{*total+=p[0];if(kind!=4)*total+=p[4];k++;p++;}while(k<entry->count);}}
 }}
 i++;slot++;
 outer_test:if(i<3)goto outer_body;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255500 */
