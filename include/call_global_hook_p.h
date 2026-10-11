#ifndef CALL_GLOBAL_HOOK_P_H
#define CALL_GLOBAL_HOOK_P_H

/*
 * Call the function pointer stored in hookSym (see call_global_hook.h),
 * with the hook variable as a parameter. Plain C.
 */
#define DEFINE_CALL_GLOBAL_HOOK_P(name, hookSym) \
    extern void (*hookSym)(void);                \
    void name(void) { hookSym(); }

#endif /* CALL_GLOBAL_HOOK_P_H */