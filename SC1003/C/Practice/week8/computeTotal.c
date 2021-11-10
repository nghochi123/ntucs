	/*edit*/

/*custom header*/
#include <string.h>
	/*end_edit*/
#include <stdio.h>
int main() 
{     
	/*edit*/
   /* Write your code here */
    int n, n2, i, j, userin, total;
    printf("Enter number of lines:\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter line %d:\n", i+1);
        scanf("%d", &n2);
        total=0;
        for(j=0;j<n2;j++){
            scanf("%d", &userin);
            total += userin;
        }
        printf("Total: %d\n", total);
    }

	/*end_edit*/
   return 0;
}