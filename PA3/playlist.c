/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA3                                                 *
 * Date: 02/14/2022                                                            *
 *                                                                             *
 * Description: Load, store, display, insert, delete from, edit, sort, rate,   *
 *		play, and shuffle songs in a playlist stored in .csv format            *
 *                                                                             *
 * Format of record in input file (musicPlayList.csv): Drake (artist char*)    *
 *                                             Album      (album char*)        *
 *									           Title      (title char*)        *
 *									           Pop        (genre char*)        *
 *								               13         (playCount int)      *
 *									           4          (rating int)         *
 *                                                                             *
 * Format of output file (musicPlayList.csv): Same as input.                   *
 ******************************************************************************/

#include "playlist.h"

/*************************************************************
 * Function: get_option ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: gets an integer and returns,                 *
 *		or -1 if no integer is entered                       *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int get_option(void) {
	// scanf for an integer and return
	int option = 0, ret = 0;
	ret = scanf("%d", &option);
	switch (ret) {
	case 1:
		return option;
	default:
		return -1;
	}
}

/*************************************************************
 * Function: get_int_in_range ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: get int between the given min and max        *
 * Input parameters: int min, int max, char* message         *
 * Returns: int                                              *
 * Preconditions: min < max                                  *
 * Postconditions: min <= return int <= max                  *
 *************************************************************/
int get_int_in_range(int min, int max, char* message) {
	int option = 0;
	// while user's option is invalid
	do {
		// sanitize input to only accept integers
		if (option == -1) {
			while (getchar() != '\n');
		}
		// print the message argument
		puts(message);
		// gets an integer value
		option = get_option();
	} while (!(option >= min && option <= max));
	return option;
}

/*************************************************************
 * Function: printMenu ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints options of the main menu              *
 * Input parameters:                                         *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void printMenu(void) {
	char cmdList[11][8] = { "load", "store", "display", "insert", "delete",
		"edit", "sort", "rate", "play", "shuffle", "exit" };

	for (int i = 0; i < 11; i++) {
		printf("(%d) %s\n", i + 1, cmdList[i]);
	}
}

/*************************************************************
 * Function: parseRecordLine ()                              *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: parses a comma separated line containing     *
 *		record data into a Record struct                     *
 * Input parameters: char* str                               *
 * Returns: Record                                           *
 * Preconditions: str is a comma separated line of format    *
 *		indicated in main.c                                  *
 * Postconditions:                                           *
 *************************************************************/
Record parseRecordLine(char* str) {
	char* token;
	Record newRec;

	// check whether artist name contains a quotation: "last, first"
	token = strtok(str, "\"");
	// if no quotation, strtok will return the entire string
	if (strcmp(str, token) != 0) {
		strcpy(newRec.artist, token);
	}
	// parse normally
	else {
		token = strtok(str, ",");
		strcpy(newRec.artist, token);
	}

	// album
	token = strtok(NULL, ",");
	strcpy(newRec.album, token);
	// title
	token = strtok(NULL, ",");
	strcpy(newRec.title, token);
	// genre
	token = strtok(NULL, ",");
	strcpy(newRec.genre, token);
	// duration minutes
	token = strtok(NULL, ":");
	newRec.length.minutes = atoi(token);
	// duration seconds
	token = strtok(NULL, ",");
	newRec.length.seconds = atoi(token);
	// plays
	token = strtok(NULL, ",");
	newRec.playCount = atoi(token);
	// rating
	token = strtok(NULL, ",");
	newRec.rating = atoi(token);
	
	return newRec;
}

/*************************************************************
 * Function: loadPlaylist ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: loads a playlist from the given .csv and add *
 *		all data to a linked list, returning the list        *
 * Input parameters: char* filename                          *
 * Returns: Node*                                            *
 * Preconditions: filename is a .csv file                    *
 * Postconditions: Node* is head pointer to list or NULL     *
 *************************************************************/
Node* loadPlaylist(char* filename) {
	FILE* infile = fopen(filename, "r");
	char line[128];
	Record data;
	Node* pHead = NULL;

	// check that infile was opened successfully
	if (infile != NULL) {
		// loop through lines of file, parse, and insert at front of list
		while (fgets(line, 128, infile)) {
			data = parseRecordLine(line);
			insertFront(&pHead, data);
		}

		fclose(infile);

		return pHead;
	}
	else {
		return NULL;
	}
}

