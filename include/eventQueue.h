#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

/*
 * Timed event queue (callback.cc). Events live in an intrusive list
 * (g_EventQueue); EventQueue_Pump counts each event's timer down and runs and
 * destroys the expired ones. C++ only (#pragma cplusplus on before including).
 */

struct EQBase {
    int timeMs;                 /* 0x00: time left until the event fires */
    unsigned char useClockB;    /* 0x04: count down with Pump's second delta */
    unsigned char runOnClear;   /* 0x05: EventQueue_ClearAll still runs it */
    char pad6[2];
};

/* Queued event; the vtable pointer follows the base members (0x08). */
struct EQEvent : EQBase {
    virtual ~EQEvent();
    virtual void v0();
    virtual void run();
};

/* Predicate for ActiveList_EraseMatching: matches the node holding *pp. */
struct EQCmp {};
struct EQPred {
    EQCmp cmp;
    EQEvent** pp;
    EQPred(const EQCmp& c, EQEvent** p) : cmp(c), pp(p) {}
};

struct EQNode { EQNode* prev; EQNode* next; EQEvent* ev; };
struct EQPos { EQNode* p; };    /* list iterator */

#endif