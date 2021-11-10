	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int main() 
{
	/*edit*/
   /* Write your code here */
    char c;
    printf("Enter a character:\n");
    scanf("%c", &c);
    c <=90 && c >= 65 ? printf("Upper case letter") : c <= 122 && c >= 97 ? printf("Lower case letter") : c <= 57 && c >= 48 ? printf("Digit") : printf("Other character");

	/*end_edit*/
   return 0;  
}