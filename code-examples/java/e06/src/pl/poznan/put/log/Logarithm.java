package pl.poznan.put.log;

// Before refactor
public class Logarithm implements Number {

  private double base, argument;

  @Override
  public double doubleValue() {
    return Math.log(this.argument) / Math.log(this.base);
  }

  public Logarithm(double inputBase, double inputArgument) {
    this.base = inputBase;
    this.argument = inputArgument;
  }
}
