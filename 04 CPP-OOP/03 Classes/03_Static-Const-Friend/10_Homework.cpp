/// Returning objects
/*
● We have a string and providing a getter for it
● You are debating with a fresh developer about the differences between these styles
● Discuss the differences
*/

string GetAnswerText() {
	return answer_text;
}

//- Correct
//- But the return calls copy constructor which takes memory & time
//- As we don't change data members, C++ OO encourages using const!



string GetAnswerText() const {
	return answer_text;
}

//- Same as above, but now doesn't violate OO

string& GetAnswerText() const {
	return answer_text;
}

//- Good side: No copy constructor. The reference saves time & memory
//- Bad. A user can make use of the returned string to reset it externally


const string& GetAnswerText() const {
	return answer_text;
}

//- Perfect
//- Return by refence, but prevent him from signing to a different value + const function also



/// Think deeper :)











