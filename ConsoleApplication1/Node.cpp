#include "pch.h"
#include "Node.h"


Node::Node(int init_nodeCellIndex, std::vector<int>* init_possibilities, Node* inputPreviousNode): nodeCellIndex(init_nodeCellIndex), previousNode(inputPreviousNode)
{
	possibilities = new std::vector<std::pair<int, bool>>();
	for (int i = 0; i < init_possibilities->size(); i++) 
	{
		possibilities->push_back(std::make_pair(init_possibilities->at(i), false));
	}
	cellsWith1PossibilityFilledSinceCreation = new std::vector<int>();
}


Node::~Node()
{
}

void Node::RegisterFilledCell(int toRegisterCellIndex) 
{
	cellsWith1PossibilityFilledSinceCreation->push_back(toRegisterCellIndex);
}

int Node::UnregisterFilledCell() {
	int lastCellIndex = cellsWith1PossibilityFilledSinceCreation->at(cellsWith1PossibilityFilledSinceCreation->size()-1);
	cellsWith1PossibilityFilledSinceCreation->pop_back();
	return lastCellIndex;
}
int Node::GetNumberOfRegisteredCells() {
	return cellsWith1PossibilityFilledSinceCreation->size();
}
/* NON USATO
void Node::AddLeaf(Node* childLeafToAdd)
{
	leafNodes->push_back(childLeafToAdd);
}
*/
int Node::RequestPossibilityForThisNode() 
{
	for (std::vector < std::pair<int, bool>>::iterator it = possibilities->begin(); it != possibilities->end(); it++) 
	{
		if ((*it).second == false) 
		{
			(*it).second = true;
			if (it == (possibilities->end() - 1)) {
				SetAlreadyExplored();
			}
			return (*it).first;
		}
	}
	return 0;
}

int Node::GetNodeCellIndex()
{
	return nodeCellIndex;
}

void Node::SetAlreadyExplored() {
	alreadyExplored = true;
}
bool Node::GetAlreadyExplored() {
	return alreadyExplored;
}
void Node::UnsetCameBack() {
	cameBack = false;
}


void Node::SetCameBack() {
	cameBack = true;
}
bool Node::GetCameBack() {
	return cameBack;
}
Node* Node::GetPreviousNode() {
	return previousNode;
}

std::wstring Node::PrintPossibilities() {
	std::wstring possibilitiesString= L"\n current node possibilities \n";
	for (int i = 0; i < possibilities->size(); i++) {
		possibilitiesString.append(L"number: " + std::to_wstring((possibilities->at(i)).first) + L"  already used: " + std::to_wstring((possibilities->at(i)).second) + L" \n");
	}
	possibilitiesString.append(L"\n");
	return possibilitiesString;
}
std::wstring Node::PrintFilledCellsCoords() {
	std::wstring filledCellsCoordsString = L"\n filled between nodes cells \n";
	for (int i = 0; i < cellsWith1PossibilityFilledSinceCreation->size(); i++) {
		int cellIndex = cellsWith1PossibilityFilledSinceCreation->at(i);
		filledCellsCoordsString.append(L"cell: row  " + std::to_wstring((int)(cellIndex / 9)) + L"  col  " + std::to_wstring((int)(cellIndex % 9))+ L"\t");
		if (i % 3 == 0) {
			filledCellsCoordsString.append(L"\n");
		}
	}
	filledCellsCoordsString.append(L"\n");
	return filledCellsCoordsString;
}


