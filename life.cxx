/*
 * Abhinav Ala <aala@scu.edu>
 * Isaac Amedie <iamedie@scu.edu>
 * Itay Volk <ivolk@scu.edu>
 */
#include <bitset>
#include <stdexcept>
#include "rng.h"
#include "dna.h"
#include "life.h"
#include <algorithm>

namespace csen79 {

// student to rewrite both
Life Life::cross(const Life& other) const {
    Life child;
    child.generation = std::max(generation, other.generation)+1;
    for (int i = 0; i < NChromo; i++) {
        child.dna[i] = DNA(0);
    }
    for (int i = 0; i < NChromo/2; i++) {
        int index;
        do {
            index = rand_int(0, NChromo-1);
        } while (child.dna[index].count());
        child.dna[index] = dna[index];
    }
    for (int i = 0; i < NChromo; i++) {
        if (!child.dna[i].count()) {
            child.dna[i] = other.dna[i];
        }
    }
    return child;
}
const unsigned int Life::dnaMatch(int c, const DNA& other) const {return dna[c].matchDNA(other);}

}   // namespace csen79
