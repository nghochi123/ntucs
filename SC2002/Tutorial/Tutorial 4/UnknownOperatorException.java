class UnknownOperatorException extends Exception {

  UnknownOperatorException() {
    super("Unknown Operator defined.");
  }

  UnknownOperatorException(char operator) {
    super(
      String.format("%c is an unknown operator.\nPlease reenter:\n", operator)
    );
  }

  UnknownOperatorException(String message) {
    super(message);
  }
}
