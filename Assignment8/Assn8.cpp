#include <string>
#include <iostream>
#include <regex>

using namespace std;

bool is_winning_combo(string num_sequence, int target_sum, string running_op_sequence);
void find_sum_combos(string num_sequence, int target_sum, vector<string> &winners);
void find_sum_combos_rec(string num_sequence, int target_sum, string running_op_sequence, int index, vector<string> &winners);
void print_winners(string num_sequence, vector<string> winners, int target_sum);
bool validate_input(int num_args, char** input);

int main(int argc, char** argv){
    if(!validate_input(argc, argv)){
        cout << "Usage ./Assn8 <number> <sum>" << endl;
        exit(0);
    }

    try{
        string num_sequence = argv[1];
        int target_sum = stoi(argv[2]);

        vector<string> winners;
        find_sum_combos(num_sequence, target_sum, winners);

        print_winners(num_sequence, winners, target_sum);

    } catch(exception e){
        cout << e.what() << endl;
        exit(1);
    }
    return 0;
}

void find_sum_combos_rec(string num_sequence, int target_sum, string running_op_sequence, int index, vector<string> &winners){
    // cout << "index: " << index << endl;
    if(index == num_sequence.length()){
        if(is_winning_combo(num_sequence, target_sum, running_op_sequence)){
            winners.insert(winners.end(), running_op_sequence);
        }
        return;
    }

        find_sum_combos_rec(num_sequence, target_sum, running_op_sequence + "+", index + 1, winners);
        find_sum_combos_rec(num_sequence, target_sum, running_op_sequence + "-", index + 1, winners);
        find_sum_combos_rec(num_sequence, target_sum, running_op_sequence + ".", index + 1, winners);
}

void find_sum_combos(string num_sequence, int target_sum, vector<string> &winners){
    find_sum_combos_rec(num_sequence, target_sum, "", 0, winners);   
    return;
}

bool is_winning_combo(string num_sequence, int target_sum, string running_op_sequence){
    try{
        string infix_string = "";

        for(int i = 0; i < num_sequence.length(); i++){
            if(running_op_sequence[i] == '.'){
                infix_string = infix_string + num_sequence[i];
            } else{
                infix_string = infix_string + running_op_sequence[i] + num_sequence[i];
            }
        }

        vector<string> terms;
        regex re("[+-]");
        sregex_token_iterator end_of_tokens;
        sregex_token_iterator token_iter(infix_string.begin(), infix_string.end(), re, -1);
        while(token_iter != end_of_tokens){
            terms.insert(terms.end(), *token_iter);
            token_iter++;
        }

        string ops = "" ;
        for(int i = 0; i < running_op_sequence.length(); i++){
            if(!(running_op_sequence[i] == '.')){
                ops = ops + running_op_sequence[i];
            }
        }

        int running_sum = 0;
        if(terms[0].compare("") != 0){
            running_sum = stoi(terms[0]);
        }
        terms.erase(terms.begin());

        for(int i = 0; i < ops.length(); i++){
            if(ops[i] == '+'){
                running_sum = running_sum + stoi(terms[i]);
            }
            if(ops[i] == '-'){
                running_sum = running_sum - stoi(terms[i]);
            }
        }

        if(running_sum == target_sum){
            return true;
        }
        return false;

    }catch(exception e){
        cout << e.what() << endl;
    }
    return false;
}

void print_winners(string num_sequence, vector<string> winners, int target_sum){
    if(winners.size() == 0){
        cout << "No solutions" << endl;
        return;
    }

    cout << "Answers:" << endl;

    vector<string> answers;

    for(int i = 0; i < winners.size(); i++){
        string infix_string = "";
        for(int j = 0; j < num_sequence.length(); j++){
            infix_string = infix_string + winners[i][j] + num_sequence[j];
        }
        
        string temp_infix_string = infix_string;
        infix_string = "";
        for(int i = 0; i < temp_infix_string.length(); i++){
            if(!(temp_infix_string[i] == '.')){
                infix_string = infix_string + temp_infix_string[i];
            }
        }
        
        if(infix_string[0] == '+'){
            infix_string = infix_string.substr(1);
        }

        if(find(answers.begin(), answers.end(), infix_string) == answers.end()){
            answers.insert(answers.end(), infix_string);
        }
    }

    for(int i = 0; i < answers.size(); i++){
        cout << "    " << (i + 1) << ": " << answers[i] << "=" << target_sum << endl;
    }
}

bool validate_input(int num_args, char** input){
    if(num_args < 3){
        return false;
    }
    regex re("\\d+");
    string num_sequence(input[1]);
    string target_sum(input[2]);
    if(regex_match(num_sequence, re) == false || regex_match(target_sum, re) == false){
        return false;
    }
    return true;
}