#pragma warning(disable:6262)
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool decrypt(const char ciphertext[], const char crib[]) {

	// copy of ciphertext that with substitutions (final result)
	char plaintext[100000];
	// copy of ciphertext with all of the unnecessary characters removed
	char copytext[100000];
	// copy of crib with unnecessary characters removed
	char copycrib[100000];

	// copy crib, make it all lowercase, and change all nonalphabet characters into spaces
	strcpy(copycrib, crib);
	for (int i = 0; i < strlen(crib); i++) {
		// changes to lowercase
		copycrib[i] = tolower(crib[i]);
		// if copycrib at i is not a letter character
		if (!isalpha(copycrib[i])) {
			// copycrib at i becomes a space
			copycrib[i] = ' ';
		}
	}

	// delete all irrelevant spaces in copycrib
	for (int i = 0; i < strlen(copycrib); i++) {
		// if copycrib at position i is a space and is also not a newline character
		if (isspace(copycrib[i]) && copycrib[i] != '\n') {
			// while the next character after position i is a space
			while (isspace(copycrib[i + 1])) {
				for (int h = i + 1; h < strlen(copycrib); h++) {
					// all characters to the right of h are shifted to the left in place of the second space (two spots to the right of position i)
					copycrib[h] = copycrib[h + 1];

				}
			}
			// if the next character after position i is a null byte character
			if (copycrib[i + 1] == '\0') {
				// character at position i becomes the null byte character
				copycrib[i] = '\0';
			}
			// if the beginning of copycrib starts with a space
			if (copycrib[0] == ' ') {
				for (int h = 0; h < strlen(copycrib); h++) {
					// all characters are shifted to the left in place of the initial space character
					copycrib[h] = copycrib[h + 1];

				}
			}

		}

	}

	// if length of copycrib is greater than 90 return false
	if (strlen(copycrib) > 90) {
		return false;
	}

	// if crib string has no words return false
	int cribCount = 0;
	for (int i = 0; i < strlen(copycrib); i++) {
		if (isalpha(copycrib[i])) {
			cribCount++;
		}
	}
	if (cribCount == 0) {
		return false;
	}
	

	// copies ciphertext into plaintext
	strcpy(plaintext, ciphertext);

	// makes all letters in plaintext lowercase
	for (int i = 0; i < strlen(plaintext); i++) {
		plaintext[i] = tolower(plaintext[i]);
	}

	// copy characters in plaintext into copytext
	strcpy(copytext, plaintext);

	// change all punctuation characters in copytext into spaces
	for (int i = 0; i < strlen(copytext); i++) {
		// if character at position i in copytext is a punctuation character
		if (ispunct(copytext[i])) {
			// character at position i becomes a space
			copytext[i] = ' ';
		}
	}

	// delete spaces when there are more than 2 in a row
	for (int i = 0; i < strlen(copytext); i++) {

		// if copytext at position i is a space character but not a newline character
		if (isspace(copytext[i]) && copytext[i] != '\n') {
			// if the next character after position i is a newline character and 2 positions after position i is a null byte character
			if (copytext[i + 1] == '\n' && copytext[i + 2] == '\0') {
				for (int h = i; h < strlen(copytext); h++) {
					// all characters after character at position h are shifted one to the left
					copytext[h] = copytext[h + 1];
				}
			}
			else {
				// while the next position after i is a space character
				while (isspace(copytext[i + 1])) {
					for (int h = i + 1; h < strlen(copytext); h++) {
						// all characters after position h are shifted to the left
						copytext[h] = copytext[h + 1];
					}
				}
			}

		}

	}

	// if length of copycrib is greater than length of copytext return false
	if (strlen(copycrib) > strlen(copytext)) {
		return false;
	}

	// count number of spaces/punctuation characters in crib
	int count1 = 0;
	for (int i = 0; i < strlen(copycrib); i++) {
		// if character at position i is a space or a punctuation character
		if (isspace(copycrib[i]) || ispunct(copycrib[i])) {
			// increment count1
			count1++;
		}
	}

	// count number of spaces in copycrib
	int count = 0;
	for (int i = 0; i < strlen(copycrib); i++) {
		// if copycrib at position i is a space character 
		if (isspace(copycrib[i])) {
			// increment count
			count++;
		}
	}


	// count number of matches in copycrib
	int count4 = 0;
	for (int i = 0; i < strlen(copycrib); i++) {
		for (int j = i + 1; j < strlen(copycrib); j++) {
			// if copycrib at position i is the same character as copycrib at position j
			if (copycrib[i] == copycrib[j]) {
				// increment count4
				count4++;
			}
		}
	}

	// count number of alphabet characters in copycrib
	int count9 = 0;
	for (int i = 0; i < strlen(copycrib); i++) {
		// if copycrib at position i is an alphabet character
		if (isalpha(copycrib[i])) {
			// increment count9
			count9++;
		}
	}


	// iterate through all of copytext
	for (int i = 0; i < strlen(copytext); i++) {

		// number of spaces in ciphertext with limits of crib size
		int count2 = 0;

		// number of matches that correlate between both crib and ciphertext
		int count3 = 0;

		// number of matches in ciphertext with limits of crib size
		int count5 = 0;

		// number of digits in sectioned ciphertext
		int count6 = 0;

		// number of "\n"s in sectioned ciphertext
		int count7 = 0;

		// number of matches for alphabet characters
		int count8 = 0;

		// number of alphabet characters in copytext
		int count10 = 0;

		int t = 0;
		int u;
		int f;
		int g;

		// see which positions match in crib
		for (int j = 0; j < strlen(copycrib); j++) {
			for (int k = j + 1; k < strlen(copycrib); k++) {
				// check correlating positions between copycrib and copytext
				if (copycrib[j] == copycrib[k]) {
					if (copytext[i + j] == copytext[i + k]) {
						// if the positions match for both copycrib and copytext increment count3
						count3++;
					}
				}
			}
		}

		// check if there are numbers in the sectioned portion of copytext
		for (int s = i; s < strlen(copycrib) + i && strlen(copycrib) + i <= strlen(copytext); s++) {
			// if plaintext at position s is a digit character
			if (isdigit(copytext[s])) {
				// increment count6
				count6++;
			}
		}

		// check if there are any "\n"s in the sectioned portion of copytext
		for (int s = i; s < strlen(copycrib) + i; s++) {
			// if plaintext at position s is a newline character
			if ((copytext[s] == '\n')) {
				// increment count7
				count7++;
			}
		}

		// counting amount of matches in copytext
		for (f = i; f < strlen(copycrib) + i; f++) {
			for (g = f + 1; g < strlen(copycrib) + i; g++) {
				// within copytext, if character at position f matches character at position g
				if (copytext[f] == copytext[g]) {
					// increment count5
					count5++;
				}
			}
		}

		// checks to see if copycrib and plaintext have same kind of characters
		for (int b = 0; b < strlen(copycrib) && strlen(copycrib) + i <= strlen(copytext); b++) {
			// if copycrib at position b and the position after are letter characters
			if (isalpha(copycrib[b]) && isalpha(copytext[b + i])) {
				// increment count8
				count8++;
			}
		}

		// checks number of alphabet characters in the first couple characters until string length (Should only be called when count == 0 and i == 0)
		for (int v = 0; v < strlen(copycrib); v++) {
			// if copytext at position v is an alphabet character
			if (isalpha(copytext[v])) {
				// increment count10
				count10++;
			}
		}

		// iterate through a section of copytext depending on the size of crib
		for (int p = i; p < i + strlen(copycrib) && strlen(copycrib) + i <= strlen(copytext); p++) {
			// count number of spaces/ punctuation characters in copytext within the size of crib
			if (isspace(copytext[p]) || ispunct(copytext[p])) {
				count2++;
			}

		}



		// if there are no spaces in copycrib
		if (count == 0) {

			// if crib matches first word in copytext
			if (i == 0) {
				// if the character after crib length in copytext isn't a letter
				if (!isalpha(copytext[strlen(copycrib)])) {
					// if the amount of correlating positions in copytext equals the amount of matches in crib
					if (count3 == count4 && count4 == count5) {
						// if each position in copytext and copycrib have the same kind of characters 
						if (count8 == count9) {
							// if there are no numbers and no newline characters
							if (count6 == 0 && count7 == 0) {
								// if the number of alphabet characters at the front is equal to the length of copycrib
								if (count10 == strlen(copycrib)) {
									for (u = i; u < strlen(copycrib) + i; u++) {
										for (int w = 0; w < strlen(plaintext); w++) {
											// if the character at position w of plaintext is the same character in copytext at position t
											if (plaintext[w] == copytext[t]) {
												//character at position w of plaintext becomes the uppercase letter of character at position t of copycrib
												plaintext[w] = toupper(copycrib[t]);
											}
										}
										// increment t (which refers to the positions in copycrib
										t++;
									}
									cout << plaintext;
									return true;
								}
							}
						}

					}
				}
			}


			// when crib matches on middle/end of copytext
			else {

				// if iteration gets to the last character in copytext
				if (i == strlen(copytext) - 1) {
					// if the amount of correlating positions in copytext equals the amount of matches in crib
					if (count3 == count4 && count4 == count5) {
						// if each position in copytext3 and copycrib have the same kind of characters 
						if (count8 == count9) {
							// if there are no numbers and no newline characters
							if (count6 == 0 && count7 == 0) {
								// if copycrib is a single letter
								if (strlen(copycrib) == 1) {
									// if the character to the left of i is not an alphabet character
									if (!isalpha(copytext[i - 1])) {
										for (u = i; u < strlen(copycrib) + i; u++) {
											for (int w = 0; w < strlen(plaintext); w++) {
												// if plaintext at position w is the same character as copytext at position u
												if (plaintext[w] == copytext[u]) {
													// plaintext at position w becomes the character at copycrib at position t
													plaintext[w] = copycrib[t];
													// plaintext at position w becomes uppercase
													plaintext[w] = toupper(plaintext[w]);
												}

											}
										}
										cout << plaintext;
										return true;

									}
								}
							}
						}
					}
					return false;
				}

				// when i is not at last character and it iterates through copytext
				if (strlen(copycrib) + i <= strlen(copytext)) {
					// if not at last character in copytext check that the character before sectioned copytext and after sectioned copytext are not alphabet characters
					if (!isalpha(copytext[i - 1]) && !isalpha(copytext[i + strlen(copycrib)])) {
						// if the amount of correlating positions in copytext equals the amount of matches in crib
						if (count3 == count4 && count4 == count5) {
							// if each position in copytext3 and copycrib have the same kind of characters 
							if (count8 == count9) {
								// if there are no numbers and no newline characters
								if (count6 == 0 && count7 == 0) {
									for (u = i; u < strlen(copycrib) + i; u++) {
										for (int w = 0; w < strlen(plaintext); w++) {
											// if plaintext at position w is the same character as copytext at position u
											if (plaintext[w] == copytext[u]) {
												// plaintext at position w becomes the character at copycrib at position t
												plaintext[w] = copycrib[t];
												// plaintext at position w becomes uppercase
												plaintext[w] = toupper(plaintext[w]);

											}

										}
										// increment t (which travels through each character in crib)
										t++;
									}
									cout << plaintext;
									return true;
								}
							}
						}
					}
				}
			}
		}




		// if there is at least one space in copycrib
		else {
			// if the number of spaces for the length of crib in copytext equals the number of spaces in crib
			if (count1 == count2) {
				// if the amount of correlating positions in ciphertext equals the amount of matches in crib
				if (count3 == count4 && count4 == count5) {
					// if there are no numbers 
					if (count6 == 0 && count7 == 0) {
						// if each position in copytext3 and copycrib have the same kind of characters 
						if (count8 == count9) {
							// if i is at 0
							if (i == 0) {
								if (!isalpha(copytext[strlen(copycrib)])) {
									for (u = i; u < strlen(copycrib) + i; u++) {
										for (int w = 0; w < strlen(plaintext); w++) {
											// if the character at position w of plaintext is the same character in copytext at position t
											if (plaintext[w] == copytext[t]) {
												//character at position w of plaintext becomes the uppercase letter of character at position t of copycrib
												plaintext[w] = toupper(copycrib[t]);
											}
										}
										// increment t (which refers to the positions in copycrib
										t++;
									}
									cout << plaintext;
									return true;
								}
							}
							else {
								// while the next position after length of crib in copytext is not a letter
								while (!isalpha(copytext[i + strlen(copycrib)]) && !isalpha(copytext[i - 1])) {
									for (u = i; u < strlen(copycrib) + i; u++) {
										// iterate through all of plaintext switching each corresponding letter in crib for plaintext
										for (int w = 0; w < strlen(plaintext); w++) {
											// if plaintext at position w is the same character as copytext at position u
											if (plaintext[w] == copytext[u]) {
												// plaintext at position w becomes the character at copycrib at position t
												plaintext[w] = copycrib[t];
												// plaintext at position w becomes uppercase
												plaintext[w] = toupper(plaintext[w]);

											}

										}
										// increment t (which travels through each character in crib)
										t++;

									}
									cout << plaintext;
									return true;
								}
							}
						}
					}
				}
			}

		}


	}
	return false;
}





