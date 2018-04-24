import sys
import re

def find_sum_combos_rec(num_sequence, target_sum, runnning_op_sequence, index, winners):
    if(index  == len(num_sequence)):
        if(is_winnning_combo(num_sequence, target_sum, runnning_op_sequence)):
            # print "appending..."
            winners.append(runnning_op_sequence)
        return
    
    find_sum_combos_rec(num_sequence, target_sum, runnning_op_sequence + "+", index + 1, winners)
    find_sum_combos_rec(num_sequence, target_sum, runnning_op_sequence + "-", index + 1, winners)
    find_sum_combos_rec(num_sequence, target_sum, runnning_op_sequence + ".", index + 1, winners)
    

def find_sum_combos(num_sequence, target_sum):
    winners = []
    find_sum_combos_rec(num_sequence, target_sum, "", 0, winners)
    return winners

def is_winnning_combo(num_sequence, target_sum, runnning_op_sequence):
    infix_string = ""
    for index in range(len(num_sequence)):
        if(runnning_op_sequence[index] != "."):
            infix_string = infix_string + runnning_op_sequence[index] + num_sequence[index]
        else:
            infix_string = infix_string + num_sequence[index]
        
    terms = re.split("[+-]", infix_string)
    ops = runnning_op_sequence.replace(".", "")

    # print num_sequence
    # print runnning_op_sequence
    # print infix_string
    # print ops
    # print terms

    if(terms[0] == ''):
        terms = terms[1:]
        running_sum = 0
    else:
        running_sum = int(terms[0])
        if(len(terms) > 1):
            terms = terms[1:]

    for index in range(len(ops)):
        if(ops[index] == "+"):
            running_sum = running_sum + int(terms[index])
        if(ops[index] == "-"):
            running_sum = running_sum - int(terms[index])

    # print(target_sum)
    # print(running_sum)
    if(running_sum == int(target_sum)):
        # print "found sum!"
        return True
    return False

def print_answers(num_sequence, winners, target_sum):
    if(len(winners) == 0):
        print "No solutions"
        return

    print "Answers:"
    # print "length of winners: " + str(len(winners))
    answers = []
    for outer_index in range(len(winners)):
        infix_string = ""
        for index in range(len(num_sequence)):
            infix_string = infix_string + winners[outer_index][index] + num_sequence[index]
        infix_string = infix_string.replace(".", "")
        if(infix_string[0] == "+"):
            infix_string = infix_string[1:]
        infix_string = infix_string + "=" + target_sum
        # print(infix_string in answers)
        if((infix_string in answers) == False):
            answers.append(infix_string)
            
    for index in range(len(answers)):
        print "    " + str(index + 1) + ": " + answers[index]

def validate_input():
    if(len(sys.argv) < 3):
        return False
    if(re.match("^\\d{1,}$", sys.argv[1] ) == None or re.match("^\\d{1,}$", sys.argv[2] ) == None):
        return False
    return True

if(validate_input() == False):
    print "Usage: python Assn8.py <number> <sum>"
    exit()

num_sequence = sys.argv[1]
target_sum = sys.argv[2]
# print target_sum
winners = find_sum_combos(num_sequence, target_sum)
# print(winners)
print_answers(num_sequence, winners, target_sum)