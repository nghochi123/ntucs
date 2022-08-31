public class Pyramid extends Triangle implements Shape3D {

  public Pyramid(double height, double breadth) {
    super(height, breadth);
  }

  public double calculate3DSurfaceArea() {
    double baseArea = super.breadth * super.breadth;
    return (
      Math.sqrt(
        baseArea * (4 * super.height * super.height + baseArea) + baseArea
      )
    );
  }

  public double calculate3DVolume() {
    double baseArea = super.breadth * super.breadth;
    return ((baseArea * super.height) / 3);
  }
}
