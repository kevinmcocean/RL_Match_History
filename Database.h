#pragma once
#include "sqlite3.h"
#include <string>
#include <vector>
#include <ctime>

struct MMRRecord
{
    int id;
    std::string timestamp;
    int playlist;
    float mmr;
};

class Database
{
public:
    Database(const std::string& dbPath);
    ~Database();

    bool Open();
    void Close();
    bool CreateTables();
    bool InsertMMR(int playlist, float mmr);
    std::vector<MMRRecord> GetMMRHistory();
    sqlite3* m_db;

private:
    std::string m_dbPath;
    
};
