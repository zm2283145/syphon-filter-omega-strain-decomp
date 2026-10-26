#pragma cplusplus on
extern "C" {
extern char g_Game[];
int String_CompareNoCase(const char* a, const char* b); void Game_CreateHud(void* p); void String_Copy(char* d, const char* s); }
extern "C" int confunc_RELOADSYS(int n, char** args, char* out)
{
    if (n == 1) {
        if (!String_CompareNoCase("INTERFACE", args[0])) {
            Game_CreateHud(g_Game);
            return 1;
        }
        String_Copy(out, "Cannot reload that system.");
        return 0;
    }
    String_Copy(out, "Name your system.");
    return 0;
}