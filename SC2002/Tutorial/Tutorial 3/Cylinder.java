import java.lang.Math;

public class Cylinder extends Circle {

  private int height;

  public Cylinder(int height, double radius, int x, int y) {
    super(radius, x, y);
  }

  public void setHeight(int height) {
    this.height = height;
  }

  public int getHeight() {
    return height;
  }

  public double area() {
    return area() * 2 + 2 * Math.PI * radius * height;
  }
}
