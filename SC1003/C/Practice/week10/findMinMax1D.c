	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
void findMinMax1D(int ar[], int size, int *min, int *max);
int main()
{
   int ar[40];
   int i, size;
   int min, max;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++)
      scanf("%d", &ar[i]);
   findMinMax1D(ar, size, &min, &max);
   printf("min = %d; max = %d\n", min, max);   
   return 0;              
}
void findMinMax1D(int ar[], int size, int *min, int *max)
{
	/*edit*/
	/* Write your code here */
    int i;
    *min = ar[0], *max = ar[0];
    for(i = 0; i < size; i++){
        if(ar[i] < *min){
            *min = ar[i];
        }
        if(ar[i] > *max){
            *max = ar[i];
        }
    }

	/*end_edit*/
}