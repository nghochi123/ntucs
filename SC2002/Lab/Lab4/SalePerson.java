public class SalePerson implements Comparable {

  private String firstName;
  private String lastName;
  private int totalSales;

  public SalePerson(String firstName, String lastName, int totalSales) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.totalSales = totalSales;
  }

  public String toString() {
    return String.format("%s, %s: %d", lastName, firstName, totalSales);
  }

  public String getFirstName() {
    return firstName;
  }

  public String getLastName() {
    return lastName;
  }

  public int getTotalSales() {
    return totalSales;
  }

  public boolean equals(Object o) {
    SalePerson ppl = (SalePerson) o;
    return (
      ppl.getFirstName().equals(firstName) && ppl.getLastName().equals(lastName)
    );
  }

  public int compareTo(Object o) {
    SalePerson ppl = (SalePerson) o;
    if (ppl.getTotalSales() == totalSales) {
      return ppl.getLastName().compareTo(lastName);
    }
    return totalSales - ppl.getTotalSales();
  }
}
