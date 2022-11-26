public class Calculator implements MathOperation {

  public Calculator() {
  }

  ;

  @Override
  public int fraction(int numerator, int denominator) {
    try {
      return numerator / denominator;
    } catch (ArithmeticException e) {
      System.out.println("Error: " + e);
      return 0;
    }
  }
}
