import java.util.Scanner;

public class Shape2DApp {

  public static void main(String[] args) {
    int choice, numShapes;
    double totalLen = 0;
    Scanner sc = new Scanner(System.in);
    System.out.println("Welcome to Shape2DApp.");
    System.out.println("Please enter total number of shapes.");
    numShapes = sc.nextInt();
    do {
      System.out.println("Please enter your choice:");
      System.out.println("(1) Square");
      System.out.println("(2) Rectangle");
      System.out.println("(3) Circle");
      System.out.println("(4) Triangle");
      choice = sc.nextInt();
      Shape shp;
      double side;
      switch (choice) {
        case 1:
          System.out.printf("Please enter side length of square: ");
          side = sc.nextDouble();
          shp = (Square) new Square(side);
          break;
        case 2:
          System.out.printf("Please enter length of rectangle: ");
          double len = sc.nextDouble();
          System.out.printf("Please enter width of rectangle: ");
          double wid = sc.nextDouble();
          shp = (Rectangle) new Rectangle(len, wid);
          break;
        case 3:
          System.out.printf("Please enter radius of circle: ");
          double radius = sc.nextDouble();
          shp = (Circle) new Circle(radius);
          break;
        case 4:
          System.out.printf("Please enter height of triangle: ");
          double height = sc.nextDouble();
          System.out.printf("Please enter breadth of triangle: ");
          double breadth = sc.nextDouble();
          shp = (Triangle) new Triangle(height, breadth);
          break;
        default:
          System.out.println("Entry is invalid - please enter a valid shape.");
          continue;
      }
      System.out.printf(
        "The area of your designed shape is: %.2f\n",
        shp.calculateArea()
      );
      totalLen += shp.calculateArea();

      numShapes--;
    } while (numShapes > 0);
    System.out.printf("The total area of the 2D figure is: %.2f\n", totalLen);
  }
}
