import java.util.Scanner;

public class P3 {

  public static double getSGDConversion(int usd) {
    return usd * 1.82;
  }

  public static void generateTableFor(int st, int ed, int inc) {
    for (int i = st; i <= ed; i += inc) {
      System.out.printf("%d\t\t\t%.2f\n", i, getSGDConversion(i));
    }
  }

  public static void generateTableWhile(int st, int ed, int inc) {
    while (st <= ed) {
      System.out.printf("%d\t\t\t%.2f\n", st, getSGDConversion(st));
      st += inc;
    }
  }

  public static void generateTableDoWhile(int st, int ed, int inc) {
    do {
      System.out.printf("%d\t\t\t%.2f\n", st, getSGDConversion(st));
      st += inc;
    } while (st <= ed);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int st, ed, inc;
    System.out.println(
      "Please enter starting value, ending value, and increment."
    );
    System.out.print("Starting: ");
    st = sc.nextInt();
    System.out.print("Ending: ");
    ed = sc.nextInt();
    System.out.print("Increment: ");
    inc = sc.nextInt();
    if (st > ed) {
      System.out.println("Error input!!");
      return;
    }
    System.out.println("US$" + "\t\t\t" + "S$");
    System.out.println("----------------------------");
    // generateTableFor(st, ed, inc);
    // generateTableWhile(st, ed, inc);
    generateTableDoWhile(st, ed, inc);
  }
}
