import java.util.Scanner;

public class P4 {

  public static void printRow(int rowNum) {
    String cur = rowNum % 2 == 0 ? "AA" : "BB";
    for (int i = 0; i <= rowNum; i++) {
      System.out.printf(cur);
      cur = cur == "AA" ? "BB" : "AA";
    }
    System.out.println();
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter height: ");
    int height = sc.nextInt();
    if (height <= 0) {
      System.out.println("Error input!!");
      return;
    }
    for (int i = 0; i < height; i++) {
      printRow(i);
    }
  }
}
