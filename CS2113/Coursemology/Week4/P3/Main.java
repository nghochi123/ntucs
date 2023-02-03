import java.util.ArrayList;

public class Main {

  //TODO add your methods here
  private static ArrayList<Shape> shapes = new ArrayList<Shape>();

  public static void addShape(Shape shape) {
    shapes.add(shape);
  }

  public static void printAreas() {
    for (Shape shape : shapes) {
      System.out.println(shape.area());
    }
  }

  public static void main(String[] args) {
    addShape(new Circle(5));
    addShape(new Rectangle(3, 4));
    addShape(new Circle(10));
    printAreas();
    addShape(new Rectangle(4, 4));
    printAreas();
  }
}
