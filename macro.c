#include<stdio.h>
#include<string.h>

void macro_sub(char *file)
{
    FILE *fp = fopen(file,"r");
    FILE *fp2 = fopen("abc.i","w");

    char name[100][50];  // Store macro name
    char value[100][100];  // Store macro values

    char line[500];   // Store one line from file
    int c = 0, i;

    while(fgets(line,sizeof(line),fp))  // Read file line by line
    {
        if(strncmp(line,"#define",7)==0)   // Check for macro definition
        {
            sscanf(line,"#define %s %s",
                   name[c], value[c]);  // Extract macro name and value
            c++;
        }
        else
        {
            int j = 0;

            while(line[j])
            {
                if((line[j]>='A' && line[j]<='Z') ||
                   (line[j]>='a' && line[j]<='z') ||
                    line[j]=='_')  // Check start of identifier
                {
                    char word[100];  // Store current word
                    int k = 0;       // Word index

                    while((line[j]>='A' && line[j]<='Z') ||
                          (line[j]>='a' && line[j]<='z') ||
                          (line[j]>='0' && line[j]<='9') ||
                           line[j]=='_')  // Read complete identifier
                    {
                        word[k++] = line[j++];  // Copy character to word
                    }

                    word[k] = '\0';   // End the word string

                    int found = 0;  // Macro not found 

                    for(i=0;i<c;i++)
                    {
                        if(strcmp(word,name[i])==0)  // Macro matched
                        {
                            fputs(value[i],fp2);
                            found = 1;    // Mark as found
                            break;
                        }
                    }

                    if(found==0)
                        fputs(word,fp2);
                }
                else
                {
                    fputc(line[j],fp2);
                    j++;
                }
            }
        }
    }

    fclose(fp);
    fclose(fp2);
}