int main() {
	//	no space in crib and match is at front
	decrypt("hey12 jaden@@ lee", "joy");											// JOY12 jadOn@@ lOO
	decrypt("a a c da", "j");														// J J c dJ
	decrypt("F lgr rntoy rkwndyk ahna'y\nphklk ahk mgtks fy.\n", "J");				// J lgr rntoy rkwndyk ahna'y
																					// phklk ahk mgtks Jy.
	decrypt("adb 123 db", "jas");													// JAS 123 AS
	decrypt("ew'q p-aj", "he");														// HE'q p-aj
	decrypt("Rzy pkr", "dog");														// DOG pkD
	cout << endl;

	// no space in crib and match is later in plaintext
	decrypt("happy12 birthday@ hah! you", "jkl");									// happJ12 birthdaJ@ hah! JKL
	decrypt("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "shadow");					// false	
	decrypt("123 adb db", "jas");													// 123 JAS AS
	decrypt("aab 12 343 bhy bh", "jas");											// aaJ 12 343 JAS JA
	decrypt("ac b cc", "jj");														// aJ b JJ
	decrypt("12 33 221 342", "ja");													// false
	decrypt("12 33 221 342 1", "j");												// false		
	decrypt("ab c dc", "j");														// ab J dJ
	decrypt("a a c da", "j");														// J J c dJ
	decrypt("ab c  d dc", "j");														// ab J  d dJ
	decrypt("12aj jk3# #@sa j", "Z");												// 12aZ Zk3# #@sa Z
	decrypt("jesus loves me this i know", "bub");									// false
	decrypt("jesus loves me this i know", "k");										// jesus loves me thKs K know
	decrypt("jesus@@ loves me123 this i know", "ja");								// jAsus@@ lovAs JA123 this i know
	decrypt("happy birthday to you", "he");											// happy birHhday HE yEu
	decrypt("12dd pp3# #@sa p", "qo");												// 12dd pp3# #@QO p
	decrypt("", "ja");																// false
	cout << endl;

	// at least one space in crib
	decrypt("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "my secret");					// hiESS ejsT MY SECRET oS.
	//																					// o'M foSCREET.
	decrypt("Xbg'j rsj jds jsrrsy jycn jds UcRSgJ qrqyt.", "sILent aLarm");				// xbN'T LET TdE TELLER TRIn TdE SILENT ALARM.
	decrypt("abcd efg hijk ilm nppq rst dccb cba uwwx wyz", "good one");				// abcd efg hijk ilm nppq rst dccb cba GOOD ONE
	decrypt("wmwt\nqeirtk spst\n", "turing azan");										// wmwN
	//																					// TURING AZAN
	decrypt("wmwt\nqeirtk spst\n", "alan turing");										// false	
	decrypt("Kpio't dmpbl-boe-ebhhfs opwfm", "s cloak and");							// kOiN'S CLOAK-AND-DAhhfs NOwfL
	decrypt("jesus loves me this i know", "i love v");									// false						
	decrypt("F gspt fe! zyxZYXzyx--Abca abCa    bdefg## $$dsptrqtj6437 wvuWVUwvu\n\n8 9\n", "hush hush until november");	// I LOVE IT! zyxzyxzyx--HUSH HUSH    UNTIL## $$NOVEMBER6437 wvuwvuwvu /n 8 9
	decrypt("F gspt fe! zyxZYXzyx--Abca abCa    bdefg## $$dsptrqtj6437 wvuWVUwvu\n\n8 9\n", "hush-hush until November 25, 2021");			// I LOVE IT! zyxzyxzyx--HUSH HUSH    UNTIL## $$NOVEMBER6437 wvuwvuwvu /n 8 9																																				
	decrypt("F gspt fe! zyxZYXzyx--Abca abCa    bdefg## $$dsptrqtj6437 wvuWVUwvu\n\n8 9\n", "   hush???hUSh---     --- until    NovemBER !!  ");			// I LOVE IT! zyxzyxzyx--HUSH HUSH    UNTIL## $$NOVEMBER6437 wvuwvuwvu /n 8 9
	decrypt("F gspt fe! zyxZYXzyx--Abca abCa    bdefg## $$dsptrqtj6437 wvuWVUwvu\n\n8 9\n", "hush hush  1232????111until november?? \n?");			// I LOVE IT! zyxzyxzyx--HUSH HUSH    UNTIL## $$NOVEMBER6437 wvuwvuwvu /n 8 9
	decrypt("F gspt fe! zyxZYXzyx--Abca abCa    bdefg## $$dsptrqtj6437ff wvuWVUwv", "j");									// J gspt Je! zyxzyxzyx--abca abca    bdeJg## $$dsptrqtj6437JJ wvuwvuwv
	decrypt("jesus loves me this i know", "hi jade");									// jIEuE lovIE HI JADE D know
	decrypt("jesus@@ loves me123 this i know", "jab");									// false



	 // random test cases
	decrypt("I love jesus yes i do", "hi");													// i lIve jesus yes i HI
	decrypt("I love jesus yes i do", "abdefeg");												// false
	decrypt("I love jesus yes i do", "aaa");													// false
	decrypt("jaden lee", "jaden leeyt");														// false
	decrypt("jaden lee", "jaden leeadsfadsf");												// fasle
	decrypt("jaden lee", "jaden lee adsfadsf");												// false
	decrypt("jaden leel", "jaden lee");														// false
	decrypt("jaden lee", "jaden @#123lee");														// JADEN LEE			
	decrypt("jaden lee", "jad@#123en lee");														// false
	decrypt("jaden lee", " @@ pee  $$%2@#\n@# #");												// jadEn PEE
	decrypt("jesus loves me this i know", "i love v");								// false
}

