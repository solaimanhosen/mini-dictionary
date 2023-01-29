#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void AddWord();
void DeleteWord();
void ListWord ();
void SearchWord();




int count;

struct dictionary {
      char word[20],meaning[100];
} d[1000];

void Menu()
{
       char key;
       FILE *fp;
       fp=fopen("input.txt","a+");
       count=0;
       while(feof(fp)==0){
           fscanf(fp,"%s",d[count].word);
           fscanf(fp,"%s",d[count].meaning);
           count++;
    }
    fclose(fp);
       system("cls");
       printf("\n");
       printf("\n**********************************************\n");
       printf("        *** MINI DICTIONARY ***");
       printf("\n**********************************************");
       printf("\n");printf("\n");printf("\n");
       printf("       (1) ADD A WORD TO DICTOINARY  LIBRARY \n");
       printf("       (2) DELETE WORD OF DICTIONARY LIBRARY \n");
       printf("       (3) LIST  OF  ALL  DICTIONARY   WORDS \n");
       printf("       (4) SEARCH DICTIONARY WORD WITH MEANING \n\n");
       printf(" HOME=H                                EXIT=0 ");
       printf("\n");printf("\n");printf("\n");
       printf("\n**********************************************\n");
       printf("           *** MINI DICTIONARY ***");
       printf("\n**********************************************");

            key=getch();

            if(key=='1')
                AddWord();
            if(key=='2')
                DeleteWord();
            if(key=='3')
                ListWord();
            if(key=='4')
                SearchWord();
            if(key=='0')
                exit(0);


}


void AddWord()
{
        FILE * fp;
        int i;
        char key;

        fp=fopen("input.txt","a+");
        system("cls");
        printf("\n");
        printf("\n**********************************************\n");
        printf("        *** MINI DICTIONARY ***");
        printf("\n**********************************************");
        printf("\n");printf("\n");printf("\n");

        printf("\n      ENTER A WORD : ");fscanf(stdin,"%s",d[count].word);fflush(stdin);
        fprintf(fp,"\n%s",d[count].word);
        printf("       ENTER THE MEANING : ",d[count].word);scanf("%[^\n]s",d[count].meaning);fflush(stdin);
        fprintf(fp,"\n%s",d[count].meaning);
        count++;
        printf("\n\n\n   INFORMATION ADDED SUCCESSFULLY \n\n");
        fclose(fp);
        printf("  HOME=H                               EXIT=0 ");
        printf("\n");printf("\n");printf("\n");
        printf("\n**********************************************\n");
        printf("           *** MINI DICTIONARY ***");
        printf("\n**********************************************");

        for(i=0;;i++){
            key=getch();
            if(key=='h' || key=='H')
                break;
            if(key=='0')
                 exit(0);
        }
}

void DeleteWord ()
{
        system("cls");
        FILE *sp;
        int i,aray[1000],count1=0;
        char key,str[30];

        for(i=0; i<1000; i++){
            aray[i]=0;
        }
        printf("\n");
        printf("\n**********************************************\n");
        printf("        *** MINI DICTIONARY ***");
        printf("\n**********************************************");
        printf("\n");printf("\n");printf("\n");

        printf("\n       ENTER A WORD TO DELETE : ");
        scanf("%s",str);fflush(stdin);

        for(i=0; i<count; i++){
            if(strcmp(str,d[i].word)==0){
               sp = fopen("input.txt","w");
               aray[i]=1;
               for(i=0; i<count; i++){
                   if(aray[i]==0){
                       fprintf(sp,"\n%s",d[i].word);
                       fprintf(sp,"\n%s",d[i].meaning);
                   }
               }
             fclose(sp);
            }
            else
                count1++;
        }
        if(count==count1)
            printf("\n        NO MATCH FOUND  \n\n");
        else
            printf("\n       INFORMATION DELETED SUCCESSFULLY !!!!!\n\n");

        printf("  HOME=H                                EXIT=0 ");
        printf("\n");printf("\n");printf("\n");
        printf("\n**********************************************\n");
        printf("           *** MINI DICTIONARY ***");
        printf("\n**********************************************");

        for(i=0;;i++){
            key=getch();
            if(key=='h' || key=='H')
                break;
            if(key=='0')
                 exit(0);
        }
}

void ListWord ()
{
        int i;
        char key;
        system("cls");
        printf("\n");
        printf("\n**********************************************\n");
        printf("        *** MINI DICTIONARY ***");
        printf("\n**********************************************");
        printf("\n");printf("\n");printf("\n");

        printf("\n      NO   WORDS     MEANING\n");
        for(i=0;i<count;i++){
            printf("     %2d    %-10s%-20s",i+1,d[i].word,d[i].meaning);
            printf("\n");
        }
        printf("\n\n");
        printf("  HOME=H                               EXIT=0 ");
        printf("\n");printf("\n");printf("\n");
        printf("\n**********************************************\n");
        printf("           *** MINI DICTIONARY ***");
        printf("\n**********************************************");

        for(i=0;;i++){
            key=getch();
            if(key=='h' || key=='H')
                break;
            if(key=='0')
                 exit(0);
        }
}

void SearchWord ()
{
        int i,count1,sign;
        char key,str[30];
        system("cls");
        printf("\n");
        printf("\n**********************************************\n");
        printf("        *** MINI DICTIONARY ***");
        printf("\n**********************************************");
        printf("\n");printf("\n");printf("\n");

        printf("\n      ENTER A WORD TO SEARCH : ");scanf("%s",str);fflush(stdin);
        count1=0;

        for(i=0;i<count;i++){
            sign=strcmp(str,d[i].word);
            if(sign==0){
                printf("\n          WORD       MEANING\n\n");
                printf("          %-10s %-20s",d[i].word,d[i].meaning);
                printf("\n\n");
            }
            else
                count1++;
        }
        if(count==count1)
            printf("\n      NO MATCH FOUND \n\n");

        printf("  HOME=H                               EXIT=0 ");
        printf("\n");printf("\n");printf("\n");
        printf("\n**********************************************\n");
        printf("           *** Mini Dictionary ***");
        printf("\n**********************************************");

        for(i=0;;i++){
            key=getch();
            if(key=='h' || key=='H')
                break;
            if(key=='0')
                 exit(0);
        }
}

int main ()
{
    int i;

    for(i=0;;i++)
        Menu();

    return 0;

}

