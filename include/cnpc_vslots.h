#ifndef CNPC_VSLOTS_H
#define CNPC_VSLOTS_H

/*
 * ScriptNpc: virtual-call view of the script-facing cNPC object (args[0].p
 * of the Script_cNPC_* natives, ~94 src files under npc/ and elsewhere).
 * C++ only (#pragma cplusplus on before including). No data members and no
 * defined virtuals, so no vtable is emitted; derive to add fields
 * (struct MyNpc : ScriptNpc { char pad4[0x2C]; int f30; };  vptr is +0).
 * Slot n sits at vtable offset 8 + 4*n (+0/+4 are the MW RTTI words).
 * Unnamed slots are _vNN padding.
 *
 * Signatures are the ones observed in matched callers. Parameter types only
 * matter for codegen when a variable (not a constant) is passed: e.g.
 * SetMode's 2nd arg is void* here but some callers pass an int flag, and
 * uchar/bool params force a zero-extension. If a target disagrees, keep a
 * local class for that file.
 * Not the same class as the actor object (NpcOwner+0x30) whose slot 62
 * (+0x100) is Damage(float, cNPC*, int...) - see npc/cNPC_SetUnconscious.c.
 */
#ifndef __cplusplus
#error "cnpc_vslots.h needs #pragma cplusplus on"
#endif

