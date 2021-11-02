#include<iostream>
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

//Fill cell of fields
void fill(char field[][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			field[i][j] = '#';
		}
	}
}

//Draw field 
void draw(char field[][3]) {
	using std::cout; using std::endl;
	//Collumn number
	cout << "   " << '1' << "  " << '2' << "  " << '3';
	for(int i = 0; i < 3; i++) {
			cout << endl;
			//Stroke number
			cout << (i+1) << ' ';
		for(int j = 0; j < 3; j++) {
			cout << '|' << field[i][j] << '|';
		}
	}
	cout << endl;
}

void step(char field[][3], char player) {
	using std::cout; using std::cin;
	cout << "Step of player " << player;
	int outp;
	char cell[4];
	
	//Number of cell
	int ycell = ((int)cell[o]) - 49;
	int xcell = ((int)cell[2] - 49);


	while(outp != 1) {
		cout << "\nEnter a cell:";
		cin.getline(cell, 4);
		//If coordinate over field
		if((ycell < 0 && ycell > 2) && (xcell < 0 && xcell > 2)) {
			cout << "Oops, something went wrong! Repeat please!";
			outp = 0;
		}
		//If cell already busy by other player
		else if(field[ycell][xcell] != '#') {
			cout << "This cell is busy, choose another\n"; 
			outp = 0;
		}
		else {
			field[ycell][xcell] = player;
			outp = 1;
		}
	}
	draw(field);
}

char check(char field[][3], char player) {
	//Horizontal line check
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(field[i][j] != player) break;
			else if(j == 2) return player;
			else if(field[i][j] == player) continue;
		}
	}
	//Vertical line check
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(field[j][i] != player) break;
			else if(j == 2) return player;
			else if(field[j][i] == player) continue;
		}
	}
	//Angle rise check
	for(int i =0; i < 3; i++) {
		if(field[i][i] != player) break;
		else if(i == 2) return player;
	}
	//Angle fall check
	int j = 2;
	for(int i = 0; i < 3; i++) {
		if(field[i][j] != player) break;
		else if(i == 2) return player;
		--j;	
	}
	return '0';
}
