typedef struct {
    unsigned char init;
    char pad[3];
    int count;
    int owner;
} RecursiveLock;

extern int func_00302610(int *);
extern int func_00302578(RecursiveLock *, unsigned char *);

int func_00302308(RecursiveLock *l, int *out)
{
    unsigned char got = 0;
    int self;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = func_00302610(&self);
    if (r != 0) return r;
    if (l->count != 0 && self == l->owner) {
        *out = ++l->count;
    } else {
        r = func_00302578(l, &got);
        if (r != 0) return r;
        if (got == 1) {
            r = func_00302610(&l->owner);
            if (r != 0) return r;
            *out = ++l->count;
        }
    }
    return 0;
}
