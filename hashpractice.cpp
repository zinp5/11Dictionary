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
		cout << spelling << " | " << pronounce << " | " << definition << endl;
	}
};
//------------------------ basics of any word -----------------------

//|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|

//-------------------------- basics of any bucket ------------------
/* 
this is what your average bucket will look like
add words like stack
delete words specifically
has::::
	the name of the bucket (noun, verb, adjective) 
	size of bucket
	dynamic array of words to be placed into the bucket
	function to add a word to the bucket
	function to print out entire bucket

needs:::
	a way to keep track of # of elems and resize accordingly
*/
struct actualwordtypebucket{
	string nameofbuckettype = "-- null type --";				//name of bucket (ie noun, verb, preposition...)
	int sizeofbucket = 5;										//size of bucket (no less than 1 /// size >= 1)
	word* words = new word[sizeofbucket];						//array of words
	int trackingspot = 0;										//keep track of spot on stack

	~actualwordtypebucket(){ cout << "delete specific wordtpyebucket array: " << nameofbuckettype << "\n"; delete[] words; }	//destructor

	//------------- add word to bucket -------------
	/*
	get arguments for word
	append word to end of array
	make sure new word cannot be overwritten

	need::::
		actually increase size of array
	*/
	void addword(string spell, string pronoun, string def){	

		words[sizeofbucket-1].spelling			= spell;		//move spelling into word proproty
		words[sizeofbucket-1].pronounce			= pronoun;		//move pronounciation into word proproty
		words[sizeofbucket-1].definition		= def;			//move definition into word proproty
		words[sizeofbucket-1].tobeoverwritten	= false;		//make sure word cannot be overwritten unless deleted

		cout << "done adding: " << words[sizeofbucket-1].spelling << " to: " << nameofbuckettype << "\n";

		trackingspot++;		// this needs to be last, seriously,, if not, you seriously fuck up this function
		//for example, do not set this above the cout,, or else you try to print something that doesnt exist
		//IN REVISION: do not use sizeofbucket for this function, this will cause out of bounds when printing out bucket
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
		for(int i = 0; i < sizeofbucket; i++){
			//if( !(words[i].tobeoverwritten) ){ //do not print out null values PLEASE FOR THE LOVE OF ALL HOLY NOTICE THE "!" at the start
				words[i].printword();
			//}
		}
		cout << '\n';
	}
	//---------- print out entirety bucket using forloop ----------
};
//-------------------------- basics of any bucket ------------------

//|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|

//------------------ array to hold buckets ------------
/*
this is an array of ALL the buckets in the program
has:::
	dynamic array of all the buckets
	size of array that holds all the buckets
	function to set size of dynam array
	function to print out all contents of all buckets
need::::
	create a proper constructor that grabs size
*/
struct holderoftypes{

	actualwordtypebucket* wordtypes;	//initialize but DO NOT define array of buckets,, dont define until you know size of bucket
	int sizeofbucketholder;


	//------------- construct and destruct -----------
	//0 var construct
	holderoftypes(){
		cout << "Before we start the program, I need to know how many diff word types you want: ";
		cin >> sizeofbucketholder;
		wordtypes = new actualwordtypebucket[sizeofbucketholder];
		cout << "got it... you'll start w/ " << sizeofbucketholder << " word types buckets.... set sucessfully\n";
	}
	//1 var construct
	holderoftypes(int s){
		sizeofbucketholder = s;
		wordtypes = new actualwordtypebucket[sizeofbucketholder];
		cout << "got it... you'll start w/ " << sizeofbucketholder << " word types buckets.... set sucessfully\n";
	}
	~holderoftypes(){ cout << "delete wordtypeholder array\n"; delete[] wordtypes; }	//destructor
	//------------- construct and destruct -----------


	//------------- print out entire dicionary -------------
	/*
	print out dictionary bucket by bucket
	simply goes through the wordtypeholder and calls printbucket for each wordtype
	*/
	void printoutentiredictionary(){
		cout << "Here is the entire dictionary!!\n\n";
		for(int i = 0; i < sizeofbucketholder; i++){
			wordtypes[i].printoutbucket();
		}
	}
	//------------- print out entire dicionary -------------

	//------------- add word to bucket --------------
	/*
	move through the bucket holder into the bucket to find a spot to add new word
	get user input for word proproties
	use addword function present in bucket struct
	*/ 
	void gimmeaword(){
		string givespel;		//holding variable for the user inputs
		string givepron;		//holding variable for the user inputs
		string givedefi;		//holding variable for the user inputs

		int tempsize = wordtypes[0].sizeofbucket;		//create tempsize variable just for easier reading,, not necessary
		
		cout << "gimme a word!\n";
		cin >> givespel;

		cout << "gimme the pronounciation!\n";
		cin >> givepron;

		cout << "gimme the definition!\n";
		cin >> givedefi;

		cout << "okay lemme put this into the word creation... ";
		wordtypes[0].addword(givespel, givepron, givedefi);	//send holding variables into addword function

		cout << "Heres your word!\t";
		wordtypes[0].words[tempsize-1].printword();
	}
	//------------- add word to bucket --------------
};
//------------------ array to hold buckets ------------

//|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|

int main() {

	holderoftypes wordtypesholder(2);	//create master bucket

	wordtypesholder.gimmeaword();	//get word

	wordtypesholder.printoutentiredictionary();  //print out dictionary


	cout << "\n\n--------------------------------\n-----------ending program--------\n--------------------------------\n\n";
	return 0;
}