#pragma cplusplus on

#include "network_session_types.h"

extern "C" {
extern int D_00572510;
extern int D_00572520;
extern unsigned char D_00572530;
extern unsigned char D_00572500;
extern unsigned char D_00572528;
extern int D_00572508;
extern unsigned char D_00533880;
void func_0010D060(int thread, NetworkThreadStatus* status);
void func_0010CFF0(int thread, int priority);
int func_0010E010(int thread);
void func_0010E1C0(int delay);
}

/* Stop the worker and clear its coordination and allocator-locking flags. */
extern "C" void func_0042A680(void)
{
    NetworkThreadStatus worker;
    NetworkThreadStatus current;
    func_0010D060(D_00572510, &worker);
    func_0010D060(D_00572520, &current);
    if (worker.priority <= current.priority)
        func_0010CFF0(D_00572510, 0);
    D_00572530 = 1;
    int thread = func_0010E010(D_00572510);
    func_0010E1C0(10);
    if (thread == D_00572510) {
        while ((D_00572500 != 0) ^ 1)
            func_0010E1C0(10);
    }
    D_00572530 = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    D_00572500 = 0;
    D_00533880 = 0;
}
