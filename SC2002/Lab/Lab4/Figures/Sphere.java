public class Sphere extends Circle implements Shape3D {

  public Sphere(double radius) {
    super(radius);
  }

  public double calculate3DSurfaceArea() {
    return (4 * Math.PI * super.radius * super.radius);
  }

  public double calculate3DVolume() {
    return ((4 / 3) * Math.PI * Math.pow(super.radius, 3));
  }
}
