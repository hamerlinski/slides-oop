package pl.poznan.put;

import java.io.IOException;

public interface Content {

  void read() throws IOException;

  void delete() throws Exception;
}
