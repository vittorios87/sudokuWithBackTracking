#include "pch.h"
#include "Table.h"

int demoTable[9][9] = { 
	{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
	{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

int demoTable2[9][9] = { 
	{ 0, 0, 0, 0, 7, 4, 0, 0, 0 },
	{ 0, 0, 4, 0, 0, 0, 1, 0, 0 },
	{ 6, 7, 8, 0, 1, 0, 4, 5, 3 },
	{ 2, 0, 0, 1, 6, 0, 0, 0, 0 },
	{ 5, 0, 1, 0, 8, 0, 2, 0, 9 },
	{ 0, 0, 0, 0, 2, 9, 0, 0, 1 },
	{ 4, 8, 5, 0, 9, 0, 3, 7, 6 },
	{ 0, 0, 9, 0, 0, 0, 8, 0, 0 },
	{ 0, 0, 0, 8, 3, 0, 0, 0, 0 } };

int demoTable3[9][9] = {
	{ 0, 0, 0, 0, 0, 7, 0, 8, 0 },
	{ 0, 4, 6, 0, 0, 5, 0, 0, 3 },
	{ 9, 0, 0, 0, 0, 0, 7, 0, 0 },
	{ 0, 0, 5, 0, 8, 0, 2, 0, 0 },
	{ 8, 3, 0, 5, 0, 1, 0, 9, 6 },
	{ 0, 0, 0, 0, 4, 0, 0, 0, 0 },
	{ 0, 0, 9, 0, 0, 0, 0, 0, 5 },
	{ 5, 0, 0, 7, 0, 0, 1, 4, 0 },
	{ 0, 6, 0, 2, 0, 0, 0, 0, 0 } };

int demoTable4[9][9] = {
	{ 0, 4, 0, 0, 0, 2, 5, 0, 0 },
	{ 0, 6, 5, 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 0, 0, 7, 0, 0, 0, 0 },
	{ 6, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 9, 0, 0, 0, 0, 4, 5, 0 },
	{ 0, 0, 4, 0, 9, 0, 0, 0, 2 },
	{ 0, 2, 0, 0, 6, 0, 0, 0, 8 },
	{ 0, 0, 0, 3, 0, 0, 9, 0, 0 },
	{ 0, 0, 0, 7, 0, 8, 0, 6, 0 } };


Table::Table()
{
}


Table::~Table()
{
}

//std::wstring& filePath
void Table::LoadTable() 
{
	/*
			quando faccio il loading di una tabella, imposto 
			le celle vuote con 0 e con il primo booleano settato su true e tutti gli altri a false
			le celle piene con la cifra e il primo booleano settato a false come tutti gli altri

	*/

	/*

	{ {3, 0, 6, 5, 0, 8, 4, 0, 0},
	{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
	
	*/
	int valueToLoad;
	std::array<bool, 10> possibilitiesFilledCell = { false, false, false,false, false, false, false, false, false, false };
	/*il primo booleano è true quando è possibile riempire la cella almeno con una sola cifra: inizialmente, tutte le celle vuote devono poter essere riempite con una cifra*/
	std::array<bool, 10> possibilitiesEmptyCell = { true, false, false,false, false, false, false, false, false, false };

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++) {

			valueToLoad = demoTable4[r][c];
			
			if (valueToLoad == 0) 
			{
				(*myTable)[r * 9 + c] = std::make_pair(valueToLoad, possibilitiesEmptyCell);
				emptyCellsCounter++;
			}
			else 
			{
				(*myTable)[r * 9 + c] = std::make_pair(valueToLoad, possibilitiesFilledCell);
			}
		}
	}
}
std::wstring& Table::GetIntermediateStepScreen() 
{
	toPrintTableState.clear();

	for (int r = 0; r <9; r++)
	{
		if (r % 3 == 0) {
			toPrintTableState.append(L"-------+-------+-------\n");
		}

		for (int c = 0; c < 9; c++) {
			if (c % 3 == 0) {
				toPrintTableState.append(L"|");
			}
			
			toPrintTableState.append(std::to_wstring((myTable->at(r * 9 + c)).first) + L" ");
			
		}
		toPrintTableState.append(L"|\n");
	}
	toPrintTableState.append(L"-------+-------+-------\n\n");

	toPrintTableState.append(L"empty cells: " + std::to_wstring(emptyCellsCounter) + L"  backtracking mode: " + std::to_wstring(enteredInBackTrack) + L"\n");
	if (enteredInBackTrack) {
		toPrintTableState.append(L"nodes number: " + std::to_wstring(numberOfInitializedNodes) + L"   cells with one possibility filled: " + std::to_wstring(currentNode->GetNumberOfRegisteredCells()) + L"\n");
		toPrintTableState.append(L"current node cell: row  " + std::to_wstring((int)((currentNode->GetNodeCellIndex()) / 9)) + L"  col  " + std::to_wstring((int)((currentNode->GetNodeCellIndex()) % 9)) + L" \n\n");
		toPrintTableState.append(currentNode->PrintPossibilities());
		toPrintTableState.append(currentNode->PrintFilledCellsCoords());
	}
	return toPrintTableState;
}

bool Table::AllEmptyCellsCanBeFilled() 
{
	/*
	per ciascuna cella:
	 controllo se il suo intero è 0  (ovvero se è vuota)
	 se il suo intero è 0 devo controllare che il booleano sia true
	se trovo una sola cella vuota con il booleano false esco immediatamente con return false
	*/
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++) {
			if ((myTable->at(r * 9 + c)).first == 0) {
				if (!((myTable->at(r * 9 + c)).second[0])) 
				{
					return false;
				}
			}
		}
	}
	return true;


}
void Table::UpgradeCellPossibilities() 
{
	float squareRowCoord;
	float squareColumnCoord;
	int missedPossibilitiesCount;

	cellWithNoPossibilitiesFound = false;


	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++) 
		{
			if ((myTable->at(r * 9 + c)).first == 0) {
				missedPossibilitiesCount = 0;
				for (int n = 1; n < 10; n++)
				{
					modf(r / 3, &squareRowCoord);
					modf(c / 3, &squareColumnCoord);
					if (NumberIsInRow(n,r) || NumberIsInColumn(n,c)|| NumberIsInSquare(n, (int)squareRowCoord, (int)squareColumnCoord))
					{
						(myTable->at(r * 9 + c)).second[n] = false;
						missedPossibilitiesCount++;

					}
					else
					{
					(myTable->at(r * 9 + c)).second[n] = true;
					}
				}
				if (missedPossibilitiesCount == 9)
				{
					(myTable->at(r * 9 + c)).second[0] = false;
					cellWithNoPossibilitiesFound = true;
				}
			}
		}
	}
}

