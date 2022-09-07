import java.util.Scanner;

public class DiceApp {

  private static int diceCount = 0;
  private static int sum = 0;

  private static void pressEnterToContinue(Scanner sc) {
    System.out.printf(
      "Press Enter key to roll the %s dice.\n",
      diceCount == 0 ? "first" : "second"
    );
    try {
      sc.nextLine();
    } catch (Exception e) {}
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    pressEnterToContinue(sc);
    Dice d = new Dice();
    d.printDiceValue();
    sum += d.getDiceValue();
    diceCount++;
    pressEnterToContinue(sc);
    d.setDiceValue();
    d.printDiceValue();
    sum += d.getDiceValue();
    System.out.printf("Your total number is %d.\n", sum);
  }
}
