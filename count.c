#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fh;
     int count=0, c=0, i=0, j=0, k=0, space=0;

    char str[100], p[50][100], ptr[50][100];
    fh=fopen("text.txt","r");
    if (fh==NULL)
    {
        printf("file not opened");
    }
    else
    {

        while ( fgets(str,100,fh)!=NULL)
        {
            printf("%s",str);
        }

        printf("\n Length of the String is -- %d\n", strlen(str));

            for (i = 0;i<strlen(str);i++)
            {
                if ((str[i] == ' ')||(str[i] == ',' && str[i+1] == ' ')||(str[i] == '.'))
                {
                    space++;
                }
            }

            for (i = 0, j = 0, k = 0;j < strlen(str);j++)
            {
                if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))
                {
                    p[i][k] = '\0';
                    i++;
                    k = 0;
                }
                else
                     p[i][k++] = str[j];
            }

            k = 0;

            for (i = 0;i <= space;i++)
            {
                for (j = 0;j <= space;j++)
                {
                    if (i == j)
                    {
                        strcpy(ptr[k], p[i]);
                        k++;
                        count++;

                        break;
                    }
                    else
                    {
                        if (strcmp(ptr[j], p[i]) != 0)
                            continue;
                        else
                            break;
                    }
                }
            }

            for (i = 0;i < count;i++)
            {
                for (j = 0;j <= space;j++)
                {
                    if (strcmp(ptr[i], p[j]) == 0)
                        c++;
                }
                printf("%s -> %d times\n", ptr[i], c);
                c = 0;
            }
        }
        fclose(fh);
        }