void Table::SolverStep() 
{
	//cambia lo stato della Tabella
	UpgradeCellPossibilities();
	//dopo ogni aggiornamento deve fare SOLO una cosa!!
	if (!cellWithNoPossibilitiesFound)
	{
		//modifica lo stato solo se mancano celle con 0 possibilità
		DivideByNumberOfPossibilities();
		if (cellsW1Possibility.size() != 0) {
			FillOneCellWithOnePossibility();
		}
		else {
			//esegue solo uno dei due rami per ogni ciclo
			if (!enteredInBackTrack) {
				enteredInBackTrack = true;
				SelectCellWithMoreThanOnePossibility();
				ProcessCurrentNode();
			}
			else {
				if (currentNode->GetCameBack()) {
					ProcessCurrentNode();
					currentNode->UnsetCameBack();
				}
				else {
					SelectCellWithMoreThanOnePossibility();
					ProcessCurrentNode();
				}
			}
			
		}
	}
	else {
		// decidi cosa fare allo step successivo
		if (enteredInBackTrack) {
			//torna indietro: 
			//se la cella che caratterizza il nodo ha altre possibilità, cancella tutte le celle riempite perchè con una sola possibilità; 
			//se le possibilità sono tutte esaurite, torna indietro al nodo precedente se non è il primo della sequenza
			// se è il primo hai perso
			if (! currentNode->GetAlreadyExplored() ) {
				//prepara uno stato idoneo a proseguire:
				//al prossimo step deve essere processato ancora il current node!! 
				//va bene cancellare le celle riempite con una sola possibilità, ma allo step successivo
				//devo fare una prova sulla cella dello stesso nodo
				//posso farlo qui inserendo ProcessCurrentNode() dentro questo blocco? forse sì, ma devo cancellare con un metodo
				//le celle che avevano una sola possibilità; posso anche evitare di ripetere UpgradeCellPossibilities()
				//ProcessCurrentNode() riempie la cella del nodo e le sue possibilità sono sempre quelle, registrate nel nodo
				RevertCurrentNode();
				currentNode->SetCameBack();
			}
			else {
				if (currentNode->GetPreviousNode() == nullptr) 
				{
					// questo caso si verifica quando sono al nodo iniziale e il precedente è inesistente, e contemporaneamente
					//il nodo iniziale è stato già esplorato
					canBeSolved = false;
				}
				else 
				{
					//anche qui bisogna preparare uno stato idoneo a proseguire
					//è necessario usare RevertCurrentNode(), e poi tornare al nodo con quello precedente
					//lasciando le cose così, al prossimo step tornerei allo stesso nodo attuale
					//occorre usare di nuovo RevertCurrentNode() e ProcessCurrentNode() 
					// ProcessCurrentNode() va fatto solo quando il nodo precedente è ancora incompleto

					// è necessario ripetere queste due operazioni:
					
					//   currentNode = currentNode->GetPreviousNode();
					//   RevertCurrentNode();
					// in un ciclo while con la condizione 
					// currentNode->GetAlreadyExplored()==true
					// deve tornare indietro fin quando non trova il primo nodo che restituisce false
					// CASO PARTICOLARE: se arriva al nodo iniziale e trova true? potrebbe capitare se noi stiamo esplorando
					//una sequenza di nodi che parte avendo riempito il nodo iniziale con l'ultima possibilità
					//ALLORA inserisco la condizione currentNode->GetPreviousNode() != nullptr in AND logico per
					//fare in modo che esca dal ciclo while al primo nodo

					// alreadyExplored deve essere settato a true appena si sceglie l'ultima possibilità (per ciascun nodo)
					RevertCurrentNode();
					while (currentNode->GetAlreadyExplored() == true && currentNode->GetPreviousNode() != nullptr) {
						currentNode = currentNode->GetPreviousNode();
						RevertCurrentNode();
					}
					currentNode->SetCameBack();
				}
			}

		}
		else {
			//hai perso
			canBeSolved = false;

		}
	}
}

