# Tic-Tac-Toe

Tic-Tac-Toe este un joc simplu scris în C++. Jucătorii plasează simbolurile X și O pe o tablă 3x3 și încearcă să formeze o linie orizontală, verticală sau diagonală.

## Regulile jocului

1. Jocul se joacă pe o tablă 3x3.
2. Un jucător folosește simbolul `X`, celălalt simbolul `O`.
3. Jucătorii plasează pe rând simbolurile lor într-o celulă liberă.
4. Câștigă primul jucător care reușește să alinieze 3 simboluri pe linie, coloană sau diagonală.
5. Dacă toate celulele sunt ocupate și niciun jucător nu a câștigat, jocul se termină cu remiză.
6. **Joc cu AI:** Dacă dorești să joci împotriva calculatorului, la introducerea numelui unuia dintre jucători scrie `AI`. În acest caz, vei juca împotriva inteligenței artificiale.

## Structura proiectului

- `Board`: reprezintă tabla de joc, o matrice 3x3.
- `Metode`: plasarea simbolului X sau O, verificarea dacă o poziție este liberă, resetarea tablei, verificarea câștigătorului sau remizei.
- `Player`: reprezintă un jucător cu simbolul lui X sau O.
- `Engine`: controlează logica jocului.
- `Renderer`: se ocupă de afișarea tablei în consolă sau grafic.
- `AI`: reprezintă calculatorul ca adversar.

## Laborator 02
1. Pentru a construi proiectul: 
## Cum compilez proiectul?
`cmd /c build.cmd`: - pentru a salva build-ul.
`./game.exe`: - pentu a da la executie proiectul direct din terminal 
`cmd /c build_test.cmd`: - pentru a rula testele în terminal


# Laborator 03

## Ce am realizat 
Am definit:  
- constructor implicit  
- constructor de copiere  
- constructor cu parametri  
- operator de copiere (`=`)  
- operator de comparație (`==`)  
- operatori de citire și afișare (`>>` și `<<`)  

Aceste modificări permit manipularea mai ușoară a obiectelor jocului și pregătesc proiectul pentru utilizarea bibliotecii standard C++.