#ifndef FAM5_TIMED_RETRY_H
#define FAM5_TIMED_RETRY_H
/*
 * Per-frame retry timer on a sub-object: if the current step index is below
 * the sub-object's count and the previous step is not yet resolved by the
 * service, count the timer down and fire the sub-object's expiry handler,
 * then run the owner's base update.
 *   DEFINE_TIMED_RETRY(name, idxOff, subOff, baseUpdate)
 * The timer float sits at subOff + 0x10. Declare baseUpdate before use.
 */
extern char g_Game[];
extern int cSystemContainer_GetSystem(char*, int);
extern int cGameSound_IsVAGPlaying(int, int);
extern void cQuipList_NextQuip(char*);
extern int cArray_tQuip_opIndex(char*, int);
extern int func_00461240(char*);
extern int func_00461250(void);

#define DEFINE_TIMED_RETRY(name, idxOff, subOff, baseUpdate)                         \
    void name(char* self, float dt)                                                  \
    {                                                                                \
        int svc = cSystemContainer_GetSystem(g_Game, func_00461250());                       \
        int idx = *(int*)(self + (idxOff));                                          \
        if (idx < func_00461240(self + (subOff))) {                                  \
            if (idx == 0 || !cGameSound_IsVAGPlaying(svc, cArray_tQuip_opIndex(self + (subOff), idx - 1))) { \
                float t = *(float*)(self + (subOff) + 0x10) - dt;                    \
                *(float*)(self + (subOff) + 0x10) = t;                               \
                if (t < 0.0f) cQuipList_NextQuip(self + (subOff));                        \
            }                                                                        \
        }                                                                            \
        baseUpdate(self, dt);                                                        \
    }
#endif