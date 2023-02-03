public class Main {

  // Add your method here
  public static void describe(String color, Priority priority) {
    System.out.printf(
      "%s indicates %s priority\n",
      color,
      priority == Priority.HIGH
        ? "high"
        : priority == Priority.LOW ? "low" : "medium"
    );
  }

  public static void main(String[] args) {
    describe("Red", Priority.HIGH);
    describe("Orange", Priority.MEDIUM);
    describe("Blue", Priority.MEDIUM);
    describe("Green", Priority.LOW);
  }
}
