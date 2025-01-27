#include <iostream>
#include <string>
#include <map>
#include <cctype> 

using namespace std;

string toLowerCase(const string& str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]); 
    }
    return result;
}

string sentimentAnalysis(const string& input) {
    string lowerInput = toLowerCase(input);

    if (lowerInput.find("happy") != string::npos || lowerInput.find("good") != string::npos) {
        return "positive";
    } else if (lowerInput.find("sad") != string::npos || lowerInput.find("angry") != string::npos) {
        return "negative";
    } else if (lowerInput.find("excited") != string::npos) {
        return "excited";
    } else if (lowerInput.find("bored") != string::npos) {
        return "bored";
    }
    return "neutral";
}
map<string, string> responses;

void initializeResponses() {
    responses["hello"] = "Hi there! How can I help you today?";
    responses["how are you"] = "I'm just a bot, but I'm doing well, thank you! How about you?";
    responses["bye"] = "Goodbye! Take care.";
    responses["thank you"] = "You're welcome!";
    responses["what is your name"] = "I am your friendly AI chatbot.";
    responses["how old are you"] = "I don't have an age. I was created to assist you.";
    responses["tell me a joke"] = "Why don't programmers like nature? It has too many bugs!";
    responses["what's the weather like"] = "I don't have access to live weather data, but you can check online.";
    responses["how can i improve myself"] = "Keep learning, stay curious, and always be open to feedback!";
}
string userName = "";

string getResponse(const string& input) {
    string lowerInput = toLowerCase(input);

    if (lowerInput.find("my name is") != string::npos) {
        size_t pos = lowerInput.find("my name is");
        userName = input.substr(pos + 11); 
        return "Nice to meet you, " + userName + "!";
    }
    
    if (responses.find(lowerInput) != responses.end()) {
        return responses[lowerInput];
    } else {
        return "I'm sorry, I didn't understand that. Could you please rephrase?";
    }
}
void chatbotConversation() {
    string userInput;
    string botResponse;
    string sentiment;

    cout << "Chatbot: Hello! Type 'bye' to end the conversation." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);
        
        if (userInput.empty()) {
            cout << "Chatbot: Please say something!" << endl;
            continue;
        }

        sentiment = sentimentAnalysis(userInput);
        botResponse = getResponse(userInput);

        cout << "Chatbot: " << botResponse << endl;
        cout << "Sentiment: " << sentiment << endl;
        
        if (toLowerCase(userInput) == "bye") {
            break;
        }
    }
}

int main() {
    initializeResponses();

    chatbotConversation();
    return 0;
}

