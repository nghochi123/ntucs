	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <math.h>
int main() 
{
	/*edit*/
   /* Write your code here */
    int n, i;
    float x1, x2, y1, y2, dist;
    printf("Enter the number of times:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter first point x1 y1:\n");
        scanf("%f", &x1);
        scanf("%f", &y1);
        printf("Enter second point x2 y2:\n");
        scanf("%f", &x2);
        scanf("%f", &y2);
        dist = sqrt(pow((x1-x2), 2)+pow((y1-y2),2));
        printf("The distance is %.2f\n", dist);
    }

	/*end_edit*/
   return 0;
}