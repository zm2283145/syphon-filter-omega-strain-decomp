#ifndef SCRIPT_ARG_H
#define SCRIPT_ARG_H

/*
 * ScriptArg: one 4-byte script-native argument word (Script_* natives take
 * `ScriptArg* args`; args[0].p is usually the object). Superset of the ~230
 * local copies (i/f/p, plus b = unsigned char, c = signed char, u8 as in
 * Objective_types.h). Members only add names; size and alignment stay 4.
 * Plain C or C++; any compiler.
 *
 * Several *_types.h headers also typedef ScriptArg (gobj, GuiGameScreen, hud,
 * loose01, loose02, Objective, scriptManager, scriptUtils, SpecFxDefs). They
 * all honour SCRIPT_ARG_DEFINED, so include script_arg.h FIRST to get the full
 * union; whichever definition comes first wins.
 */
#ifndef SCRIPT_ARG_DEFINED
#define SCRIPT_ARG_DEFINED
typedef union ScriptArg {
    int i;
    float f;
    void* p;
    unsigned char b;
    signed char c;
    unsigned char u8;
} ScriptArg;
#endif

#endif /* SCRIPT_ARG_H */
