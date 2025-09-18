#include <iostream>

class Quadrupede {
    private:
        std::string nom;
    public:
        std::string get_name() {
            return nom;
        }
        void set_name(std::string name) {
            nom = name;
        }
};

class Chien : public Quadrupede {
    public:
        Chien(std::string name) {
            std::cout << "hey je suis le chien " << name << std::endl;
            set_name(name);
        }
        void speak()  {
            std::cout << "WAF" << std::endl;
        }

};


class Chat : public Quadrupede {
    public:
        Chat(std::string name) {
            std::cout << "hey je suis le chat " << name << std::endl;
            set_name(name);
        }
        void speak()  {
            std::cout << "MIAOU" << std::endl;
        }

        ~Chat() {
            delete this;
        }
};

int main() {
    Chat chat("graven");
    Chien chien("oiseau");
    std::cout << chien.get_name() << std::endl;
    chien.set_name("test");
    std::cout <<chien.get_name() << std::endl;

    chat.speak();
    chien.speak();
    return 0;
}
