	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int main() 
{        
	/*edit*/
    /* Write your code here */
    int hours;
    float gross, tax, net;
    printf("Enter hours of work:\n");
    scanf("%d", &hours);
    gross = hours > 40 ? hours * 6 + (hours - 40) * 3 : hours * 6;
    tax = gross <= 1000 ? 0.1 * gross : gross <= 1500 ? 100 + (gross-1000)*0.2 : 200 + (gross-1500) * 0.3;
    net = gross-tax;
    printf("Gross pay=%.2f\n", gross);
    printf("Tax=%.2f\n", tax);
    printf("Net pay=%.2f\n", net);

	/*end_edit*/
   return 0;  
}