#ifndef CALL_GLOBAL_HOOK_H
#define CALL_GLOBAL_HOOK_H

/*
 * Call the function pointer stored in D_00485E80 (built with tail calls
 * off, so the call keeps its own frame). Plain C.
 */
extern void (*D_00485E80)(void);

#define DEFINE_CALL_GLOBAL_HOOK(name) \
    void name(void) { D_00485E80(); }

#endif /* CALL_GLOBAL_HOOK_H */