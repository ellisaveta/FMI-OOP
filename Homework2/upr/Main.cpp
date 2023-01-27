#include <iostream>
#include "Result.hpp";
#include "ElectionResultsDatabase.hpp"
#include "Vector4D.hpp"

using namespace std;

int main()
{
	//Task 1:
	Error er1("treig");
	Error er2;

	Error er3 = er1;
	cout << er3.get_message() << '\n';

	Optional<Error> op1;
	Optional<Error> op2(er1);
	Optional<Error> op3;
	op3 = op2;
	op1.get_value();
	op1.is_none();
	op2.is_none();
	op3.get_value();
	op3.is_none();

	Optional<int> op4;
	Optional<int> op5(6);
	Optional<int> op6;
	op6 = op5;
	if (op5.get_value() == 0) cout << "yes\n";
	else cout << "no\n";
	op4.get_value();
	op4.is_none();
	op5.is_none();
	op6.get_value();
	op6.is_none();

	Result<int> re1;
	Result<int> re2(4);
	Result<int> re3("treyu");
	re1.get_error();
	re1.get_result();
	re2.get_error();
	re2.get_result();
	re3.get_error();
	re3.get_result();

	re1 == 4;
	re2 == 7;
	re3 == 9;
	re1 == er1;
	re2 == er1;
	re3 == er1;

	er1.SetMessage("errorrrr");
	op1.SetValue(er1);
	op1.get_value();
	op1.is_none();
	op4.SetValue(5);
	op4.get_value();
	op4.is_none();
	re1.setError("Trjhsb");
	re1.get_error();
	re1.get_result();
	/*
	//Task 2:
	SectionVotes s;
	s.SetVotesForParty(PARTY1, 4);
	s.SetVotesForParty(PARTY2, 3);
	s.SetVotesForParty(PARTY3, 6);
	s.votesForParty(PARTY1);
	s.votesForParty(PARTY2);
	s.votesForParty(PARTY3);

	SectionVotes s1(34, 52, 12);
	s1.votesForParty(PARTY1);
	s1.votesForParty(PARTY2);
	s1.votesForParty(PARTY3);

	ElectionResultsDatabase el;
	el.addResultsFromFile("ElectionResults.txt");
	el.numberOfSections();
	el.votesForParty(PARTY1);
	el.votesForParty(PARTY2);
	el.votesForParty(PARTY3);
	el.winningParty();
	cout << el;
	

	//Task 3:
	Vector4D vec(1, 2, 3, 4);
	if (vec[0] == 1.0) cout << "yes\n";
	if (vec[1] == 1) cout << "yes\n";
	if (vec[3] == 4) cout << "yes\n";
	vec[2] = 7;
	Vector4D vec1(-3.4, 2.3, 5.2, 1);
	Vector4D vec2(-2.4, 4.3, 8.2, 5);
	vec[2] = 3;
	Vector4D temp(0, 0, 0, 0);
	temp = vec + vec1;
	vec + vec1 == vec2;
	vec2 - vec == vec1;
	vec2 - vec1 == vec;
	vec += vec1;
	vec == vec2;
	vec -= vec1;
	Vector4D vec3(-3.4, 4.6, 15.6, 4);
	vec*vec1 == vec3;
	vec3 / vec == vec1;
	vec1 *= vec;
	vec1 == vec3;
	vec1 /= vec;
	Vector4D vec4(-6.8, 9.2, 31.2, 8);
	vec3 * 2 == vec4;
	vec3 *= 2;
	vec3 == vec4;
	vec3 * 2 != vec4;
	vec3 <= vec4;
	vec3 >= vec4;
	vec4 < vec2;
	vec1 > vec2;
	!vec;
	Vector4D vec5(6.8, -9.2, -31.2, -8);
	-vec4 == vec5;
	-vec5 == vec4;
	vec3 *= 0;
	!vec3;
	*/
	return 0;
}