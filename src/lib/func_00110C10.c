extern void *func_001109F0(void *);
extern void func_00110A48(void *);
extern void SleepThread(void);

void func_00110C10(void *q)
{
    void *n;
    for (;;) {
        while ((n = func_001109F0(q)) != 0) func_00110A48(n);
        SleepThread();
    }
}