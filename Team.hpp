#include <iostream>

class Team {
public: 
	short points = 0;
	bool got_last_answer; // so for example we will check if current_guess == false && !got_lost_answer = -2 points

	void increment(int amt) {
		points = points + amt;
	}

	void decrease(int amt) {
		points = points - amt;
	}
};