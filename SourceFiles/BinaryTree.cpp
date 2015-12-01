#include "../HeaderFiles/BinaryTree.h"

/** =================================== */
/* DestroyTree function to destroy all nodes in the tree.
Recieves the root of the tree.
No return values. */
void BinaryTree::destroyTree(BinaryNode* nodePtr)
{
	if (nodePtr != 0)
	{
		destroyTree(nodePtr->getLeftPtr());
		destroyTree(nodePtr->getRightPtr());
		delete nodePtr;
	}
}

/** =================================== */
/* Prints the indented tree by level.
Takes in the root of the tree and the current level.
No return values. Outputs the tree to the screen in an indented list. */
void BinaryTree::_printIndentedTree(BinaryNode * nodePtr, int level)
{
	if (nodePtr != 0)//Recursion Terminator Statement
	{
		_printIndentedTree(nodePtr->getRightPtr(), level + 1);
		cout << setw(level * 7) << level << ". " << nodePtr->getItem()->getKey() << " " << nodePtr->getItem()->getName() << endl;
		_printIndentedTree(nodePtr->getLeftPtr(), level + 1);
	}
}

/** =================================== */
/* Public member function to place all items in the tree into a Stack inOrder.
No input paramerters.
No return value. */
void BinaryTree::inOrderPrint()
{
	_inOrderPrint(rootPtr);
}

/** =================================== */
/* Private member function called by inOrderStack to make an inOrder Stack.
Recieves the root of the tree.
No return value. Output's an inOrder of the BT. */
void BinaryTree::_inOrderPrint(BinaryNode * nodePtr)
{
	if (sortedKey)
	{
		if (nodePtr != 0)
		{
			_inOrderPrint(nodePtr->getLeftPtr());
			cout << "\nKey: " << nodePtr->getItem()->getKey();
			_inOrderPrint(nodePtr->getRightPtr());
		}
	}
	else
	{
		if (nodePtr != 0)
		{
			_inOrderPrint(nodePtr->getLeftPtr());
			cout << "\nName: " << nodePtr->getItem()->getName();
			_inOrderPrint(nodePtr->getRightPtr());
		}
	}
}

/** =================================== */
/* <function purpose>
<explanation of all input parameters>
<explanation of all output actions and return value > */
Food * BinaryTree::inOrderArr(Food arr[])
{
	return _inOrderArr(rootPtr, arr);
}



/** =================================== */
/* <function purpose>
<explanation of all input parameters>
<explanation of all output actions and return value > */
Food * BinaryTree::_inOrderArr(BinaryNode * nodePtr, Food arr[])
{
	int i = 0;
	if (nodePtr != 0)
	{
		_inOrderArr(nodePtr->getLeftPtr(), arr);
		arr[i] = *nodePtr->getItem();
		i++;
		_inOrderArr(nodePtr->getRightPtr(), arr);
	}
	return arr;
}

LinkedList BinaryTree::inOrderLL()
{
	LinkedList list;
	return _inOrderLL(rootPtr, list);
}

LinkedList BinaryTree::_inOrderLL(BinaryNode * nodePtr, LinkedList list)
{
	if (nodePtr != 0)
	{
		_inOrderLL(nodePtr->getLeftPtr(), list);
		list.addItem(nodePtr->getItem());
		_inOrderLL(nodePtr->getRightPtr(), list);
	}
	return LinkedList();
}
