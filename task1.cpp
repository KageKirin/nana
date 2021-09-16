// Hello!
// This was my task from last week.
// I was only able to display the parts but not the quantity so I put `//` over the line for quantity
// or it wont even run.
// It wont progress further then "Enter zero to quit or choose.." 

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// Constants for array size
static const int NUM_BINS = 10;

// Declaration of the InventoryBin structure
struct InventoryBin
{
  string description;
  int number;

    
};

// Function prototypes
void updateBin(InventoryBin[], int);
void addParts(InventoryBin &, int);
void removeParts(InventoryBin &, int);

int main()
{
    // The user's menu choice
    int choice = 0;

    // Declare and intitialize an array of InventoryBin structures. For this
    // exercise, we'll use a standard 'C' style array but take advantage of
    // the C++ initializer list to set the initial values of the structures.
    
    // Remove this comment wrapper after coding the InventoryBin structure
    InventoryBin bins[NUM_BINS] =
    {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    do
    {
        // Display the contents of each bin as a menu.

        cout<<"Inventory Bins:\n ";
        for (int bin=0;bin<NUM_BINS;bin++){
          cout<<"Bin # "<<setw(3)<<(bin+1);
          cout<<",Part: "/*<<setw(14)*/<<bins[bin].description;
          //cout<<",Quantity: "<<bins[bin].num;
          cout<<"\n";

        }

        cout<<"\nEnter 0 to quit or choose a bin number: ";
        cin>>choice;

        while(choice<10 || choice> NUM_BINS)
        {
          cout<<"\nEnter 0 to quit or choose a bin number: ";
          cin>>choice;
        }

        if(choice!= 0)
        {
          updateBin(bins,choice - 1);
        }

    } while (choice != 0);

    return 0;
}

//*********************************************************
// Function updateBin                                     *
// This function lets the user choose whether to add or   *
// remove parts from the bin bins[Choice].                   *
//*********************************************************
void updateBin(InventoryBin bins[], int choice)
{
  int numParts;
  char aorr;

  cout<<"Add or Remove parts (A or R):";
  cin>>aorr;

  while(toupper(aorr)!='A'&&toupper(aorr)!='B')
  {
    cout<<"Enter A or R:";
    cin>>aorr;
  }

  if(toupper(aorr)=='A')
  {
    cout<<"How many parts to add?";
    cin>>numParts;

    addParts(bins[choice],numParts);
  }

  else
  {
    cout<<"How many parts to remove?";
    cin>>numParts;

    removeParts(bins[choice],numParts);
  }
}

//***********************************************************
// Function addParts                                        *
// This function adds the value passed to numAdd to the     *
// num member of the bin structure. The value is validated. *
//                                                          *
// Note the use of the C++ reference type to pass the       *
// InventoryBin structure to the function.                  *
//***********************************************************
void addParts(InventoryBin & bin, int numAdd)
{
    // Validate the number of parts and add them
    // if the number is valid.
    if (numAdd <0)
    {
      cout<<"\n**Error: Add positive values.\n";
    }

    else if(numAdd + bin.num > 30)
    {
      cout<<"\n** Error: the bin can only hold 30 parts.\n";
    }

    else
    {
      bin.num += numAdd;
      cout<<"\n** Success: parts were added to the bin.\n";
    }
}

//************************************************************
// Function removeParts                                      *
// This function subtracts the value passed to numRem to the *
// num member of the bin structure. The value is validated.  *
//                                                           *
// Note the use of the C++ reference type to pass the        *
// InventoryBin structure to the function.                   *
//************************************************************
void removeParts(InventoryBin & bin, int numRem)
{
    // Validate the number of parts and remove them
    // if the number is valid.

    // TODO - enter your code here
}