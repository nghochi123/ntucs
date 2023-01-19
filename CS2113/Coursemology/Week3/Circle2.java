public class Circle2 {

  private int x;
  private int y;
  private double radius;

  public Circle2() {
    this(0, 0, 0);
  }

  public Circle2(int x, int y, double radius) {
    this.x = x;
    this.y = y;
    this.radius = radius >= 0 ? radius : 0;
  }

  public int getArea() {
    double area = Math.PI * Math.pow(radius, 2);
    return (int) area;
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

  public double getRadius() {
    return radius;
  }

  public void setX(int x) {
    this.x = x;
  }

  public void setY(int y) {
    this.y = y;
  }

  public void setRadius(double radius) {
    this.radius = radius >= 0 ? radius : 0;
  }
}
