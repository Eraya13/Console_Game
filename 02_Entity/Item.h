#pragma once
#include "../02_Entity/Entity.h"

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
	virtual void setInfo() = 0;
	virtual void setCategory() = 0;
};
