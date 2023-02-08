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

#ifndef PA3
#define PA3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <time.h>

typedef struct duration {
	unsigned int minutes;
	unsigned int seconds;
} Duration;

typedef struct record {
	char artist[32];
	char album[32];
	char title[32];
	char genre[16];
	Duration length;
	unsigned int playCount;
	unsigned int rating;
} Record;

typedef struct node {
	Record data;
	struct node* next;
	struct node* previous;
} Node;

int get_option(void);
int get_int_in_range(int min, int max, char* message);
void printMenu(void);
Record parseRecordLine(char* string);
Node* loadPlaylist(char* filename);
int storeList(Node* pHead, char* filename);
Node* makeNode(Record data);
int countRecords(Node* pHead);
int insertFront(Node** pHead, Record data);
void printRecord(Record data);
void printList(Node* pHead);
Node* searchArtist(Node* pHead, char* query, int select);
void printFound(Node* foundSongs[], int count);
Node* searchTitle(Node* pHead);
Duration parseMinSec(char* str);
void caseDisplay(Node* pHead);
void caseInsert(Node** pHead);
void caseDelete(Node** pHead);
void caseEdit(Node* pHead);
void swapNodes(Node* nodeOne, Node* nodeTwo);
void selectionSort(Node* pHead, int sort);
void caseSort(Node* pHead);
void caseRate(Node* pHead);
void printPlay(Node* pCurrent, int cls);
void playTracks(Node* startTrack);
void playShuffled(Node* pHead, int numTracks, int* playOrder, int cls);
void shuffleTracks(Node* pHead);

#endif