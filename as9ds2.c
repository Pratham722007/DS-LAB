#include <stdio.h>
void merge(int a[], int left, int mid, int right);
void mergesort(int a[], int left, int right);
int main()
{

    int a[5] = {4, 1, 3, 9, 7};
    int n = 5;
    mergesort(a, 0, n - 1);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
void mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftarr[n1], rightarr[n2];
    for (i = 0; i < n1; i++)
    {
        leftarr[i] = a[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightarr[j] = a[mid + 1 + j];
    }
    i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (leftarr[i] <= rightarr[j])
        {
            a[left + k] = leftarr[i];
            i++;
            k++;
        }
        else{
            a[left + k] = rightarr[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[left + k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[left + k] = rightarr[j];
        j++;
        k++;
    }

}
