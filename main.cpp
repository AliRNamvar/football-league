#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

// ***** Start Prototypes  ****** //

vector<string> read_game_score(void);
bool check_correct_team_input(string);
bool check_correct_score_input(string);
bool check_correct_week(string);
void write_gameinfo_2_file(vector<string>, string del = "-");

// ***** End of Prototypes ****** //


// ***** Start of Global Variables ***** //
// ***** End of Global Variables   ***** //

int main(int argc, char const *argv[]) {

    vector<string> one_game_info = read_game_score();
    cout << "teams: " << one_game_info[0] << "\tscores: " << one_game_info[1] << "\tweek: " << one_game_info[2] <<endl;

    write_gameinfo_2_file(one_game_info);
    return 0;
}

void write_gameinfo_2_file(vector<string> game_info, string del) {

    fstream myfile("game_informations.csv", ios::app);
    
    myfile << game_info[2] << ",";
    string s = game_info[0];
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        myfile << s.substr(start, end - start) << ",";
        start = end + del.size();
        end = s.find(del, start);
    }
    myfile << s.substr(start, end - start) << ",";

    s = game_info[1];
    start = 0;
    end = s.find(del);
    while (end != -1) {
        myfile << s.substr(start, end - start) << ",";
        start = end + del.size();
        end = s.find(del, start);
    }
    myfile << s.substr(start, end - start) << endl;
    myfile.close();
}

vector<string> read_game_score(void) {
    
    string team_inputs{};
    string score_inputs{};
    string week{};

    // Try to get teams and score in right format
    do {
        cout << "Which week is it?\n";
        getline(cin, week);
    }
    while (!check_correct_week(week));

    do {
        cout << "Which teams have a play? (Enter team A & B in \"A-B\" form)\n";
        getline(cin, team_inputs);
    }
    while (!check_correct_team_input(team_inputs));

    do {
        cout << "What is the score? (\"A-B\" form)\n";
        getline(cin, score_inputs);
    }
    while (!check_correct_score_input(score_inputs));


    // returning teams and score inputs
    vector<string> output{};
    output.push_back(team_inputs);
    output.push_back(score_inputs);
    output.push_back(week);
    return output;
}

// Start Check correctness functions  //

bool check_correct_team_input(string check) {
    
    if (regex_match (check, regex(("^[A-Za-z ]+-[A-Za-z ]+$"))))
        return true;
    return false;
}

bool check_correct_week(string check) {
    
    if (regex_match (check, regex(("^[1-9]+[0-9]*$"))))
        return true;
    return false;
}

bool check_correct_score_input(string check) {
    
    if (regex_match (check, regex(("^[0-9]+-[0-9]+$"))))
        return true;
    return false;
}

// End of Check correctness functions //