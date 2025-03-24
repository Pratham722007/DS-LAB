#include<stdio.h>
int main(){
    int n,count=0;
    printf("enter no of elements you want to enter in array : ");
    scanf("%d",&n);
int a[n];
for (int i = 0; i <n ; i++)
{
    scanf("%d",&a[i]);
}

for (int i = 0; i <n; i++)
{
    for (int j=i; j<n; j++)
    {
    if(a[i]>a[j])
    {
        count++;

    }
    }
    
}
printf("\n%d",count);
return 0;
}