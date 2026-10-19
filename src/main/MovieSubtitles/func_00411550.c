/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

extern void Renderer_RefreshCamera(SubtitleEntry* entry);
extern float Renderer_UpdateCameraMatrices(SubtitleOwner* owner);

char* func_00411550(SubtitleOwner* owner) {
    Renderer_UpdateCameraMatrices(owner);
    return owner->unkEC0;
}

/* Updates the current entry and returns its block at +0xA0. */
char* SubtitleOverlay_GetGsOffset(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    Renderer_RefreshCamera(entry);
    return entry->unk0A0;
}

/* Updates the current entry and returns its block at +0x90. */
char* SubtitleOverlay_GetGsScale(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    Renderer_RefreshCamera(entry);
    return entry->unk090;
}
