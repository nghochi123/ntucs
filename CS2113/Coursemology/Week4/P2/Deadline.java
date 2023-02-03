public class Deadline extends Todo {

  protected String by;

  public Deadline(String description, String by) {
    super(description);
    this.by = by;
  }

  public void setBy(String by) {
    this.by = by;
  }

  public String getBy() {
    return by;
  }

  @Override
  public String toString() {
    return String.format("%s\ndo by: %s", super.toString(), by);
  }
}
