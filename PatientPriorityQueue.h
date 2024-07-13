//PriorityQueue
//PatientPriorityQueue
//2/23/2024
//pepper berry
#include ing>
#include eam>
#include ream>
#include eam>
#include tor>
#include "Patient.h"

using namespace std;

class PatientPriorityQueue{
    public:

        PatientPriorityQueue();
        void add(string name, int level);
        Patient peek();
        Patient remove();
        int size();
        string to_string();
    private:
        int nextPatientNumber;
        vector<Patient> queue;

};

//Constructor - Creates an empty triage system with no patients.
PatientPriorityQueue::PatientPriorityQueue(){
    nextPatientNumber = 1;
}

//add - Adds the patient to the priority queue.
//Heap order is defined as the order that patients must be seen, so this function needs to maintain heap order.
void PatientPriorityQueue::add(string name, int level){
    Patient temp(name,level,nextPatientNumber);
    ++nextPatientNumber;
    queue.push_back(temp);

    //fixes order
    if(queue.size() >= 2){
        for(int i = (queue.size()-1); i > 0; --i){
            if (queue.at(i-1) > queue.at(i)){
                temp = queue.at(i);
                queue.at(i) = queue.at(i-1);
                queue.at(i-1) = temp;
            }
        }
    }
}

//peek - Returns the highest priority patient without removing it.
Patient PatientPriorityQueue::peek(){
    return queue.front();
}



//remove - Removes the highest priority patient from the queue and returns it. This function needs to maintain heap order.
Patient PatientPriorityQueue::remove(){
    Patient temp = queue.front();
    queue.erase(queue.begin());//get iterator postion
    return temp;
}

//size - Returns the number of patients still waiting.
int PatientPriorityQueue::size(){
    return queue.size();
}

//to_string - Returns the string representation of the object in heap (or level) order.
string PatientPriorityQueue::to_string(){
    int size = queue.size();
    string str = "";
    for (int i = 0; i < size; ++i){
        Patient temp = queue.at(i);
        str += temp.to_string();
        str += "\n";
    }
    return str;
}

