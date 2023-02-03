public class Person implements Printable {

  private String name;

  public Person(String name) {
    this.name = name;
  }

  public void print() {
    System.out.println("Person of name " + name);
  }
}
