import java.util.Arrays;

public class Plane {

  private int NUMSEATS = 12;
  private PlaneSeat[] seat = new PlaneSeat[NUMSEATS];
  private int numEmptySeat;

  public Plane() {
    for (int i = 0; i < NUMSEATS; i++) {
      seat[i] = new PlaneSeat(i);
    }
    numEmptySeat = NUMSEATS;
  }

  public PlaneSeat[] sortSeats() {
    PlaneSeat[] copyOfSeats = new PlaneSeat[NUMSEATS];
    System.arraycopy(seat, 0, copyOfSeats, 0, NUMSEATS);
    Arrays.sort(copyOfSeats, (a, b) -> a.getCustomerId() - b.getCustomerId());
    return copyOfSeats;
  }

  public void showNumEmptySeats() {
    System.out.printf("There are %d empty seats.\n", numEmptySeat);
  }

  public void showEmptySeats() {
    for (int i = 0; i < NUMSEATS; i++) {
      if (!seat[i].isOccupied()) System.out.printf(
        "Seat %d is empty\n",
        seat[i].getSeatId() + 1
      );
    }
  }

  public void showAssignedSeats(boolean bySeatId) {
    if (bySeatId) {
      for (int i = 0; i < NUMSEATS; i++) {
        if (seat[i].isOccupied()) System.out.printf(
          "Seat %d is occupied by customer id %d\n",
          seat[i].getSeatId() + 1,
          seat[i].getCustomerId()
        );
      }
      return;
    }
    PlaneSeat[] seatsResorted = sortSeats();
    for (int i = 0; i < NUMSEATS; i++) {
      if (seatsResorted[i].isOccupied()) System.out.printf(
        "Seat %d is occupied by customer id %d\n",
        seatsResorted[i].getSeatId() + 1,
        seatsResorted[i].getCustomerId()
      );
    }
  }

  public void assignSeat(int seatId, int cust_id) {
    if (!seat[seatId - 1].isOccupied()) {
      seat[seatId - 1].assign(cust_id);
      numEmptySeat--;
      System.out.printf(
        "Seat %d has been assigned to customer %d\n\n",
        seatId,
        cust_id
      );
      return;
    }
    System.out.printf(
      "This seat is already assigned to customer %d.\n",
      seat[seatId - 1].getCustomerId()
    );
  }

  public void unAssignSeat(int seatId) {
    if (seat[seatId - 1].isOccupied()) {
      seat[seatId - 1].unAssign();
      numEmptySeat++;
      System.out.printf("Seat %d has been unassigned\n\n", seatId);

      return;
    }
    System.out.printf("This seat is not assigned to anyone.\n");
  }
}
