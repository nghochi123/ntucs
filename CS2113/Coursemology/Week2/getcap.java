public class getcap {

  // ADD YOUR CODE HERE

  public static double getGradeCap(String grade) {
    double cap;
    switch (grade) {
      case "A+":
        cap = 5.0;
        break;
      case "A":
        cap = 5.0;
        break;
      case "A-":
        cap = 4.5;
        break;
      case "B+":
        cap = 4.0;
        break;
      case "B":
        cap = 3.5;
        break;
      case "B-":
        cap = 3.0;
        break;
      case "C":
        cap = 2.5;
        break;
      default:
        cap = 0.0;
    }
    return cap;
  }

  public static void main(String[] args) {
    System.out.println("A+: " + getGradeCap("A+"));
    System.out.println("B : " + getGradeCap("B"));
  }
}
