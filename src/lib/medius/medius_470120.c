/*
 * lib/medius: 2 files, 00470120-00470150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00470120 */
extern int sprintf(char* buf, const char* fmt, ...);
int iCreateAndAllocateMessageID(int a, int b, int unused, char* buf)
{
    sprintf(buf, "%s.%d", a, b);
    return 0;
}
/* merge_units: end func_00470120 */

/* merge_units: begin func_00470150 */
extern char* strncpy(char* d, const char* s, int n);
extern int atoi(const char* s);
int iGetMessageIDValues(char* s, char* out, int* a, int* b)
{
    char* p = s;
    int n = 0;
    unsigned int v;
    while (*p != '.') {
        p++;
        n++;
    }
    if (*p == '.') p++;
    strncpy(out, s, n - 1);
    v = atoi(p);
    *a = (v >> 7) & 0x1FF;
    *b = v & 0x7F;
    return 0;
}
/* merge_units: end func_00470150 */
