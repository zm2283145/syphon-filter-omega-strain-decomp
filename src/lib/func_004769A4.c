extern char D_00497E58[64];
extern char D_00497E98[64];
void* memcpy(void*, const void*, unsigned int);

/* Keep the two memcpy expansions separate so their address temporaries match retail. */
int KM_GetSoftwareKeyPair(char* a, char* b)
{
    do { memcpy(a, D_00497E58, 64); } while (0);
    __asm__("");
    do { memcpy(b, D_00497E98, 64); } while (0);
    return 0;
}
