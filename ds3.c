#include<stdio.h>
struct student{
    int rollno;
    char sname[40];
    float marks;
};

int main(){
    int n;
    printf("Enter no of students");
    scanf("%d",&n);
struct student ai[n];
for (int i = 0; i <n; i++)
{
printf("\nenter roll no  : ");
scanf("%d",&ai[i].rollno);
printf("\nenter name : ");
scanf("%s",ai[i].sname);
printf("\nenter marks :  ");
scanf("%f",&ai[i].marks);

    
}

printf("\n student info ");
for (int i = 0; i < n; i++)
{
    printf("\n roll no=%d ",ai[i].rollno);
    printf("\nname = %s ",ai[i].sname);
    printf("\nmarks = %f ",ai[i].marks);
    
}

return 0;

}   