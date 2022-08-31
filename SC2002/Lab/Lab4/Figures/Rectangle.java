public class Rectangle implements Shape {

  protected double length;
  protected double width;

  public Rectangle(double l, double w) {
    length = l;
    width = w;
  }

  public double calculateArea() {
    return (length * width);
  }
}
