class Fey : public Creature {
private:
    int type = 3; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength = DEFAULT_STRENGTH; // How much damage we can inflict
    int hitpoints = DEFAULT_HIT_POINTS; // How much damage we can sustain
    string getSpecies(); // Returns type of species
}
static const std::string ELF_NAME = "Elf";
class Elf : public Fey{
private:
    int type = 3;
    int strength = DEFAULT_STRENGTH;
    int strength = DEFAULT_HIT_POINTS;
    const string &getSpecies() const {
        return ELF_NAME;
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

};