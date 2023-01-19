import java.util.Scanner;

public class totalamt {

  // You can add more methods here

  public static void main(String[] args) {
    String line;
    Scanner in = new Scanner(System.in);

    System.out.print("Your expenses while overseas?");
    // TODO: add your code here
    line = in.nextLine();
    String[] words = line.split(" ");
    String items = "[";
    double amt = 0;
    int i = 0;
    for (String s : words) {
      if (s.charAt(0) == '$') {
        amt += Double.parseDouble(s.replace("$", ""));
        if (i != 0) {
          items += ", ";
        }
        i = 1;
        items += s;
      }
    }
    items += "]";
    System.out.printf("Expenses in overseas currency:%s", items);
    System.out.printf("Total in local currency: $%.2f", amt * 1.7);
  }
}
