/*
 * Abhinav Ala <aala@scu.edu>
 * Isaac Amedie <iamedie@scu.edu>
 * Itay Volk <ivolk@scu.edu>
 */
#include <bitset>
#include <stdexcept>
#include <ostream>
#include "rng.h"
#include "dna.h"
#include "life.h"
#include <algorithm>

namespace csen79 {

// student to rewrite both
Life Life::cross(const Life& other) const {
    Life child;
    child.generation = std::max(generation, other.generation)+1;
    DNA blank(0);
    for (int i = 0; i < NChromo; i++) {
        child.dna[i] = blank;
    }
    for (int i = 0; i < NChromo/2; i++) {
        int index;
        do {
            index = rand_int(0, NChromo-1);
        } while (child.dna[index].matchDNA(blank) != child.dna[index].size());
        child.dna[index] = dna[index];
    }
    for (int i = 0; i < NChromo; i++) {
        if (child.dna[i].matchDNA(blank) != child.dna[i].size()) {
            child.dna[i] = other.dna[i];
        }
        int index = rand_int(0, child.dna[i].size()-1);
        child.dna[i].setCode(index, !child.dna[i].getCode(index));
    }
    return child;
}
const unsigned int Life::dnaMatch(int c, const DNA& other) const {return dna[c].matchDNA(other);}

std::ostream &operator<<(std::ostream &outs, const Life &source) {
    outs << "{";
    for (auto dna : source.dna) {
        outs << dna << ", ";
    }
    outs << "}";
    return outs;
}

}   // namespace csen79
