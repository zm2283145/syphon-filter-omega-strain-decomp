/*
 * Libs/SFOLobby/SFOLobby/SFO_MGCL: 1 file, 004446A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004446A0 */
#pragma push /* merge_units */
#include "SFOLobby_Callback_types.h"

extern int D_0058423C;
unsigned int D_004976D8[2] = { 0xFFFFFFFF, 0x0 };

/* Publish the callback's value on success, or mark the operation as failed. */
void Callback_MGCLCreateGameOnMeRequest(int unused0, int unused1, int unused2, LobbyStatusResult* result)
{
    if (!result->status) {
        (*(int*)D_004976D8) = result->value;
        D_0058423C = 1;
    } else {
        D_0058423C = -1;
    }
}
static inline void merge_flush_func_004446A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004446A0 */
