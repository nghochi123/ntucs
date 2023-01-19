public class cir3 {

  public static void main(String[] args) {
    Circle3 c = new Circle3();
    System.out.println("max radius used so far : " + Circle3.getMaxRadius());
    c = new Circle3(0, 0, 10);
    System.out.println("max radius used so far : " + Circle3.getMaxRadius());
    c = new Circle3(0, 0, -15);
    System.out.println("max radius used so far : " + Circle3.getMaxRadius());
    c.setRadius(12);
    System.out.println("max radius used so far : " + Circle3.getMaxRadius());
  }
}
