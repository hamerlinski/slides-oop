public class Order implements Pizza{
    private Pizza s;
    private double tip;

    public Order(Pizza s, double tip) {
        this.s = s;
        this.tip = tip;
    }

    @Override
    public String description() {
        return "Please, " + this.s.description();
    }
    public double cost(){
        return this.s.cost()*(1+tip);
    }
}