struct ScriptNpc {
    virtual void _v00(); virtual void _v01(); virtual void _v02(); virtual void _v03(); virtual void _v04(); virtual void _v05();
    virtual void _v06(); virtual void _v07(); virtual void _v08(); virtual void _v09(); virtual void _v0A(); virtual void _v0B();
    virtual void _v0C(); virtual void _v0D(); virtual void _v0E(); virtual void _v0F();
    virtual void Activate(); /* 16 +0x48 */
    virtual void Deactivate(); /* 17 +0x4C */
    virtual void _v12(); virtual void _v13(); virtual void _v14(); virtual void _v15(); virtual void _v16(); virtual void _v17();
    virtual void _v18(); virtual void _v19(); virtual void _v1A(); virtual void _v1B(); virtual void _v1C(); virtual void _v1D();
    virtual void _v1E(); virtual void _v1F(); virtual void _v20(); virtual void _v21(); virtual void _v22(); virtual void _v23();
    virtual void _v24(); virtual void _v25(); virtual void _v26(); virtual void _v27(); virtual void _v28(); virtual void _v29();
    virtual void _v2A(); virtual void _v2B(); virtual void _v2C(); virtual void _v2D();
    virtual void DeactivateForAllPlayers(); /* 46 +0xC0 */
    virtual void _v2F(); virtual void _v30(); virtual void _v31(); virtual void _v32(); virtual void _v33(); virtual void _v34();
    virtual void SetMode(unsigned char mode, void* arg); /* 53 +0xDC */
    virtual void ResumeAIMode(); /* 54 +0xE0 */
    virtual void AddAwareness(void* target); /* 55 +0xE4 */
    virtual void RemoveAwareness(void* target); /* 56 +0xE8 */
    virtual void AddAwarenessOfPlayers(); /* 57 +0xEC */
    virtual void* GetClosestPlayer(); /* 58 +0xF0 */
    virtual void ResendNewAwarenessMessage(void* target); /* 59 +0xF4 */
    virtual void SendNewAwarenessOfPlayers(); /* 60 +0xF8 */
    virtual void Follow(void* target, float minDist, float maxDist); /* 61 +0xFC */
    virtual unsigned char MoveToNode(void* node); /* 62 +0x100 */
    virtual unsigned char MoveToGobj(void* target); /* 63 +0x104 */
    virtual unsigned char CarryBodyToNode(void* body, void* node); /* 64 +0x108 */
    virtual void Teleport(void* node); /* 65 +0x10C */
    virtual void SetAggressiveness(float value); /* 66 +0x110 */
    virtual void SetAimMode(unsigned char mode); /* 67 +0x114 */
    virtual void SetAimSubtarget(signed char sub); /* 68 +0x118 */
    virtual void ResumeAIAiming(); /* 69 +0x11C */
    virtual void _v46(); virtual void _v47();
    virtual void RequestLookAt(void* target, float time, int priority); /* 72 +0x128 */
    virtual void RequestFacial(void* target, float time, int priority); /* 73 +0x12C */
    virtual void _v4A();
    virtual void LookAround(int priority); /* 75 +0x134 */
    virtual void StopAndLookAround(int priority); /* 76 +0x138 */
    virtual void ResumeAILookAt(int priority); /* 77 +0x13C */
    virtual void SetTravelSpeed(float value); /* 78 +0x140 */
    virtual void ResumeAITravelSpeed(); /* 79 +0x144 */
    virtual float GetTravelSpeed(unsigned char mode); /* 80 +0x148 */
    virtual void _v51();
    virtual void RequestAction(unsigned char action, int priority); /* 82 +0x150 */
    virtual void StopMovement(float time, int priority); /* 83 +0x154 */
    virtual void ResumeMovement(); /* 84 +0x158 */
    virtual void SetDesiredDistance(float minDist, float maxDist, int priority); /* 85 +0x15C */
    virtual void DeactivateDead(int value); /* 86 +0x160 */
    virtual void _v57();
    virtual void Kill(); /* 88 +0x168 */
    virtual float SetFiringThreshold(float value); /* 89 +0x16C */
    virtual int GetHitPoints(); /* 90 +0x170 */
    virtual void SetHitPoints(int value); /* 91 +0x174 */
    virtual void CheckHotbox(void* hotbox); /* 92 +0x178 */
    virtual void SetOnFire(float duration); /* 93 +0x17C */
    virtual void SetViewConeRadius(float value); /* 94 +0x180 */
    virtual void SetViewConeAngle(float value); /* 95 +0x184 */
    virtual unsigned char InViewCone(void* target); /* 96 +0x188 */
    virtual void* GetCurrentNode(); /* 97 +0x18C */
    virtual void* GetNextNode(); /* 98 +0x190 */
    virtual void* GetDestinationNode(); /* 99 +0x194 */
    virtual void ForceWeaponFire(int count, float delay, int flag); /* 100 +0x198 */
    virtual void SetGrenadeTarget(void* target, float time, int flag); /* 101 +0x19C */
    virtual void SetGrenadeThrowAngle(float value); /* 102 +0x1A0 */
    virtual int GetActiveWeapon(); /* 103 +0x1A4 */
    virtual void StoreWeapon(); /* 104 +0x1A8 */
    virtual void DrawWeapon(int value); /* 105 +0x1AC */
    virtual void ChangeWeapon(); /* 106 +0x1B0 */
    virtual void DropWeapon(); /* 107 +0x1B4 */
    virtual void AddWeapon(int weapon); /* 108 +0x1B8 */
    virtual void RemoveWeapon(int weapon); /* 109 +0x1BC */
    virtual int GetWeapon(unsigned char slot); /* 110 +0x1C0 */
    virtual void SetWeaponPreference(int weapon, unsigned char flag); /* 111 +0x1C4 */
    virtual void SetWeaponPreferenceDistance(float value); /* 112 +0x1C8 */
    virtual void ActivateByRadius(float radius); /* 113 +0x1CC */
    virtual void ActivateByRadiusOff(); /* 114 +0x1D0 */
    virtual void SetPickupable(bool on, int flag); /* 115 +0x1D4 */
    virtual void SetHasDisguise(int on, int flag); /* 116 +0x1D8 */
    virtual void SetDarkness(int value); /* 117 +0x1DC */
    virtual int GetDarkness(); /* 118 +0x1E0 */
    virtual float GetAimPercent(); /* 119 +0x1E4 */
    virtual void SetInvulnerable(int on, int flag); /* 120 +0x1E8 */
    virtual void RequestDeathAnimation(int value); /* 121 +0x1EC */
    virtual void EquipGoggles(int on); /* 122 +0x1F0 */
    virtual void RestrictMovementToNodeGroup(void* group); /* 123 +0x1F4 */
    virtual void AddGroupToPathRegion(void* group); /* 124 +0x1F8 */
    virtual void RemoveGroupFromPathRegion(void* group); /* 125 +0x1FC */
    virtual void DontDropWeapons(); /* 126 +0x200 */
    virtual void SetFireInvulnerability(bool on); /* 127 +0x204 */
    virtual void SetUnconscious(); /* 128 +0x208 */
    virtual void SetNotTaserable(int value); /* 129 +0x20C */
    virtual void SetNotGasable(bool on); /* 130 +0x210 */
    virtual void SetNotTargetable(int value); /* 131 +0x214 */
    virtual void AddItem(int item, int count); /* 132 +0x218 */
    virtual void RemoveItem(int item, int count); /* 133 +0x21C */
    virtual int GetItemCount(int item); /* 134 +0x220 */
};

#endif /* CNPC_VSLOTS_H */
