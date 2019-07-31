// ConsoleApplication1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"

using namespace std;

Display* myDisplay = new Display();
wstring displayString = L"ciao, provo a risolvere il sudoku";

InputManager* myInputManager = InputManager::GetInstance();
Key pressedKey;

Table myTable;


void Input(){
	myInputManager->Input();
}

void Update() {
	pressedKey = Key::None;
	if (myInputManager->ButtonPressed()) 
	{
		pressedKey = myInputManager->GetButtonPressed();
	}
	if (pressedKey != Key::None)
	{
		myTable.SolveTable();
		displayString.clear();

		// nella riga successiva non serve usare assign al posto di append
		// il problema del corretto refresh della schermata si risolve creando un buffer wstring nella classe display: in quel caso va usato assign
		displayString.append(myTable.GetIntermediateStepScreen());
		myDisplay->cls();
	}
}


void Render() {
	myDisplay->printBuffer(displayString);
}



int main()


{


	
	myTable.LoadTable();

	displayString.clear();
	displayString.append(myTable.GetIntermediateStepScreen());
	Render();
	while (true)
	{
		Input();
		Update();
		Render();
	}


}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
