#include "types.h"

extern void MotionGraph_BuildRunRollForward(void* self);
extern void MotionGraph_BuildRunRollBackLeft(void* self);
extern void MotionGraph_BuildRunRollBackRight(void* self);
extern void MotionGraph_BuildRunRollLeft(void* self);
extern void MotionGraph_BuildRunRollRight(void* self);
extern void MotionGraph_BuildRollBack(void* self);
extern void MotionGraph_BuildLyingDown(void* self);
extern void MotionGraph_BuildHang(void* self);
extern void MotionGraph_BuildLadderAim(void* self);
extern void MotionGraph_BuildLadder(void* self);
extern void MotionGraph_BuildClimbDown(void* self);
extern void MotionGraph_BuildCore(void* self);
extern void MotionGraph_InstallBuddyClimb(void* self);
extern void MotionGraph_BuildCarryBody(void* self);
extern void MotionGraph_BuildJumpFall(void* self);
extern void MotionGraph_BuildDeathLanding(void* self);
extern void MotionGraph_BuildStealthKills(void* self);

/* Runs every registration step on self in order. */
#pragma optimization_level 1
void MotionGraph_RunBuilders(void* self)
{
    MotionGraph_BuildRunRollForward(self);
    MotionGraph_BuildRunRollBackLeft(self);
    MotionGraph_BuildRunRollBackRight(self);
    MotionGraph_BuildRunRollLeft(self);
    MotionGraph_BuildRunRollRight(self);
    MotionGraph_BuildRollBack(self);
    MotionGraph_BuildLyingDown(self);
    MotionGraph_BuildHang(self);
    MotionGraph_BuildLadderAim(self);
    MotionGraph_BuildLadder(self);
    MotionGraph_BuildClimbDown(self);
    MotionGraph_BuildCore(self);
    MotionGraph_InstallBuddyClimb(self);
    MotionGraph_BuildCarryBody(self);
    MotionGraph_BuildJumpFall(self);
    MotionGraph_BuildDeathLanding(self);
    MotionGraph_BuildStealthKills(self);
}
#pragma optimization_level reset
