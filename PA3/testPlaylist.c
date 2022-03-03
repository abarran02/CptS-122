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
#include "testPlaylist.h"

void testInsertFront(void) {
	// initialize success and linked list pHead
	int success = 0;
	Node* pHead = NULL;
	// test case
	Duration testDuration = { 4, 36 };
	Record testCase = { "Perry, Katy", "Chained to the Rhythm", "Witness", "Pop", testDuration, -1, 6 };
	
	// test insertFront() and determine success
	success = insertFront(&pHead, testCase);

	// success indicates that malloc was able to allocate memory
	if (success) {
		puts("Successfully allocated memory for Node insertion.");
		// the actual insertion will change replace pHead, which began as a NULL pointer
		if (pHead != NULL) {
			puts("Successfully changed pHead from NULL to record Node.");
		}
		else {
			puts("Unsuccessfully changed pHead from NULL.");
		}
	}
	else {
		puts("Unsuccessfully allocated memory for Node insertion.");
	}
}

void testDelete(void) {
	// initialize success and linked list pHead
	int success = 0;
	Node* pHead = NULL, * delNode;
	// test case
	Duration testDuration = { 4, 36 };
	Record testCase = { "Perry, Katy", "Chained to the Rhythm", "Witness", "Pop", testDuration, 3, 5 };
	// initialize linked list contents
	insertFront(&pHead, testCase);

	// search for Node to delete (guaranteed to find) and delete it
	// determine success of deletion
	delNode = searchTitle(pHead, "Witness");
	success = deleteNode(&pHead, delNode);

	// success indicates only if a Node was found to delete
	if (success) {
		puts("Successfully found node to delete.");
		// successful deletion will free memory of the Node and set pHead back to NULL pointer
		if (pHead == NULL) {
			puts("Successfully freed memory for node and set pHead to NULL.");
		}
		else {
			puts("Unsuccessfully freed memory and set pHead to NULL.");
		}
	}
	else {
		puts("Unsuccessfully found node to delete.");
	}
}

void testShuffle(void) {
	// initialize shuffle order and linked list pHead
	int playOrder[3] = { 2, 0, 1 };
	Node* pHead = NULL;
	// three songs to add to list
	Duration testDurations[3] = { {4, 36}, {5, 19}, {4, 28} };
	Record testCases[3] = {
		{ "Perry, Katy", "Chained to the Rhythm", "Witness", "Pop", testDurations[0], 3, 3},
		{ "Soundgarden", "Superunknown", "Black Hole Sun", "Rock", testDurations[0], 18, 5},
		{ "Third Eye Blind", "Third Eye Blind", "Semi-Charmed Life", "Rock", testDurations[0], 26, 5}
	};
	
	// initialize linked list with all three songs
	for (int i = 0; i < 3; i++) {
		insertFront(&pHead, testCases[i]);
	}

	// play songs in the given test order
	// success must be determined by studying the output
	playShuffled(pHead, 3, playOrder, 0);
}