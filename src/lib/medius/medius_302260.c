/*
 * lib/medius: 2 files, 00302260-00302308
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00302260 */
typedef struct {
    unsigned char init;
    char pad[3];
    int count;
    int owner;
} RecursiveLock;

extern int rt_mutex_platform_get_thread_id(int *);
extern int rt_mutex_platform_lock(RecursiveLock *);

int rt_mutex_lock(RecursiveLock *l, int *out)
{
    int self;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    r = rt_mutex_platform_get_thread_id(&self);
    if (r != 0) return r;
    if (l->count != 0 && self == l->owner) {
        l->count++;
    } else {
        r = rt_mutex_platform_lock(l);
        if (r != 0) return r;
        r = rt_mutex_platform_get_thread_id(&l->owner);
        if (r != 0) return r;
        l->count++;
    }
    if (out != 0) *out = l->count;
    return 0;
}
/* merge_units: end func_00302260 */

/* merge_units: begin func_00302308 */
extern int rt_mutex_platform_lock_no_block(RecursiveLock *, unsigned char *);

int rt_mutex_lock_no_block(RecursiveLock *l, int *out)
{
    unsigned char got = 0;
    int self;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    if (out == 0) return 2;
    *out = 0;
    r = rt_mutex_platform_get_thread_id(&self);
    if (r != 0) return r;
    if (l->count != 0 && self == l->owner) {
        *out = ++l->count;
    } else {
        r = rt_mutex_platform_lock_no_block(l, &got);
        if (r != 0) return r;
        if (got == 1) {
            r = rt_mutex_platform_get_thread_id(&l->owner);
            if (r != 0) return r;
            *out = ++l->count;
        }
    }
    return 0;
}
/* merge_units: end func_00302308 */
