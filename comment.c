#include<stdio.h>
#include<string.h>

void comment(char *file)
{
  FILE *fp = fopen(file,"r");
  FILE *fp2 = fopen("temp2.i","w");
  
  int ch,next;
  
  while((ch = fgetc(fp)) != EOF)   // Read file character by character
  {
    if(ch == '/')  //Checking Comment
    {
      next = fgetc(fp); // Read next character to identify comment 
      
      if(next == '/') // Single-line comment 
      {
        while((ch = fgetc(fp)) != '\n' && ch != EOF);
        
        if(ch == '\n')
        fputc('\n',fp2);
      }
      else if(next == '*') // Multi-line comment 
      {
        int prev = 0;
        
        while((ch = fgetc(fp)) != EOF)// Read until end of comment
        {
          if(prev == '*' && ch == '/') // Stop when "*/" is found
          break;
          
          prev = ch;
        }
      }
      else
      {
        fputc(ch,fp2);
        fputc(next,fp2);
      }
      
    }
    else
    fputc(ch,fp2);
  }
  fclose(fp);
  fclose(fp2);
  
}

