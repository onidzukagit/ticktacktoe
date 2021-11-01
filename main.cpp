#include<iostream>
#include<cstring>
const int arsize = 9;
const char player1 = 'o';
const char player2 = 'x';
void fill(char[][3]);
void draw(char[][3]);
void step(char[][3], char);
char check(char[][3], char);

int main(void) {
	using namespace std;
	char field[3][3];
	fill(field);
	int count = 1;
	draw(field);
	while(1) {
		if(count%2 != 0) {
			step(field, player1);
			if(check(field, player1) == player1){
				   	cout << "Player 1 win!"; 
					break;
			}
		}
		else{
			step(field, player2); 
			if(check(field, player2) == player2) {
					cout << "Player 2 win!"; 
					break;
			}
		}
		++count;
	}
	

	return 0;

}

void fill(char field[][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			field[i][j] = '#';
		}
	}
}

void draw(char field[][3]) {
	using namespace std;
	cout << "   " << '1' << "  " << '2' << "  " << '3';
	for(int i = 0; i < 3; i++) {
			cout << std::endl;
			cout << (i+1) << ' ';
		for(int j = 0; j < 3; j++) {
			cout << '|' << field[i][j] << '|';
		}
	}
	cout << std::endl;
}

void step(char field[][3], char player) {
	using namespace std;
	cout << "Step of player " << player;
	int* outp = new int;
	char cell[4];
	while(*outp != 1) {
	cout << "\nEnter a cell:";
	cin.getline(cell, 4);
	if((((int)cell[0]-49) < 0 && ((int)cell[0]-49) > 9) && (((int)cell[2]-49) < 0 && ((int)cell[2]-49) > 9)) {
		cout << "Oops, something went wrong! Repeat please!";
		*outp = 0;
	}
	else if(field[(int)cell[0] - 49][(int)cell[2] - 49] != '#') {
		cout << "This cell is busy, choose another\n"; 
		*outp = 0;
	}
	else {
		field[(int)cell[0] - 49][(int)cell[2] - 49] = player;
		*outp = 1;
	}

	}
	draw(field);
	delete outp;
}

char check(char field[][3], char player) {
	using namespace std;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(field[i][j] != player) break;
			else if(j == 2) return player;
			else if(field[i][j] == player) continue;
		}
	
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(field[j][i] != player) break;
			else if(j == 2) return player;
			else if(field[j][i] == player) continue;
		}
	}
	for(int i =0; i < 3; i++) {
		if(field[i][i] != player) break;
		else if(i == 2) return player;
	}
	int j = 2;
	for(int i = 0; i < 3; i++) {
		if(field[i][j] != player) break;
		else if(i == 2) return player;
		--j;	
	}
	
	return '0';

}
