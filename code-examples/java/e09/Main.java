public class Main {
    public static void main(String[] args) {
        Pizza p = new Order(new CoupleOrder(
            (new Basic("Margheritta", 18.00)),
            (new Basic("Capriciosa", 33.00)))
            , 0.15);
        String string = p.description();
        System.out.println(string);
    }
}