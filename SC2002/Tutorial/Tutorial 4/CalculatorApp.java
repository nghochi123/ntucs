import java.util.Scanner;

class CalculatorApp {

  public static void main(String[] args) {
    SimpleCalculator calc = new SimpleCalculator();
    Scanner sc = new Scanner(System.in);
    System.out.println("Calculator is on.");
    char operator;
    double operand = 0.0;
    do {
      System.out.printf("Result: %.1f\n", calc.getResult());
      operator = sc.next().charAt(0);
      if (operator == 'q' || operator == 'Q') {
        continue;
      }
      operand = sc.nextDouble();
      try {
        switch (operator) {
          case '+':
            calc.add(operand);
            break;
          case '-':
            calc.subtract(operand);
            break;
          case '*':
            calc.multiply(operand);
            break;
          case '/':
            calc.divide(operand);
            break;
          default:
            throw new UnknownOperatorException(operator);
        }
      } catch (UnknownOperatorException e) {
        System.out.println("Exception: " + e.getMessage());
      } catch (Exception e) {
        System.out.println("Not Unknow Exception: " + e.getMessage());
        break;
      }
    } while (operator != 'Q' && operator != 'q');
    System.out.printf("Final Result: %.1f\n", calc.getResult());
    System.out.println("End of program");
  }
}
