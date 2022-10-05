public class VendingMachine(){
    public Drink[] drinks;
    public VendingMachine(Drink[] drinks) {
        this.Drink = drinks;
    }
    public double selectDrink(){}
    public double insertCoins(double drinkCost){}
    public void checkChange(double amount, double drinkCost){}
    public void printReceipt(){}
}