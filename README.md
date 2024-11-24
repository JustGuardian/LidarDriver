# LidarDriverProject

## Descrizione del Progetto
**LidarDriverProject** è un'implementazione simulata di un sensore LiDAR, sviluppata in C++ per gestire e analizzare scansioni di distanza angolari. 
La classe principale, `LidarDriver`, utilizza un buffer circolare, implementato dalla classe `CircularArray`, 
per gestire le scansioni in modo efficiente, garantendo un utilizzo ottimale della memoria.

### Obiettivi principali:
- **Gestione delle scansioni**: memorizzazione, recupero e analisi delle letture dal sensore.
- **Flessibilità del buffer**: supporto per operazioni di sovrascrittura, dimensionamento dinamico e verifica di stato (vuoto/pieno).
- **Accesso specifico ai dati**: possibilità di ottenere valori interpolati basati su angoli specifici.

---

# Classi e Funzionalità

## `LidarDriver`
La classe `LidarDriver` rappresenta un **sensore LiDAR** che utilizza un buffer circolare per memorizzare le scansioni.

### Funzionalità principali:

- **Costruttori**:
  ```cpp
  LidarDriver(int x = 10);  // Costruttore di default
  LidarDriver(const LidarDriver&);  // Costruttore di copia

- **Gestione delle scansioni**:
  ```cpp
  void clear_buffer();  // Svuota il buffer
  void new_scan(const std::vector<double>& scan);  // Aggiunge una nuova scansione al buffer
  std::vector<double> get_scan();  // Recupera e rimuove la scansione più vecchia
  
- **Analisi delle scansioni**:
  ```cpp
  std::vector<double> latest_scan() const;  // Ultima scansione acquisita senza rimuoverla
  double get_distance(double angle) const;  // Distanza relativa a un angolo specifico
  
- **Stampa**:
  ```cpp
  void print_all_scans() const;  // Stampa tutto il buffer
  friend std::ostream& operator<<(std::ostream& os, const LidarDriver& driver);  // Stampa l'ultima lista dati inserita

- **Funzione adjust_scan_size**:
  ```cpp
  std::vector<double> adjust_scan_size(std::vector<double> scan) const;  // Normalizza la scansione a dimensioni tra 181 e 1810
  ```
  La funzione regola la dimensione di una scansione, aggiungendo zeri se la dimensione è inferiore a 181 o tagliando gli elementi se la scansione supera i 1810 elementi.


## `CircularArray`
La classe `CircularArray` implementa un **buffer circolare** per gestire un numero limitato di vettori di scansioni.

### Funzionalità principali:

- **Costruttori**:
  ```cpp
  CircularArray(int size = 10);  // Costruttore con dimensione
  CircularArray(const CircularArray &vecchioArray);  // Copy constructor
  CircularArray(CircularArray &&vecchioArray);  // Move constructor

- **Inserimento**:
  ```cpp
  void enqueue(const std::vector<double>& elemento);  // Aggiungi elemento al buffer
  void enqueue(std::vector<double>&& elemento);  // Aggiungi elemento al buffer (move)

- **Rimozione**:
  ```cpp
  std::vector<double> dequeue();  // Rimuove e ritorna l'elemento più vecchio

- **Accesso e verifica**:
  ```cpp
  std::vector<double> getLatestVector() const;  // Restituisce l'ultimo vettore inserito
  int getSize() const;  // Ottiene la dimensione del buffer
  double getAngle() const; // Ottiene angolo tra le misure dell'ultimo vettore inserito
  bool isEmpty() const;  // Verifica se il buffer è vuoto
  bool isFull() const;  // Verifica se il buffer è pieno
  int capacity() const;  // Ritorna la capacità del buffer

- **Operatori**:
  ```cpp
  bool operator==(const CircularArray& other) const;  // Confronta due CircularArray per uguaglianza
  bool operator!=(const CircularArray& other) const;  // Confronta due CircularArray per disuguaglianza
  std::vector<double>& operator[](int indice);  // Accesso con indice relativo
  const std::vector<double>& operator[](int indice) const;  // Accesso con indice relativo (const)

- **Stampa**:
  ```cpp
  void print(std::ostream& os) const;  // Stampa lo stato del buffer
  friend std::ostream& operator<<(std::ostream& os, const CircularArray& array);  // Operatore di stampa
  
---

## Contributi del team

### Scabbia Fabrizio
- **Implementazioni nella classe `LidarDriver`**:
  - `get_distance()`: per ottenere la distanza relativa a un angolo specifico.
  - `is_buffer_empty()`: per verificare se il buffer è vuoto.
  - `is_buffer_full()`: per verificare se il buffer è pieno.
  - `print_all_scans()`: per stampare tutte le scansioni nel buffer.
  - `operator<<()`: per sovraccaricare l'operatore di output e permettere la stampa dell'oggetto `LidarDriver`.
  

- **Implementazioni nella classe `CircularArray`**:
  - `getSize()`: per ottenere il numero di elementi inseriti.
  - `getAngle()`: per ottenere la dimensione dell'angolo tra le misure.
  - `operator==()` : per confrontare due oggetti `CircularArray`.
  - `operator!=` : per confrontare due oggetti `CircularArray`.
  - `operator[]` : per accedere ad un `vector<double>` salvato in `CircularArray`.
  - `print_all()` : per stampare tutte le scansioni nel buffer.
  - `operator<<()` : per sovraccaricare l'operatore di output e permettere la stampa dell'oggetto `CircularArray`.
  
### Stevanin Michele
- **Implementazioni nella classe `LidarDriver`**:
  - `adjust_scan_size()`: per normalizzare la dimensione delle scansioni.
  - `new_scan()`: per aggiungere una nuova scansione al buffer.
  - `get_scan()`: per recuperare e rimuovere la scansione più vecchia.
  - `latest_scan()`: per ottenere l'ultima scansione senza rimuoverla.
  - `clear_buffer()`: per svuotare il buffer.

- **Implementazioni nella classe `CircularArray`**:
  - `enqueue()`: per aggiungere un elemento al buffer.
  - `dequeue()`: per rimuovere e restituire l'elemento più vecchio.
  - `clear()`: per svuotare il buffer.
  - `getLatestVector()`: per ottenere l'ultimo vettore inserito.
  - `capacity()`: per ottenere la capacità massima del buffer.
  - `isEmpty()`: per verificare se il buffer è vuoto.
  - `isFull()`: per verificare se il buffer è pieno.
  
---

## Struttura del Progetto
  ```plaintext
    LidarDriverProject/
    ├── include/
    │   ├── CircularArray.h          # Dichiarazioni della classe CircularArray
    │   └── LidarDriver.h            # Dichiarazioni della classe LidarDriver
    ├── src/
    │   ├── main.cpp                 # File principale per i test del progetto
    │   ├── CircularArray.cpp        # Implementazione della classe CircularArray
    │   └── LidarDriver.cpp          # Implementazione della classe LidarDriver
    ├── README.md                    # Documentazione del progetto
    └── ProvaIntermedia24_25.pdf     # Consegna del progetto
  ```

---

## Istruzioni per l'uso
1. Clonare il repository:
   ```bash
   git clone https://github.com/JustGuardian/progetto-uni-intermedio
   
2. Compilare il progetto:
   ```bash
   g++ src/main.cpp src/CircularArray.cpp src/LidarDriver.cpp -o LidarDriverProject

3. Eseguire il programma:
   ```bash
   .\LidarDriverProject
