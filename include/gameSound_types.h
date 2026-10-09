#ifndef GAMESOUND_TYPES_H
#define GAMESOUND_TYPES_H

/*
 * Types for gameSound.cc: sound script natives and the sound manager
 * receiver (constructor 0x001C9EA0, message handler SoundMgr_OnMessage
 * 0x001C9D00, which forwards voice actions to 0x001C8770).
 */

/* One script-native argument slot (4 bytes). */
typedef union SoundScriptArg {
    int i;
    float f;
    void* p;
    signed char s8;
    unsigned char u8;
} SoundScriptArg;

/* Element of the sound manager's channel pool (432 bytes, 50 of them). */
typedef struct SoundChannel {
    char pad[432];
} SoundChannel;

/* Sound manager receiver. Size at least 0x54B4. */
typedef struct SoundMgr {
    void* vtable;               /* 0x00 */
    char pad04[0x1C];
    unsigned char unk20;        /* 0x20 */
    char pad21[0x0F];
    SoundChannel channels[50];  /* 0x30 */
    char pad5490[0x18];
    int unk54A8;                /* 0x54A8 */
    int unk54AC;                /* 0x54AC */
    int unk54B0;                /* 0x54B0 */
} SoundMgr;

#endif
