#include<stdio.h>
#include<string.h>

void headerfile(char *abc)
{
    FILE *fp = fopen(abc, "r");
    FILE *fp2 = fopen("temp.i", "w");
    FILE *hf;

    char line[500];  // Stores one line read from source file
    char header[100]; // Stores header file name extracted from #include
    int ch;

    if(fp == 0)
    {
        printf("File not present\n");
        return;
    }

    while(fgets(line, sizeof(line), fp))  // Read source file line by line
    {
        if(sscanf(line, "#include<%[^>]>", header) == 1)
        {
            if(strcmp(header, "stdio.h") == 0)
                hf = fopen("/usr/include/stdio.h", "r");
            else if(strcmp(header, "string.h") == 0)
                hf = fopen("/usr/include/string.h", "r");
            else
                hf = 0;

            if(hf)
            {
                while((ch = fgetc(hf)) != EOF)
                    fputc(ch, fp2);

                fclose(hf);
            }
        }
        else if(sscanf(line, "#include \"%[^\"]\"", header) == 1)
        {
           hf = fopen(header, "r");     // Open user headerfile from current directory

           if(hf)
          {
             while((ch = fgetc(hf)) != EOF)
             fputc(ch, fp2);

             fclose(hf);
          }
       }
       else
       {
          fputs(line, fp2);
       }
    }

    fclose(fp);
    fclose(fp2);
}















