/*
 * lib/medius: 3 files, 002CEC00-002CEC70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CEC00 */
extern char D_0051EFD8[];
extern char* strncpy(char* d, const char* s, int n);
void func_002CEC00(char* d)
{
    if (d != 0)
        strncpy(d, D_0051EFD8, 17);
}
/* merge_units: end func_002CEC00 */

/* merge_units: begin func_002CEC38 */
void func_002CEC38(const char* s)
{
    if (s != 0)
        strncpy(D_0051EFD8, s, 17);
}
/* merge_units: end func_002CEC38 */

/* merge_units: begin func_002CEC70 */
typedef struct { int w[6]; } SEC70;
extern SEC70 D_0051EFF0;
void func_002CEC70(SEC70* d)
{
    *d = D_0051EFF0;
}
/* merge_units: end func_002CEC70 */
