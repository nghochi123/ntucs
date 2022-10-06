class SimpleCalculator {

  private double result;

  SimpleCalculator() {
    this.result = 0;
  }

  void printResult(char operator, double value) {
    System.out.printf(
      "result %c %.1f = %.1f\nupdated result = %.1f\n",
      operator,
      value,
      this.result,
      this.result
    );
  }

  void add(double value) {
    this.result += value;
    printResult('+', value);
  }

  void subtract(double value) {
    this.result -= value;
    printResult('-', value);
  }

  void multiply(double value) {
    this.result *= value;
    printResult('*', value);
  }

  void divide(double value) {
    this.result /= value;
    printResult('/', value);
  }

  double getResult() {
    return this.result;
  }
}
