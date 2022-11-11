
#ifndef CPP_ISBN_H
#define CPP_ISBN_H


class ISBN {
private:
    std::string value;


public:
    std::string isbnValue() {
        return this->value;
    }

    ISBN(std::string value) {
        this->value = value;
    }

    ISBN() {}
};


#endif //CPP_ISBN_H
