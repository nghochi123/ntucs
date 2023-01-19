public class Circle3 {

  private int x;
  private int y;
  private double radius;
  private static double maxRadius = 0;

  public Circle3() {
    this(0, 0, 0);
  }

  public Circle3(int x, int y, double radius) {
    setX(x);
    setY(y);
    setRadius(radius);
  }

  public int getX() {
    return x;
  }

  public void setX(int x) {
    this.x = x;
  }

  public int getY() {
    return y;
  }

  public void setY(int y) {
    this.y = y;
  }

  public double getRadius() {
    return radius;
  }

  public void setRadius(double radius) {
    this.radius = Math.max(radius, 0);
    if (radius > maxRadius) {
      maxRadius = radius;
    }
  }

  public int getArea() {
    double area = Math.PI * Math.pow(radius, 2);
    return (int) area;
  }

  public static double getMaxRadius() {
    return maxRadius;
  }
}
