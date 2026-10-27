/*
 * SFOGame/Source/game: 1 file, 00130770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00130770 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char g_Game[];
int String_CompareNoCase(const char* a, const char* b); void cGameSystem_LoadHud(void* p); void Libc_Strcpy(char* d, const char* s); }
extern "C" int confunc_RELOADSYS(int n, char** args, char* out)
{
    if (n == 1) {
        if (!String_CompareNoCase("INTERFACE", args[0])) {
            cGameSystem_LoadHud(g_Game);
            return 1;
        }
        Libc_Strcpy(out, "Cannot reload that system.");
        return 0;
    }
    Libc_Strcpy(out, "Name your system.");
    return 0;
}
static inline void merge_flush_func_00130770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00130770 */