/*************************************************************
 * Function: storeList ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: stores linked list data in the given .csv    *
 * Input parameters: Node* pHead, char* filename             *
 * Returns: int indicating success                           *
 * Preconditions: filename is a .csv file                    *
 * Postconditions: return int is 1 or 0                      *
 *************************************************************/
int storeList(Node* pHead, char* filename) {
	Node* pCurrent = pHead;
	FILE* outfile = fopen(filename, "w");
	char* token, checker[32];

	// check that outfile was opened successfully
	if (outfile != NULL) {
		while (pCurrent != NULL) {
			// check whether artist name contains a comma
			strcpy(checker, pCurrent->data.artist);
			token = strtok(checker, ",");
			if (strcmp(token, pCurrent->data.artist) != 0) {
				// if comma, must put the artist back in double quotes
				fprintf(outfile, "\"%s\"", pCurrent->data.artist);
			}
			else {
				// print normally otherwise
				fputs(pCurrent->data.artist, outfile);
			}

			// print the rest of the data, separated by commas, ended by a newline
			fprintf(outfile, ",%s,%s,%s,%d:%d,%d,%d\n", pCurrent->data.album, pCurrent->data.title,
				pCurrent->data.genre, pCurrent->data.length.minutes, pCurrent->data.length.seconds,
				pCurrent->data.playCount, pCurrent->data.rating);

			pCurrent = pCurrent->next;
		}

		fclose(outfile);
		return 1;
	}
	else {
		return 0;
	}
	
}

/*************************************************************
 * Function: makeNode ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: creates Node for given Record struct,        *
 *		correct rating if out of range                       *
 * Input parameters: Record data                             *
 * Returns: Node*                                            *
 * Preconditions:                                            *
 * Postconditions: Node* contains record data or NULL ptr    *
 *************************************************************/
Node* makeNode(Record data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	// check that memory was allocated successfully
	if (newNode != NULL) {
		// initialize newNode
		newNode->data = data;
		newNode->next = NULL;
		newNode->previous = NULL;

		if (newNode->data.rating < 1) {
			newNode->data.rating = 1;
		}
		else if (newNode->data.rating > 5) {
			newNode->data.rating = 5;
		}

		return newNode;
	}
	// otherwise memory was not allocated
	else {
		// return NULL ptr to indicate error
		return NULL;
	}
}

/*************************************************************
 * Function: countRecords ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: counts a length for the given linked list    *
 * Input parameters: Node* pHead                            *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions: return int > 0                            *
 *************************************************************/
int countRecords(Node* pHead) {
	Node* pCurrent = pHead;
	int numTracks = 0;
	// get total number of tracks in the list by traversing to the end
	while (pCurrent != NULL) {
		numTracks++;
		pCurrent = pCurrent->next;
	}

	return numTracks;
}

/*************************************************************
 * Function: insertFront ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: makes a Node for and inserts record data at  *
 *		front of linked list                                 *
 * Input parameters: Node** pHead, Record data               *
 * Returns: int indicating success                           *
 * Preconditions:                                            *
 * Postconditions: success int is 1 or 0                     *
 *************************************************************/
int insertFront(Node** pHead, Record data) {
	Node* pMem = makeNode(data);
	
	// ensure memory allocated successfully
	if (pMem != NULL) {
		// check if list is empty
		if (*pHead == NULL) {
			// pHead becomes pMem
			*pHead = pMem;
		}
		else {
			// change next and previous values of pMem and pHead, respectively
			// to point at one another, and change which Node represents the
			// front of the list
			pMem->next = *pHead;
			(*pHead)->previous = pMem;
			*pHead = pMem;
		}

		return 1;
	}
	// in the event of an error
	else {
		return 0;
	}
}

