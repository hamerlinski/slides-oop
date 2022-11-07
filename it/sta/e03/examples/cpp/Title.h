#ifndef CPP_TITLE_H
#define CPP_TITLE_H

class Title {
private:
    std::string polishTitle;
    std::string englishTitle;


public:
    std::string value(std::string langIsoCode) {
        return langIsoCode == "ENG" ? this->englishTitle : this->polishTitle;
    }

    Title(std::string polishTitle, std::string englishTitle) {
        this->polishTitle = polishTitle;
        this->englishTitle = englishTitle;
    }

    Title() {}
};


#endif //CPP_TITLE_H
