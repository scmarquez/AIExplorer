//Explorer.cpp
#include "Explorer.h"
Explorer::Explorer(){
	x = 0;
	y = 0;
	for(int i = 0; i < size; i++){
		for(int j= 0; j < size; j++){
			Mymap[i][j] = '?';
			VisitedMap[i][j] = 0;
		}
	}
	//The cells that (x+y)*(x+1)%3 == 0 will contain an 'x' the rest will contain an 'a'
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if(((j+i+(j*i))*(j+7))%17 == 2){
				OriginalMap[i][j] = 'x';
			}
			else{
				OriginalMap[i][j] = 'a';
			}
		}
	}
}
void Explorer::Sigth(){
	if(y!= 0){
		Mymap[x][y-1] = OriginalMap[x][y-1];
	}
	if(y!= size-1){
		Mymap[x][y+1] = OriginalMap[x][y+1];
	}
	if(x!= 0){
		Mymap[x-1][y] = OriginalMap[x-1][y];
	}
	if(x!= size-1){
		Mymap[x+1][y] = OriginalMap[x+1][y];
	}
}
bool Explorer::Move(orientation o){
	if(CanGo(o)){
		switch(o){
			case north:
				y--;
			break;
			case south:
				y++;
			break;
			case east:
				x--;
			break;
			case west:
				x++;
			break;
		}
		return true;
	}
	return false;	
}
bool Explorer::CanGo(orientation o){
	switch(o){
		case north:
			if(y == 0 || OriginalMap[y-1][x] == 'x'){
				return false;
			}
		break;
		case south:
			if(y == size-1 || OriginalMap[y+1][x] == 'x'){
				return false;
			}
		break;
		case east:
			if(x == 0 || OriginalMap[y][x-1] == 'x'){
				return false;
			}
		break;
		case west:
			if(x == size-1|| OriginalMap[y][x+1] == 'x'){
				return false;
			}
		break;
	}
	return true;
}
void Explorer::AutoMove(){
	Sigth();
	orientation options[4];
	int nVisits[4];
	options[0] = north;
	options[1] = south;
	options[2] = east;
	options[3] = west;

	nVisits[0] = VisitedMap[x][y-1];
	nVisits[1] = VisitedMap[x][y+1];
	nVisits[2] = VisitedMap[x-1][y];
	nVisits[3] = VisitedMap[x+1][y];

	//Better than quicksort in this case because the list is too short
	for(int i = 1; i < 4; i++){
		for(int j = i; (j > 0) && (nVisits[j] < nVisits[j-1]); j--){
			int tmp = nVisits[j];
			nVisits[j] = nVisits[j-1];
			nVisits[j-1] = tmp;

			orientation tmp_orientation = options[j];
			options[j] = options[j-1];
			options[j-1] = tmp_orientation;
		}
	}
	bool moved = false;
	int i = 0;
	while(!moved){
		moved = Move(options[i]);
		i++;
	}
	VisitedMap[x][y]++;

}