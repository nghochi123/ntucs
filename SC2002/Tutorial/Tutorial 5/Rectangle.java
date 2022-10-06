public class Rectangle extends Polygon {

  Rectangle(float width, float height) {
    super("Rectangle", width, height);
    this.polytype = KindOfPolygon.POLY_RECT;
  }

  public float calArea() {
    return this.width * this.height;
  }
}
