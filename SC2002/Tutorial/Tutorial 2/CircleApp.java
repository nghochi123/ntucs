import java.util.Scanner;

public class CircleApp {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Circle c = new Circle(-1);
    int choice;
    do {
      System.out.println("==== Circle Computation ====");
      System.out.println("| 1. Create a new circle   |");
      System.out.println("| 2. Print Area            |");
      System.out.println("| 3. Print Circumference   |");
      System.out.println("| 4. Quit                  |");
      System.out.println("===========================");
      System.out.println("Choose option: (1-3):");
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          System.out.println("Please enter the radius of the circle: ");
          double rad = sc.nextInt();
          c = new Circle(rad);
          System.out.printf(
            "A circle with radius %.2f has been created.\n",
            rad
          );
          break;
        case 2:
          if (c.getRadius() < 0) {
            System.out.println("Please create a circle first.");
          } else {
            c.printArea();
          }
          break;
        case 3:
          if (c.getRadius() < 0) {
            System.out.println("Please create a circle first.");
          } else {
            c.printCircumference();
          }
          break;
        default:
          System.out.println("Thank you for using CircleApp!");
          return;
      }
    } while (choice < 4);
  }
}
