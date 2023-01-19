public class score {

  public static void printTotalScore(String[] values) {
    // TODO: add your code here
    int score = 0;
    for (String i : values) {
      score += Integer.parseInt(i);
    }
    System.out.println(score);
  }

  public static void main(String[] args) {
    printTotalScore(new String[] {});
    printTotalScore(new String[] { "0", "124", "-15" });
  }
}
