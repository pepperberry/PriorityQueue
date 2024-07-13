//PriorityQueue
//Patient.h
//2/23/2024
//pepper berry
#include ream>
#include ing>
#include eam>

using namespace std;


#ifndef _PATIENT_
#define _PATIENT_

class Patient{
    public:
        Patient(string, int, int);
        string to_string();
        //allows us to print a patient and there info out
        string getName(){return name;}
        int getPriorityCode(){return priorityCode;}
        int getarrivalOrder(){return arrivalOrder;}
        bool operator==(const Patient &obj);
        // assume i can just use one then than or greater than sign and flip var rather than flliping operators
        bool operator>(const Patient &obj);

    private:
        string name;
        int priorityCode;
        int arrivalOrder;


};

//creates a patient
Patient::Patient(string name, int code, int order){
    this->name = name;
    priorityCode = code;
    arrivalOrder = order;
}

//allows us to print a patient and there info out
string Patient::to_string(){
    string str = "      ";
    stringstream stream;
    stream << arrivalOrder;
    string orderString;
    stream >> orderString;
    str += orderString;
    int length = orderString.length();
    for (int i = 7; i > length; --i){
        str +=" ";
    }
    if (priorityCode == 2){
        str += "emergency       ";
    }else if(priorityCode == 4){
        str += "minimal         ";
    }else if(priorityCode == 1){
        str += "immediate       ";
    }else{
        str += "urgent          ";
    }
    str += name;
    return str;
}



//check if one patient is more emergent than the other
bool Patient::operator>(const Patient &obj){
    if(this->priorityCode > obj.priorityCode){
        return true;
    }else{
        return false;
    }
}

//check if patients are of the same level
bool Patient::operator == (const Patient &obj){
    if(this->priorityCode == obj.priorityCode){
        return true;
    }else{
        return false;
    }
}


#endif
