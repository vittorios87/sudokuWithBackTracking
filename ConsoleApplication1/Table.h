#pragma once
class Table
{
public:
	Table();
	~Table();
	//std::wstring& filePath
	void LoadTable();
	std::wstring& GetIntermediateStepScreen();

	void SolveTable();
private:
	size_t sudokuDim = 81;
	size_t numbersDim = 10;
	//array di 81 elementi, ciascuno è una pair (coppia)
	//questa pair è formata da un intero e da un set di 10 booleani
	// cella vuota: primo elemento = 0 e primo elemento dell'array di bool = true
	std::array< std::pair < int, std::array<bool, 10> >, 81 >* myTable = new std::array< std::pair < int, std::array<bool, 10> >, 81>();

	std::vector <  std::pair < int, std::array<bool, 10> >  >* previousCellStates = new std::vector <  std::pair < int, std::array<bool, 10> >  >();

	std::wstring toPrintTableState;

	bool AllEmptyCellsCanBeFilled();
	void UpgradeCellPossibilities();

	void SolverStep();

	int  emptyCellsCounter = 0;
	bool canBeSolved = true;

	bool cellWithNoPossibilitiesFound = false;

	bool enteredInBackTrack = false;

	std::vector<int> cellsW1Possibility= std::vector<int>();
	std::vector<int> cellsW2Possibilities = std::vector<int>();
	std::vector<int> cellsW3Possibilities = std::vector<int>();
	std::vector<int> cellsW4Possibilities = std::vector<int>();
	std::vector<int> cellsW5Possibilities = std::vector<int>();
	std::vector<int> cellsW6Possibilities = std::vector<int>();
	std::vector<int> cellsW7Possibilities = std::vector<int>();
	std::vector<int> cellsW8Possibilities = std::vector<int>();
	std::vector<int> cellsW9Possibilities = std::vector<int>();

	bool NumberIsInRow(int number, int row);
	bool NumberIsInColumn(int number, int column);
	bool NumberIsInSquare(int number, int squareRowCoord, int squareColumnCoord);

	void CountEmptyCells();
	void DivideByNumberOfPossibilities();
	void FillOneCellWithOnePossibility();


	Node* currentNode=nullptr;
	int numberOfInitializedNodes = 0;
	//std::vector<Node*>* previousNodes= new std::vector<Node *>();
	void SelectCellWithMoreThanOnePossibility();
	void ProcessCurrentNode();
	void RevertCurrentNode();

	//void PopulateCurrentNodeWithLeafNodes();
	//void ChangeCurrentNode();
};

