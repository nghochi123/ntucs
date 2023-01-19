import java.awt.Rectangle;

public class rect2 {

  public static void main(String[] args) {
    Rectangle r = new Rectangle(0, 0, 4, 6);
    System.out.println(r);

    int area;
    //TODO: add a line below to calculate the area using width and height properties of r
    // and assign it to the variable area
    area = r.width * r.height;

    System.out.println("Area: " + area);

    //TODO: add a line here to set the size of r to 8x10 (width x height)
    //Recommended: use the setSize(int width, int height) method of the Rectangle object
    r.setSize(8, 10);

    System.out.println(r);
  }
}
