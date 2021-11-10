	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int countOddDigits1(int num);
void countOddDigits2(int num, int *result);
int main()
{
   int number, result;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("countOddDigits1(): %d\n", countOddDigits1(number));
   countOddDigits2(number, &result);
   printf("countOddDigits2(): %d\n", result);
   return 0;
}
int countOddDigits1(int number) 
{  
	/*edit*/
   /* Write your code here */
    int count = 0;
    while(number > 0){
        if(number % 2 == 1){
            count++;
        }
        number /= 10;
    }
    return count;

	/*end_edit*/
}
void countOddDigits2(int number, int *count) 
{  
	/*edit*/
   /* Write your code here */
    *count = 0;
    while(number > 0){
        if(number % 2 == 1){
            (*count)++;
        }
        number /= 10;
    }

	/*end_edit*/
}