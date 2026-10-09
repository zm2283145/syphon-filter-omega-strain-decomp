/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

extern void func_00374DF0(SubtitleEntry* entry);
extern float func_0037D9A0(SubtitleOwner* owner);

char* func_00411550(SubtitleOwner* owner) {
    func_0037D9A0(owner);
    return owner->unkEC0;
}

/* Updates the current entry and returns its block at +0xA0. */
char* func_00411580(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    func_00374DF0(entry);
    return entry->unk0A0;
}

/* Updates the current entry and returns its block at +0x90. */
char* func_004115C0(SubtitleOwner* owner) {
    SubtitleEntry* entry = &owner->entries[owner->current];
    func_00374DF0(entry);
    return entry->unk090;
}
