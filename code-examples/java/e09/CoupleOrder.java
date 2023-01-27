public class CoupleOrder implements Pizza{

    private Pizza a;
    private Pizza b;

    public CoupleOrder(Pizza a, Pizza b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public String description() {
        return this.a.description() + " and " + this.b.description();
    }
    public double cost(){
        return this.a.cost() + this.b.cost();
    }

}