#pragma once
#include "IEntity.h"

class Item: public IEntity {
protected:
		std::string m_name;
		std::string m_description;		// konkretni popis predmetu
		std::string m_info;
		std::string m_category; // rebuilt to enum class
// category: armor		healing_potion		weapon
public:
	Item(std::string name);
	std::string getName() const;
	std::string getCategory() const;
	std::string getInfo() const;
    void printInfo();
    virtual void setInfo(std::string info) = 0;
    virtual void setCategory(std::string category) = 0;
    // specifická metoda, která zobrazí formátovaně info o daném objektu místo předání hodnot
    virtual void printBriefInfo() = 0;
    virtual ~Item() = 0;
};
