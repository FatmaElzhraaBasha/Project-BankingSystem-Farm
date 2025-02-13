#pragma once

class Parser {
public:
    static vector<string> split(string line, char delimiter = ',') {
        vector<string> result;
        stringstream ss(line);
        string field;

        while (getline(ss, field, delimiter)) {
            result.push_back(field);
        }
        return result;
    }

    static Client parseToClient(string line) {
        vector<string> tokens = split(line);

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid client data format!");
        }

        return Client(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Employee parseToEmployee(string line) {
        vector<string> tokens = split(line);

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid employee data format");
        }

        return Employee(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Admin parseToAdmin(string line) {
        vector<string> tokens = split(line);

        if (tokens.size() != 4) {
            throw invalid_argument("Invalid admin data format");
        }

        return Admin(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }
};

