public class Cylinder extends Rectangle implements Shape3D {

  private double radius;
  private double height;

  public Cylinder(double radius, double height) {
    super(radius * 2, height);
    this.radius = radius;
    this.height = height;
  }

  public double calculate3DVolume() {
    return (Math.PI * radius * radius * height);
  }

  public double calculate3DSurfaceArea() {
    return (Math.PI * 2 * radius * height);
  }
}
