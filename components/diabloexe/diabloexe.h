#ifndef DIABLO_EXE_H
#define DIABLO_EXE_H

#include <string>
#include <map>
#include <vector>

#include <settings/settings.h>
#include <faio/faio.h>

#include "monster.h"
#include "npc.h"
#include "baseitem.h"
#include "affix.h"
#include "uniqueitem.h"
#include "characterstats.h"
namespace DiabloExe
{
    class DiabloExe
    {
        public:
            DiabloExe(const std::string& pathEXE = "Diablo.exe");

            const Monster& getMonster(const std::string& name) const;
            std::vector<const Monster*> getMonstersInLevel(size_t levelNum) const;

            const Npc& getNpc(const std::string& name) const;
            std::vector<const Npc*> getNpcs() const;

            const BaseItem& getItem(const std::string& name) const;
            std::map<std::string, BaseItem> getItemMap() const;
            const std::map<std::string, UniqueItem> & getUniqueItemMap() const;
            const CharacterStats getCharacterStat(std::string character) const;

            std::string dump() const;

            bool isLoaded() const;

            uint32_t swapEndian(uint32_t arg);



        private:
            std::string getMD5(const std::string& pathEXE);
            std::string getVersion(const std::string& pathEXE);


            void loadMonsters(FAIO::FAFile* exe);
            void loadNpcs(FAIO::FAFile* exe);
            void loadBaseItems(FAIO::FAFile* exe);
            void loadUniqueItems(FAIO::FAFile* exe);
            void loadAffixes(FAIO::FAFile* exe);
            void loadCharacterStats(FAIO::FAFile * exe);



            Settings::Settings mSettings;

            std::string mVersion;
            std::map<std::string, Monster> mMonsters;
            std::map<std::string, Npc> mNpcs;
            std::map<std::string, BaseItem> mBaseItems;
            std::map<std::string, UniqueItem> mUniqueItems;
            std::map<std::string, Affix> mAffixes;
            std::map<std::string, CharacterStats> mCharacters;
    };
}

#endif
