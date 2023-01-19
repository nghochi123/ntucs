import java.util.Arrays;

public class emails {

  public static String[] filterEmails(String[] items) {
    // TODO: add your code here
    String[] filtered = new String[items.length];
    int idx = 0;
    for (String s : items) {
      if (s.contains("@")) {
        filtered[idx] = s;
        idx += 1;
      }
    }
    return Arrays.copyOf(filtered, idx);
  }

  public static void printItems(String[] items) {
    // TODO: add your code here
    String st = "[";
    int first = 0;
    for (String s : items) {
      if (first != 0) {
        st += ", ";
      }
      st += s;
      first = 1;
    }
    st += "]";
    System.out.println(st);
  }

  public static void main(String[] args) {
    printItems(filterEmails(new String[] {}));
    printItems(filterEmails(new String[] { "abc" }));
    printItems(
      filterEmails(
        new String[] { "adam@example.com", "aab", "john@example.com", "some@" }
      )
    );
    printItems(filterEmails(new String[] { "xyz", "@bee.com", "aab" }));
  }
}
