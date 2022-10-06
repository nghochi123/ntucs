public class Triangle extends Polygon {

  Triangle(float width, float height) {
    super("Triangle", width, height);
    this.polytype = KindOfPolygon.POLY_RECT;
  }

  public float calArea() {
    return this.width * this.height * (float) 0.5;
  }
}
