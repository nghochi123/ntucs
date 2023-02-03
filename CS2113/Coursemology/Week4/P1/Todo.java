public class Todo extends Task {

  private boolean isDone;

  public Todo(String description) {
    super(description);
    this.isDone = false;
  }

  public boolean isDone() {
    return this.isDone;
  }

  public void setDone(boolean isDone) {
    this.isDone = isDone;
  }
}
