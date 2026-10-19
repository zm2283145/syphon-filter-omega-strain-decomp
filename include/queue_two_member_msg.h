#ifndef QUEUE_TWO_MEMBER_MSG_H
#define QUEUE_TWO_MEMBER_MSG_H

/*
 * Script command that builds a stack message (whose payload members at
 * +0x78 and +0x114 are destroyed by FileMan_Release) with ctor(&msg, arg),
 * queues a clone of it when networking is active (D_005721D0), and destroys
 * it again. D_005723C8 is a re-entrancy flag set for the duration.
 * Returns 0x30. msgSize is the message size (stack frame layout).
 */
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char g_Game[];
extern void MsgQueue_QueueClone(void* msg, void* queue, int a, int b);
extern void FileMan_Release(void* member, int flags);
extern void cMessage_dtor(void* self, int flags);

#define DEFINE_QUEUE_TWO_MEMBER_MSG(name, msgSize, ctor, vtableSym)          \
    extern char vtableSym[];                                                  \
    typedef struct name##_Msg {                                               \
        void* vtable;                                                         \
        char pad04[0x74];                                                     \
        char memberA[0x9C];                                                   \
        char memberB[(msgSize) - 0x114];                                      \
    } name##_Msg;                                                             \
    extern void ctor(name##_Msg* msg, void* arg);                             \
    int name(int a0, int a1, int a2, void* arg)                               \
    {                                                                         \
        name##_Msg msg;                                                       \
        if (!D_005723C8)                                                      \
            D_005723C8 = 1;                                                   \
        if (D_005721D0) {                                                     \
            ctor(&msg, arg);                                                  \
            MsgQueue_QueueClone(&msg, g_Game, 0, 0);                      \
            msg.vtable = vtableSym;                                           \
            FileMan_Release(msg.memberB, -1);                                   \
            FileMan_Release(msg.memberA, -1);                                   \
            cMessage_dtor(&msg, 0);                                           \
        }                                                                     \
        D_005723C8 = 0;                                                       \
        return 0x30;                                                          \
    }

#endif /* QUEUE_TWO_MEMBER_MSG_H */