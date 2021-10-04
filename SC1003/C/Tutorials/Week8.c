/*   
 1  
Tutorial 1 – Basic C Programming and Control Flow 
 
1. State the data type of each of the following: 
 
a.  '1'  g.  1870943465324L 
b.  23  h.  1.234F 
c.  0.0  i.  ‐564 
d.  '\040'  j.  0177 
e.  0x92  k.  0XfF4 
f.  '\a'  l.  0xaaBB76L 
 
2.   (a)     What will the following program output? (refer to an ASCII table) 
(b)  What will happen if the format specifier of the second printf is changed to %d? 
(c)  What will be the result if 0x in the third printf is removed? 
(d)  What if the first 0 in the fourth printf is deleted? 
 
#include <stdio.h> 
 
int main() 
{ 
  printf("%c", 'A'); 
  printf("%c", 65); 
  printf("%c", 0x41); 
  printf("%c", 0101); 
  return 0; 
} 
 
3. Assume x and y are integer variables. What will happen if one of the following statements is 
executed?  
 
(a)  scanf("%d %d", &x, &y); 
(b)  scanf("%d %d", x, y); 
(c)  scanf("%d/%d", &x, &y); 
 
4. The output of the following code is not zero.  Why? 
 
{   ....... 
  double A = 373737.0; 
  double B; 
 
  B = A * A * A + 0.37/A ‐ A * A * A ‐ 0.37/A; 
  printf(“ The value of B is %f.\n”, B); 
} 
 
5. Given the following declarations and initial assignments: 
 
int     i,  j,  m,  n; 
 2  
float   f,  g; 
 
i  =  j  =  2; 
m  =  n  =  5; 
f  =  1.2; 
g  =  3.4; 
 
evaluate the following expressions independently, i.e. all variables start with the same set 
of initial values.  Show any conversions which take place and the type of result. 
 
(a)  m * j / j        (b)       m / j * j 
(c)  (f + 10) * 20       (d)       (i++) * n 
(e)  i++ * n        (f)       ‐12L * (g ‐ f) 
(g)  m = n = ‐‐j;       (h)       (int) g * 10 
(i)  (int) (g * 10)  (j)  j = i + f 
 
6. Which of the following are acceptable case constant expressions? Assume the convention 
that upper case is used for defining a constant, e.g. 
    #define   SVALUE   10 
 
  and other identifiers are variables. 
(a)  case 76:      (b)  case number*2: 
(c)  case SVALUE*2:     (d)  case 80.1: 
 
7. In some computer games it is necessary to introduce a delay to slow the computer down.  
Assume that you are running the following program on a computer which uses 16 bits to 
represent an integer. How can the delay be (a) shortened, (b) made a thousand times 
longer, (c) made variable after compilation? 
 
#include  <stdio.h> 
#define  DLENGTH 32000 
 
int main() 
{ 
       int count; 
  ...... 
  for (count = ‐DLENGTH; count <= DLENGTH; count++) 
    ;   
  ...... 
} 
 
8. Are the following code segments the same? 
(a) if (x != 0 && 2/x != 1) { .....} 
(b)  if (2/x != 1 &&  x != 0) { .....} 
 
9. Write a section of C program to interchange the values of two integer variables. Is there a 
way of solving this problem without using a third variable? 


1. 
a. Character
b. Integer (Decimal Integer)
c. Float (Floating point)
d. String (ASCII for space)
e. Hexadecimal (Hexadecimal Integer)
f. Character (Alarm escape sequence)
g. ??? (Decimal Long integer)
h. Float (Floating Point)
i. Integer (Negative Decimal Integer)
j. Hexadecimal (Octal Integer - Starts with 0)
k. Hex (Hexadecimal Integer)
l. ? (Hexadecimal Long Integer)

2.
a) A A A A
b) Printed will be 65 instead
c) Printed will be a ) instead
d) Printed will be an e instead.

3.
a) user will be asked for input of 2 digits.
b) Error
c) User input will have to be separated with a / instead.

// 4.

// #include <stdio.h>

// int main(){
//   double A = 373737.0;
//   double B;

//   B = A * A * A + 0.37/A - A * A * A - 0.37/A;
//   printf("The value of B is %f", B);
// }

// Floating Point Imprecision

5.
a) 5.0 Convert m from integer to float. Result is float.
b) 5.0 Convert m from integer to float. Result is float.
c) 224. No conversion. Result is float
d) 10. No conversion. Result is integer.
e) 10. No conversion. Result is integer.
f) -26.4. Conversion from long to float. Result is float
g) m and n are equal to 1. No conversion. Result is integer
h) 30. Conversion from float to integer. Result is integer.
i) 34. Conversion from float to integer. Result is integer.
j) 3.2. Conversion from integer to float. Result is float.

6.
a, c are valid.
b, d are not valid

7.
a) Reduce DLENGTH
b) Multiply DLENGTH by 1000.
c) Instead of declaring as a constant, declare as an int or something.

8.
No, second one will throw an error if x = 0, but not the first one.

9.

# include <stdio.h>

int main(){

  int a,b, temp;

  a = 3, b = 5;

  temp = a;
  a = b;
  b = temp;

  printf("a: %d, b: %d", a, b);

  return 0;

}

#include <stdio.h>

int main(){

  int a,b;

  a = 3, b = 5;

  a = a+b;
  b = a-b;
  a = a-b;

  printf("a: %d, b: %d", a, b);

  return 0;
}

*/


