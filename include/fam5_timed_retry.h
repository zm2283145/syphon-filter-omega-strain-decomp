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
extern char D_004FFB50[];
extern int Service_Lookup(char*, int);
extern int SoundMgr_IsQuipPlaying(int, int);
extern void VoiceQueue_Fire(char*);
extern int func_00461220(char*, int);
extern int func_00461240(char*);
extern int func_00461250(void);

#define DEFINE_TIMED_RETRY(name, idxOff, subOff, baseUpdate)                         \
    void name(char* self, float dt)                                                  \
    {                                                                                \
        int svc = Service_Lookup(D_004FFB50, func_00461250());                       \
        int idx = *(int*)(self + (idxOff));                                          \
        if (idx < func_00461240(self + (subOff))) {                                  \
            if (idx == 0 || !SoundMgr_IsQuipPlaying(svc, func_00461220(self + (subOff), idx - 1))) { \
                float t = *(float*)(self + (subOff) + 0x10) - dt;                    \
                *(float*)(self + (subOff) + 0x10) = t;                               \
                if (t < 0.0f) VoiceQueue_Fire(self + (subOff));                        \
            }                                                                        \
        }                                                                            \
        baseUpdate(self, dt);                                                        \
    }
#endif