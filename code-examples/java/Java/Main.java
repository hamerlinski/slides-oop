package Java;

public class Main {
    public static void main(String[] args) {
        Shape shape1 = new Rectangle(5, 8);
        Shape shape2 = new Circle(4);

        System.out.println("Area of shape1: " + shape1.getArea()); // Output: "Area of shape1: 40.0"
        System.out.println("Area of shape2: " + shape2.getArea()); // Output: "Area of shape2: 50.26548245743669"
    }
}
