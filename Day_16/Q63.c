// Q63. WAP to find pair with given sum. 

#include<stdio.h>
int main()
{
    int n, i,j;
     printf("Enter number of array element: ");
     scanf("%d",&n);

     int arr[n];
    
     printf("Enter %d array elements \n",n);
     for(i=0; i<n; i++)
     {
        scanf("%d",&arr[i]);
     }
     int x=12;
     int countPair=0;

     printf("Pairs is/are ");
     for(i=0; i<n; i++)
     {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==x)
            {
                countPair++;
            
            printf("(%d,%d) ",arr[i], arr[j]);
            }
        }
     }
     printf("\nNumber of pairs is/are %d ",countPair);

     return 0;
}