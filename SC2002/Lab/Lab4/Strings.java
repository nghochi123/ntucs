import java.util.Scanner;

public class Strings {

  // --------------------------------------------
  // Reads in an array of strings, sorts them,
  // then prints them in sorted order.
  // --------------------------------------------
  public static void main(String[] args) {
    String[] strlist;
    int size;
    Scanner scan = new Scanner(System.in);
    System.out.print("\nHow many strings do you want to sort? ");
    size = scan.nextInt();
    strlist = new String[size];
    System.out.println("\nEnter the strings...");
    for (int i = 0; i < size; i++) strlist[i] = scan.next();
    // Sorting.selectionSort(strlist);
    Sorting.insertionSort(strlist);
    System.out.println("\nYour strings in sorted order...");
    for (int i = 0; i < size; i++) System.out.print(strlist[i] + " ");
    System.out.println();
  }
}
