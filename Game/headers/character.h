
class Character {
 
public:

    Character(int hp = 100, int base_dmg = 10, int pos = 0, char model = '1'):
    hp_(hp),
    base_dmg_(base_dmg),
    pos_(pos),
    model_(model)
    {};

    int& GetHp() {
        return hp_;
    }

    int& GetDmg() {
        return base_dmg_;
    }

    int& GetPos() {
        return pos_;
    }

    char& GetModel() {
        return model_;
    }

    void Move(int val) {
        pos_ += val;
    }

    void Attack(Character& chr) {
        chr.hp_ -= base_dmg_;
    }

private:

    int hp_;
    int base_dmg_;
    int pos_;
    char model_;
};

inline std::ostream& operator<<(std::ostream& os, Character& ch) {
    os << ch.GetHp() << std::endl
       << ch.GetDmg() << std::endl
       << ch.GetPos() << std::endl;
    return os;
}