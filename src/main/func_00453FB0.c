#include "loose05_types.h"

extern void func_00438A10(void);
extern void func_00438770(int enabled);

/* Dispatch the lobby notification only while the suppression flag is clear. */
void func_00453FB0(SFOLobby* lobby)
{
    if (!lobby->unk23D5)
        func_00438A10();
}

/* Enable the lobby operation only while the suppression flag is clear. */
void func_00453FE0(SFOLobby* lobby)
{
    if (!lobby->unk23D5)
        func_00438770(1);
}
