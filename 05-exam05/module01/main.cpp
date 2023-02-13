#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

// int main() {
//     Warlock richard("Richard", "the Titled");

//     Dummy bob;
//     Fwoosh *fwoosh = new Fwoosh();

//     richard.learnSpell(fwoosh);

//     richard.introduce();
//     richard.launchSpell("Fwoosh", bob);

//     richard.forgetSpell("Fwoosh");
//     richard.launchSpell("Fwoosh", bob);
// }

int main(void) {
    std::cout << "--- Constructors:\n";

    Warlock richard("Richard", "Master of the Universe");
    Fwoosh *spell = new Fwoosh();
    Dummy targetPractice;

    std::cout << "--- \"Fwoosh\" not learned:\n";

    richard.launchSpell("Fwoosh", targetPractice);

    std::cout << "--- \"Fwoosh\" learned:\n";

    richard.learnSpell(spell);
    richard.launchSpell("Fwoosh", targetPractice);

    std::cout << "--- Forgotten \"Fwoosh\":\n";

    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", targetPractice);

    std::cout << "--- Non-existant spell:\n";

    richard.launchSpell("Splash", targetPractice);
    richard.forgetSpell("Splash");
    richard.launchSpell("Splash", targetPractice);

    std::cout << "--- Destructors:\n";
    return (0);
}
