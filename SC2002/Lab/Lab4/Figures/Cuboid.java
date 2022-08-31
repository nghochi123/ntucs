public class Cuboid extends Rectangle implements Shape3D {

  private double height;

  public Cuboid(double length, double width, double height) {
    super(length, width);
    this.height = height;
  }

  public double calculate3DVolume() {
    return this.height * super.length * super.width;
  }

  public double calculate3DSurfaceArea() {
    return (
      2 *
      super.length *
      super.width +
      2 *
      this.height *
      super.length +
      2 *
      this.height *
      super.width
    );
  }
}
