#ifndef PARTICLE_TYPES_H
#define PARTICLE_TYPES_H

/* Types for the particle directory. Layouts are provisional. */

/* Particle emitter (update routine 0x003A2400). */
typedef struct ParticleEmitter {
    char pad00[0x1C];
    int active;                 /* 0x1C: nonzero while alive */
    char pad20[0x30];
    float time;                 /* 0x50: accumulated time */
    float rate;                 /* 0x54 */
    float rateScale;            /* 0x58 */
    float unk5C;                /* 0x5C */
    float unk60;                /* 0x60 */
    float unk64;                /* 0x64 */
    unsigned char pending;      /* 0x68 */
    unsigned char unk69;        /* 0x69 */
} ParticleEmitter;

/* Object with a table of 4-byte slots starting at +4, indexed by a byte. */
typedef struct ParticleSlotTable {
    int unk00;                  /* 0x00 */
    int slots[256];             /* 0x04 */
} ParticleSlotTable;

/* Three zeroed words followed by a flag (constructor 0x003983E0). */
typedef struct ParticleRelFlag {
    Rel rel;                    /* 0x00 */
    unsigned char flag;         /* 0x0C */
} ParticleRelFlag;

/* Wrapper whose real system object is at +8. */
typedef struct ParticleHandle {
    char pad00[0x08];
    void* system;               /* 0x08 */
} ParticleHandle;

/* Object with fields read at +0x100 and +0x120. */
typedef struct ParticleObj {
    char pad000[0x100];
    int unk100;                 /* 0x100 */
    char pad104[0x1C];
    int unk120;                 /* 0x120 */
} ParticleObj;

#endif