/*************************************************************
 * Function: printRecord ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: formats and prints all data in Record struct *
 * Input parameters: Record data                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void printRecord(Record data) {
	// ugly formatting but prints the data prettily to the console
	printf("\"%s\" (%d:%d) by %s from %s. %s | Played %d times | %d Stars", data.title, data.length.minutes, data.length.seconds,
		data.artist, data.album, data.genre, data.playCount, data.rating);
}

/*************************************************************
 * Function: printList ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints record data for entire linked list    *
 * Input parameters: Node* pHead                            *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void printList(Node* pHead) {
	Node* pCurrent = pHead;

	// loop through list until end, where pCurrent is NULL
	while (pCurrent != NULL) {
		printRecord(pCurrent->data);
		printf("\n");
		pCurrent = pCurrent->next;
	}
}

/*************************************************************
 * Function: searchArtist ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: searched the linked list for the given       *
 *		given artist, with option to display and/or return   *
 * Input parameters: Node* pHead, char* query, int select    *
 * Returns: Node*                                            *
 * Preconditions: select is 1 or 0                           *
 * Postconditions: Node* with found record data or NULL ptr  *
 *************************************************************/
Node* searchArtist(Node* pHead, char* query, int select) {
	// Node* array in case multiple songs are found
	Node* foundSongs[8];
	int count = 0, option;
	Node* pCurrent = pHead;

	// loop pCurrent is NULL, makes return easier
	while (pCurrent != NULL) {
		// if query artist is found
		if (strcmp(query, pCurrent->data.artist) == 0) {
			foundSongs[count] = pCurrent;
			count++;
		}

		// increment list
		pCurrent = pCurrent->next;
	}

	// calling from dislay, do not need to return a song, just print and exit
	if (!select) {
		printFound(foundSongs, count);
		return NULL;
	}

	// if multiple songs found, need to prompt user for which to use
	if (count > 1) {
		printFound(foundSongs, count);

		// get wanted song from user
		option = get_int_in_range(0, count - 1, "Enter which song to select: ");
		return foundSongs[option];
	}
	// if one song found
	else if (count == 1) {
		return foundSongs[0];
	}
	// otherwise no song was found
	else {
		return NULL;
	}
}

/*************************************************************
 * Function: printFound ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints songs found from a previous search    *
 * Input parameters: Node* foundSongs[], int count           *
 * Returns: void                                             *
 * Preconditions: length of foundSongs[] > 0 and == count    *
 * Postconditions:                                           *
 *************************************************************/
void printFound(Node* foundSongs[], int count) {
	// print Record data for all the found songs
	puts("The following songs were found for that searched artist:\n");
	for (int i = 0; i < count; i++) {
		printf("[%d]", i + 1);
		printRecord(foundSongs[i]->data);
		printf("\n");
	}
}

/*************************************************************
 * Function: searchTitle ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: searches the linked list for a song matching *
 *		the given title                                      *
 * Input parameters: Node* pHead, char* query                *
 * Returns: Node*                                            *
 * Preconditions:                                            *
 * Postconditions: pCurrent contains record data or is NULL  *
 *************************************************************/
Node* searchTitle(Node* pHead, char* query) {
	Node* pCurrent = pHead;

	// loop pCurrent is NULL, makes return easier
	while (pCurrent != NULL) {
		// if query title is found
		if (strcmp(query, pCurrent->data.title) == 0) {
			break;
		}

		// increment list
		pCurrent = pCurrent->next;
	}

	return pCurrent;
}

/*************************************************************
 * Function: parseMinSec ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: parses a string in the format xx:xx where x  *
 *		is an integer to a Duration struct                   *
 * Input parameters: char* string                            *
 * Returns: Duration struct                                  *
 * Preconditions: str is of aforementioned format xx:xx      *
 * Postconditions:                                           *
 *************************************************************/
Duration parseMinSec(char* str) {
	Duration time;
	char* token;

	// get minutes
	token = strtok(str, ":");
	time.minutes = atoi(token);

	// get seconds
	token = strtok(NULL, ":");
	time.seconds = atoi(token);

	return time;
}

/*************************************************************
 * Function: caseDisplay ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: function from main switch-case to display    *
 *		all songs or songs from a searched artist            *
 * Input parameters: Node* pHead                             *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL                          *
 * Postconditions:                                           *
 *************************************************************/
