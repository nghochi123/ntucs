	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int main() 
{
	/*edit*/
   /* Write your code here */
    int n, i;
    float s, t;
    printf("Enter the number of times:\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter distance (in km):\n");
        scanf("%f", &s);
        printf("Enter time (in sec):\n");
        scanf("%f", &t);
        printf("The speed is %.2f km/sec\n", s/t);
    }

	/*end_edit*/
   return 0;
}