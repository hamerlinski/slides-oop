public class Basic implements Pizza{
    private String s;
    private double d;

    public Basic(String s, double d) {
        this.s = s;
        this.d = d;
    }

    @Override
    public String description() {
        return this.s;
    }
    public double cost() {
        return this.d;
    }
}