#include "DataFormatting.h"

namespace DataFormatting {
    // funkce naformatuje Description na pozadovany tvar pro zobrazeni
    std::string formateDescription(std::string toBePrinted) {
        std::string finalPrint = "";        // vysledny retezec k zobrazeni
        int counterChars = 0;               // pocitadlo znaku pro 1 radek
        // -1 inicialni value (nezmeni se, pokud se na radku nenajde mezera)  
        int lastSpaceIndex = -1;            // index posledni mezery na aktualnim radku

        for (int i = 0; i < toBePrinted.size(); i++) {          // i = index znaku v Poli znaku
            counterChars++;
            if (toBePrinted.at(i) == ' ') {             // ulozime si index posledni mezery
                lastSpaceIndex = i;
            }
            // vyhodnoceni 21 znaku
            if (counterChars == 60) {       // ovlivnuje delku radku
                // 21 je mezera
                if (toBePrinted.at(i) == ' ') {
                    // pridani znaku do finalniho retezce substringu v rozmezi 0 az do mezery + konec radku
                    finalPrint += toBePrinted.substr(0, i) + "\n\t";
                    toBePrinted = toBePrinted.substr(i + 1);      // odstraneni substringu mezi 0 a i --> zadavame POCET znaku, tedy +1
                }
                // na 21 je znak
                else if (lastSpaceIndex != -1) {        // -1 inicialni value (nezmeni se, pokud se na radku nenajde mezera)       
                    // pridani substringu od posledni mezery do finalniho retezce
                    finalPrint += toBePrinted.substr(0, lastSpaceIndex) + "\n\t";
                    toBePrinted = toBePrinted.substr(lastSpaceIndex + 1);       // odstraneneni znaku do lastSpace (POCET ZNAKU)!
                }
                // na radku nebyla ani jedna mezera
                else {
                    finalPrint += toBePrinted.substr(0, i) + "\n\t";
                    toBePrinted = toBePrinted.substr(i);
                }
                i = -1;     // Reset indexu i, doslo ke zmene vstupniho retezce
                counterChars = 0;
                lastSpaceIndex = -1;
            }
        }
        finalPrint += toBePrinted;
        std::cout << finalPrint;
        return finalPrint;
    }
}
