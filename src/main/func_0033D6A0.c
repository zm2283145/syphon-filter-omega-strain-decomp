#pragma cplusplus on
typedef struct { char* begin; char* end; char* cap; } String;
extern "C" {
void String_CtorCStr_13B480(String* s, const char* text);
void func_0013D680(void* list, String* s);
void String_Dtor(String* s, int flags);

void Lobby_FormatString(void* self, const char* fmt, const char* a0, const char* a1, const char* a2, const char* a3) {
    String s;
    const char* args[4] = {0};
    char buf[0x400];
    int n;

    args[1] = a1;
    args[0] = a0;
    n = 0;
    args[2] = a2;
    args[3] = a3;
    while (!((fmt != 0) ^ 1) && n < 0x3FF) {
        char c = fmt[0];
        if (c == '$' && fmt[1] >= '1' && fmt[1] < '5') {
            const char* a = args[fmt[1] - '1'];
            if (a != 0) {
                buf[n++] = fmt[1] - 0x20;
                while (!((*a != 0) ^ 1) && n < 0x3FF) {
                    buf[n++] = *a++;
                }
                buf[n++] = 0x10;
            }
            fmt += 2;
        } else {
            buf[n] = c;
            fmt++;
            n++;
        }
    }
    buf[n] = 0;
    String_CtorCStr_13B480(&s, buf);
    func_0013D680(self, &s);
    String_Dtor(&s, 0);
}
}



