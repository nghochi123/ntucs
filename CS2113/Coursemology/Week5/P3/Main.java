public class Main {

  public static void printArea(String descriptor) {
    //TODO: modify the code below
    try {
      System.out.println(descriptor + "=" + calculateArea(descriptor));
    } catch (NumberFormatException e) {
      System.out.println("WIDTH or HEIGHT is not a number: " + descriptor);
    } catch (IndexOutOfBoundsException e) {
      System.out.println("WIDTH or HEIGHT is missing: " + descriptor);
    } catch (IllegalShapeException e) {
      System.out.println("Too many dimensions: " + descriptor);
    }
  }

  private static int calculateArea(String descriptor)
    throws IllegalShapeException {
    //TODO: modify the code below
    String[] dimensions = descriptor.split("x");
    if (dimensions.length > 2) {
      throw new IllegalShapeException();
    }
    return Integer.parseInt(dimensions[0]) * Integer.parseInt(dimensions[1]);
  }

  public static void main(String[] args) {
    printArea("3x4");
    printArea("5x5");
  }
}
