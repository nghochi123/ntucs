//TODO add your code here
public class Circle {

  private int x;
  private int y;
  double radius;

  Circle() {
    this.x = 0;
    this.y = 0;
    this.radius = 0;
  }

  Circle(int x, int y, double radius) {
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public int getArea() {
    return (int) (Math.PI * Math.pow(radius, 2));
  }
}
