
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

// ============================
// هيكل الجامعة
struct University {
    string name;
    string department;
    double minScore;
    string field;
};


string toLowerString(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return str;
}


void matchUniversities(const vector<University>& universities, const string& field, double score) {
    cout << "\n🔍 Matching Universities for field: " << field << " and score: " << score << "\n";
    bool found = false;

    for (const auto& uni : universities) {
        if (toLowerString(uni.field) == toLowerString(field) && score >= uni.minScore) {
            cout << "✅ " << uni.name << " - " << uni.department << " (Min: " << uni.minScore << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "❌ No matching universities found.\n";
    }
}


void displayJobsByCollege() {
    cin.ignore();
    string collegeName;
    cout << "🎓 Enter the college name you want: ";
    getline(cin, collegeName);

    string lowerCollege = toLowerString(collegeName);

    if (lowerCollege == "faculty of mathematical and informatics sciences" ||
        lowerCollege == "كلية العلوم الرياضية و المعلوماتية") {

        vector<string> jobs = {
            "Data Analyst",
            "Software Developer",
            "Mathematician",
            "University Lecturer",
            "Data Scientist",
            "Systems Analyst",
            "AI Programmer",
            "Cybersecurity Expert",
            "Network Engineer",
            "Algorithm Designer",
            "Mobile App Developer",
            "Database Administrator",
            "Software Engineer"
        };

        cout << "\n📌 Jobs related to the Faculty of Mathematical and Informatics Sciences:\n";
        for (const string& job : jobs) {
            cout << "🔹 " << job << endl;
        }

    } else {
        cout << "\n❌ Sorry, no data available for this college.\n";
    }
}


void showUniversitiesWithWebsites() {
    ifstream file("uw.txt");
    if (!file) {
        cout << "❌ Error: Could not open the file uw.txt\n";
        return;
    }

    string line;
    cout << "📚 Sudanese Universities and Their Websites:\n";
    while (getline(file, line)) {
        stringstream ss(line);
        string name, website;
        getline(ss, name, ',');
        getline(ss, website, ',');

        cout << "🔹 " << name << " - 🌐 " << website << endl;
    }

    file.close();
}


void showMenu() {
    cout << "\n============================\n";
    cout << "🎓 Welcome to Univers Guide\n";
    cout << "============================\n";
    cout << "1️⃣  View Admission guide Link\n";
    cout << "2️⃣  Find Colleges by Field & Score\n";
    cout << "3️⃣  Show Jobs\n";
    cout << "4️⃣  Show Universities\n";
    cout << "0️⃣  Exit\n";
    cout << "============================\n";
    cout << "👉 Enter your choice: ";
}

int main() {
    int choice;
    string daleel = "https://daleel.admission.gov.sd/index.htm";

    // بيانات افتراضية للجامعات
    vector<University> universities = {
        {"University of Khartoum", "Computer Science", 85.0, "science"},
        {"Sudan University", "Engineering", 80.0, "science"},
        {"Gezira University", "Medicine", 90.0, "science"},
        {"Omdurman Ahlia", "Business", 75.0, "literature"},
        {"Red Sea University", "Arts", 70.0, "literature"}
    };

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 0) {
            cout << "✨ Thank you for using Univers Guide. Good luck! ✨\n";
            break;
        } else if (choice == 1) {
            cout << "\n🔗 Admission Guide Link: " << daleel << "\n";
        } else if (choice == 2) {
            string field;
            double score;
            cout << "\n📚 Enter your field (science / literature): ";
            cin >> field;
            cout << "📊 Enter your score: ";
            cin >> score;
            matchUniversities(universities, field, score);
        } else if (choice == 3) {
            displayJobsByCollege();
        } else if (choice == 4) {
            showUniversitiesWithWebsites();
        } else {
            cout << "❌ Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
