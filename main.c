#include<stdio.h>
#include<stdlib.h>

void options();
void cleanstdin();
int start=1,show=0,k=1;
int main()
{
    int *person;
    int persons,i,killed=0,pos=0,del;
    char opt;
    
    printf("Enter No of Persons: ");
    scanf("%d",&persons);
    printf("Enter the no of should be skipped: ");
    scanf("%d",&del);
    cleanstdin();
    printf("Do you want any more options(y/n): ");
    scanf("%c",&opt);
    if(opt=='y' || opt=='Y')
    {
        options();
    }
    person=(int *)calloc(persons,sizeof(int));
    
    for(i=start-1; killed<(persons-1); i+=k)
    {
        if(i<0)
        {
            i=persons+i;
        }
        if(person[i%persons]==0 && pos==del)
        {
            person[i%persons]=1;
            if(show)
            {
                printf("%d\t",i%persons+1);
            }
            killed++;
            pos=0;
        }
        if(person[i%persons]==0)
        {
            if(killed==(persons-2))
            {
                printf("\nThe person who remains is %d\n",i%persons+1);
                break;
            }
            pos++;
        }
    }
    free(person);
    return 0;
}
void options()
{
    char opt;
    printf("Enter Starting option: ");
    scanf("%d",&start);
    
    do
    {
        printf("Enter Direction:(right=1/left=-1): ");
        scanf("%d",&k);
    }while(k!=1 && k!=-1);
    
    cleanstdin();
    printf("Do you want see the position of after executing?(y/n) ");
    scanf("%c",&opt);
    if(opt=='y' || opt=='Y')
    {
        show = 1;
    }
}
void cleanstdin()
{
    while(getchar()!='\n');
}
