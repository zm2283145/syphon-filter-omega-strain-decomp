#pragma cplusplus on
#include "types.h"

struct WpnState { int f0; int weaponId; char pad[8]; };
struct cWeapon { void* mAirTaser; WpnState mWpnStates[8];
    int GetSlotWeapon(unsigned char slot) { return mWpnStates[slot].weaponId; }
};
struct tInvItem { int id; int count; };
struct cArray { int f0; int count; tInvItem* data; int fC; tInvItem& operator[](unsigned int n) { return data[n]; } };
struct cInventory { cArray mItems; void* mOwner; };
struct cHuman { char pad[0x4C]; int type; char pad50[0x3524 - 0x50]; cWeapon* mWeapon; cInventory* mInventory; };
struct cPlayer { char pad[0x30]; cHuman* mActor;
    cHuman* GetHuman() { return (mActor && mActor->type == g_HumanActorClassKey) ? mActor : 0; }
    static int g_HumanActorClassKey;
};
struct GuiWeaponDisplay { char pad[0x48]; int mWeapon; };
struct GuiWidget;
struct GuiEquipmentPane { char pad[0x48]; GuiWeaponDisplay* mWeaponDisplay; void* mWeaponDescription; void* mWeaponName; void* mWeaponStats; };

extern "C" {
extern cPlayer* g_LocalPlayer;
extern int g_HumanActorClassKey;
GuiWidget* Gui_Canvas(void);
void GuiWidget_SendMessage(void* to, GuiWidget* from, int msg, int a, int b);
void GuiEquipmentPane_SetWeapon(GuiEquipmentPane* o, cHuman* h, int id);
}

static inline cHuman* GetHuman(cPlayer* p) { cHuman* a = p->mActor; return (a && a->type == g_HumanActorClassKey) ? a : 0; }

extern "C" void GuiEquipmentPane_SelectNext(GuiEquipmentPane* self, int next)
{
    cPlayer* player = g_LocalPlayer;
    GuiWeaponDisplay* disp = self->mWeaponDisplay;
    if (player && GetHuman(player) && disp) {
        int i;
        bool found;
        int j;
        cWeapon& weapon = *GetHuman(player)->mWeapon;
        int equipIds[64];
        int equipNum = -1;
        int numEquipIds;
        for (i = 0, numEquipIds = 0; i < 8; i++) {
            int slotWeapon = weapon.GetSlotWeapon(i);
            if (slotWeapon != -1) {
                found = false;
                for (j = 0; j < numEquipIds; j++) {
                    if (slotWeapon == equipIds[j]) { found = true; break; }
                }
                if (!found) {
                    equipIds[numEquipIds] = slotWeapon;
                    if (equipNum < 0 && slotWeapon == self->mWeaponDisplay->mWeapon) equipNum = numEquipIds;
                    numEquipIds++;
                }
            }
        }
        cInventory* inv = GetHuman(player)->mInventory;
        for (int i = 0; i < inv->mItems.count; i++) {
            if (inv->mItems[i].count > 0) {
                int id = inv->mItems[i].id + 10000;
                equipIds[numEquipIds] = id;
                if (equipNum < 0 && id == self->mWeaponDisplay->mWeapon) equipNum = numEquipIds;
                numEquipIds++;
            }
        }
        if (equipNum < 0 && numEquipIds > 0) equipNum = 0;
        if (equipNum == -1) return;
        equipNum += (unsigned char)next == 0 ? -1 : 1;
        if (equipNum < 0) equipNum = numEquipIds - 1;
        else if (equipNum >= numEquipIds) equipNum = 0;
        if (numEquipIds > 1) GuiWidget_SendMessage(self->mWeaponDisplay, Gui_Canvas(), 16, 0, 0);
        GuiEquipmentPane_SetWeapon(self, GetHuman(player), equipIds[equipNum]);
    }
}