void caseDisplay(Node* pHead) {
	char query[32];
	char options[2][16] = { "display all", "search artist" };
	int selected;

	// print options
	for (int i = 0; i < 2; i++) {
		printf("[%d] %s\n", i, options[i]);
	}

	// get and process user selected option
	selected = get_int_in_range(0, 1, "Enter an option: ");
	switch (selected) {
	case 0:
		// display all
		printList(pHead);
		break;
	case 1:
		// search and display
		printf("Enter the artist name to search: ");
		scanf(" %[^\n]s", &query);
		searchArtist(pHead, query, 0);

		break;
	}
}

/*************************************************************
 * Function: caseInsert ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: function from main-switch case to add a song *
 *		to the playlist, and get all song attributes from    *
 *		the user                                             *
 * Input parameters: Node** pHead                            *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void caseInsert(Node** pHead) {
	// prompt for artist name, album title, song title, genre, song length, number of times played, and rating
	Record song;
	char query[32];
	char options[7][16] = { "artist", "album", "title", "genre", "duration", "times played", "rating"};

	for (int i = 0; i < 7; i++) {
		printf("Enter the %s: ", options[i]);
		scanf(" %[^\n]s", &query);

		switch (i) {
		case 0:
			strcpy(song.artist, query);
			break;
		case 1:
			strcpy(song.album, query);
			break;
		case 2:
			strcpy(song.title, query);
			break;
		case 3:
			strcpy(song.genre, query);
			break;
		case 4:
			song.length = parseMinSec(query);
			if (song.length.minutes == 0 && song.length.seconds == 0) {
				puts("Invalid song length.");
				i--;
			}
			break;
		case 5:
			song.playCount = atoi(query);
			if (song.playCount < 0) {
				puts("Invalid play count");
				i--;
			}
			break;
		case 6:
			song.rating = atoi(query);
			if (song.rating < 1 || song.rating > 5) {
				puts("Invalid rating.");
				i--;
			}
			break;
		}
	}

	insertFront(pHead, song);
}

/*************************************************************
 * Function: deleteNode ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: deletes the given Node from the linked list  *
 * Input parameters: Node** pHead, Node* delNode             *
 * Returns: int indicating success                           *
 * Preconditions: pHead is not NULL, delNode is not NULL     *
 * Postconditions:                                           *
 *************************************************************/
int deleteNode(Node** pHead, Node* delNode) {
	// name not found
	if (delNode == NULL) {
		return 0;
	}
	else {
		// if found at start of list
		if (delNode->previous == NULL) {
			*pHead = delNode->next;
			delNode->next = NULL;
		}
		// found at end of list
		else if (delNode->next == NULL) {
			delNode->previous->next = NULL;
		}
		// in middle of list
		else {
			delNode->previous->next = delNode->next;
			delNode->next->previous = delNode->previous;
		}

		// deallocate memory for delNode
		free(delNode);

		return 1;
	}
}

/*************************************************************
 * Function: caseDelete ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: function from main switch-case to search by  *
 *		title for a song to delete, and remove it from list  *
 * Input parameters: Node** pHead                            *
 * Returns: void                                             *
 * Preconditions: *pHead is not NULL                         *
 * Postconditions:                                           *
 *************************************************************/
void caseDelete(Node** pHead) {
	Node* delNode;
	char query[32];

	// prompt user for song to delete
	printf("Enter the song title to search: ");
	scanf(" %[^\n]s", &query);
	delNode = searchTitle(*pHead, query);

	deleteNode(pHead, delNode);
}

/*************************************************************
 * Function: caseEdit ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: allows the user to search for an artist's    *
 *		songs and edit any attribute of that song            *
 * Input parameters: Node* pHead                             *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL                          *
 * Postconditions:                                           *
 *************************************************************/
