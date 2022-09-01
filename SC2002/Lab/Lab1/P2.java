import java.util.Scanner;

public class P2 {

  public static char getGrade(int salary, int merit) {
    if (salary >= 700) {
      if (salary >= 800 || merit >= 20) {
        return 'A';
      } else {
        return 'B';
      }
    } else if (salary >= 650 || (merit >= 10 && salary >= 600)) {
      return 'B';
    }
    return 'C';
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int salary, merit;
    System.out.print("Enter a salary: $");
    salary = sc.nextInt();
    System.out.print("Enter a merit: ");
    merit = sc.nextInt();
    System.out.printf("Grade %c\n", getGrade(salary, merit));
  }
}
