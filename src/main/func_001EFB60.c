#include "types.h"

extern void BuildAnimationBlend_RollBack(void* self);
extern void BuildAnimationBlend_RunRollBackLeft(void* self);
extern void BuildAnimationBlend_RunRollBackRght(void* self);
extern void BuildAnimationBlend_RunRollLeft(void* self);
extern void BuildAnimationBlend_RunRollRght(void* self);
extern void BuildAnimationBlend_RunRollForw(void* self);
extern void BuildAnimationBlend_Crawl(void* self);
extern void BuildAnimationBlend_Hang(void* self);
extern void BuildAnimationBlend_LadderWeaponAim(void* self);
extern void BuildAnimationBlend_LadderClimb(void* self);
extern void BuildAnimationBlend_Climbs(void* self);
extern void BuildAnimationBlend_CoreMotions(void* self);
extern void BuildAnimations_BuddyClimb(void* self);
extern void BuildAnimations_CarryBody(void* self);
extern void BuildAnimations_JumpFallLand(void* self);
extern void BuildAnimations_BodyLand(void* self);
extern void BuildAnimations_NeckSnap(void* self);

/* Runs every registration step on self in order. */
#pragma optimization_level 1
void nHumanAnimData_BuildAnimations(void* self)
{
    BuildAnimationBlend_RollBack(self);
    BuildAnimationBlend_RunRollBackLeft(self);
    BuildAnimationBlend_RunRollBackRght(self);
    BuildAnimationBlend_RunRollLeft(self);
    BuildAnimationBlend_RunRollRght(self);
    BuildAnimationBlend_RunRollForw(self);
    BuildAnimationBlend_Crawl(self);
    BuildAnimationBlend_Hang(self);
    BuildAnimationBlend_LadderWeaponAim(self);
    BuildAnimationBlend_LadderClimb(self);
    BuildAnimationBlend_Climbs(self);
    BuildAnimationBlend_CoreMotions(self);
    BuildAnimations_BuddyClimb(self);
    BuildAnimations_CarryBody(self);
    BuildAnimations_JumpFallLand(self);
    BuildAnimations_BodyLand(self);
    BuildAnimations_NeckSnap(self);
}
#pragma optimization_level reset
