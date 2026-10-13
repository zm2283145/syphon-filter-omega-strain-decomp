/* True when the queue at +0x6C/+0x70 is empty or its last entry is earlier than the time at +0x54. */
typedef struct S458030 {
    char pad[0x54];
    float t;
    char pad2[0x14];
    int n;
    float* arr;
} S458030;

#pragma opt_common_subs off

static inline float* End458030(S458030* s) { return s->arr + s->n; }

int func_00458030(S458030* s)
{
    return s->n == 0 || End458030(s)[-1] < s->t;
}
