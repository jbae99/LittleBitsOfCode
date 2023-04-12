//This Program will play Snakes and Ladders with
//the names in a given text file

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <fstream>

using namespace std;
//structure to hold player info
struct Player{
  int position;
  string name;
  bool tookBridge;
};
//structure to hold ladder locations
struct Ladder{
  int startPos, endPos;
};
//structure to hold snake locations
struct Snake{
  int startPos, endPos;
};

int main() {
    //changeable constants for playercount and number 
    //of snakes/ladders
    const int numPlayers = 6;
    const int numBridge = 8;
    const string playerNameDataFile = "playerNames.txt";
    //to hold players
    vector<Player> players;
    //load player names from file
    ifstream nameFile;
    nameFile.open(playerNameDataFile);
    cin.clear();
    for(int i = 0;i<numPlayers;i++){
        Player tempPlayer;
        getline(nameFile,tempPlayer.name);
        tempPlayer.position = 1;
        tempPlayer.tookBridge = false;
        players.push_back(tempPlayer);
        cout << players[i].name << " ";
    }
    nameFile.close();
    //random devices to select first player, to position snakes/ladders,
    //and roll die
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> starter(0, numPlayers - 1);
    uniform_int_distribution<int> bridgeHeads(2,99);
    uniform_int_distribution<int> roll(1,6);
    //forming the snakes and ladders randomly
    vector<Ladder> ladderPos;
    vector<Snake> snakePos;
    for(int i = 0;i<numBridge;i++){
      Ladder tempLadder;
      tempLadder.startPos = bridgeHeads(mt);
      uniform_int_distribution<int> bridgeTail(tempLadder.startPos,100);
      tempLadder.endPos = bridgeTail(mt);
      ladderPos.push_back(tempLadder);

      Snake tempSnake;
      tempSnake.startPos = bridgeHeads(mt);
      uniform_int_distribution<int> snakeTail(1,tempSnake.startPos);
      tempSnake.endPos = snakeTail(mt);
      snakePos.push_back(tempSnake);
    }

    int currentPlayer = starter(mt);
    bool winner = false;
    string winName;

    while(!winner){
      int currentRoll = roll(mt);
      players[currentPlayer].position += currentRoll;
      cout << players[currentPlayer].name << " rolled " << currentRoll <<endl;

      if(players[currentPlayer].position == 100){
        winner = true;
        winName = players[currentPlayer].name;
        cout << "We have a winner!" << endl;
      }
      else if(players[currentPlayer].position > 100){
        players[currentPlayer].position = (100 - (players[currentPlayer].position - 100));
      }
      cout << "They landed on " << players[currentPlayer].position << endl << endl;
      for(int i = 0;i < snakePos.size();i++){
        if(players[currentPlayer].position == snakePos[i].startPos){
          players[currentPlayer].position = snakePos[i].endPos;
          cout << "Oh No! A snake! That will set them back to space " << players[currentPlayer].position << endl << endl;
          players[currentPlayer].tookBridge = true;
        }
      }
      for(int j = 0;j < ladderPos.size();j++){
        if(players[currentPlayer].position == ladderPos[j].startPos){
          players[currentPlayer].position = ladderPos[j].endPos;
          cout << "A ladder! That puts them ahead to space " << 
          players[currentPlayer].position << endl << endl;
        }
      }

      if(currentRoll != 6 && currentPlayer < 5){
        currentPlayer++;
      }
      else if(currentRoll == 6 && currentPlayer != 5){
       
      }
      else if (currentPlayer == 5){
        currentPlayer = 0;
      }
      else{
        currentPlayer++;
      }

    }
    cout << "The winner is " << winName << "!" << endl;

  return 0;
} 