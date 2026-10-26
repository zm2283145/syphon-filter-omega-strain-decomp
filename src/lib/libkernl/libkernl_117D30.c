#include "types.h"
extern void func_0011BB00(float);
void TimerFreq2BusClock(float hz)
{
    func_0011BB00(147456000.0f / hz);
    __asm__ __volatile__("");
}