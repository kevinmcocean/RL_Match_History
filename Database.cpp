#include "pch.h"
#include "Database.h"
#include <iostream>

Database::Database(const std::string& dbPath)
    : m_dbPath(dbPath), m_db(nullptr)
{
}

Database::~Database()
{
    Close();
}

bool Database::Open()
{
    int rc = sqlite3_open(m_dbPath.c_str(), &m_db);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    return true;
}

void Database::Close()
{
    if (m_db) {
        sqlite3_close(m_db);
        m_db = nullptr;
    }
}

bool Database::CreateTables()
{
    if (!m_db) return false;

    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS mmr_history ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "timestamp TEXT,"
        "playlist INTEGER,"
		"playlist_name TEXT,"
        "mmr REAL);";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(m_db, createTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Create table failed: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::InsertMMR(int playlist, const std::string playlist_name, const float mmr)
{
    if (!m_db) return false;

    std::string timestamp = std::to_string(std::time(nullptr));
    std::string sql =
        "INSERT INTO mmr_history (timestamp, playlist, playlist_name, mmr) VALUES ('" +
        timestamp + "', " +
        std::to_string(playlist) + ", '" +
		playlist_name + "', " +
        std::to_string(mmr) + ");";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Insert failed: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

std::vector<MMRRecord> Database::GetMMRHistory()
{
    std::vector<MMRRecord> history;
    if (!m_db) return history;

    const char* sql = "SELECT id, timestamp, playlist, mmr FROM mmr_history;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(m_db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return history;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        MMRRecord r;
        r.id = sqlite3_column_int(stmt, 0);
        r.timestamp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        r.playlist = sqlite3_column_int(stmt, 2);
        r.mmr = static_cast<float>(sqlite3_column_double(stmt, 3));
        history.push_back(r);
    }

    sqlite3_finalize(stmt);
    return history;
}
