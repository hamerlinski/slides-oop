package lesson3;

public class Title {
  private final String polishTitle;
  private final String englishTitle;

  Title(String polishTitle, String englishTitle) {
    this.polishTitle = polishTitle;
    this.englishTitle = englishTitle;
  }

  public String title(String langIsoCode) {
    return langIsoCode.equals("ENG") ? this.englishTitle : this.polishTitle;
  }
}
