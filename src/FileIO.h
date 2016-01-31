int fileSize(FILE* fp)
{
    //Size of file in bytes
    int sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return sz;
}


char* fileContents(char* fname)
{
    //Contents of a file
    FILE* fp = fopen(fname, "r");
    int sz = fileSize(fp);
    char* buffer = malloc(sz);
    fread(buffer, sz, 1, fp);
    fclose(fp);
    return buffer;
}


int exists(char* filename)
{
    return access(filename, F_OK) != -1;
}

void touch(char* filename)
{
    if (exists(filename))
        return;
    FILE *fp;
    fp = fopen(filename, "w");
    fclose(fp);
}
