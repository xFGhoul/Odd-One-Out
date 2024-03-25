// Odd One Out.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <random>

#include "Team.hpp"

using namespace std;


auto choose_random_guess(vector<map<string, bool>> guesses) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, guesses.size() - 1);

    int randomIndex = distr(gen);

    auto random_guess = guesses[randomIndex];

    return random_guess;
}
 
int main()
{
    Team TeamA;
    Team TeamB;

    vector<map<string, bool>> guesses = {
        {{"something", false}, {"okay", true}, {"test", false}}
    };

    cout << "Welcome To Odd One Out" << endl;

    while (TeamA.points < 10 && TeamB.points < 10) {


        cout << "Team A Points: " << TeamA.points << endl;
        cout << "Team B Points: " << TeamB.points << endl;

        auto guess = choose_random_guess(guesses);

        cout << "Listing The Guesses" << endl;

        for (auto kv : guess) {
            cout << kv.first << endl;
        }

        string current_try;

        cout << "Which one is the odd one out?: " << endl;
        cin >> current_try;

        for (auto kv : guess) {
            if (kv.first == current_try && kv.second == true) {
                cout << "You have guessed correctly! +2 points" << endl;
                TeamA.increment(2);
            }
        }
    }

    // wait jn lemme share my whole screen


}

