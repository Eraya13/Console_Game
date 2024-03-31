#pragma once
#include <iostream>

namespace Errors {
	extern std::string m_allErrors;
	extern int amountErrors;
	void addErrorOnList(std::string error);		// neni hotovo
	// Errors prints:
	void File_Not_Found();
	void Unknown_Char_in_Room_File(int row, int column, char tileFromFile);		// metoda nasla neznamy tileType (char) v Roomfilu
	void Error_Opening_File();
};

