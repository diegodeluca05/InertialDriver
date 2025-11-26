ATTIVITÀ SVOLTE DA CIASCUN MEMBRO:

	STEFAN:
	main, funzione get reading e operator <<

	DIEGO:
	generalizzazione classe myVector, scheletro finale, lettura, misura, file .h

	EZIO:
	scheletro inziale, funzione push, funzione pop e funzione clear
DIFFICOLTÀ RISCONTRATE:

	Durante lo sviluppo del nostro progetto di programmazione abbiamo incontrato diverse difficoltà, in particolare nella gestione del buffer e nell’utilizzo della classe myVector assegnata. La composizione del buffer non è stata immediata: capire come organizzare correttamente gli elementi e garantirne l’inserimento corretto ha richiesto diverse consultazioni. Anche la classe myVector ha rappresentato una sfida, non capendo come riuscire 	ad adoperarla per costruire il buffer.
	Abbiamo quindi dovuto dedicare del tempo a comprenderne a fondo il funzionamento, ma nonostante le difficoltà queste esperienze ci hanno permesso di 	migliorare la comprensione delle strutture dati e della programmazione in C++.
```markdown
COMPITI SVOLTI DA CIASCUN COMPONENTE NEL DETTAGLIO :

	EZIO: Ho fatto lo scheletro inziale Mercoledì sera, impostando una prima idea dei metodi e delle verie classi, il giorno successivo ci siamo confrontati su quanto da me fatto per trovare una soluzione che fosse il più efficiente possibile.
In seguito ho implementato 2 variabili: count e pnttr che aiutavano nell'implemetazione dei metodi push e pop, ho fatto il metodo push tentedo conto che fosse un buffer circolare; per la funzione pop ho dovuto prima trovare l'indice dell'elemento più vecchio (old), e in seguito sovrascrivere la misura con una vuota, non prima di averla salvata in una opportuna variabile per darla all'utente.
Infine per la funzione clear ho utilizzato un ciclo for che sovrascrive tutti gli elementi all'interno del buffet con misure vuote.

	DIEGO: Come prima cosa mi sono occupato della generalizzazione della classe myVector sfruttando i template, così da poterla sfruttare nella gestione della 		memoria del buffer.
Dopo aver creato opportunamente la classe lettura , gestendone le eventuali eccezioni con la classe Invalid{}, tramite un vettore di 6 double, ovvero i 			dati raccolti dal sensore, ho proceduto con la creazione dei metodi get(), che ritornavano le singole componenti, utili successivamente nella classe Misura. 		Abbiamo proceduto con una funzione print per la classe lettura per testare la correttezza della classe. La classe misura è stat come array stile c di 17 			letture, la quale preveddeva il classico metodo print, il metodo getArray, e l' overloading doppio dell' operatore [], infine abbiamo creato lo scheletro di 		Interial driver, dandogli dimensione due e creato come un contenute di Misure. 
STEFAN:(spiega friend perche con tonin non l abbiamo fatto)
```
