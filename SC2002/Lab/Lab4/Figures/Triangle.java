public class Triangle implements Shape {

  protected double height;
  protected double breadth;

  public Triangle(double height, double breadth) {
    this.height = height;
    this.breadth = breadth;
  }

  public double calculateArea() {
    return (height * breadth) / 2;
  }
}
