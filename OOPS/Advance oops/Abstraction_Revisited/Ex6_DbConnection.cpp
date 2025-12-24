// Exercise 6: Database Connection Abstraction
// Problem: Create an abstract database connection system.

// Requirements:

// Abstract class DatabaseConnection with:
// connect(), disconnect(), executeQuery(), beginTransaction(), commit(), rollback()
// Implement classes MySQLConnection and SQLiteConnection
// Use the Factory Method pattern in a DatabaseFactory class
// Demonstrate polymorphism by using base class pointers


#include<bits/stdc++.h>
using namespace std;

class DatabaseConnection{
  public:
    virtual void connect()=0;
    virtual void disconnect()=0;
    virtual void executeQuery(const std::string& query)=0;
    virtual void beginTransaction()=0;
    virtual void commit()=0;
    virtual void rollback()=0;

    virtual ~DatabaseConnection() = default;
};


//class for mysql connection
class MySQLConnection : public DatabaseConnection {
public:
    void connect() override {
        std::cout << "Connecting to MySQL database...\n";
    }

    void disconnect() override {
        std::cout << "Disconnecting from MySQL database...\n";
    }

    void executeQuery(const std::string& query) override {
        std::cout << "MySQL executing: " << query << "\n";
    }

    void beginTransaction() override {
        std::cout << "MySQL BEGIN TRANSACTION\n";
    }

    void commit() override {
        std::cout << "MySQL COMMIT\n";
    }

    void rollback() override {
        std::cout << "MySQL ROLLBACK\n";
    }
};

//Sqllite connection
class SQLiteConnection : public DatabaseConnection {
public:
    void connect() override {
        std::cout << "Opening SQLite database...\n";
    }

    void disconnect() override {
        std::cout << "Closing SQLite database...\n";
    }

    void executeQuery(const std::string& query) override {
        std::cout << "SQLite executing: " << query << "\n";
    }

    void beginTransaction() override {
        std::cout << "SQLite BEGIN TRANSACTION\n";
    }

    void commit() override {
        std::cout << "SQLite COMMIT\n";
    }

    void rollback() override {
        std::cout << "SQLite ROLLBACK\n";
    }
};


//factory methord pattern

enum class DatabaseType {
    MYSQL,
    SQLITE
};

class DatabaseFactory {
public:
    static std::unique_ptr<DatabaseConnection> createConnection(DatabaseType type) {
        if (type == DatabaseType::MYSQL) {
            return make_unique<MySQLConnection>();
        }
        else if (type == DatabaseType::SQLITE) {
            return make_unique<SQLiteConnection>();
        }
        return nullptr;
    }
};




int main(){
  auto db = DatabaseFactory::createConnection(DatabaseType::MYSQL);
  db->connect();
  db->beginTransaction();
  db->executeQuery("SELECT * FROM TABLE");
  db->rollback();
  db->commit();
  db->disconnect();


  db = DatabaseFactory::createConnection(DatabaseType::SQLITE);
  db->connect();
  db->beginTransaction();
  db->executeQuery("SELECT * FROM TABLE");
  db->rollback();
  db->commit();
  db->disconnect();
  
}