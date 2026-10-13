#ifndef MOTIONMANAGER_TYPES_H
#define MOTIONMANAGER_TYPES_H

/*
 * Motion manager (motionManager.cc): a single heap-allocated tree/map
 * object (0x10 bytes) held in g_MotionManager.
 */

typedef struct MotionManager {
    int unk0;                   /* 0x00 */
    void* root;                 /* 0x04 tree root (NULL when empty) */
    char pad08[8];
} MotionManager;                /* size 0x10 */

#endif