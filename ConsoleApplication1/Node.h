#pragma once
class Node
{
public:
	Node(int init_nodeCellIndex, std::vector<int>* init_possibilities, Node* inputPreviousNode);
	~Node();

	void RegisterFilledCell(int toRegisterCellIndex);
	int UnregisterFilledCell();
	int GetNumberOfRegisteredCells();

	//void AddLeaf(Node* childLeafToAdd);
	int RequestPossibilityForThisNode();
	int GetNodeCellIndex();
	void SetAlreadyExplored();
	bool GetAlreadyExplored();
	void UnsetCameBack();
	void SetCameBack();
	bool GetCameBack();
	Node* GetPreviousNode();
	std::wstring PrintPossibilities();
	std::wstring PrintFilledCellsCoords();
private:
	//std::vector<Node*>* leafNodes; NON USATO
	
	int nodeCellIndex;
	Node* previousNode;
	std::vector < std::pair<int, bool>>* possibilities;
	std::vector<int>* cellsWith1PossibilityFilledSinceCreation;
	bool alreadyExplored = false;
	bool cameBack = false;
};

