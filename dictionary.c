#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct dict{
    struct dict *left,*right;
    char word[20],meaning[20];
}*Root = NULL;

typedef struct dict dictionary ;

void search();
void insert(dictionary *);
void view(dictionary *);
int check(char [],char []);

int main()
{
    int ch;
    while(ch!=4)
    {

        dictionary *temp;
        printf("\n1.search\n2.Insert\n3.View\n4.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: search();
                    break;
            case 2: temp = (dictionary *)malloc(sizeof(dictionary));
                    temp->left = NULL;
                    temp->right = NULL;
                    printf("\ninsert word: ");
                    scanf("%s",temp->word);
                    printf("\ninsert meaning: ");
                    scanf("%s",temp->meaning);
                    insert(temp);
                    break;
            case 3: view(Root);
                    break;
            case 4:exit(0);
        }
    }
    getch();
    return 0;
}
int check(char a[],char b[])
{
    int i,j,c;
    for(i=0,j=0; a[i]!='\0'&&b[j]!='\0' ; i++,j++)
    {
        if(a[i]>b[j])
        {
            c=1;
            break;
        }
        else if(a[i]<b[j])
        {
            c = -1;
            break ;
        }
        else
        {
            c=0;
        }
    }
    if(c==1)
    {
        return 1;
    }
    else if(c==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
void search()
{
    char w[20];
    dictionary *ptr;
    int flag=0;
    ptr = Root;
    printf("\nenter the word..");
    scanf("%s",w);
    while(ptr!=NULL && flag == 0)
    {
        if(check(w,ptr->word)==1)
        {
            ptr= ptr->right;
        }
        else if (check(w,ptr->word)==-1)
        {
            ptr= ptr->left;
        }
        else
        {
            flag=1;
            printf("\nMeaning: %s",ptr->meaning);
            break;
        }
    }
    if(flag==0 && ptr == NULL)
    {
        printf("\nword not found");
    }
}
void insert(dictionary *temp)
{
    dictionary *ptr,*par;
    int flag=0;
    ptr = Root;
    if(Root == NULL)
    {
        Root = temp;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(check(temp->word,ptr->word)==1)
            {
                par=ptr;
                ptr= ptr->right;
            }
            else if (check(temp->word,ptr->word)==-1)
            {
                par = ptr;
                ptr= ptr->left;
            }
            else
            {
                flag=1;
                printf("\nword exists\n");
                break;
            }
        }
        if(flag == 0)
        {
            if(check(par->word,temp->word)==1)
            {
                par->left = temp;
            }
            else if(check(par->word,temp->word)==-1)
            {
                par->right = temp ;
            }
        }
    }

}
void view(dictionary *ptr)
{
    if(Root == NULL)
    {
        printf("\nempty dictionary\n");

    }
    else
    {
        if(ptr!= NULL)
        {
            view(ptr->left);
            printf("\nword : %s",ptr->word);
            printf("\nmeaning : %s",ptr->meaning);
            view(ptr->right);

        }
    }
}
