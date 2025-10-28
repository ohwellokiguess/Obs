#include <vector>

class Map {

public:

    Map(std::vector<char> map = {}){};

    std::vector<char>& GetMap() {
    return map_;
}

    void GenerateMap() {   
        for (int i = 0; i <= 20; ++i) {
            map_.push_back('0');
        }
    }

private:
    std::vector<char> map_;
};

inline std::ostream& operator<<(std::ostream& os, Map& map) {
        for (int i = 0; i < map.GetMap().size(); ++i) {
            os << map.GetMap()[i];
        }
        return os;
    }