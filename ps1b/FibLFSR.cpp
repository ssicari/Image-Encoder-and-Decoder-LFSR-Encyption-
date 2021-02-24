//Sal Sicari 
#include"FibLFSR.h"

FibLFSR::FibLFSR(string seed)// constructor
{
	for (int i = 0; i < 16; i++) // fills the vector with the seed
	{
		myVector.push_back(seed[i]);
	}
}
int FibLFSR::step()//simulate one step and return the new bit as 0 or 1
{
	vector<int> seedVect = myVector;
	int topNum = seedVect[0];
	int tapBitOne = seedVect[2];
	int tapBitTwo = seedVect[3];
	int tapBitThree = seedVect[5];

	topNum = topNum ^ tapBitOne;
	topNum = topNum ^ tapBitTwo;
	topNum = topNum ^ tapBitThree;
	myVector.erase(myVector.begin());//tutor told me to add this
	myVector.push_back(topNum);
	return topNum;
}
int FibLFSR::generate(int k)//simulate k steps and return k-bit integer
{
	int k_bit_int = 0; // initialized to 0

	for (int i = 0; i < k; i++) // loop to step depending on input
		{
			int xor_bit = step(); // call step
			k_bit_int = k_bit_int << 1; // doubled the variable
			k_bit_int += xor_bit; // add extracted variable
		}
		return k_bit_int; // return next seed
}
ostream& operator<< (ostream& out, const FibLFSR &FibLFSR)
{
	// Since operator<< is a friend of the FibLFSR class, we can access FibLFSR's members directly.
	for (int i = 0; i < 16; i++)
	{
		out << "FibLFSR(" << FibLFSR.myVector[i] << ')'; // actual output done here
	}
	return out; // return std::ostream so we can chain calls to operator<<
}
/*int main(int argc, char* argv[])
{
  return 0;
  }*/