/*
void Table::SolverStep() {

	UpgradeCellPossibilities();
	if (!cellWithNoPossibilitiesFound)
	{

		
		DivideByNumberOfPossibilities();

		if (!enteredInBackTrack) {
			if (cellsW1Possibility.size() != 0) {
				FillCellsWithOnePossibility();
			}
			else {
				enteredInBackTrack = true;
				SelectCellWithMoreThanOnePossibility();
				ProcessCurrentNode();
			}
			
		}
		else {
		
			if (currentNode->GetIsComingBack()) {
				if (currentNode->GetAlreadyExplored()) {
					//torniamo indietro di un nodo
					std::array<bool, 10> possibilitiesEmptyCell = { true, false, false,false, false, false, false, false, false, false };
					while (currentNode->GetNumberOfRegisteredCells() > 0) {
						int toCleanCellIndex = currentNode->UnregisterFilledCell();
						(myTable->at(toCleanCellIndex)) = std::make_pair(0, possibilitiesEmptyCell);
					}
					(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(0, possibilitiesEmptyCell);

					currentNode = currentNode->GetPreviousNode();
				}
				else {
					ProcessCurrentNode();
				}
			}
			else {
				if (cellsW1Possibility.size() != 0) {
					FillCellsWithOnePossibility();
				}
				else
				{
					SelectCellWithMoreThanOnePossibility();
					ProcessCurrentNode();

				}
				
			}
			
		}
		
	
	}
	else 
	{
		if (!enteredInBackTrack)
		{
			canBeSolved = false;
		}
		else
		{
			if (currentNode->GetAlreadyExplored())
			{
				//CONDIZIONI ATTUALI: 
				// 1) c'è almeno una casella con zero possibilità di riempimento
				// 2) il back tracking è iniziato
				// 3) il nodo è stato tutto esplorato
				//DENTRO QUESTO BLOCCO DEVO METTERE LA PROCEDURA PER TORNARE AL NODO PRECEDENTE: QUESTO LO POSSO FARE SOLO
				//SE IL NODO PRECEDENTE ESISTE
				if (currentNode->GetPreviousNode() == nullptr)
				{
					canBeSolved = false;
				}
				else
				{
					std::array<bool, 10> possibilitiesEmptyCell = { true, false, false,false, false, false, false, false, false, false };
					while (currentNode->GetNumberOfRegisteredCells() > 0) 
					{
						int toCleanCellIndex = currentNode->UnregisterFilledCell();
						(myTable->at(toCleanCellIndex)) = std::make_pair(0, possibilitiesEmptyCell);
					}
					
					(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(0, possibilitiesEmptyCell);

					currentNode = currentNode->GetPreviousNode();
					currentNode->SetIsComingBack();
				}
			}
			else {
				std::array<bool, 10> possibilitiesEmptyCell = { true, false, false,false, false, false, false, false, false, false };
				while (currentNode->GetNumberOfRegisteredCells() > 0) {
					int toCleanCellIndex = currentNode->UnregisterFilledCell();
					(myTable->at(toCleanCellIndex)) = std::make_pair(0, possibilitiesEmptyCell);

				}
				(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(0, possibilitiesEmptyCell);
				currentNode->SetIsComingBack();
				}
		}
	}
}
*/

