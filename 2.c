    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>

    typedef enum MENU{EXIT,STR_CPY,STR_CAT,STR_CMP,STR_REV} mchoice;
    int menu();
    char *my_strcpy(char *dest, const char *src);
    char *my_strcat(char *dest, const char *src);
    int my_strcmp(const char *str1, const char *str2);
    int *my_strrev(char *str);

    int main(void)
    {

        char str[20] = {};
        char str2[20] = {};
        char opr[20] = {};
        int ret;

        while (1)
        {
            int input = menu();
            switch (input)
            {
            case EXIT:
                exit(0);

            case STR_CPY:
                printf("\tEnter String:");
                scanf("%s", str);

                my_strcpy(opr, str);

                break;

            case STR_CAT:
                printf("\tEnter String 1:");
                scanf("%s", str);
                printf("\tEnter String 2:");
                scanf("%s", str2);

                my_strcat(str, str2);

                break;

            case STR_CMP:
                printf("\tSpecify String 1: ");
                scanf("%*c");
                gets(str);
                printf("\tSpecify String 2: ");
                gets(str2);
                ret = stricmp(str, str2);

                if (ret == 0)
                    printf("\t\"String 1: %s\" is equal to \"String 2: %s\"\n", str, str2);
                else
                    printf("\t\"String 1: %s\" is not equal to \"String 2: %s\"\n", str, str2);
                break;

            case STR_REV:
                printf("\tSpecify String 1: ");
                scanf("%*c");
                gets(str);
                //strrev(str);
                my_strrev(str);
                printf("\tReversed String: %s", str);
                break;
            }
        }

        return 0;
    }

    int menu()
    {
        int n;
        printf("\n\nMenu of operations:\n");
        printf("\t0.EXIT\n");
        printf("\t1.To Copy String\n");
        printf("\t2.To Concatnate String\n");
        printf("\t3.To Compare String\n");
        printf("\t4.To Reverse String\n");
        printf("\nEnter number which operation is to be performed:");
        scanf("%d", &n);
        return n;
    }

    char *my_strcpy(char *dest, const char *src)
    {
        int i, n;
        n = strlen(src);
        for (i = 0; i < n; i++)
            dest[i] = src[i];
        printf("Inserted String : %s\n", src);
        printf("Copied String : %s\n", dest);
    }

    char *my_strcat(char *dest, const char *src)
    {
        int i, n, m, l = 0;

        n = strlen(dest);
        m = strlen(src);

        for (i = n; i <= (m + n); i++)
        {
            dest[i] = src[l];
            l++;
        }

        printf("%s\n", dest);
    }

    int my_strcmp(const char *p1, const char *p2)
    {
        const unsigned char *s1 = (const unsigned char *)p1;
        const unsigned char *s2 = (const unsigned char *)p2;
        unsigned char c1, c2;
        do
        {
            c1 = (unsigned char)*s1++;
            c2 = (unsigned char)*s2++;
            if (c1 == '\0')
                return c1 - c2;
        } while (c1 == c2);
        return c1 - c2;
    }

    int *my_strrev(char *str)
    {
        int temp[20], i;
        int n = strlen(str) - 1;
        for (i = 0; i < strlen(str); i++)
        {
            temp[n] = str[i];
            n--;
        }

        for (i = 0; i < strlen(str); i++)
        {
            str[i] = temp[i];
        }
    }