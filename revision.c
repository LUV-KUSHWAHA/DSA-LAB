// STUDENT STRUCTURE
#include <stdio.h>

struct student
{
    char Name[20];
    int roll;
    float marks;
}s[3],temp;

int main()
{
    int i,j;
    printf("Enter the asked data for 3 students  respectively:");
    for(i=0;i<3;i++)
    {
        printf("\nEnter name of student %d: ",i+1);
        scanf("%s",s[i].Name);
        printf("\nEnter roll: ");
        scanf("%d",&s[i].roll);
        printf("\nEnter his/her total marks: ");
        scanf("%f",&s[i].marks);
    }  
    printf("\nThe stored information are: ");
    for(i=0;i<3;i++)
    {
        printf("\nStudent %d: %s ",i+1,s[i].Name);
        printf("\nroll: %d",s[i].roll);
        printf("\n his/her total marks: %.2f",s[i].marks);
    }  
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(s[i].roll>s[j].roll)
             {
                   temp= s[j];
                s[j]= s[i];
                s[i]= temp;
             }
        }
    }
    printf("\nThe stored information in sorted form are: ");
    for(i=0;i<3;i++)
    {
        printf("\nStudent %d: %s ",i+1,s[i].Name);
        printf("\nroll: %d",s[i].roll);
        printf("\n his/her total marks: %.2f",s[i].marks);
    }  
    return 0;
}
