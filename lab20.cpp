/******************************************

COMSC 210 | Lab 20 | Skylar Robinson | IDE used: Eclipse

********************************************/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
const int SIZE = 3, MAX = 99999, MIN = 10000;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        if (rand() % 2)
        	legs = 3;
        else
        	legs = 4;
        for (int i = 0; i < SIZE; i++) {
        	double p = (rand() % (MAX - MIN + 1) + MIN) / 100.00;
            prices[i] = p;
        }
    }
    Chair(int l, double p[]) {
        legs = l;
        prices = &p;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    //deconstructor
    ~Chair() {
    	delete [] prices;
    }
};

int main() {
	srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    //creating dynamic chair object with constructor
    double * prices = new double[SIZE];
    for (int i; i < SIZE; i++)
    	prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.00;
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}
