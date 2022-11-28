package pl.poznan.put.content;

public final class Character implements Symbol {

  private final char characterValue;

  @Override
  public char value() {
    return this.characterValue;
  }

  public Character(int inputCharacterCode) {
    this.characterValue = (char) inputCharacterCode;
  }


}