void caseEdit(Node* pHead) {
	int selected;
	char query[32];
	char options[5][12] = { "artist", "album", "title", "genre", "duration" };
	Node* search;

	// prompt user for artist to search
	printf("Enter the artist name to search: ");
	scanf(" %[^\n]s", &query);
	search = searchArtist(pHead, query, 1);

	// check if song was found
	if (search != NULL) {
		// show options to user
		for (int i = 0; i < 5; i++) {
			printf("[%d] %s\n", i, options[i]);
		}

		selected = get_int_in_range(0, 4, "Enter an attribute to edit: ");
		switch (selected) {
		case 0:
			// artist
			printf("Current artist is %s.\n", search->data.artist);
			printf("Enter the new value: ");
			scanf(" %[^\n]s", &query);
			strcpy(search->data.artist, query);
			break;
		case 1:
			// album
			printf("Current album is %s.\n", search->data.album);
			printf("Enter the new value: ");
			scanf(" %[^\n]s", &query);
			strcpy(search->data.album, query);
			break;
		case 2:
			// title
			printf("Current title is %s.\n", search->data.title);
			printf("Enter the new value: ");
			scanf(" %[^\n]s", &query);
			strcpy(search->data.title, query);
			break;
		case 3:
			// genre
			printf("Current genre is %s.\n", search->data.genre);
			printf("Enter the new value: ");
			scanf(" %[^\n]s", &query);
			strcpy(search->data.genre, query);
			break;
		case 4:
			// duration
			printf("Current duration is %d:%d.\n", search->data.length.minutes, search->data.length.seconds);
			printf("Enter the new value: ");
			scanf(" %[^\n]s", &query);
			search->data.length = parseMinSec(query);
			break;
		}
	}
	else {
		printf("Artist not found with query \"%s\".\n", query);
	}
}

/*************************************************************
 * Function: swapNodes ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: swap the data of the two input Node pointers *
 * Input parameters: Node* nodeOne, Node* nodeTwo            *
 * Returns: void                                             *
 * Preconditions: nodeOne is not NULL, nodeTwo is not NULL   *
 * Postconditions:                                           *
 *************************************************************/
void swapNodes(Node* nodeOne, Node* nodeTwo) {
	// swap the data of the two nodes
	// easier than swapping their actual position in the list
	Record temp = nodeOne->data;
	nodeOne->data = nodeTwo->data;
	nodeTwo->data = temp;
}

/*************************************************************
 * Function: selectionSort ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: sort the contents of pHead based on the      *
 *		given sort category                                  *
 * Input parameters: Node* pHead, int sort                   *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL, sort is 0-3             *
 * Postconditions:                                           *
 *************************************************************/
void selectionSort(Node* pHead, int sort) {
	// sort the list given at pHead using the selection sort algorithm
	int i, numTracks = countRecords(pHead);
	Node* pCurrent, * pTemp = pHead, * pMin;

	// loop through all but the last element of the list
	for (i = 0; i < numTracks - 1; i++) {
		// initialize start and minimum values of this traversal
		pCurrent = pTemp;
		pMin = pCurrent;
		// traverse until the end of the list
		while (pCurrent->next != NULL) {
			pCurrent = pCurrent->next;

			// if the given sort category is less than the previously found minimum
			switch (sort) {
			case 0:
				// artist
				if (strcmp(pCurrent->data.artist, pMin->data.artist) < 0) {
					pMin = pCurrent;
				}
				break;
			case 1:
				// album
				if (strcmp(pCurrent->data.album, pMin->data.album) < 0) {
					pMin = pCurrent;
				}
				break;
			case 2:
				// rating
				if (pCurrent->data.rating < pMin->data.rating) {
					pMin = pCurrent;
				}
				break;
			case 3:
				// play count
				if (pCurrent->data.playCount > pMin->data.playCount) {
					pMin = pCurrent;
				}
				break;
			}
		}

		// swap the data of the start and minimum nodes
		swapNodes(pTemp, pMin);
		// increment to next starting pointer
		pTemp = pTemp->next;
	}
}

/*************************************************************
 * Function: caseSort ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: function from main switch-case to sort       *
 *		playlist based on a specified category               *
 * Input parameters: Node* pHead                             *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL                          *
 * Postconditions:                                           *
 *************************************************************/
void caseSort(Node* pHead) {
	// print option
	char options[4][12] = { "artist", "album", "rating", "play count" };
	for (int i = 0; i < 4; i++) {
		printf("[%d] %s\n", i, options[i]);
	}

	// prompt user for which attribute to sort by
	int option = get_int_in_range(0, 3, "Enter an option to sort by: ");
	//bubbleSort(pHead, option);
	selectionSort(pHead, option);
}

/*************************************************************
 * Function: caseRate ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: function from main switch-case to change     *
 *		rating of a searched song                            *
 * Input parameters: Node* pHead                             *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL                          *
 * Postconditions:                                           *
 *************************************************************/
