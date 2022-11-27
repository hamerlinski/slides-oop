package pl.poznan.put;

import java.io.IOException;

public class Main {

  public static void main(String[] args) {
    FileContent fileContent = new FileContent("/var/tmp/test.txt");
    try {
      System.out.println("File content:");
      fileContent.read();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }
    try {
      System.out.println("File content deletion");
      fileContent.delete();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    try {
      System.out.println("File content:");
      fileContent.read();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }
  }
}