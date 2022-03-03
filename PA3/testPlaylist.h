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

#ifndef testPA3
#define testPA3

#include "playlist.h"

void testInsertFront(void);
void testDelete(void);
void testShuffle(void);

#endif