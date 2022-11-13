#ifndef CPP_AUTHOR_H
#define CPP_AUTHOR_H


class Author {
private:
    std::string firstName;
    std::string lastName;


public:
    std::string name() {
        return this->firstName + " " + this->lastName;
    }

    Author(std::string firstName, std::string lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }

    Author() {}
};


#endif //CPP_AUTHOR_H
