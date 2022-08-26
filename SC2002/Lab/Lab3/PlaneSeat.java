public class PlaneSeat {

  private int seatId;
  private boolean assigned;
  private int customerId;

  public PlaneSeat() {
    seatId = -1;
    assigned = false;
    customerId = -1;
  }

  public PlaneSeat(int seat_id) {
    this.seatId = seat_id;
    this.assigned = false;
    this.customerId = -1;
  }

  public int getSeatId() {
    return seatId;
  }

  public int getCustomerId() {
    return customerId;
  }

  public boolean isOccupied() {
    return assigned;
  }

  public void assign(int cust_id) {
    customerId = cust_id;
    assigned = true;
  }

  public void unAssign() {
    assigned = false;
  }
}
