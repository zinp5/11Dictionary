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
	resizing function
needs:::
	a way to delete words
*/
struct actualwordtypebucket{
	string nameofbuckettype = "-- null type --";				//name of bucket (ie noun, verb, preposition...)
	int sizeofbucket = 5;										//size of bucket (no less than 1 /// size >= 1)
	word* words = new word[sizeofbucket];						//array of words

	int trackingspot = 0;										//keep track of spot on stack
	word* tempholding;											//temp array for resizing

	~actualwordtypebucket(){ cout << "delete specific wordtpyebucket array: " << nameofbuckettype << "\n"; delete[] words; }	//destructor

	//------------- check if word can be added to bucket -------------
	/*
	get arguments for word
	if current spot is out of range, resize
	append word to end of array
	make sure new word cannot be overwritten
	*/
	void baseAddWord(string spell, string pronoun, string def){	
		if(trackingspot > sizeofbucket-1){	//if out of range, resize
			cout << trackingspot << " > " << sizeofbucket - 1 << " resizing...\n";
			resize();
			actuallyaddword(spell, pronoun, def);
		}
		else{ //else, add like normal
			actuallyaddword(spell, pronoun, def);
		}
	}
	//------------- check if word can be added to bucket -------------

	//-------------------- actually add the word --------------------
	/*
	compliments the baseAddWord function
	simple function that adds word to bucket
	*/
	void actuallyaddword(string spell, string pronoun, string def){
		words[trackingspot].spelling			= spell;		//move spelling into word proproty
		words[trackingspot].pronounce			= pronoun;		//move pronounciation into word proproty
		words[trackingspot].definition			= def;			//move definition into word proproty
		words[trackingspot].tobeoverwritten		= false;		//make sure word cannot be overwritten unless deleted

		cout << "done adding: " << words[trackingspot].spelling << " to: " << nameofbuckettype << "\n";

		trackingspot++;		// this needs to be last, seriously,, if not, you seriously fuck up this function
		//for example, do not set this above the cout,, or else you try to print something that doesnt exist
		//IN REVISION (6/29?): do not use sizeofbucket for this function, this will cause out of bounds when printing out bucket(dumbass)
		//instead use trackingspot
	}
	//-------------------- actually add the word --------------------

	
	//-------------- resizing -------------
	/*
	resizing of array when necessary
	*/
	void resize(){
		int tempsize = sizeofbucket*2;
		tempholding = new word[tempsize];		//define temp holding array
		for(int i = 0; i < sizeofbucket; i++){	//move everything from main array into holding
			tempholding[i] = words[i];
		}
		delete[] words;							//free up main arrays old space
		sizeofbucket*=2;						//set new max size to 2x old size
		words = tempholding;					//have main array point to temp array
	}
	//-------------- resizing -------------

	//---------- print out entirety bucket using forloop ----------
	/*
	prints out entire bucket, avoiding word to be overwritten
	*/
	void printoutbucket(){	
		cout << "\n==================";
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
		cout << "\nHere is the entire dictionary!!\n";
		for(int i = 0; i < sizeofbucketholder; i++){
			wordtypes[i].printoutbucket();
		}
		cout << "====================end of dictionary======================\n";
	}
	//------------- print out entire dicionary -------------

	//------------- add word to bucket --------------
	/*
	move through the bucket holder into the bucket to find a spot to add new word
	get user input for word proproties
	use addword function present in bucket struct
	needs:::
		replace tempsize w/ tracking spot
	*/ 
	void gimmeaword(){
		string givespel;		//holding variable for the user inputs
		string givepron;		//holding variable for the user inputs
		string givedefi;		//holding variable for the user inputs

		int tempsize = wordtypes[0].sizeofbucket -1;		//create tempsize variable just for easier reading,, not necessary
		
		cout << "gimme a word!\n";
		cin >> givespel;

		cout << "gimme the pronounciation!\n";
		cin >> givepron;

		cout << "gimme the definition!\n";
		cin >> givedefi;

		cout << "okay lemme put this into the word creation... ";
		wordtypes[0].baseAddWord(givespel, givepron, givedefi);	//send holding variables into addword function

		cout << "Heres your word!\t";
		wordtypes[0].words[tempsize].printword();
	}
	//------------- add word to bucket --------------
};
//------------------ array to hold buckets ------------

//|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|

//sole purpose of testing,, no need to keep
string makeIstring(int i){
	string a = {"x"};
	char c = i + 97;
	a[0] = c;
	return a;
}

int main() {

	holderoftypes wordtypesholder(1);	//create master bucket


	for(int i = 0; i < 27; i++){ 
		string input = makeIstring(i);
		wordtypesholder.wordtypes[0].baseAddWord(input, input, input);
		wordtypesholder.printoutentiredictionary();  //print out dictionary
	}


	cout << "\n\n--------------------------------\n-----------ending program--------\n--------------------------------\n\n";
	return 0;
}