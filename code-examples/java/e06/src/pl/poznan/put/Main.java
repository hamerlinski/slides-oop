package pl.poznan.put;

import java.io.IOException;
import pl.poznan.put.content.FileContent;
import java.util.Scanner;
import pl.poznan.put.log.Logarithm;

public class Main {

  public static void main(String[] args) {
    System.out.print("Select example...\n[0] - FileContent\n[1] - Logarithm\nOption: ");
    Scanner scan = new Scanner(System.in);
    int example = scan.nextInt();
    if (example == 0){
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

    } else if (example == 1) {
      try {
        Logarithm logarithm = new Logarithm(2,8);
        System.out.println(logarithm.doubleValue());
      }catch (Exception ex){
        System.out.println("Logarithm operation failed: " + ex.getMessage());
      }
    }
  }
}