void caseRate(Node* pHead) {
	Node* search;
	char query[32];
	int newRating;
	// prompt user for song to play from
	printf("Enter the song title to search: ");
	scanf(" %[^\n]s", &query);
	search = searchTitle(pHead, query);

	// check that song was found
	if (search != NULL) {
		// display current and prompt for new rating
		printf("Song current rating is %d.\n", search->data.rating);
		newRating = get_int_in_range(1, 5, "Enter the new rating for the song: ");

		// set new rating
		search->data.rating = newRating;
	}
	else {
		printf("Unable to find song with query \"%s\"\n", query);
	}
}

/*************************************************************
 * Function: printPlay ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints record data from the given Node, and  *
 *		can clear screen if desired                          *
 * Input parameters: Node* pCurrent, int cls                 *
 * Returns: void                                             *
 * Preconditions: pCurrent is not NULL, cls is 1 or 0        *
 * Postconditions:                                           *
 *************************************************************/
void printPlay(Node* pCurrent, int cls) {
	// clear screen and indicate that song is playing
	if (cls) {
		system("CLS");
	}
	else {
		printf("\n");
	}
	printf("Playing: ");
	printRecord(pCurrent->data);
	// sleep for 2 seconds
	Sleep(2000);
	// increment playCount
	pCurrent->data.playCount++;
}

/*************************************************************
 * Function: playTracks ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: plays tracks in order from the start track   *
 * Input parameters: Node* startTrack                        *
 * Returns: void                                             *
 * Preconditions: startTrack is not NULL                     *
 * Postconditions:                                           *
 *************************************************************/
void playTracks(Node* startTrack) {
	Node* pCurrent = startTrack;
	
	// traverse linked list and print each record content
	while (pCurrent != NULL) {
		printPlay(pCurrent, 1);
		// increment through list
		pCurrent = pCurrent->next;
	}
}

/*************************************************************
 * Function: playShuffled ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Plays the tracks in pHead in the specified   *
 *		order, and can clear screen if specified             *
 * Input parameters: Node* pHead, int numTracks,             *
 *		int* playOrder, int cls                              *
 * Returns: void                                             *
 * Preconditions: length of playOrder == numTracks,          *
 *		pHead is not NULL, cls is 1 or 0                     *
 * Postconditions:                                           *
 *************************************************************/
void playShuffled(Node* pHead, int numTracks, int* playOrder, int cls) {
	int r, prevTrack = 0, difference;
	Node* pCurrent = pHead;
	for (int i = 0; i < numTracks; i++) {
		// next track to play
		r = playOrder[i];
		// shuffled track is before the last played
		if (r < prevTrack) {
			// find how far to seek through the playlist
			difference = prevTrack - r;
			for (int seek = 0; seek < difference; seek++) {
				pCurrent = pCurrent->previous;
			}
		}
		// shuffled track is after the last played
		else if (r > prevTrack) {
			difference = r - prevTrack;
			for (int seek = 0; seek < difference; seek++) {
				pCurrent = pCurrent->next;
			}
		}

		// there is a third case where r == prevTrack
		// but this is only possible if first shuffled track 
		// is the first song in the playlist, and doesn't require any seeking

		printPlay(pCurrent, cls);
		prevTrack = r;
	}
}

/*************************************************************
 * Function: shuffleTracks ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Shuffles and plays the tracks from the list  *
 *		pointed to by pHead, without modifying the list      *
 * Input parameters: Node* pHead                             *
 * Returns: void                                             *
 * Preconditions: pHead is not NULL                          *
 * Postconditions:                                           *
 *************************************************************/
void shuffleTracks(Node* pHead) {
	int numTracks, *playOrder, *randArray, r, randCount = 0;
	Node* pCurrent = pHead;

	numTracks = countRecords(pHead);
	// create parallel arrays to keep track of order and which tracks are left
	playOrder = calloc(numTracks, sizeof(int));
	randArray = calloc(numTracks, sizeof(int));
	
	// shuffle the tracks
	while (randCount < numTracks) {
		r = rand() % numTracks;
		if (randArray[r] == 0) {
			randArray[r] = 1;
			playOrder[randCount] = r;
			randCount++;
		}
	}

	playShuffled(pHead, numTracks, playOrder, 1);

	// prevent dangling pointers
	free(playOrder);
	free(randArray);
}