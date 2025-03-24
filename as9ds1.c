#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements in the array: ");
scanf("%d",&n);
int a[n];
printf("Enter the elements of the array: ");
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if(a[i]<a[j])
        {
           int temp = a[i];
              a[i] = a[j];
                a[j] = temp;
        }
    }
}
printf("The sorted array is: ");
for(int i=0;i<n;i++)
{
    printf("%d ",a[i]);
}


return 0;
}