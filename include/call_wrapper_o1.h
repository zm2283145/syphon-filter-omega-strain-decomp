#ifndef CALL_WRAPPER_O1_H
#define CALL_WRAPPER_O1_H

/*
 * Unoptimised wrappers that only call one function (arguments untouched).
 * Compile the member between #pragma optimization_level 1 / reset.
 */
#define DEFINE_CALL_WRAPPER(name, callee)                                     \
    void callee(void);                                                        \
    void name(void)                                                           \
    {                                                                         \
        callee();                                                             \
    }

#endif /* CALL_WRAPPER_O1_H */