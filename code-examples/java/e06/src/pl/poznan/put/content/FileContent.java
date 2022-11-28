package pl.poznan.put.content;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public final class FileContent implements Content {

  private final String filePath;

  @Override
  public void read() throws IOException {
    File file = new File(this.filePath);
    FileInputStream stream = new FileInputStream(file);
    int i;
    while ((i = stream.read()) != -1) {
      Character character = new Character(i);
      System.out.print(character.value());
    }
    stream.close();
  }

  @Override
  public void delete() throws Exception {
    File file = new File(this.filePath);
    if (!file.exists()) {
      throw new IOException(
          String.format(
              "File %s doesn't exist",
              file.getAbsolutePath()
          )
      );
    } else {
      BufferedWriter writer = Files.newBufferedWriter(Paths.get(this.filePath));
      writer.write("");
      writer.flush();
    }
  }

  public FileContent(String inputFilePath) {
    this.filePath = inputFilePath;
  }
}