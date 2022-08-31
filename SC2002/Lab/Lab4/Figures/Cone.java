public class Cone extends Triangle implements Shape3D {

  public Cone(double height, double breadth) {
    super(height, breadth);
  }

  public double calculate3DVolume() {
    return (
      (Math.PI * (super.breadth / 2) * (super.breadth / 2) * super.height) / 3
    );
  }

  public double calculate3DSurfaceArea() {
    double radius = (super.breadth / 2);
    return (
      (Math.PI * radius) *
      (radius + Math.sqrt(super.height * super.height + radius * radius))
    );
  }
}
