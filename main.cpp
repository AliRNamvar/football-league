#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

// ***** Start Prototypes ****** //
vector<string> read_game_score(void);
bool check_correct_team_input(string);
bool check_correct_score_input(string);

// *****  End Prototypes  ****** //


int main(int argc, char const *argv[]) {
   
    vector<string> one_game_info = read_game_score();
    cout << "teams: " << one_game_info[0] << "\tscores: " << one_game_info[1] <<endl;
    return 0;
}



vector<string> read_game_score(void) {
    
    string team_inputs{};
    string score_inputs{};

    // Try to get teams and score in right format
    do {
        cout << "Which teams have a play? (enter team A & B in \"A - B\" form)\n";
        getline(cin, team_inputs);
    }
    while (!check_correct_team_input(team_inputs));

    do {
        cout << "What is the score? (enter team's score A & B in \"A - B\" form)\n";
        getline(cin, score_inputs);
    }
    while (!check_correct_score_input(score_inputs));

    // returning teams and score inputs
    vector<string> output{};
    output.push_back(team_inputs);
    output.push_back(score_inputs);
    return output;
}

bool check_correct_team_input(string check) {
    
    if (regex_match (check, regex(("^.* - .*$"))))
        return true;
    return false;
}

bool check_correct_score_input(string check) {
    
    if (regex_match (check, regex(("^[0-9]+ - [0-9]+$"))))
        return true;
    return false;
}
