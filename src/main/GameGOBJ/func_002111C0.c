#include "script_arg.h"

typedef struct { char pad[0xDC]; unsigned char busy; } MoverGS;
typedef enum { MOVER_GS_IDLE0, MOVER_GS_IDLE1 } MoverGSState;

/* The enum-typed inline result keeps MW's movz select (a plain int/bool folds to sltu/xori). */
static inline MoverGSState MoverGS_State(MoverGS* m) { return m->busy ? MOVER_GS_IDLE0 : MOVER_GS_IDLE1; }

unsigned char Script_Mover_GetState(ScriptArg* args)
{
    return MoverGS_State((MoverGS*)args[0].p);
}
