//Artificial intelligence
//Explorer.h
#ifndef EXPLORER_H
#define EXPLORER_H
#include <iostream>
using namespace std;
enum orientation{north,west,east,south};
class Explorer{
	private:
		static const int size = 50;
		char Mymap[size][size]; //The discovered map
		int x,y; //The current position on the map
		int VisitedMap[size][size];
		char OriginalMap[size][size];

	public:
		Explorer();
		//Fill Mymap with the information that the agent can see
		void Sigth();
		//Movement operations
		bool Move(orientation o);
		//Calculate the next move
		void AutoMove();
		bool CanGo(orientation o);
		float Points(){
			float p = 0;
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					if(Mymap[i][j] == OriginalMap[i][j]){
						p++;
					}
				}
			}
			return p/(size*size);
		}
		void ShowMap(){
			for(int i = 0; i <size; i++){
				for(int j = 0; j < size; j++){
					cout << " " << OriginalMap[i][j];
				}
				cout << endl;
			}
			cout << endl;
			for(int i = 0; i <size; i++){
				for(int j = 0; j < size; j++){
					cout << " " << Mymap[i][j];
				}
				cout << endl;
			}
		}
};
#endif
