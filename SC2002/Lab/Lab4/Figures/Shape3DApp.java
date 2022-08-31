import java.util.Scanner;

public class Shape3DApp {

  public static void main(String[] args) {
    int choice, numShapes;
    double totalArea = 0;
    Scanner sc = new Scanner(System.in);
    System.out.println("Welcome to Shape3DApp.");
    System.out.println("Please enter total number of shapes.");
    numShapes = sc.nextInt();
    do {
      System.out.println("Please enter your choice:");
      System.out.println("(1) Sphere");
      System.out.println("(2) Pyramid (Square-base)");
      System.out.println("(3) Cuboid");
      System.out.println("(4) Cone");
      System.out.println("(5) Cylinder");
      choice = sc.nextInt();
      Shape3D shp;
      double side, brd, ht, radius;
      switch (choice) {
        case 1:
          System.out.printf("Please enter radius of sphere: ");
          radius = sc.nextDouble();
          shp = (Sphere) new Sphere(radius);
          break;
        case 2:
          System.out.printf(
            "Please enter height of bisecting triangle of pyramid: "
          );
          ht = sc.nextDouble();
          System.out.printf(
            "Please enter breadth of bisecting triangle of pyramid: "
          );
          brd = sc.nextDouble();
          shp = (Pyramid) new Pyramid(ht, brd);
          break;
        case 3:
          System.out.printf("Please enter length of cuboid: ");
          double len = sc.nextDouble();
          System.out.printf("Please enter breadth of cuboid: ");
          brd = sc.nextDouble();
          System.out.printf("Please enter height of cuboid: ");
          ht = sc.nextDouble();
          shp = (Cuboid) new Cuboid(len, brd, ht);
          break;
        case 4:
          System.out.printf("Please enter height of triangle linked to cone: ");
          ht = sc.nextDouble();
          System.out.printf(
            "Please enter breadth of triangle linked to cone: "
          );
          brd = sc.nextDouble();
          shp = (Cone) new Cone(ht, brd);
          break;
        case 5:
          System.out.printf("Please enter radius of cylinder: ");
          radius = sc.nextDouble();
          System.out.printf("Please enter height of cylinder: ");
          ht = sc.nextDouble();
          shp = (Cylinder) new Cylinder(radius, ht);
          break;
        default:
          System.out.println("Entry is invalid - please enter a valid shape.");
          continue;
      }
      System.out.printf(
        "The surface area of your designed 3D shape is: %.2f\n",
        shp.calculate3DSurfaceArea()
      );
      totalArea += shp.calculate3DSurfaceArea();

      numShapes--;
    } while (numShapes > 0);
    System.out.printf(
      "The total surface area of the 3D figure is: %.2f\n",
      totalArea
    );
  }
}
