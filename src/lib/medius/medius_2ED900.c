extern char *strncpy(char *, const char *, unsigned int);
void GridSetName(char *p, const char *src)
{
    strncpy(p + 0x10, src, 0x40);
    p[0x4F] = 0;
}