#ifndef LAB_APP_H
#define LAB_APP_H
#include "../../includes/lab/lab.h"

void menu_lab(int** labs, int*sizes);
void choice_i(int** labs, int* sizes);
void choice_o(int** labs, int*sizes);



//----------------------------------//

void menu_lab(int** labs, int* sizes){
  char choice;
  string tabs = "\n//-------------------------//\n";
  cout << setw(20) <<"Welcome to LAB program" << endl;
  do{
    cout << tabs;
    cout << setw(6)<< "Log[i]n, Log[o]ut, or [E]xit"<< endl;
    cout << setw(6) << "Please enter what you would like to do: ";
    cin >> choice;
    switch(choice){
      case 'i':
      case 'I':
        choice_i(labs,sizes);
        break; 
      case 'o':
      case 'O':
        choice_o(labs,sizes);
        break;
      case 'e':
      case 'E':
        return;
        break;
      default:
        cout << "\nThat not a valid command, please enter a different one"<< endl;
    }
  } while (choice != 'e' || choice != 'E');
}

void choice_i(int** labs, int* sizes){
  int lab, station, id;
  const bool debug = false;
  cout << "\nWhat lab station would you like to login?" << endl;
  
  do {
    //--------------------------------//
    
    //long version

    // cout << "Enter the lab number: ";
    // cin >> lab;
    // cout << "Enter the station number: ";
    // cin >> station;
    // cout << "Enter id number: ";
    // cin >> id;

    //--------------------------------//
    cout << "Enter the lab number, station number, and id number: ";
    cin >> lab>>station>> id;
    
    if(debug){
      cout << "lab: " << lab << ", station: " << station;
      cout << ", id: " << id << endl;
    }
    bool valid = index_is_valid(sizes,lab,station);

    if(valid == false){
      cout << "\nPlease enter a valid lab and/or station" << endl;
      continue;
    }

    bool logged_in = login(labs,lab,station,id);
    if(debug){
      cout << "labs are: \n";
      print_twod(labs,sizes);
    }
    if(logged_in == true){
      cout << "Successfully login into lab " << lab;
      cout << ", station "<< station << endl;
      cout << "Bringing user back into main program\n";
      break;
    } else{
      cout << "The lab and/or station is occupied. ";
      cout << "Please choose a different one" << endl;
      continue;
    }
  } while (1);
}


void choice_o(int** labs, int* sizes){
  int lab, station, id;
  char cont;
  const bool debug = true;
  cout << "\nWhat lab station would you like to logout?" << endl;
  
  do {
    //--------------------------------//
    
    //long version

    // cout << "Enter the lab number: ";
    // cin >> lab;
    // cout << "Enter the station number: ";
    // cin >> station;
    // cout << "Enter id number: ";
    // cin >> id;

    //--------------------------------//
    cout << "Enter the id number you would like to log out of: ";
    cin >>id;
    

    bool logout_s = logout(labs,sizes,id);
    if(debug){
      cout << "labs are: \n";
      print_twod(labs,sizes);
    }
    if(logout_s == true){
      cout << "Successfully logout of all lab and station" << endl;
      cout << "Bringing user back into main program\n";
      break;
    } else{
      cout << "There is no id number " << id << " in logged in\n";
      cout << "Please input the correct id you wishes to [l]ogout";
      cout << " or [e]xit to main program: "; 
      cin >> cont;

      if(cont == 'E' || cont == 'e') {
        cout << "\nExiting to main program\n"; 
        break;
      }    
      continue;
    }
  } while (1);
}
#endif