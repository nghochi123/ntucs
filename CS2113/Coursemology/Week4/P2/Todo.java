public class Todo extends Task {

  protected boolean isDone;

  public Todo(String description) {
    super(description);
    isDone = false;
  }

  public void setDone(boolean done) {
    isDone = done;
  }

  public boolean isDone() {
    return isDone;
  }

  @Override
  public String toString() {
    return String.format(
      "%s\nis done? %s",
      super.toString(),
      isDone ? "Yes" : "No"
    );
  }
}
