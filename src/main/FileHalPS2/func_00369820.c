/*
 * Matched functions (byte-identical with the retail executable).
 * FileHalPS2.cc: PS2 file HAL handle construction.
 */

#include "types.h"
#include "FileHalPS2_types.h"

extern FileHalFile* D_00533860;
extern int func_00369050(FileHalFile* file, int a1, int a2);

/* Construct a closed handle, then initialise it from (a1, a2). */
FileHalFile* func_00369820(FileHalFile* file, int a1, int a2) {
    file->handle = -1;
    file->unk28 = 0;
    file->unkC4 = 0;
    file->unk41 = 0;
    file->unk40 = 0;
    file->unk3C = 0;
    func_00369050(file, a1, a2);
    return file;
}

/* Default constructor: closed handle with cleared state. */
FileHalFile* func_00369870(FileHalFile* file) {
    file->handle = -1;
    file->unk28 = 0;
    file->unkC4 = 0;
    file->unk41 = 0;
    file->unk40 = 0;
    file->unk3C = 0;
    return file;
}

/* Store the global file HAL pointer. */
void func_003698A0(FileHalFile* file) {
    D_00533860 = file;
}
