#include "constructingTable.hpp"

void ConstructActionTable(ActionTable &actionTable)
{
    const std::string TABLE_FILE = "Tables/ActionTable.txt";

    std::ifstream inFile(TABLE_FILE);
    std::string value;
    int i = 0;

    if (inFile.is_open())
    {
        // Reading the first line for names.
        while (inFile >> value)
        {
            actionTable.AddActionList(ActionList(value));

            if (inFile.peek() == '\n' || inFile.peek() == '\r')
            {
                break; // Stop at new line
            }
        }

        while (inFile >> value)
        {
            ActionObj actionObj = ActionObj();
            switch (value.at(0))
            {
            case '-':
                actionObj.actionOp = EMPTY;
                break;
            case 's':
                actionObj.actionOp = SHIFT;
                break;
            case 'r':
                actionObj.actionOp = REDUCE;
                break;
            case 'a':
                actionObj.actionOp = ACCEPT;
                break;
            default:
                actionObj.actionOp = EMPTY;
                break;
            }

            if (value.size() > 1 && std::isdigit(value.at(1)))
            {
                actionObj.actionId = value.at(1) - '0';
            }
            else
                actionObj.actionId = -1;

            actionTable.actions.at(i)
                .AddOperation(actionObj);
            i++;
            if (i == actionTable.actions.size())
                i = 0;
        }
    }

    inFile.close();
}

void ConstructGoToTable(GotoTableManager &gotoManager)
{
    const std::string TABLE_FILE = "Tables/GotoTable.txt";

    std::ifstream readGoto(TABLE_FILE);
    std::string value;
    int locationNo = 0;

    if (readGoto.is_open())
    {
        while (readGoto >> value)
        {
            gotoManager.setGotoLocationEntry(value);

            if (readGoto.peek() == '\n' || readGoto.peek() == '\r')
            {
                break; // Stop at new line
            }
        }

        while (readGoto >> value)
        {
            if (std::isdigit(value.at(0)))
                gotoManager.setGotoValueEntry(locationNo, std::stoi(value));
            else
                gotoManager.setGotoValueEntry(locationNo, -1);

            if (locationNo == gotoManager.getTableSize() - 1)
                locationNo = 0;
            else
                locationNo++;
        }
    }

    readGoto.close();
}

void ConstructGrammarTable(GrammarManager &grammarManager)
{
    const std::string TABLE_FILE = "Tables/Grammar.txt";

    std::ifstream readGrammar(TABLE_FILE);
    std::string Id, value, arrow;
    std::string grammarUse = "";
    std::string grammarReplace = "";

    if (readGrammar.is_open())
    {
        // Reading the grammar file line by line
        std::string line;
        while (std::getline(readGrammar, line))
        {
            // Putting it into a sstream for easier reading
            std::stringstream ss(line);
            // Id is read
            ss >> Id;

            // grammarUse will be read
            while (ss >> value && value != "->")
            {
                grammarUse += value;
            }

            // Rest is read for the replace
            std::getline(ss, grammarReplace);

            grammarReplace.erase(0, grammarReplace.find_first_not_of(" "));
            grammarReplace.erase(grammarReplace.find_last_not_of(" ") + 1);

            grammarManager.setGrammar(std::stoi(Id), grammarUse, grammarReplace);
            grammarUse = "";
        }

        readGrammar.close();
    }
}