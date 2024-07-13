// main.cpp
//PriorityQueue
//Pepper Berry
#include "PatientPriorityQueue.h"
#include "Patient.h"
#include ream>
#include eam>
#include ing>
using namespace std;


void welcome();
// Prints welcome message.

void goodbye();
// Prints goodbye message.

void help();
// Prints help menu.

bool processLine(string, PatientPriorityQueue &);
// Process the line entered from the user or read from the file.

void addPatientCmd(string, PatientPriorityQueue &);
// Adds the patient to the waiting room.

void peekNextCmd(PatientPriorityQueue &);
// Displays the next patient in the waiting room that will be called.

void removePatientCmd(PatientPriorityQueue &);
// Removes a patient from the waiting room and displays the name on the screen.

void showPatientListCmd(PatientPriorityQueue &);
// Displays the list of patients in the waiting room.

void execCommandsFromFileCmd(string, PatientPriorityQueue &);
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.

string delimitBySpace(string &);
// Delimits (by space) the string from user or file input.


int main() {
	// declare variables
	string line;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue priQueue;
	do {
		cout << "\ntriage> ";
		getline(cin, line);
	} while (processLine(line, priQueue));

	// goodbye message
	goodbye();
}

bool processLine(string line, PatientPriorityQueue &priQueue) {
	// get command
	string cmd = delimitBySpace(line);
	if (cmd.length() == 0) {
		cout << "Error: no command given.";
		return false;
	}

	// process user input
	if (cmd == "help"){
		help();
	}else if (cmd == "add"){
		addPatientCmd(line, priQueue);
	}else if (cmd == "peek"){
		peekNextCmd(priQueue);
	}else if (cmd == "next"){
		removePatientCmd(priQueue);
	}else if (cmd == "list"){
		showPatientListCmd(priQueue);
	}else if (cmd == "load"){
		execCommandsFromFileCmd(line, priQueue);
	}else if (cmd == "quit"){
		return false;
	}else{
		cout << "Error: unrecognized command: " << cmd << endl;
	}
	return true;
}

void addPatientCmd(string line, PatientPriorityQueue &priQueue) {
	string priority, name;
	int level;

	// get priority and name
	priority = delimitBySpace(line);
	if (priority.length() == 0 || priority == "add") {
		cout << "Error: no priority code given.\n";
		return;
	}
	name = line;//error here
	cout << name << " ";
	if (name.length() == 0 || name == priority) {
		cout << "Error: no patient name given.\n";
		return;
	}

	// TODONE: validate priority is between 1 and 4
	if (priority == "immediate" ){
		level = 1;
	}else if (priority == "emergency"){
		level = 2;
	}else if (priority == "urgent"){
		level = 3;
	}else if (priority == "minimal" ){
		level = 4;
	}else{
		cout << "Error: priority code given is incorrect.\n";
		return;
	}

	// TODONE: add patient to queue
	priQueue.add(name, level);
	cout <<"Added patient \""<<name<<"\" to the priority system"<<endl;
}


void peekNextCmd(PatientPriorityQueue &priQueue) {
	// TODONE: shows next patient to be seen
	if(priQueue.size() == 0){
		cout <<"There are no patients in the waiting area."<<endl;
	}else{
		Patient temp = priQueue.peek();
		cout <<"Highest priority patient to be called next: "<< temp.getName() << endl;
	}

}

void removePatientCmd(PatientPriorityQueue &priQueue) {
	// TODONE: removes and shows next patient to be seen
	if(priQueue.size() == 0){
		cout <<"There are no patients in the waiting area."<<endl;
	}else{
		Patient temp = priQueue.peek();
		cout <<"This patient will now be seen: "<< temp.getName() << endl;
		priQueue.remove();
	}

}

void showPatientListCmd(PatientPriorityQueue &priQueue) {
	cout << "# patients waiting: " << priQueue.size() << endl;
	cout << "  Arrival #   Priority Code   Patient Name\n"
		  << "+-----------+---------------+--------------+\n";
	// TODONE: shows patient detail in heap order
	cout << priQueue.to_string();
}

void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue) {
	ifstream infile;
	string line;

	// open and read from file
	infile.open(filename);
	if (infile) {
		while (getline(infile, line)) {
			cout << "\ntriage> " << line;
			// process file input
			processLine(line, priQueue);
		}
	} else {
		cout << "Error: could not open file.\n";
	}
	// close file
	infile.close();
}


string delimitBySpace(string &s) {
	unsigned pos = 0;
	char delimiter = ' ';
	string result = "";

	pos = s.find(delimiter);
	if (pos != string::npos) {
		result = s.substr(0, pos);
		s.erase(0, pos + 1);
	}
	return result;
}

void welcome() {
	// TODONE tells you what this code is / slightly humerous
	cout <<"Welcome to the Savory-ish medical center you are a front desk worker.\nType help to find a full list of commands.";
	cout<<endl<<"Please add patients to the queue as they come in and use your astute medical knowledge to put them at one of four levels";
	cout<<"\n\nmedical codes:\n1. immediate 2. emergency 3. urgent 4. minimal\n\nCall them up when the doctors are ready!\nDon't kill anyone!\n";
}

void goodbye() {
	// TODONE thanks you for helping / slightly humerous
	cout <<"Thank you for your help in getting our patients seen to today and saving lives!\n Looks like your replacement is here";
	cout <<" so you can leave see you next shift!\n\n";
}

void help() {
	cout << "add <priority-code> <patient-name>\n"
<< "            Adds the patient to the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-name>: patient's full legal name (may contain spaces)\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "list        Displays the list of all patients that are still waiting\n"
<< "            in the order that they have arrived.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}
