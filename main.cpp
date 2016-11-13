#include <iostream>
#include "Explorer.h"
using namespace std;

int main(){
	Explorer e;
	int i = 0;
	while(e.Points() != 1){
		e.AutoMove();
		i++;
	}
	cout << "Need " << i << "steps\n";
	e.ShowMap();
	cout << e.Points();
}