#include "Team.hpp"
#include <iostream>
#include <algorithm>

using namespace ariel;

Team::Team(Character* leader)
    : m_leader(leader) {
    m_fighters.push_back(leader);
}

Team::~Team() {
    for (Character* fighter : m_fighters) {
        delete fighter;
    }
}

void Team::add(Character* fighter) {
    m_fighters.push_back(fighter);
}

void Team::attack(Team* enemyGroup) {
    if (m_leader == nullptr || !m_leader->isAlive()) {
        // Find the living character closest to the dead leader and set it as the new leader
        double closestDistance = std::numeric_limits<double>::max();
        Character* newLeader = nullptr;
        for (Character* fighter : m_fighters) {
            if (fighter->isAlive()) {
                double distance = m_leader->distance(fighter);
                if (distance < closestDistance) {
                    closestDistance = distance;
                    newLeader = fighter;
                }
            }
        }
        m_leader = newLeader;
    }

    Character* victim = nullptr;
    double closestDistance = std::numeric_limits<double>::max();
    for (Character* enemy : enemyGroup->m_fighters) {
        if (enemy->isAlive()) {
            double distance = m_leader->distance(enemy);
            if (distance < closestDistance) {
                closestDistance = distance;
                victim = enemy;
            }
        }
    }

    if (victim != nullptr) {
        for (Character* fighter : m_fighters) {
            if (fighter->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
                if (cowboy != nullptr && cowboy->hasBullets()) {
                    cowboy->shoot(victim);
                } else {
                    Ninja* ninja = dynamic_cast<Ninja*>(fighter);
                    if (ninja != nullptr && ninja->distance(victim) < 1.0) {
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }
            }
        }

        if (!victim->isAlive()) {
            // Find the living enemy character closest to the attacking group's leader as the new victim
            closestDistance = std::numeric_limits<double>::max();
            for (Character* enemy : enemyGroup->m_fighters) {
                if (enemy->isAlive()) {
                    double distance = m_leader->distance(enemy);
                    if (distance < closestDistance) {
                        closestDistance = distance;
                        victim = enemy;
                    }
                }
            }
        }
    }
}

int Team::isAlive() const {
    int aliveCount = 0;
    for (Character* fighter : m_fighters) {
        if (fighter->isAlive()) {
            aliveCount++;
        }
    }
    return aliveCount;
}

void Team::print() const {
    for (Character* fighter : m_fighters) {
        fighter->print();
    }
}
