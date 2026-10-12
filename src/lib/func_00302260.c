typedef struct {
    unsigned char init;
    char pad[3];
    int count;
    int owner;
} RecursiveLock;

extern int func_00302610(int *);
extern int func_00302548(RecursiveLock *);

int RecursiveLock_Acquire(RecursiveLock *l, int *out)
{
    int self;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    r = func_00302610(&self);
    if (r != 0) return r;
    if (l->count != 0 && self == l->owner) {
        l->count++;
    } else {
        r = func_00302548(l);
        if (r != 0) return r;
        r = func_00302610(&l->owner);
        if (r != 0) return r;
        l->count++;
    }
    if (out != 0) *out = l->count;
    return 0;
}
