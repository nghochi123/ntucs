public class Circle {

  private double radius;
  private static final double PI = 3.14159;

  public Circle(double rad) {
    this.radius = rad;
  }

  public void setRaidus(double rad) {
    this.radius = rad;
  }

  public double getRadius() {
    return radius;
  }

  public double area() {
    return PI * radius * radius;
  }

  public double circumference() {
    return PI * 2 * radius;
  }

  public void printArea() {
    System.out.printf("Area is: %.2f\n", area());
  }

  public void printCircumference() {
    System.out.printf("Circumference is: %.2f\n", circumference());
  }
}
