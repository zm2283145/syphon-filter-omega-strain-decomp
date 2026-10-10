#include "types.h"

typedef struct PendingEvent {
    char pad00[0x10];
    void* queued; /* 0x10 */
} PendingEvent;

extern char D_0055A0F0[];
extern void func_003E2EE0(PendingEvent** outIt, void* map, int* key);
extern void func_003DFAF0(int* outEnd, void* map);
extern void func_003DFAE0(PendingEvent** out, int* end);
extern void func_003E3160(void* map, PendingEvent** it);
extern void EventQueue_Remove(void* queued);

/* Unschedule(id): removes a pending scheduled event. */
void Script_Unschedule(int id) {
    int key;
    int endRaw;
    PendingEvent* eraseIt;
    PendingEvent* found;
    PendingEvent* end;
    PendingEvent* it;
    key = id;
    func_003E2EE0(&found, D_0055A0F0, &key);
    it = found;
    func_003DFAF0(&endRaw, D_0055A0F0);
    func_003DFAE0(&end, &endRaw);
    if ((it == end) ^ 1) {
        EventQueue_Remove(it->queued);
        eraseIt = it;
        func_003E3160(D_0055A0F0, &eraseIt);
    }

}
