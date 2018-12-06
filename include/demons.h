class Demons : public Creature {
private:

}

static const std::string CYBERDEMON_NAME = "CyberDemon";
static const std::string BALROG_NAME = "BALROG";
class Cyberdemon : public Demons{
private:
    int type = 1;
    int strength = DEFAULT_STRENGTH;
    int strength = DEFAULT_HIT_POINTS;
    const string &getSpecies() const {
        return CYBERDEMON_NAME;
    };

public :
    Creature( );
    // Initialize to human, 10 strength, 10 hit points
    Creature( int newType, int newStrength, int newHit);
    // Initialize creature to new type, strength, hit points
    // Also add appropriate accessor and mutator functions
    // for type, strength, and hit points
    int getDamage();
    // Returns amount of damage this creature
    // inflicts in one round of combat
};

class Balrog : public Demons {
private:
    int type = 2;
    int strength = DEFAULT_STRENGTH;
    int strength = DEFAULT_HIT_POINTS;
    const string &getSpecies() const {
        return BALROG_NAME;
    };

public :
    Creature( );
    // Initialize to human, 10 strength, 10 hit points
    Creature( int newType, int newStrength, int newHit);
    // Initialize creature to new type, strength, hit points
    // Also add appropriate accessor and mutator functions
    // for type, strength, and hit points
    int getDamage();
    // Returns amount of damage this creature
    // inflicts in one round of combat
};