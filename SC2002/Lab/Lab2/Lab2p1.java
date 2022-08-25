import java.lang.Math;
import java.util.Scanner;

public class Lab2p1 {

  private static final int NUMQNS = 5;
  private static final int RANGE = 10;
  private static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int choice;
    Scanner sc = new Scanner(System.in);
    do {
      System.out.println("Perform the following methods:");
      System.out.println("1: Multiplication test");
      System.out.println("2: Quotient using division by subtraction");
      System.out.println("3: Remainder using division by subtraction");
      System.out.println("4: Count the number of digits");
      System.out.println("5: Position of a digit");
      System.out.println("6: Extract all odd digits");
      System.out.println("7: Quit");
      choice = sc.nextInt();
      int n, m;
      switch (choice) {
        case 1:/* add mulTest() call */
          System.out.println(
            "You have chosen to go for a multiplication test!"
          );
          mulTest();
          break;
        case 2:/* add divide() call */
          System.out.println("You have chosen to divide!");
          System.out.print("Please enter number to be divided: ");
          n = sc.nextInt();
          System.out.print("Please enter number to divide by: ");
          m = sc.nextInt();
          int div = divide(n, m);
          System.out.printf("The answer is: %d\n\n", div);
          break;
        case 3:/* add modulus() call */
          System.out.println("You have chosen to get the modulus!");
          System.out.print("Please enter first number: ");
          n = sc.nextInt();
          System.out.print("Please enter second number: ");
          m = sc.nextInt();
          int mod = modulus(n, m);
          System.out.printf("The answer is: %d\n\n", mod);
          break;
        case 4:/* add countDigits() call */
          System.out.println("You have chosen to count digits!");
          System.out.print("Please enter your number: ");
          n = sc.nextInt();
          if (n < 0) {
            System.out.println("Error input!!");
            break;
          }
          int digits = countDigits(n);
          System.out.printf("Your number has %d digits\n\n", digits);
          break;
        case 5:/* add position() call */
          System.out.println("You have chosen to get position!");
          System.out.print("Please enter your number: ");
          n = sc.nextInt();
          System.out.print("Please enter the position: ");
          m = sc.nextInt();
          int posn = position(n, m);
          System.out.printf("Your number's position is: %d\n\n", posn);
          break;
        case 6:/* add extractOddDigits() call */
          System.out.println("You have chosen to extract odd digits!");
          System.out.print("Please enter your number: ");
          long ln = sc.nextLong();
          if (ln < 0) {
            System.out.println("Error input!!");
            break;
          }
          long newNumber = extractOddDigits(ln);
          System.out.printf("Your number's odd digits are: %d\n\n", newNumber);
          break;
        case 7:
          System.out.println("Program Terminating");
      }
    } while (choice < 7);
  }

  public static void mulTest() {
    int m1, m2, answer, score = 0;
    for (int i = 0; i < NUMQNS; i++) {
      m1 = (int) (Math.random() * RANGE);
      m2 = (int) (Math.random() * RANGE);
      System.out.printf("%d: How much is %d times %d? ", i + 1, m1, m2);
      answer = sc.nextInt();
      score += (answer == m1 * m2) ? 1 : 0;
    }
    System.out.printf("%d answers out of %d are correct\n\n", score, NUMQNS);
  }

  public static int divide(int m, int n) {
    int count = 0;
    while (m - n >= 0) {
      m -= n;
      count++;
    }
    return count;
  }

  public static int modulus(int m, int n) {
    while (m - n >= 0) {
      m -= n;
    }
    return m;
  }

  public static int countDigits(int n) {
    int count = 0;
    double ans = n;
    if (n == 0) return 1;
    while (ans > 0) {
      ans = Math.floor(ans / 10);
      count++;
    }
    return count;
  }

  public static int position(int m, int digit) {
    int count = 0;
    int mod;
    while (m > 0) {
      count++;
      mod = m % 10;
      m /= 10;
      if (mod == digit) return count;
    }
    return -1;
  }

  public static long extractOddDigits(long n) {
    int multiplier = 1, newNumber = 0, flag = 0, mod;
    while (n > 0) {
      mod = (int) (n % 10);
      n /= 10;
      if (mod % 2 != 0) {
        newNumber += multiplier * mod;
        multiplier *= 10;
        flag = 1;
      }
    }
    if (flag == 0) return -1;
    return newNumber;
  }
}
