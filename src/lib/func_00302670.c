#define SCF_LOCK_PAIR(name, fn) int name(void) { fn(2); fn(3); return 0; }
extern void Alloc_Lock(int n);
extern void Alloc_Unlock(int n);
SCF_LOCK_PAIR(func_00302670, Alloc_Unlock)
