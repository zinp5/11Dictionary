#include <iostream>
#include <vector>

using namespace std;

//------------------------ basics of any word -----------------------
struct word{
	string spelling = "-- null spelling --";
	string pronounce = "-- null pronounciation --";
	string definition = "-- null definition --";

	void printword(){
		cout << spelling << " " << pronounce << " " << definition << endl;
	}
};
//------------------------ basics of any word -----------------------

//-------------------------- basics of any bucket ------------------
struct actualwordtypebucket{
	string nameofbuckettype = "-- null name --";	//name of bucket (ie noun, verb...)
	int size = 1;									//size of bucket
	word* words = new word[size];					//array of words

	~actualwordtypebucket(){ delete[] words; }		//deleting array of words

};
//-------------------------- basics of any bucket ------------------

int main() {

	int numberofbuckets = 3;															//size of wordtype bucket *testing value*
	actualwordtypebucket* wordtypes = new actualwordtypebucket[numberofbuckets];		//create bucket of wordtypes


	//-------- get name of wordtypes ------------
	cout << "gimme the name of the first and second and third bucket plz\n";
	for(int i = 0; i < numberofbuckets; i++){
		cout << "bucket #" << i+1 << ":\t";
		cin >> wordtypes[i].nameofbuckettype;
	}
	cout << "thanks!! heres the names ya picked out!\n";
	for(int i = 0; i < numberofbuckets; i++){
		cout << wordtypes[i].nameofbuckettype << "\t";
	}
	//-------- get name of wordtypes ------------

	delete[] wordtypes;

	return 0;
}