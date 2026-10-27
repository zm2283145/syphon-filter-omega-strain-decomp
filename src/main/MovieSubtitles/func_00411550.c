/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

extern void cXViewport_Validate(SubtitleEntry* entry);
extern float XLib_UpdateCompMat(SubtitleOwner* owner);

char* XLib_GetCompMat(SubtitleOwner* owner) {
    XLib_UpdateCompMat(owner);
    return owner->unkEC0;
}

/* Updates the current entry and returns its block at +0xA0. */
char* XLib_GetVPOffset(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    cXViewport_Validate(entry);
    return entry->unk0A0;
}

/* Updates the current entry and returns its block at +0x90. */
char* XLib_GetVPScale(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    cXViewport_Validate(entry);
    return entry->unk090;
}
