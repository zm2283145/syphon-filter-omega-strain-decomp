/*
 * lib/medius: 3 files, 002D8AF0-002D8B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D8AF0 */
typedef struct { int f0; int n; } X8AF0;
int GetAudioSequence(X8AF0* p)
{
    return p->n++;
}
/* merge_units: end func_002D8AF0 */

/* merge_units: begin func_002D8B08 */
typedef struct { int f0; int f4; int n; } X8B08;
int GetVideoSequence(X8B08* p)
{
    return p->n++;
}
/* merge_units: end func_002D8B08 */

/* merge_units: begin func_002D8B20 */
int GetPackSequence(int* p)
{
    return (*p)++;
}
/* merge_units: end func_002D8B20 */
