#include "doctest.h"
#include "mat.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") 
{
	/* 1
	@@@@@@@@@
	@-------@
	@-@@@@@-@
	@-@---@-@
	@-@@@@@-@
	@-------@
	@@@@@@@@@
	*/
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	
	/* 2
	1111111111111
	1           1
	1 111111111 1
	1           1
	1111111111111
	*/
	CHECK(nospaces(mat(13, 5, '1', ' ')) == nospaces("1111111111111\n1           1\n1 111111111 1\n1           1\n1111111111111"));
	
	/* 3
	$$$
	$+$
	$+$
	$+$
	$$$
	*/
	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n$+$\n$+$\n$+$\n$$$\n"));
	
	/* 4
	#
	*/
	CHECK(nospaces(mat(1, 1, '#', '(')) == nospaces("#\n"));
	
	/* 5 - same chars
	@@@
	@@@
	@@@
	*/
	CHECK(nospaces(mat(3, 3, '@', '@')) == nospaces("@@@\n@@@\n@@@"));
	
	/* 6
	!!!!!
	!^^^!
	!!!!!
	*/
	CHECK(nospaces(mat(5, 3, '!', '^')) == nospaces("!!!!!\n!^^^!\n!!!!!"));
	
	/* 7
	(((((((
	()))))(
	()((()(
	()()()(
	()()()(
	()()()(
	()((()(
	()))))(
	(((((((
	*/
	CHECK(nospaces(mat(7, 9, '(', ')')) == nospaces("(((((((\n()))))(\n()((()(\n()()()(\n()()()(\n()()()(\n()((()(\n()))))(\n((((((("));
	
	/* 8
	aaaaaaaaaaaaaaa
	abbbbbbbbbbbbba
	aaaaaaaaaaaaaaa
	*/
	CHECK(nospaces(mat(15, 3, 'a', 'b')) == nospaces("aaaaaaaaaaaaaaa\nabbbbbbbbbbbbba\naaaaaaaaaaaaaaa"));

	/* 9
	+
	+
	+
	+
	+
	+
	+
	*/
	CHECK(nospaces(mat(1, 7, '+', '-')) == nospaces("+\n+\n+\n+\n+\n+\n+"));
	
	/* 10
	***********
	*%%%%%%%%%*
	***********
	*/
	CHECK(nospaces(mat(11, 3, '*', '%')) == nospaces("***********\n*%%%%%%%%%*\n***********"));
	
	/* 11
	+++++++
	*/
	CHECK(nospaces(mat(7, 1, '+', '-')) == nospaces("+\n+\n+\n+\n+\n+\n+"));
}

TEST_CASE("Bad input") 
{
	// 1
    CHECK_THROWS(mat(10, 5, '$', '%'));
	// 2
	CHECK_THROWS(mat(5, 10, 'a', 'b'));
	// 3 - negative rows
	CHECK_THROWS(mat(-1, 5, '!', '%'));
	// 4 - negative columns
	CHECK_THROWS(mat(3, -5, '@', '#'));
	// 5
	CHECK_THROWS(mat(4, 4, '1', '2'));
	// 6
	CHECK_THROWS(mat(8, 6, '(', ')'));
	// 7 - negative both
	CHECK_THROWS(mat(-5, -7, 'a', 'b'));
	// 8 
	CHECK_THROWS(mat(20, 20, ' ', ' '));
	// 9 - 0 columns
	CHECK_THROWS(mat(0, 3, 'a', 'b'));
	// 10 - 0 rows
	CHECK_THROWS(mat(21, 0, '3', '5'));
}