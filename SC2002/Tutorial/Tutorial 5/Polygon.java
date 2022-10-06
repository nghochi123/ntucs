public abstract class Polygon {

  public enum KindOfPolygon {
    POLY_PLAIN,
    POLY_RECT,
    POLY_TRIANG,
  }

  protected String name;
  protected float width;
  protected float height;
  protected KindOfPolygon polytype;

  public Polygon(String theName, float theWidth, float theHeight) {
    name = theName;
    width = theWidth;
    height = theHeight;
    polytype = KindOfPolygon.POLY_PLAIN;
  }

  public KindOfPolygon getPolytype() {
    return polytype;
  }

  public void setPolytype(KindOfPolygon value) {
    polytype = value;
  }

  public String getName() {
    return name;
  }

  public abstract float calArea();

  public void printWidthHeight() {
    System.out.println("Width = " + width + " Height = " + height);
  }
}
