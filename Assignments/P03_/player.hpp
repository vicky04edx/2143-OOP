#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    Player(const std::string& name);

    const std::string& getName() const;

private:
    std::string name;
};

#endif // PLAYER_HPP
