package pl.poznan.put;

public class Title {
  private String polishTitle;
  private String englishTitle;

  Title(String polishTitle, String englishTitle) {
    this.polishTitle = polishTitle;
    this.englishTitle = englishTitle;
  }

  public String title(String langIsoCode) {
    return langIsoCode == "PL" ? this.polishTitle : this.englishTitle;
  }
}
