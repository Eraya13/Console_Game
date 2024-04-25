#include "NPC.h"

NPC::NPC(std::string name) : IEntity() {
    m_name = name;
}

std::string NPC::getName() const { return m_name;}