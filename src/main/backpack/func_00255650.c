#include "types.h"
typedef struct AmmoPair{int primary[4];int secondary[4];}AmmoPair;
typedef struct AmmoEntry{AmmoPair v;int item,count;}AmmoEntry;
typedef struct AmmoSlot{unsigned char kind;char pad[3];AmmoEntry entries[5];int count;unsigned char active;char padD1[3];}AmmoSlot;
typedef struct BackpackQuery{char pad[0x64];AmmoSlot slots[3];}BackpackQuery;
extern int D_004FFD30;
int WeaponInv_SlotOfItem(int);
unsigned char* WeaponDb_Get(int, int);
static inline int Min(int a, int b) {
    if (b < a) return b;
    return a;
}
int Backpack_RemoveAmmo(BackpackQuery* self, int item, int amount) {
    AmmoSlot* slot;
    AmmoEntry* entry;
    int total;
    unsigned char* w;
    int k;
    int take;
    int i;
    int j;
    int kind;
    kind = WeaponInv_SlotOfItem(item);
    slot = self->slots;
    i = 0;
    goto outer_test;
outer_body:
    if (slot->kind == (unsigned char)kind) {
        entry = slot->entries;
        for (j = 0; j < slot->count; j++, entry++) {
            if (entry->item == item) {
                total = 0;
                w = WeaponDb_Get(D_004FFD30, item);
                for (k = 0; ((amount != 0) ^ 1) == 0 && k < entry->count; k++) {
                    take = Min(entry->v.primary[k], amount);
                    amount -= take;
                    entry->v.primary[k] -= take;
                    total += take;
                    if (w[0xF0] == 1 || w[0xF0] == 7) {
                        if (entry->v.primary[k] == 0) {
                            if (--entry->count == 0) {
                                AmmoEntry* src = &slot->entries[--slot->count];
                                entry->v = src->v;
                                entry->item = src->item;
                                entry->count = src->count;
                                break;
                            }
                        }
                    } else {
                        take = Min(entry->v.secondary[k], amount);
                        amount -= take;
                        total += take;
                        entry->v.secondary[k] -= take;
                    }
                }
                return total;
            }
        }
    }
    i++;
    slot++;
outer_test:
    if (i < 3) goto outer_body;
    return 0;
}



