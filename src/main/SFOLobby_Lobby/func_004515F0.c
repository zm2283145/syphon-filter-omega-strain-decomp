#include "SFOLobby.h"
/* Sets the lobby mode (which list func_004516E0 refreshes). */
void func_004515F0(SFOLobby* o, int value) {
    if (value != o->mode) o->mode = value;
}
