#include <stdio.h>

int main(int argc, char * argv[])
{
    if(argc < 3)
    {
        printf("Input or output file is undefind!");
        return 1;
    }
    FILE * fp = fopen(argv[1], "rb");
    char c;
    int i = 0;
    int pos = 0;

    if(fp)
    {   
        FILE * ofp = fopen(argv[2], "wb");
        fseek(fp, 0L, SEEK_END);
        int sz = ftell(fp);
        rewind(fp);
        while(i < sz)
        {
            c = getc(fp);
            if(pos < 0x80)
            {
                c = c ^ (i + 0x77);
                pos++;
            }
            putc(c, ofp);
            i++;
        }
        fclose(ofp);
        fclose(fp);
        printf("OK");
    }
    else
    {
        printf("Incorrected input filename!");
        return 1;
    }
    return 0;
}