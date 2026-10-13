#ifndef CALL_WITH_GLOBAL_ARG_H
#define CALL_WITH_GLOBAL_ARG_H

/*
 * Library wrapper (EE-GCC 2.96 -G0): tail-call WaitSema with the
 * global D_00518A04. Plain C.
 */
extern int D_00518A04;
extern int WaitSema(int x);

#define DEFINE_CALL_WITH_GLOBAL_ARG(name) \
    int name(void) { return WaitSema(D_00518A04); }

#endif /* CALL_WITH_GLOBAL_ARG_H */