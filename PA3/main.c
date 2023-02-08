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

#include "testPlaylist.h"

int main(void) {
	// initialize option and exit integers
	int option, exit = 0, result;
	Node* pHead = NULL;
	Node* search = NULL;
	char query[32];
	char* filename = "musicPlayList.csv";
	// init random for shuffle function
	srand(time(NULL));

	//testInsertFront();
	//testDelete();
	//testShuffle();

	do {
		// show user all options and get which to perform
		printMenu();
		option = get_int_in_range(1, 11, "Enter an option: ");
		system("CLS");

		// make sure some options won't break if playlist is empty
		if (pHead == NULL && !(option == 1 || option == 3 || option == 4 || option == 11)) {
			puts("You must create or load playlist before performing that action.");
			continue;
		} 

		// switch-case based on user input
		switch (option) {
		case 1:
			// load
			pHead = loadPlaylist(filename);
			if (pHead != NULL) {
				puts("Playlist loaded successfully.");
			}
			else {
				printf("Unable to read playlist from %s.", filename);
			}
			
			break;
		case 2:
			// store
			result = storeList(pHead, filename);
			if (result == 1) {
				printf("Playlist output to %s successfully.", filename);
			}
			else {
				printf("Unable to output playlist to %s.", filename);
			}

			break;
		case 3:
			// display
			caseDisplay(pHead);
			break;
		case 4:
			// insert
			caseInsert(&pHead);
			break;
		case 5:
			// delete
			caseDelete(&pHead);
			break;
		case 6:
			// edit
			caseEdit(pHead);
			break;
		case 7:
			// sort
			caseSort(pHead);
			break;
		case 8:
			// rate
			caseRate(pHead);
			break;
		case 9:
			// play
			// prompt user for song to play from
			printf("Enter the song title to search: ");
			scanf(" %[^\n]s", &query);
			search = searchTitle(pHead, query);

			// check that song was found
			if (search != NULL) {
				playTracks(search);
			}
			else {
				printf("Unable to find song with query \"%s\"\n", query);
			}			

			break;
		case 10:
			// shuffle
			shuffleTracks(pHead);
			break;
		case 11:
			// exit
			result = storeList(pHead, filename);
			if (result == 1) {
				printf("Playlist output to %s successfully.", filename);
			}
			else {
				printf("Unable to output playlist to %s.", filename);
			}

			exit = 1;
			break;
		}

		printf("\n");
	} while (!exit);
}