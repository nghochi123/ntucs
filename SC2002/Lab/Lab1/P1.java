import java.util.Scanner;

public class P1 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String choice;
    System.out.println("Please enter a character");
    choice = sc.next();
    switch (choice.toUpperCase()) {
      case "A":
        System.out.println("Action Movie Fan");
        break;
      case "C":
        System.out.println("Comedy Movie Fan");
        break;
      case "D":
        System.out.println("Drama Movie Fan");
        break;
      default:
        System.out.println("Invalid Choice");
    }
  }
}
