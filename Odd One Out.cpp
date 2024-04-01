// Odd One Out.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


int main()
{
    // Initialize Variables

    // Team Points
    int team_a_points = 0;
    int team_b_points = 0;
    int points_needed_to_win = 20;

    // Variables to be used for Double Incorrect Logic
    int team_a_wrong_answers = 0;
    int team_b_wrong_answers = 0;

    // Choosing Which Team's Turn
    bool team_a_turn = true;
    bool team_b_turn = false;

    // Varialbe Used For Reading Lines In File
    int size = 0;

    // Arrays That Stores Cards and Answers
    string deck[5];
    string answers[5];
    string categories[5];

    // User Answer (Reusable)
    string answer;

    // Card File Handler
    ifstream Fcards("cards.txt");
    if (!Fcards) {
        cout << "Error Opening Cards File!" << endl;
        return 0;
    }

    // Answers File Handler
    ifstream Fanswers("answers.txt");
    if (!Fanswers) {
        cout << "Error Opening Answers File!" << endl;
        return 0;
    }

    // Category File Handler
    ifstream Fcategories("category.txt");
    if (!Fcategories) {
        cout << "Error Opening Categories File!" << endl;
        return 0;
    }

    // Reading Files Into Arrays
    string line;
    while (getline(Fcards, line, '\n')) {
        deck[size] = line;
        size += 1;
    }

    size = 0; // reset size

    while (getline(Fanswers, line, '\n')) {
        answers[size] = line;
        size += 1;
    }

    size = 0; // reset size

    while (getline(Fcategories, line, '\n')) {
        categories[size] = line;
        size += 1;
    }
    
    cout << "Welcome To Odd One Out!\n" << endl;

    while (team_a_points < points_needed_to_win && team_b_points < points_needed_to_win) {

        if (team_a_turn) {
            // List Points
            cout << "Team A Points: " << team_a_points << endl;
            cout << "Team B Points: " << team_b_points << endl;

            int random_card = rand() % 3;

            cout << "\nDisplaying Options: " << endl;
            cout << deck[random_card] << endl;

            cout << "\nTeam A's Choice To Choose The Odd One Out" << endl;
            cout << "Enter The Odd One Out: " << endl;
            cin >> answer;

            if (answer == answers[random_card]) {
                cout << "\nCorrect!, Team A Guessed Correctly!" << endl;
                team_a_points = team_a_points + 2;

                if (team_a_points >= points_needed_to_win) {
                    cout << "\nTeam A Won The Game!!!" << endl;
                    break;
                }
            }
            else {
                team_a_wrong_answers = team_a_wrong_answers + 1;

                cout << "\nTeam A Entered The Incorrect Odd One Out" << endl;
                cout << "Team B You Now Have A Choice To Enter The Odd One Out" << endl;

                cout << "\nEnter The Odd One Out: " << endl;
                cin >> answer;

                if (answer == answers[random_card]) {
                    cout << "Team B Got It Correct" << endl;
                    team_b_points = team_b_points + 1;

                    if (team_b_points >= points_needed_to_win) {
                        cout << "\nTeam B Won The Game!!!" << endl;
                        break;
                    }
                }
                else {
                    cout << "Both Teams Got The Odd One Out Incorrect, No Points Awarded!" << endl;
                }

                if (team_a_wrong_answers >= 2) {
                    cout << "Deducting 1 Point From Team A For Double Incorrect" << endl;
                    team_a_points = team_a_points - 1;
                    team_a_wrong_answers = 0; // reset points
                }
            }

            cout << "The Category Was: " << categories[random_card] << endl;
            cout << "The Answer Was: " << answers[random_card] << endl;

            team_a_turn = false;
            team_b_turn = true;

            Sleep(3000);
            system("cls");
        }

        if (team_b_turn) {
            // List Points
            cout << "Team A Points: " << team_a_points << endl;
            cout << "Team B Points: " << team_b_points << endl;

            int random_card = rand() % 3;

            cout << "\nDisplaying Options: " << endl;
            cout << deck[random_card] << endl;

            cout << "\nTeam B's Choice To Choose The Odd One Out" << endl;
            cout << "Enter The Odd One Out: " << endl;
            cin >> answer;

            if (answer == answers[random_card]) {
                cout << "\nCorrect!, Team B Guessed Correctly!" << endl;
                team_b_points = team_b_points + 2;
            }
            else {
                team_b_wrong_answers = team_b_wrong_answers + 1;

                cout << "\nTeam B Entered The Incorrect Odd One Out" << endl;
                cout << "Team A You Now Have A Choice To Enter The Odd One Out" << endl;

                cout << "\nEnter The Odd One Out: " << endl;
                cin >> answer;

                if (answer == answers[random_card]) {
                    cout << "Team A Got It Correct" << endl;
                    team_a_points = team_a_points + 1;
                }
                else {
                    cout << "Both Teams Got The Odd One Out Incorrect, No Points Awarded!" << endl;
                }

                if (team_b_wrong_answers >= 2) {
                    cout << "Deducting 1 Point From Team B For Double Incorrect" << endl;
                    team_b_points = team_b_points - 1;
                    team_b_wrong_answers = 0; // reset points
                }
            }

            cout << "The Category Was: " << categories[random_card] << endl;
            cout << "The Answer Was: " << answers[random_card] << endl;

            team_a_turn = true;
            team_b_turn = false;

            Sleep(3000);
            system("cls");
        }

    }

    cout << "\nTeam A Points: " << team_a_points << endl;
    cout << "Team B Points: " << team_b_points << endl;
    
    return 0;
}

