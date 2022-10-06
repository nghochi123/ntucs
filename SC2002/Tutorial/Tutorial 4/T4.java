class T4 {

  public static void main(String[] args) {
    int waitTime = 12;
    try {
      System.out.println("Try block entered");
      if (waitTime > 30) throw new Exception("Time Limited Exceeded");
      if (1 == 1) throw new PowerFailureException("You are gay.");
      System.out.println("Leaving try block");
    } catch (Exception e) {
      System.out.println("Exception: " + e.getMessage());
    }
    System.out.println("After catch block");
  }
}
