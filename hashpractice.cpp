#include <iostream>
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
	bool tobeoverwritten = true; //if the word is deleted and to be overwritten, this must be true

	void printword(){
		cout << spelling << " ||| " << pronounce << " ||| " << definition << endl;
	}
};
//------------------------ basics of any word -----------------------

//-------------------------- basics of any bucket ------------------
/* 
this is what your average bucket will look like
has::::
the name of the bucket (noun, verb, adjective) 
size of bucket
dynamic array of words to be placed into the bucket
function to add a word to the bucket
function to print out entire bucket
*/
struct actualwordtypebucket{
	string nameofbuckettype = "-- null type --";				//name of bucket (ie noun, verb...)
	int size = 2;												//size of bucket (no less than 1 /// size >= 1)
	word* words = new word[size];								//array of words

	~actualwordtypebucket(){ cout << "delete specific wordtpyebucket array: " << nameofbuckettype << "\n"; delete[] words; }	//destructor

	//------------- add word to bucket -------------
	/*
	get arguments for word
	append word to end of array
	make sure new word cannot be overwritten

	need to::::
	actually increase size of array
	*/
	void addword(string spell, string pronoun, string def){	

		words[size-1].spelling			= spell;		//move spelling into word proproty
		words[size-1].pronounce			= pronoun;		//move pronounciation into word proproty
		words[size-1].definition		= def;			//move definition into word proproty
		words[size-1].tobeoverwritten	= false;		//make sure word cannot be overwritten unless deleted

		cout << "done adding: " << words[size-1].spelling << " to: " << nameofbuckettype << "\n";

		size++;		// this needs to be last, seriously,, if not, you seriously fuck up this function
		//for example, do not set this above the cout,, or else you try to print something that doesnt exist
	}
	//------------- add word to bucket -------------

	//---------- print out entirety bucket using forloop ----------
	/*
	prints out entire bucket, avoiding word to be overwritten
	*/
	void printoutbucket(){	
		cout << "==================";
		cout << "Here is the entirety of the " << nameofbuckettype << " bucket: ";
		cout << "==================\n";
		for(int i = 0; i < size; i++){
			if( !(words[i].tobeoverwritten) ){ //do not print out null values PLEASE FOR THE LOVE OF ALL HOLY NOTICE THE "!" at the start
				words[i].printword();
			}
		}
		cout << '\n';
	}
	//---------- print out entirety bucket using forloop ----------
};
//-------------------------- basics of any bucket ------------------


//------------------ array to hold buckets ------------
/*
this is an array of ALL the buckets in the program
has:::
size of array that holds all the buckets
dynamic array of all the buckets
function to set size of dynam array
function to print out all contents of all buckets
*/
struct holderoftypes{

	actualwordtypebucket* wordtypes;	//initialize but DO NOT define array of buckets,, dont define until you know size of bucket
	int size = 5;						//size of array of buckets

	~holderoftypes(){ cout << "delete wordtypeholder array\n"; delete[] wordtypes; }	//destructor

	//---------- get size of array of bucket from user ------------
	/*
	at this point in time, absolutely necessary for the program to run
	get size, make array of that size, very simple
	but critical as the array will never get created otherwise
	always call this function in main
	*/
	void setsize(int t){
		size = t;
		cout << "size sucessfully set...\n";
		wordtypes = new actualwordtypebucket[size];
	}
	//---------- get size of array of bucket from user ------------

	//------------- print out entire dicionary -------------
	/*
	print out dictionary bucket by bucket
	simply goes through the wordtypeholder and calls printbucket for each wordtype
	*/
	void printoutentiredictionary(){
		cout << "Here is the entire dictionary!!\n\n";
		for(int i = 0; i < size; i++){
			wordtypes[i].printoutbucket();
		}
	}
	//------------- print out entire dicionary -------------

};
//------------------ array to hold buckets ------------

//------------- add word to bucket --------------
/*
take address of single bucket
get user input for word proproties
use addword function present in bucket struct
*/ 
void gimmeaword(actualwordtypebucket& wordtypebucketforfunction){
	string givespel;		//holding variable for the user inputs
	string givepron;		//holding variable for the user inputs
	string givedefi;		//holding variable for the user inputs

	int tempsizeofbucket = wordtypebucketforfunction.size;		//create tempsize variable just for easier reading,, not necessary

	cout << "gimme a word!\n";
	cin >> givespel;

	cout << "gimme the pronounciation!\n";
	cin >> givepron;

	cout << "gimme the definition!\n";
	cin >> givedefi;

	cout << "okay lemme put this into the word creation... ";
	wordtypebucketforfunction.addword(givespel, givepron, givedefi);	//send holding variables into addword function

	cout << "Heres youre word!\t";
	wordtypebucketforfunction.words[tempsizeofbucket-1].printword();
}
//------------- add word to bucket --------------

int main() {

	holderoftypes wordtypesholder;
	wordtypesholder.setsize(5);

	gimmeaword(wordtypesholder.wordtypes[0]);


	wordtypesholder.printoutentiredictionary();


	cout << "\n\n--------------------------------\n-----------ending program--------\n--------------------------------\n\n";
	return 0;
}