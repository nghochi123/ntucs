public class TestPolygon {

  //   public static void printArea(Rectangle r) {
  //     System.out.println("Rectangle Area: " + r.calArea());
  //   }

  //   public static void printArea(Triangle t) {
  //     System.out.println("Triangle Area: " + t.calArea());
  //   }

  public static void printArea(Polygon p) {
    System.out.println(p.getName() + " Area: " + p.calArea());
  }

  public static void main(String[] args) {
    Triangle t = new Triangle(10, 10);
    Rectangle r = new Rectangle(10, 10);
    printArea(t);
    printArea(r);
  }
}
