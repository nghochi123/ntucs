public class cir2 {

  public static void main(String[] args) {
    Circle2 c = new Circle2(1, 2, 5);

    c.setX(4);
    c.setY(5);
    c.setRadius(6);
    System.out.println("x      : " + c.getX());
    System.out.println("y      : " + c.getY());
    System.out.println("radius : " + c.getRadius());
    System.out.println("area   : " + c.getArea());

    c.setRadius(-5);
    System.out.println("radius : " + c.getRadius());
    c = new Circle2(1, 1, -4);
    System.out.println("radius : " + c.getRadius());
  }
}
