#include "ErrorLog.h"

namespace Errors {
	std::string m_allErrors = "";
	int amountErrors = 0;

	// Errors printy
	void File_Not_Found() {
		std::cerr << "File not found. The specified path does not lead to any existing file.\n" << std::endl;
		amountErrors++;
		m_allErrors += "File not found. The specified path does not lead to any existing file.\n";
	}
	
	void Unknown_Char_in_Room_File(int row, int column, char tileFromFile) {
		std::cerr << "\n\tUnknown character in the room file. Please correct the file!"
			<< "\n\nUnknown character: " << tileFromFile
			<< "\nRow: " << row + 1 << "\nColumn:" << column + 1 << std::endl;
		amountErrors++;
	}

	void Error_Opening_File() {
		std::cout << "Error occured during opening the file.\n" << std::endl;
		amountErrors++;
	}
}

