/*
 * Student ID: 201234567
 * Student Name: Tomas Wardle
 * Email: T.wardle@student.liverpool.ac.uk
 * User: sgtwardl
 *
 * Problem ID: 1086
 * RunID: 32100
 * Result: Presentation Error
*/

#include <stdio.h>

void decode() {

	//Initialisation
	char repeat1, repeat2;
	int repeatTimes;
	char mult;

	//Loops until end of file.
	while (scanf("%c%c", &repeat1, &repeat2) != EOF) {
		//Next two IFs deal with newline characters being present.

		if (repeat1 == '\n') {
			printf("\n");
			repeat1 = repeat2;
			scanf("%c", &repeat2);
		}

		if (repeat2 == '\n') {
			printf("%c\n", repeat1);
			continue;
		}

		//Deals with the case that a single character is detected.
		//
		while (repeat1 != repeat2) {
			printf("%c", repeat1);
			repeat1 = repeat2;
			scanf("%c", &repeat2);
		}

		//Reads in the amount of times the character will be repeated + the asterisk following the int.
		scanf("%i%c", &repeatTimes, &mult);

		//Prints the character the amount of times specified in repeatTimes.
		for (int i = 0; i < repeatTimes; i++) {
			printf("%c", repeat1);
		}
	}
}

void encode() {

	//Initialisation
	char inputChar;
	char lastChar = 0;
	int charCount = 0;

	//Loops until the end of the file.
	while (scanf("%c", &inputChar) != EOF) {
		
		//Increments charCount if the new character is the same as the last one.
		if (inputChar == lastChar) {
			charCount++;
			continue;
		}

		//Prints the characters in the format specified, unless there's only one character, in which case only the character is submitted.
		if (charCount > 1) {
			printf("%c%c%i*", lastChar, lastChar, charCount);
		}
		else {
			printf("%c", lastChar);
		}

		//Deals with newline characters by printing the newline, scanning in the next character (to prevent newline becoming encoded).
		if (inputChar == '\n') {
			printf("\n");
			scanf("%c", &inputChar);
		}

		//Sets up the next lastChar.
		charCount = 1;
		lastChar = inputChar;
	}

	//Prints last char in memory when EOF reached.
	if (charCount > 1) {
		printf("%c%c%i*", lastChar, lastChar, charCount);
	}
	else {
		printf("%c", lastChar);
	}
}

void main() {
	char mode;
	scanf("%c", &mode);

	//Determines mode of operation.
	if (mode == 'C') { encode(); }
	if (mode == 'E') { decode(); }
}
