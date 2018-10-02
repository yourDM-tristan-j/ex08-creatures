## Exercise: Creatures (25 Points)

The objective of this project is to learn about inheritance in the context of object oriented programming
and the syntax and semantics in C++.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions
[here](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki)
to get started.

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

### Requirements of this project

This project is based on the programming assignment described above from _Absolute C++_(5th Edition).

```cpp
class Creature {
private:
  int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
  int strength; // How much damage we can inflict
  int hitpoints; // How much damage we can sustain
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
```

Here is an implementation of the getSpecies( ) function:

```cpp
string Creature::getSpecies() {
  switch (type) {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
  }
  return "Unknown";
}
```

The `getDamage()` function outputs and returns the damage this creature can
inflict in one round of combat. The rules for calculating the damage are as follows:

- Every creature inflicts damage that is a random number `r`, where `0 < r <= strength`.
- Demons have a 5% chance of inflicting a demonic attack, which is an additional
50 damage points. Balrogs and Cyberdemons are demons.
- Elves have a 10% chance to inflict a magical attack that doubles the normal
amount of damage.
- Balrogs are very fast, so they get to attack twice.

An implementation of `getDamage( )` is given here:

```cpp
int Creature::getDamage( ) {
  int damage;
  // All creatures inflict damage, which is a
  // random number up to their strength
  damage = (rand( ) % strength) + 1;
  cout << getSpecies( ) << " attacks for " <<
  damage << "points!" << endl;
  // Demons can inflict damage of 50 with a 5% chance
  if ((type = 2) || (type == 1))
  if ((rand( ) % 100) < 5) {
    damage = damage + 50;
    cout << "Demonic attack inflicts 50 " << "additional damage points!" << endl;
  }
  // Elves inflict double magical damage with a 10% chance
  if (type == 3) {
    if ((rand( ) % 10)==0) {
      cout << "Magical attack inflicts " << damage<< "additional damage points!" << endl;
      damage = damage * 2;
    }
  }
  // Balrogs are so fast they get to attack twice
  if (type == 2) {
    int damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << "additional damage points!" << endl;
    damage = damage + damage2;
  }
  return damage;
}
```

One problem with this implementation is that it is unwieldy to add new creatures.
Rewrite the class to use inheritance, which will eliminate the need for the variable
type. The `Creature` class should be the base class. The classes `Demon` , `Elf` , and
`Human` should be derived from `Creature`. The classes `Cyberdemon` and `Balrog`
should be derived from Demon`. You will need to rewrite the `getSpecies()` and
`getDamage()` functions so they are appropriate for each class.

For example, the `getDamage()` function in each class should only compute the
damage appropriate for that object. The total damage is then calculated by com-
bining the results of `getDamage()` at each level of the inheritance hierarchy.
As an example, invoking `getDamage()` for a `Balrog` object should invoke
`getDamage()` for the `Demon` object, which should invoke `getDamage()` for the
`Creature` object. This will compute the basic damage that all creatures inflict,
followed by the random 5% damage that demons inflict, followed by the double
damage that balrogs inflict.

Also include mutator and accessor functions for the private variables. Write a main
function that contains a driver to test your classes. It should create an object for
each type of creature and repeatedly outputs the results of `getDamage()` . First ,
make the `getDamage()` function virtual . Then, make a function in your main
program, `battleArena(Creature &creature1, Creature &creature2 )`, that
takes two Creature objects as input. The function should calculate the damage
done by creature1 , subtract that amount from creature2’ s hit points, and vice
versa. If both creatures end up with zero or less hit points, then the battle is a tie.
Otherwise, at the end of a round, if one creature has positive hit points but the
other does not, then the battle is over. The function should loop until the battle is
either a tie or over. Since the `getDamage()` function is virtual, it should invoke
the `getDamage()` function defined for the specific creature. Test your program
with several battles involving different creatures.

In this assignment you will create several classes (in the namespace `edu::vcccd::vc::csv13`). These classes
resemble creatures from a simple game. I have supplied you with the implementation of the parent
class `Creature` and provided the implementations of all the common methods. You will then have
to add the `Balrog`, `Cyberdemon`, `Elf` and `Human` classes that all inherit from `Creature`.
Additionally, you will then provide the polymorphic implementations of the `getDamage` (for all 
but the `Human` classes) and `getSpecies` (for all the classes) methods.

The manner in which the damage is calculated is different for the `Balrog`, `Cyberdemon`, and
`Elf` classes, therefore, you should override the `getDamage` method in each of these classes.
The damage calculation for each of these classes is described in the book.

### Writing the code for this Project

For each of the `Balrog`, `Cyberdemon`, `Elf` and `Human` classes, you'll need to add `.h` and 
`.cc` files for each. Additionally, at the bottom of `creature.h` file you need to add `#include`
directives for each of these classes. For example, starting at line 49 add:

```cpp
// Include your Human, Cyberdemon, Balrog and Elf declarations here.
#include "human.h"
...
```

The `creature_unittest.cc` will not compile if you do not add these includes.

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `Creature | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
Human, Damage: 10
Cyber Demon, Damage: 6
Balrog, Damage: 10
Elf, Damage: 5

Process finished with exit code 0
```

Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `Creature_Gtest` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from CreatureTest
[ RUN      ] CreatureTest.Human
[       OK ] CreatureTest.Human (2 ms)
[ RUN      ] CreatureTest.CyberDemon
[       OK ] CreatureTest.CyberDemon (3 ms)
[ RUN      ] CreatureTest.Balrog
[       OK ] CreatureTest.Balrog (4 ms)
[ RUN      ] CreatureTest.Elf
[       OK ] CreatureTest.Elf (3 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 4 tests from CreatureTest (12 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (12 ms total)
[  PASSED  ] 4 tests.

Process finished with exit code 0
```

You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc` `balrog.cc`, `cyberdemon.cc`,
`elf.cc`, & `human.cc` (or whatever you called them) and `balrog.h`, `cyberdemon.h`, `elf.h`, &
`human.h`. Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Leave `Run git hooks` checked. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
