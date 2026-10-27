/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameOptions.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void GuiGameOptions_OnSaveDone(char* self, char value) {
    self[1025] = value;
}
