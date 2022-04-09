/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA8                                                 *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads product buying and selling data from file, place data in *
 *			binary search trees. Then run data analysis on the input.          *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (data.csv): Units,Type,Transaction           *
 ******************************************************************************/

#include "Node.h"

 /*************************************************************
  * Function: Node ()                                         *
  * Description: constructor for Node class                   *
  * Input parameters: string data                             *
  * Returns:                                                  *
  * Preconditions:                                            *
  * Postconditions: mpLeft and mpRight are NULL               *
  *************************************************************/
Node::Node(string data) {
	mData = data;
	mpLeft = NULL;
	mpRight = NULL;
}

/*************************************************************
 * Function: Node ()                                         *
 * Description: destructor for Node class, deletes inOrder   *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Node::~Node() {
	delete mpLeft;
	delete mpRight;
}

/*************************************************************
 * Function: setData ()                                      *
 * Description: setter for mData                             *
 * Input parameters: string data                             *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Node::setData(string data) {
	mData = data;
}

/*************************************************************
 * Function: getData ()                                      *
 * Description: getter for mData                             *
 * Input parameters:                                         *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string Node::getData() const {
	return mData;
}

/*************************************************************
 * Function: setLeft ()                                      *
 * Description: setter for mpLeft                            *
 * Input parameters: Node* pLeft                             *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Node::setLeft(Node* pLeft) {
	mpLeft = pLeft;
}

/*************************************************************
 * Function: getLeft ()                                      *
 * Description: getter for mpLeft                            *
 * Input parameters:                                         *
 * Returns: Node*&                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Node*& Node::getLeft() {
	return mpLeft;
}

/*************************************************************
 * Function: setRight ()                                     *
 * Description: setter for mpRight                           *
 * Input parameters: Node* pRight                            *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Node::setRight(Node* pRight) {
	mpRight = pRight;
}

/*************************************************************
 * Function: setRight ()                                     *
 * Description: setter for mpRight                           *
 * Input parameters:                                         *
 * Returns: Node*&                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Node*& Node::getRight() {
	return mpRight;
}