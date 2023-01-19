public class stringproc {

  public static void printPrice(String item) {
    // TODO: add your code here
    System.out.println(
      item.trim().replace(" --$", ": ").replace("/", ".").toUpperCase()
    );
  }

  public static void main(String[] args) {
    printPrice("sandwich  --$4/50");
    printPrice("  soda --$10/00");
    printPrice("  fries --$0/50");
  }
}
