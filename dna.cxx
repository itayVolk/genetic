/*
 * Abhinav Ala <aala@scu.edu>
 * Isaac Amedie <iamedie@scu.edu>
 * Itay Volk <ivolk@scu.edu>
 */
#include "rng.h"
#include "dna.h"

namespace csen79 {

// Student to implement all of these member functions
DNA::DNA(unsigned int v) {
    // Initialize the bitset with the lower bits of v
    codes = static_cast<Gene>(v & mask);
}

bool DNA::getCode(const int i) const {
    // Return the bit at position i
    return codes.test(i);
}

void DNA::setCode(const int i, bool v) {
    // Set the bit at position i to value v
    codes.set(i, v);
}

size_t DNA::size() const {
    // Return the length of the DNA aka number of codes
    return codes.size();
}

size_t DNA::count() const {
    // Return the count of bits that are set to 1
    return codes.count();
}

unsigned int DNA::matchDNA(const DNA& other) const {
    // Return how many bits match between this DNA and the other DNA using xor
    return (codes ^ other.codes).flip().count();
}

}   // namespace csen79