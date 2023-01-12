#ifndef HW4_HEALER
#define HW4_HEALER
#include "Player.h"

class Healer : public Player{
    
public:
    Healer(const std::string name);
    void heal(int addHp) override;
    std::string getJob() const override;
    static std::shared_ptr<Healer> getPlayer(const std::string name);
    
};

#endif // HW4_HEALER