bool Table::NumberIsInRow(int number, int row)
{
	for (int c = 0; c < 9; c++)
	{
		if ((myTable->at(row * 9 + c)).first == number)
		{
			return true;
		}
	}
	return false;
}
bool Table::NumberIsInColumn(int number, int column)
{
	for (int r = 0; r < 9; r++)
	{
		if ((myTable->at(r * 9 + column)).first == number)
		{
			return true;
		}
	}
	return false;
}
bool Table::NumberIsInSquare(int number, int squareRowCoord, int squareColumnCoord)
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if ((myTable->at((squareRowCoord * 3 + r) * 9 + (squareColumnCoord * 3 + c))).first == number)
			{
				return true;
			}
		}
	}
	return false;
}

void Table::CountEmptyCells()
{
	emptyCellsCounter = 0;
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++) {
			if ((myTable->at(r * 9 + c)).first == 0) {
				emptyCellsCounter++;
			}
		}
	}
}

void Table::DivideByNumberOfPossibilities()

{
	int possibilitiesCounter;
	cellsW1Possibility.clear();
	cellsW2Possibilities.clear();
	cellsW3Possibilities.clear();
	cellsW4Possibilities.clear();
	cellsW5Possibilities.clear();
	cellsW6Possibilities.clear();
	cellsW7Possibilities.clear();
	cellsW8Possibilities.clear();
	cellsW9Possibilities.clear();
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++) {
			possibilitiesCounter = 0;
			if ((myTable->at(r * 9 + c)).first == 0) {
				for (int n = 1; n < 10; n++)
				{
					if ((myTable->at(r * 9 + c)).second[n] == true) 
					{
						possibilitiesCounter++;
					}

				}
				switch (possibilitiesCounter) 
				{
				
				case 1:
					cellsW1Possibility.push_back(r * 9 + c);
					break;
				case 2:
					cellsW2Possibilities.push_back(r * 9 + c);
					break;
				case 3:
					cellsW3Possibilities.push_back(r * 9 + c);
					break;
				case 4:
					cellsW4Possibilities.push_back(r * 9 + c);
					break;
				case 5:
					cellsW5Possibilities.push_back(r * 9 + c);
					break;
				case 6:
					cellsW6Possibilities.push_back(r * 9 + c);
					break;
				case 7:
					cellsW7Possibilities.push_back(r * 9 + c);
					break;
				case 8:
					cellsW8Possibilities.push_back(r * 9 + c);
					break;
				case 9:
					cellsW9Possibilities.push_back(r * 9 + c);
					break;
				default:
					break;
				}
			}
		}
	}
}

