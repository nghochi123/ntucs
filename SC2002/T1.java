import java.util.Scanner;

public class T1 {

  public static void bubble(int[] a, int n) {
    int i, j, t;
    for (i = n - 2; i >= 0; i--) {
      for (j = 0; j <= i; j++) {
        if (a[j] > a[j + 1]) {
          t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
        }
      }
    }
  } // end function.

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n, i;
    int[] a = new int[100];
    System.out.println("Enter number of Integer elements to be sorted: ");
    n = sc.nextInt();
    for (i = 0; i <= n - 1; i++) {
      System.out.println("Enter integer value: ");
      a[i] = sc.nextInt();
    }
    bubble(a, n);
    System.out.println("Finally sorted array is: ");
    for (i = 0; i <= n - 1; i++) System.out.print(a[i] + " ");
    System.out.println();
  }
}
