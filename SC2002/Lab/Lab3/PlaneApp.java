import java.lang.Math;
import java.util.Scanner;

public class PlaneApp {

  private static Plane pln = new Plane();

  public static void main(String[] args) {
    int choice;
    Scanner sc = new Scanner(System.in);
    System.out.println("Welcome to PlaneApp.");
    do {
      System.out.println("Please enter your choice:");
      System.out.println("(1) Show number of empty seats");
      System.out.println("(2) Show list of empty seats");
      System.out.println("(3) Show list of seat assignments by seat ID");
      System.out.println("(4) Show list of seat assignments by customer ID");
      System.out.println("(5) Assign a customer to a seat");
      System.out.println("(6) Remove a seat assignment");
      System.out.println("(7) Exit");
      choice = sc.nextInt();
      int sid, cid;
      switch (choice) {
        case 1: // Show number of empty seats
          pln.showNumEmptySeats();
          break;
        case 2: // Show list of empty seats
          pln.showEmptySeats();
          break;
        case 3: // Show list of seat assignments by seat ID
          pln.showAssignedSeats(true);
          break;
        case 4: // Show list of seat assignments by customer ID
          pln.showAssignedSeats(false);
          break;
        case 5: // Assign customer to seat
          System.out.printf("Please enter the seat you want to assign: ");
          sid = sc.nextInt();
          System.out.printf(
            "Please enter the customer you would like to assign to seat %d: ",
            sid
          );
          cid = sc.nextInt();
          pln.assignSeat(sid, cid);
          break;
        case 6: // Remove seat assignment
          System.out.printf("Please enter the seat you want to un-assign: ");
          sid = sc.nextInt();
          pln.unAssignSeat(sid);
          break;
        case 7:
          System.out.println("Program Terminating");
      }
    } while (choice < 7);
  }
}
