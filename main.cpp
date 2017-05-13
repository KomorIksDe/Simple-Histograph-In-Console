#include <iostream>
#include <vector>
#include <utility>
#include <conio.h>
#include <windows.h>

class DataHolder {
    private:
        std::vector< std::pair<char, unsigned> > letters;

    public:
        bool isThere(char character) {
            for(unsigned i = 0; i < this->letters.size(); i++) {
                if(this->letters[i].first == character)
                    return true;
            }

            return false;
        }

        void loadData(char character, unsigned value) {
            this->letters.push_back(std::make_pair(character, value));
        }

        void incrementValueFor(char character) {
            for(unsigned i = 0; i < this->letters.size(); i++) {
                if(this->letters[i].first == character) {
                    this->letters[i].second++;
                    break;
                }
            }
        }

        void loadLetter(char character) {
            if(this->isThere(character)) {
                this->incrementValueFor(character);
            }
            else {
                this->loadData(character, 1);
            }
        }

        char getNishLetter(int n) const {
            return this->letters[n].first;
        }

        unsigned getNishValue(int n) const {
            return this->letters[n].second;
        }

        unsigned lettersCount() const {
            return this->letters.size();
        }
};

class Histograph {
    private:
        DataHolder dHolder;

    public:
        void loadHistographData(std::string& sentence) {
            for(unsigned i = 0; i < sentence.length(); i++) {
                if(sentence[i] == ' ') {
                    continue;
                }
                else {
                    this->dHolder.loadLetter(sentence[i]);
                }
            }
        }

        void printHistograph() {
            for(unsigned i = 0; i < dHolder.lettersCount(); i++) {
                std::cout<<dHolder.getNishLetter(i)<<" ";

                for(unsigned j = 0; j < dHolder.getNishValue(i); j++)
                    std::cout<<"#";

                std::cout<<std::endl;
            }
        }
};

int main() {
    Histograph myHistograph;
    std::string sentence;

    std::cout<<"Type in your sentence: ";
    std::getline(std::cin, sentence);

    system("cls");
    std::cout<<"Your sentence's histograph ("<<sentence<<")"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl<<std::endl;

    myHistograph.loadHistographData(sentence);
    myHistograph.printHistograph();
    getch();

    return 0;
}
