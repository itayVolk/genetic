/*
 * Abhinav Ala <aala@scu.edu>
 * Itay Volk <ivolk@scu.edu>
 */
#include <iostream>
#include <iomanip>
#include <random>
#include <stdexcept>
#include "rng.h"
#include "dna.h"
#include "life.h"
#include "select.h"
#include "arena.h"

using namespace std;

// Global RNG implementation
// anonymous namespace is visible only to this file
namespace {
    mt19937& global_rng() {
        static mt19937 rng(random_device{}());
        return rng;
    }
}

using namespace csen79;

int main() {
    // RNG seeded automatically in rng.h via random_device
    Arena tribe;    // constructor populates them with random "genes."
    double avgScore;
    double maturity;
    do {
        maturity = tribe.matured();
        tribe.compete();
        avgScore = tribe.averageScore();
        int n = tribe.highGeneration();
        cout << "Generation: " << setw(3) << n << 
            ", Average score: " << setw(8) << fixed << setprecision(4) << avgScore << 
            ", Maturity: " << maturity << endl;
        tribe.evolve();
    } while (maturity <= Arena::MATURITY);
    cout << "Population:" << endl << tribe << "Generation: " << setw(3) << tribe.highGeneration() << 
            ", Average score: " << setw(8) << fixed << setprecision(4) << avgScore << 
            ", Maturity: " << maturity << endl;
    return 0;
}

// RNG implementation
int rand_int(int lo, int hi) {
    if (hi <= lo) return lo;
    uniform_int_distribution<int> d(lo, hi);
    return d(global_rng());
}

bool rand_bool() {
    bernoulli_distribution d(0.5);
    return d(global_rng());
}
