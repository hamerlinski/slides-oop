#include <string>
class String {
 public:
  String(char *ch);                  // Declare constructor
  ~String();                         // and destructor.
 private:
  char *_text;
  size_t sizeOfText;
};
String::String(char *ch) {           // Define the constructor.
  sizeOfText = strlen(ch) + 1;
  _text = new char[sizeOfText];      // Dynamically allocate the correct amount of memory.
  if (_text)
    strcpy(_text, ch);               // If the allocation succeeds, copy the initialization string.
}
String::~String() {                  // Define the destructor.
  delete[] _text;                    // Deallocate the memory that was previously reserved for this string.
}
int main() {
  String str("The point is there ain't no point.");
}