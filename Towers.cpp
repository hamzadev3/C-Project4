#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> towers[3]; // three towers A, B, C as an array of 3 vectors
  int numRings, ringToMove = 1, targetTower, sourceTower = 0, stepCount = 0; // initialize variables
  cout << "Enter the number of rings: "; // Prompt user to enter number of rings
  cin >> numRings; // Store input
  cout << endl;

  // determine if numRings is even or odd
  bool isEven = false;
  if (numRings % 2 == 0) isEven = true; // use modulus to determine

  // initialize the 3 towers
  for (int i = numRings + 1; i >= 1; i--) { towers[0].push_back(i); }
  towers[1].push_back(numRings + 1); // set initial values for tower 1
  towers[2].push_back(numRings + 1); // set initial values for tower 2

  if (isEven) targetTower = 2; // initial target tower for even number of rings
  else targetTower = 1; // initial target tower for odd number of rings

  towers[sourceTower].back(); // ringToMove (towers[sourceTower].back()) is the ring to be moved

  // continue transferring rings until tower B (towers[1]) contains all rings
  while (towers[1].size() < numRings + 1) {
    cout << "Move number " << ++stepCount << ": Transfer ring " << ringToMove << " from tower " << char(sourceTower + 65) << " to tower " << char(targetTower + 65) << endl;

    // move rings from source tower to target tower
    towers[targetTower].push_back(towers[sourceTower].back());
    towers[sourceTower].pop_back();

    // determine the next source tower
    if (towers[(targetTower + 1) % 3].back() < towers[(targetTower + 2) % 3].back())
      sourceTower = (targetTower + 1) % 3;
    else
      sourceTower = (targetTower + 2) % 3;

    // update the next ring to move
    ringToMove = towers[sourceTower].back();

    // adjust target tower based on odd or even number of rings
    isEven = numRings % 2 == 1;
    if (isEven) {
      if (ringToMove < towers[(sourceTower + 1) % 3].back())
        targetTower = (sourceTower + 1) % 3;
      else
        targetTower = (sourceTower + 2) % 3;
    } else {
      if (ringToMove < towers[(sourceTower + 2) % 3].back())
        targetTower = (sourceTower + 2) % 3;
      else
        targetTower = (sourceTower + 1) % 3;
    }
  }
  return 0;
}