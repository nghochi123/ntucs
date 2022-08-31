public class Point {

  protected int x;
  protected int y;

  public Point(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public String toString() {
    return String.format("[ %d, %d ]", x, y);
  }

  public void setPoint(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public int getX() {
    return this.x;
  }

  public int getY() {
    return this.y;
  }
}
