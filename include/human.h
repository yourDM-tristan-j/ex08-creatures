class Human : public Creature {
private:
    int type = 0; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength = DEFAULT_STRENGTH; // How much damage we can inflict
    int hitpoints = DEFAULT_HIT_POINTS; // How much damage we can sustain
    string getSpecies(); // Returns type of species
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