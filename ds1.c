#include<stdio.h>
void main(){
    int n;
    printf("enter no of elements you want to enter in array : ");
    scanf("%d",&n);
    int a[n];
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
    
}
int maxi;
for (int i = 0; i < n; i++)
{
    if(a[i]<a[i+1]){
        maxi=i+1;
    }
    if(a[i]>a[i+1]){
        break;
    }

}
int mid;
printf("maximum index is %d\n",maxi);
int low=0,up=n;
while(low<up){
    mid=(low+up)/2;
    if(maxi==mid){break;}
    if(maxi>mid){low=mid-1;}
    if(maxi<mid){up=mid-1;}
}
printf("maximum element is %d",a[mid]);

}
