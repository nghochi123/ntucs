import java.lang.Math;

public class Circle extends Point {

  protected double radius;

  public Circle(double radius, int x, int y) {
    super(x, y);
    this.radius = radius;
  }

  public void setRadius(double radius) {
    this.radius = radius;
  }

  public double getRadius() {
    return radius;
  }

  public double area() {
    return Math.PI * radius * radius;
  }
}
