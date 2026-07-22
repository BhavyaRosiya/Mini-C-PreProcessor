void headerfile(char *);
void comment(char *);
void macro_sub(char *);
#include"extra.h"

int main(int argc, char **argv)
{
    headerfile(argv[1]);
    comment("temp.i");
    macro_sub("temp2.i");      
    return 0;
}
