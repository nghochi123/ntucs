public class FinallyDemo {

  public static void main(String[] args) {
    try {
      sampleMethod(0);
    } catch (Exception e) {
      System.out.println("Caught in main.");
    }
  }

  public static void sampleMethod(int n) throws Exception {
    try {
      if (n > 0) throw new Exception(); else if (
        n < 0
      ) throw new NegativeNumberException(); else System.out.println(
        "No exception"
      );
    } catch (NegativeNumberException e) {
      System.out.println("Caught in sampleMethod");
    } finally {
      System.out.println("In Finally block");
    }
    System.out.println("After Finally block");
  }
}
