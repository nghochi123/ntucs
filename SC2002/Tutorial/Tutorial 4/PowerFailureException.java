class PowerFailureException extends Exception {

  private String message;

  PowerFailureException() {
    this.message = "Power failure!";
  }

  PowerFailureException(String message) {
    this.message = message;
  }

  public String getMessage() {
    return this.message;
  }
}