void Table::FillOneCellWithOnePossibility()
{
	int tableIndex = cellsW1Possibility.at(cellsW1Possibility.size() - 1);
	cellsW1Possibility.pop_back();
	int n;
	for (n = 1; n < 10; n++)
	{
		if ((myTable->at(tableIndex)).second[n] == true)
		{
			(myTable->at(tableIndex)).first = n;
			break;
		}
	}
	(myTable->at(tableIndex)).second[n] = false;
	(myTable->at(tableIndex)).second[0] = false;

	if (enteredInBackTrack)
	{
		currentNode->RegisterFilledCell(tableIndex);
	}
		

}
void Table::SelectCellWithMoreThanOnePossibility() 
{
	int cellIndex;
	if (cellsW2Possibilities.size() != 0) 
	{
		cellIndex= cellsW2Possibilities.at(cellsW2Possibilities.size()-1);
		cellsW2Possibilities.pop_back();
	}
	else if (cellsW3Possibilities.size() != 0)
	{
		cellIndex = cellsW3Possibilities.at(cellsW3Possibilities.size()-1);
		cellsW3Possibilities.pop_back();
	}
	else if (cellsW4Possibilities.size() != 0)
	{
		cellIndex = cellsW4Possibilities.at(cellsW4Possibilities.size() - 1);
		cellsW4Possibilities.pop_back();
	}
	else if (cellsW5Possibilities.size() != 0)
	{
		cellIndex = cellsW5Possibilities.at(cellsW5Possibilities.size() - 1);
		cellsW5Possibilities.pop_back();
	}
	else if (cellsW6Possibilities.size() != 0)
	{
		cellIndex = cellsW6Possibilities.at(cellsW6Possibilities.size() - 1);
		cellsW6Possibilities.pop_back();
	}
	else if (cellsW7Possibilities.size() != 0)
	{
		cellIndex = cellsW7Possibilities.at(cellsW7Possibilities.size() - 1);
		cellsW7Possibilities.pop_back();
	}
	else if (cellsW8Possibilities.size() != 0)
	{
		cellIndex = cellsW8Possibilities.at(cellsW8Possibilities.size() - 1);
		cellsW8Possibilities.pop_back();
	}
	else if (cellsW9Possibilities.size() != 0)
	{
		cellIndex = cellsW9Possibilities.at(cellsW9Possibilities.size() - 1);
		cellsW9Possibilities.pop_back();
	}
	std::vector<int>* possibilities = new std::vector<int>();
	for (int n = 1; n < 10; n++)
	{
		if ((myTable->at(cellIndex)).second[n] == true) {
			possibilities->push_back(n);
		}
	}
	numberOfInitializedNodes++;
	currentNode = new Node(cellIndex, possibilities,currentNode);
}
void Table::SolveTable() 
{
	if (emptyCellsCounter > 0 && canBeSolved)
	{		
		SolverStep();
	}
	CountEmptyCells();

}

void Table::ProcessCurrentNode() 
{
	/*questo metodo riempie la cella con uno dei numeri nel vettore possibilities e lo etichetta come già scelto dal - fa tutto RequestPossibilityForThisNode*/
	/*il vector delle foglie deve essere popolato dopo aver rivalutato le possibilities per ogni cella rimasta vuota e aver riempito quelle con una sola possibilità*/
	
	
	int numberForThisNode = currentNode->RequestPossibilityForThisNode();
	std::array<bool, 10> possibilitiesFilledCell = { false, false, false,false, false, false, false, false, false, false };
	(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(numberForThisNode, possibilitiesFilledCell);
    /*
	if (numberForThisNode != 0) 
	{
		std::array<bool, 10> possibilitiesFilledCell = { false, false, false,false, false, false, false, false, false, false };
		(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(numberForThisNode, possibilitiesFilledCell);
	}
	else {
		currentNode->SetAlreadyExplored();
	}*/
}
void Table::RevertCurrentNode() 
{
	std::array<bool, 10> possibilitiesEmptyCell = { true, false, false,false, false, false, false, false, false, false };
	while (currentNode->GetNumberOfRegisteredCells() > 0)
	{
		int toCleanCellIndex = currentNode->UnregisterFilledCell();
		(myTable->at(toCleanCellIndex)) = std::make_pair(0, possibilitiesEmptyCell);
	}
	(myTable->at(currentNode->GetNodeCellIndex())) = std::make_pair(0, possibilitiesEmptyCell);
}


/*
NON USATI
void Table::PopulateCurrentNodeWithLeafNodes() {

}
void Table::ChangeCurrentNode() {

}
*/



