#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// ***** Prototypes ****** //
void read_game_score(void);
bool check_correct_team_input(string);


int main(int argc, char const *argv[])
{
    // std::cout << "Hello boy!";


    read_game_score();
    return 0;
}



void read_game_score(void) {
    
    string user_input{};
    bool team_input_correctness = false;
    cout << "Which teams have a play? (enter team A & B in \"A - B\" form)\n";
    string team_inputs{};
    getline(cin, team_inputs);

    team_input_correctness = check_correct_team_input(team_inputs);
    cout << team_input_correctness;
    /*ofstream read_from_cli1;
    read_from_cli1.open("scores.txt", ios::app);
    read_from_cli1 << input;
    read_from_cli1.close();*/

}


bool check_correct_team_input(string check) {
    
    if (regex_match (check, regex(("^.* - .*$"))))
        return true;
    return false;
}