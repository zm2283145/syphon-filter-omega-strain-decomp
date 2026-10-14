/*
 * lib/medius: 2 files, 003226E0-00322738
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003226E0 */
extern void func_00322C68(int, int, int);
extern void func_003227E0(int, int, int);
void func_003226E0(int a, int b, int n)
{
    int h = n / 2;
    func_00322C68(a, b, h);
    func_003227E0(b, a, h);
}
/* merge_units: end func_003226E0 */

/* merge_units: begin func_00322738 */
void func_00322738(float *re, float *im, int n)
{
    int i, j = n >> 1, k;
    float t;
    for (i = 1; i < n - 1; i++) {
        if (i > j) {
            t = re[i]; re[i] = re[j]; re[j] = t;
            t = im[i]; im[i] = im[j]; im[j] = t;
        }
        k = n;
        do {
            k >>= 1;
            j ^= k;
        } while (j < k);
    }
}
/* merge_units: end func_00322738 */
