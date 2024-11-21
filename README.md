# progetto-uni-intermedio

#La classe LidarDriver deve implementare:

● La funzione new_scan che accetta uno std::vector<double> contenente una scansione e lo memorizza nel buffer (sovrascrivendo la scansione meno recente se il buffer è pieno). 
Questa funzione esegue anche il controllo di dimensione: se le letture sono in numero minore del previsto, completa i dati mancanti a 0; 
se sono in numero maggiore, li taglia;

● La funzione get_scan che fornisce in output uno std::vector<double> contenente la scansione più vecchia del sensore e la rimuove dal buffer;

● La funzione clear_buffer che elimina (senza restituirle) tutte le scansioni salvate;

● La funzione get_distance che accetta un angolo espresso in gradi (double) e ritorna la lettura corrispondente a tale angolo nella scansione più recente acquisita dal sensore; 
tale scansione non è eliminata dal buffer, e se l’angolo richiesto non è disponibile ritorna la lettura relativa al valore di angolo più vicino;

● L’overloading dell’operator<< che stampa a schermo l’ultima scansione salvata (ma non la rimuove dal buffer).

#Note per l’implementazione:
● La risoluzione del LidarDriver è fissa per tutta la durata di vita del relativo oggetto (il che deve avere un riscontro nel costruttore).

● Per la gestione del buffer interno alla classe è possibile utilizzare un container come std::vector oppure usare direttamente l’allocazione dinamica della memoria (new, new[], delete, delete[]);

● Le funzioni dell’elenco precedente devono essere opportunamente completate con i tipi di ritorno; 
gli argomenti indicati devono essere opportunamente completati con eventuali reference e const, se necessario o opportuno. 
È importante implementare le funzioni esattamente con il nome descritto (case sensitive) e con gli argomenti elencati;

● La classe può essere completata con le variabili membro utili e con funzioni membro a
scelta;

● Deve essere implementata ogni altra funzione membro ritenuta necessaria.


La classe LidarDriver (e altre eventuali classi) devono essere correttamente separate nei file .h e .cpp. Un ulteriore file .cpp deve contenere il main, usato per i test. 
Il progetto deve essere opportunamente strutturato in cartelle e sottocartelle analogamente a quanto illustrato nello schema seguente (relativo al progetto Rational):
'''
Rational:
├── include
│ └── rational.h
├── README.txt
└── src
├── main.cpp
└── rational.cpp
'''
È inoltre obbligatorio allegare un file README in formato testo con la descrizione delle attività di ciascun membro del gruppo.
