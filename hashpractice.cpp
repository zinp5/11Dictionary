#include <iostream>
#include <vector>			//honeslty I might delete this later... i dont think vectors will work well w/ my program
using namespace std;

//------------------------ basics of any word -----------------------
/* 
this holds basics proprotires of your basic word 
also has function for printing entire proproties of word out 
*/
struct word{
	string spelling = "-- null spelling --";
	string pronounce = "-- null pronounciation --";
	string definition = "-- null definition --";

	void printword(){
		cout << spelling << " ||| " << pronounce << " ||| " << definition << endl;
	}
};
//------------------------ basics of any word -----------------------

//-------------------------- basics of any bucket ------------------
/* 
this is what your average bucket will look like
has::::
	the name (noun, verb, adjective) of the bucket
	size of bucket
	dynamic array of words to be placed into the bucket
	function to add a word to the bucket
	function to print out entire bucket
*/
struct actualwordtypebucket{
	string nameofbuckettype = "Noun";	//name of bucket (ie noun, verb...)
	int size = 2;									//size of bucket
	word* words = new word[size];					//array of words

	~actualwordtypebucket(){ cout << "delete specific wordtpyebucket array: " << nameofbuckettype << "\n"; delete[] words; }	//destructor
	
	//add word to bucket
	void addword(string spell, string pronoun, string def){	
		//grab arguments and slam them into word pointed to by bucket
		words[size-1].spelling		= spell;		//move spelling into word proproty
		words[size-1].pronounce		= pronoun;		//move pronounciation into word proproty
		words[size-1].definition	= def;			//move definition into word proproty
		size++;
		cout << "done adding " << words[size-1].spelling << " to: " << nameofbuckettype << "\n";
	}

	//print out entirety bucket using forloop
	void printoutbucket(){	
		cout << "==================";
		cout << "Here is the entirety of the " << nameofbuckettype << " bucket: ";
		cout << "==================\n";
		for(int i = 0; i < size; i++){
			words[i].printword();
		}
		cout << '\n';
	}
};
//-------------------------- basics of any bucket ------------------

/*
this is an array of ALL the buckets in the program
has:::
	size of array that holds all the buckets
	dynamic array of all the buckets
	function to print out all contents of all buckets
*/
struct holderoftypes{
	
	actualwordtypebucket* wordtypes;	//initialize but DO NOT declare array of buckets
	int size = 0;						//size of array of buckets

	~holderoftypes(){ cout << "delete wordtypeholder array\n"; delete[] wordtypes; }	//destructor

	//get size of array of bucket from user
	void setsize(int t){
		size = t;
		cout << "size sucessfully set...\n";
		wordtypes = new actualwordtypebucket[size];
	}

	//print out entire dicionary
	void printoutentiredictionary(){
		cout << "Here is the entire dictionary!!\n\n";
		for(int i = 0; i < size; i++){
			wordtypes[i].printoutbucket();
		}
	}
};

void gimmeaword(actualwordtypebucket* wordtypesforfunction){
	string givespel;
	string givepron;
	string givedefi;

	cout << "gimme a word!\n";
	cin >> givespel;

	cout << "gimme the pronounciation!\n";
	cin >> givepron;

	cout << "gimme the definition!\n";
	cin >> givedefi;

	cout << "okay lemme put this into the word creation...";
	wordtypesforfunction[0].addword(givespel, givepron, givedefi);
	cout << "Heres you're word!\t";
	wordtypesforfunction[0].words[0].printword();
}

int main() {

	int temp;

	holderoftypes wordtypesholder;
	cout << "so uhh, how many buckets do you want? a good starting is around 5: ";
	cin >> temp;
	wordtypesholder.setsize(temp);
	
	wordtypesholder.printoutentiredictionary();
	//wordtypesholder.wordtypes[0].printoutbucket();


	cout << "\n\n--------------------------------\n-----------ending program--------\n--------------------------------\n\n";
	return 0;
}