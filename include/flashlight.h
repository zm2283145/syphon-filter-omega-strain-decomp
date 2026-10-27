#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

/*
 * The player's flashlight (flashlight.cc), a 0x1C-byte object at actor
 * +0x33EC, built for actor roles 1 and 3. See research FLASHLIGHT.md.
 * Plain C layout, usable from MW C and C++ units.
 */
typedef struct Flashlight {
    unsigned char on;     /* +0x00 only this byte is cleared by the constructor */
    char pad01[3];        /* +0x01 */
    void *owner;          /* +0x04 owner actor */
    void *beamLight;      /* +0x08 point-pool light (type 4) while on */
    void *glareLight;     /* +0x0C point-pool light (type 0x40, the corona) while on */
    float beamLength;     /* +0x10 smoothed beam length; <= 0 means unset (-1.0 at construction) */
    float beamSpeed;      /* +0x14 beam length speed */
    void *litSpot;        /* +0x18 0x60-byte world object at the beam's end point */
} Flashlight; /* 0x1C */

#define FLASHLIGHT_LITSPOT_ID_CATEGORY 0xE7 /* nGobjManager_GetNextId category of the lit spot */

#endif /* FLASHLIGHT_H */
