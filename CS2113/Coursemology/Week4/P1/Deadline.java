public class Deadline extends Todo {

  private String by;

  public Deadline(String description, String by) {
    super(description);
    this.by = by;
  }

  public String getBy() {
    return this.by;
  }

  public void setBy(String by) {
    this.by = by;
  }
}
